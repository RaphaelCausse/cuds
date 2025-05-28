#==============================================================================
# Project : cuds (C Utilities and Data Structures)
# Structure : Linux-only, static and shared library, pkg-config support
# Author: Raphael CAUSSE
#==============================================================================

PROJECT_NAME := cuds

VERSION_MAJOR := 0
VERSION_MINOR := 1
VERSION_PATCH := 0
PROJECT_VERSION := $(VERSION_MAJOR).$(VERSION_MINOR).$(VERSION_PATCH)

BUILD_TYPE ?= release


#==============================================================================
# DIRECTORIES
#==============================================================================

# System directories
DESTPREFIX ?= /usr/local/
DIR_PKGCONFIG = $(DESTPREFIX)lib/pkgconfig/

# Project directories
DIR_SRC   := src/
DIR_INC   := include/
DIR_LIB   := lib/
DIR_BUILD := build/
DIR_GEN   := $(DIR_INC)$(PROJECT_NAME)/


#==============================================================================
# FILES AND TARGETS
#==============================================================================

# Source file for cuds library
CUDS_SRC_FILES :=

# Object files for cuds library
CUDS_OBJ_FILES := $(patsubst $(DIR_SRC)%.c,$(DIR_BUILD)%.o,$(CUDS_SRC_FILES))
CUDS_DEP_FILES := $(CUDS_OBJ_FILES:.o=.d)

# Targets for cuds library
CUDS_TARGET_LIB_STATIC := $(DIR_LIB)lib$(PROJECT_NAME).a
CUDS_TARGET_LIB_SHARED := $(DIR_LIB)lib$(PROJECT_NAME).so

# Pkg-config file
PKGCONFIG_FILE := $(PROJECT_NAME).pc

# Auto-generated version files
VERSION_FILE   := VERSION
VERSION_HEADER := $(DIR_GEN)version.h


#==============================================================================
# COMPILER AND LINKER
#==============================================================================

CC := gcc
AR := ar

# Extra flags to give to the C compiler
CFLAGS         := -std=c99 -Wall -Wextra -pedantic -fPIC
CFLAGS_DEBUG   := -O0 -g -fsanitize=address
CFLAGS_RELEASE := -O2 -g0

# Extra flags to give to the C preprocessor (e.g. -I, -D, -U ...)
CPPFLAGS         := -I$(DIR_INC)
CPPFLAGS_DEBUG   := -DDEBUG
CPPFLAGS_RELEASE := -DNDEBUG

# Extra flags to give to compiler when it invokes the linker (e.g. -L ...)
LDFLAGS :=

# Library names given to compiler when it invokes the linker (e.g. -l ...)
LDLIBS :=

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

# Internal rules protection
$(if $(filter __%, $(MAKECMDGOALS)), $(error Rules prefixed with "__" are only for internal use))


.PHONY: all libstatic libshared clean cleanall install uninstall version pkgconfig help __check

all: version pkgconfig libstatic libshared


libstatic: __check $(VERSION_HEADER) $(CUDS_TARGET_LIB_STATIC)

# Build cuds static library
$(CUDS_TARGET_LIB_STATIC): $(CUDS_OBJ_FILES)
	@$(MKDIR) $(DIR_LIB)
	@echo "  AR    $@"
	$(Q)$(AR) rcs $@ $^


libshared: __check $(VERSION_HEADER) $(CUDS_TARGET_LIB_SHARED)

# Build cuds shared library
$(CUDS_TARGET_LIB_SHARED): $(CUDS_OBJ_FILES)
	@$(MKDIR) $(DIR_LIB)
	@echo "  LD    $@"
	$(Q)$(CC) $(LDFLAGS) -shared -o $@ $^ $(LDLIBS)


# Build object files
$(DIR_BUILD)%.o: $(DIR_SRC)%.c $(VERSION_HEADER) 
	@$(MKDIR) $(dir $@)
	@echo "  CC    $@"
	$(Q)$(CC) $(CPPFLAGS) $(CFLAGS) $(DEPFLAGS) -c $< -o $@


# Clean build artifacts
clean:
	@echo "  RM    $(DIR_BUILD)"
	$(Q)$(RMDIR) $(DIR_BUILD)
	@echo "  RM    $(DIR_LIB)"
	$(Q)$(RMDIR) $(DIR_LIB)


# Clean all build artifacts
cleanall:
	@echo "  RM    $(DIR_BUILD)"
	$(Q)$(RMDIR) $(DIR_BUILD)
	@echo "  RM    $(DIR_LIB)"
	$(Q)$(RMDIR) $(DIR_LIB)
	@echo "  RM    $(VERSION_FILE)"
	$(Q)$(RM) $(VERSION_FILE)
	@echo "  RM    $(VERSION_HEADER)"
	$(Q)$(RM) $(VERSION_HEADER)
	@echo "  RM    $(PKGCONFIG_FILE)"
	$(Q)$(RM) $(PKGCONFIG_FILE)


# Install headers and libs
install: all
	@echo "Installing headers and libraries..."
	@$(MKDIR) $(DESTPREFIX)$(DIR_INC)$(PROJECT_NAME)/
	$(Q)$(CP) -r $(DIR_GEN) $(DESTPREFIX)$(DIR_INC)
	$(Q)$(CP) $(CUDS_TARGET_LIB_STATIC) $(DESTPREFIX)$(DIR_LIB)
	$(Q)$(CP) $(CUDS_TARGET_LIB_SHARED) $(DESTPREFIX)$(DIR_LIB)
	@$(MKDIR) $(DIR_PKGCONFIG)
	$(Q)$(CP) $(PKGCONFIG_FILE) $(DIR_PKGCONFIG)$(PKGCONFIG_FILE)
	$(Q)ldconfig
	@echo "Done."


# Uninstall headers and libs
uninstall:
	@echo "Uninstalling headers and libraries..."
	@$(RMDIR) $(DESTPREFIX)$(DIR_GEN)
	$(Q)$(RM) $(DESTPREFIX)$(CUDS_TARGET_LIB_STATIC)
	$(Q)$(RM) $(DESTPREFIX)$(CUDS_TARGET_LIB_SHARED)
	$(Q)$(RM) $(DIR_PKGCONFIG)$(PKGCONFIG_FILE)
	$(Q)ldconfig
	@echo "Done."


version: $(VERSION_FILE) $(VERSION_HEADER)

# Auto-generate version file
$(VERSION_FILE):
	@echo "  GEN   $@ $(PROJECT_VERSION)"
	@echo "$(PROJECT_VERSION)" > $@

# Auto-generate version header
$(VERSION_HEADER):
	@$(MKDIR) $(DIR_GEN)
	@echo "  GEN   $@"
	@echo "#ifndef CUDS_VERSION_H_" > $@
	@echo "#define CUDS_VERSION_H_" >> $@
	@echo "" >> $@
	@echo "#define CUDS_VERSION_MAJOR $(VERSION_MAJOR)" >> $@
	@echo "#define CUDS_VERSION_MINOR $(VERSION_MINOR)" >> $@
	@echo "#define CUDS_VERSION_PATCH $(VERSION_PATCH)" >> $@
	@echo "#define CUDS_VERSION_STRING \"$(PROJECT_VERSION)\"" >> $@
	@echo "" >> $@
	@echo "#define CUDS_VERSION_ENCODE(major, minor, patch) ((major) * 10000 + (minor) * 100 + (patch))" >> $@
	@echo "#define CUDS_VERSION_CODE CUDS_VERSION_ENCODE(CUDS_VERSION_MAJOR, CUDS_VERSION_MINOR, CUDS_VERSION_PATCH)" >> $@
	@echo "" >> $@
	@echo "#endif // CUDS_VERSION_H_" >> $@


# Auto-generate pkg-config file
pkgconfig: $(PKGCONFIG_FILE)

$(PKGCONFIG_FILE): __check
	@echo "  GEN   $@"
	@echo "prefix=$(DESTPREFIX)" > $@
	@echo "exec_prefix=\$${prefix}" >> $@
	@echo "libdir=\$${exec_prefix}lib" >> $@
	@echo "includedir=\$${prefix}include" >> $@
	@echo "" >> $@
	@echo "Name: $(PROJECT_NAME)" >> $@
	@echo "Description: C Utilities and Data Structures" >> $@
	@echo "Version: $(PROJECT_VERSION)" >> $@
	@echo "Libs: -L\$${libdir} -l$(PROJECT_NAME)" >> $@
	@echo "Cflags: -I\$${includedir}/$(PROJECT_NAME)" >> $@


# Help message
help:
	@echo "Available targets:"
	@echo "  all           Build static and shared libraries"
	@echo "  libstatic     Build static library only"
	@echo "  libshared     Build shared library only"
	@echo "  clean         Remove build/ and lib/ directories"
	@echo "  cleanall      Remove all generated artifacts"
	@echo "  install       Install headers and libraries"
	@echo "  uninstall     Uninstall everything"
	@echo "  version       Generate version files"
	@echo "  pkgconfig     Generate pkg-config file"


# (Internal) Check configuration
__check:
ifeq ($(PROJECT_NAME),)
	$(error PROJECT_NAME is required. Must provide a project name)
endif
ifeq ($(VERSION_MAJOR),)
	$(error VERSION_MAJOR is required. Must provide a major version)
endif
ifeq ($(VERSION_MINOR),)
	$(error VERSION_MINOR is required. Must provide a minor version)
endif
ifeq ($(VERSION_PATCH),)
	$(error VERSION_PATCH is required. Must provide a patch version)
endif


# Dependencies
-include $(CUDS_DEP_FILES)
