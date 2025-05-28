#==============================================================================
# Project : cuds (C Utilities and Data Structures)
# Structure : Linux-only, static and shared library, pkg-config support
# Author: Raphael CAUSSE
#==============================================================================

PROJECT_NAME := cuds

# BUILD_TYPE ?= release
BUILD_TYPE ?= debug


#==============================================================================
# DIRECTORIES
#==============================================================================

# Project directories
DIR_SRC   := src
DIR_INC   := include
DIR_LIB   := lib
DIR_BUILD := build
DIR_TEST  := test

# System directories
DESTPREFIX ?= /usr/local
DIR_PKGCONFIG = $(DESTPREFIX)/lib/pkgconfig


#==============================================================================
# FILES AND TARGETS
#==============================================================================

# Sources and objects
SRCS := $(wildcard $(DIR_SRC)/*/*.c)
OBJS := $(patsubst $(DIR_SRC)/%.c,$(DIR_BUILD)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

# Targets libraries
TARGET_LIB_STATIC := $(DIR_LIB)/lib$(PROJECT_NAME).a
TARGET_LIB_SHARED := $(DIR_LIB)/lib$(PROJECT_NAME).so

# Tests sources and targets
TEST_SRCS := $(wildcard $(DIR_TEST)/test_*.c)
TEST_TARGETS := $(patsubst $(DIR_TEST)/%.c,$(DIR_BUILD)/$(DIR_TEST)/%,$(TEST_SRCS))

# Pkg-config file
PKGCONFIG := $(PROJECT_NAME).pc


#==============================================================================
# COMPILER AND LINKER
#==============================================================================

# C Compiler
CC ?= gcc

# Archiver
AR ?= ar

# Extra flags to give to the C compiler
CFLAGS         := -std=c99 -Wall -Wextra -pedantic -fPIC
CFLAGS_DEBUG   := -O0 -g -fsanitize=address
CFLAGS_RELEASE := -O2 -g0

# Extra flags to give to the C preprocessor (e.g. -I, -D, -U ...)
CPPFLAGS         := -I$(DIR_INC)
CPPFLAGS_DEBUG   := -DDEBUG
CPPFLAGS_RELEASE := -DNDEBUG

# Extra flags to give to compiler when it invokes the linker (e.g. -L ...)
LDFLAGS      :=
LDFLAGS_TEST := -L$(DIR_LIB)

# Library names given to compiler when it invokes the linker (e.g. -l ...)
LDLIBS      :=
LDLIBS_TEST := -l$(PROJECT_NAME)

# Enable automatic dependency tracking
DEPFLAGS := -MMD -MP

# Append flags according to build type
ifeq ($(BUILD_TYPE),release)
    CFLAGS   += $(CFLAGS_RELEASE)
    CPPFLAGS += $(CPPFLAGS_RELEASE)
else ifeq ($(BUILD_TYPE),debug)
    CFLAGS   += $(CFLAGS_DEBUG)
    CPPFLAGS += $(CPPFLAGS_DEBUG)
else
    $(warning Unknown BUILD_TYPE '$(BUILD_TYPE)', using default flags)
endif


#==============================================================================
# TOOLS
#==============================================================================

# Commands
MKDIR := mkdir -p
RM    := rm -f
RMDIR := rm -rf
CP    := cp


#==============================================================================
# VERBOSITY
#==============================================================================

VERBOSITY := $(or $(V), $(VERBOSE))
ifneq ($(VERBOSITY),1)
    Q := @
else
    Q :=
endif


#==============================================================================
# RULES
#==============================================================================

.PHONY: __check
.PHONY: all libstatic libshared tests run-tests clean install uninstall


all: libstatic libshared


# Internal rules protection
$(if $(filter __%, $(MAKECMDGOALS)), $(error Rules prefixed with "__" are only for internal use))

# (Internal) Check configuration
__check:
ifeq ($(PROJECT_NAME),)
	$(error PROJECT_NAME is required. Must provide a project name)
endif


libstatic: $(TARGET_LIB_STATIC)

# Build static library
$(TARGET_LIB_STATIC): $(OBJS)
	@$(MKDIR) $(DIR_LIB)
	$(Q)$(AR) rcs $@ $^


libshared: $(TARGET_LIB_SHARED)

# Build shared library
$(TARGET_LIB_SHARED): $(OBJS)
	@$(MKDIR) $(DIR_LIB)
	$(Q)$(CC) $(LDFLAGS) -shared -o $@ $^ $(LDLIBS)


# Build object files
$(DIR_BUILD)/%.o: $(DIR_SRC)/%.c
	@$(MKDIR) $(dir $@)
	$(Q)$(CC) $(CPPFLAGS) $(CFLAGS) $(DEPFLAGS) -c $< -o $@


tests: $(TEST_TARGETS)

# Build test targets
$(DIR_BUILD)/$(DIR_TEST)/%: $(DIR_TEST)/%.c libstatic
	@$(MKDIR) $(dir $@)
	$(Q)$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS_TEST) $< -o $@ $(LDLIBS) $(LDLIBS_TEST)


# Run all tests
run-tests:
	@for t in $(TEST_BINS); do \
		echo "[RUN] $$t"; \
		./$$t || exit 1; \
	done


# Clean build artifacts
clean:
	$(Q)$(RMDIR) $(BUILD_DIR) $(LIB_DIR)


# Install headers and libs
install: all
	@$(MKDIR) $(DESTPREFIX)/include/$(PROJECT_NAME)
	$(Q)$(CP) -r $(INC_DIR)/$(PROJECT_NAME)/*.h $(DESTPREFIX)/include/$(PROJECT_NAME)/
	$(Q)$(CP) $(TARGET_LIB_STATIC) $(TARGET_LIB_SHARED) $(DESTPREFIX)/lib/
	@$(MKDIR) $(DIR_PKGCONFIG)
	$(Q)$(CP) $(PKGCONFIG) $(DIR_PKGCONFIG)/
	ldconfig


# Uninstall headers and libs
uninstall:
	$(Q)$(RM) $(DESTPREFIX)/$(TARGET_LIB_STATIC) $(DESTPREFIX)/$(TARGET_LIB_SHARED)
	$(Q)$(RMDIR) $(DESTPREFIX)/include/cuds
	$(Q)$(RM) $(DIR_PKGCONFIG)/$(PKGCONFIG)
	ldconfig
