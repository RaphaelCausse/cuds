#==============================================================================
# CUDS - C Utilities and Data Structures
# Cross-platform Makefile
#==============================================================================

NAME        := cuds
DESCRIPTION := C Utilities and Data Structures


#==============================================================================
# INSTALL OPTIONS
#==============================================================================

PREFIX       ?= /usr/local
DESTDIR      ?=
BINDIR       ?= $(PREFIX)/bin
LIBDIR       ?= $(PREFIX)/lib
INCLUDEDIR   ?= $(PREFIX)/include
PKGCONFIGDIR ?= $(LIBDIR)/pkgconfig


#==============================================================================
# VERSION (read from the source)
#==============================================================================

fn_cuds_ver = $(shell awk -v macro='CUDS_VERSION_$(1)' '$$1 == "#define" && $$2 == macro { value = $$3; sub(/\r$$/, "", value); if (value ~ /^[0-9]+$$/) { print value; exit } }' "$(VERSION_H)")

VERSION_H     := include/cuds/version.h
VERSION_MAJOR := $(call fn_cuds_ver,MAJOR)
VERSION_MINOR := $(call fn_cuds_ver,MINOR)
VERSION_PATCH := $(call fn_cuds_ver,PATCH)
VERSION       := $(VERSION_MAJOR).$(VERSION_MINOR).$(VERSION_PATCH)
REVISION      := $(shell git rev-parse --short HEAD 2>/dev/null || echo norevision)


#==============================================================================
# PLATFORM DETECTION
#==============================================================================

ifeq ($(OS),Windows_NT)
  PLATFORM := windows
else
  UNAME_S := $(shell uname -s 2>/dev/null)
  ifeq ($(UNAME_S),Linux)
    PLATFORM := linux
  else ifeq ($(UNAME_S),Darwin)
    PLATFORM := macos
  else
    PLATFORM := unix
  endif
endif

# Platform specifics
EXE_EXT         :=
CPPFLAGS_PLAT   :=
CFLAGS_SHARED   := -fPIC -fvisibility=hidden
INSTALL_LINKS   := :
SHARED_POSTLINK := :

ifeq ($(PLATFORM),linux)
  CPPFLAGS_PLAT   := -D_DEFAULT_SOURCE
  SONAME          := lib$(NAME).so.$(VERSION_MAJOR)
  SHARED_NAME     := lib$(NAME).so.$(VERSION)
  LDFLAGS_SHARED   = -shared -Wl,-soname,$(SONAME)
  SHARED_POSTLINK  = ln -sf $(SHARED_NAME) $(@D)/$(SONAME) && ln -sf $(SONAME) $(@D)/lib$(NAME).so
  INSTALL_LINKS   := cd $(DESTDIR)$(LIBDIR) && ln -sf $(SHARED_NAME) $(SONAME) && ln -sf $(SONAME) lib$(NAME).so
else ifeq ($(PLATFORM),windows)
  CFLAGS_SHARED   :=
  EXE_EXT         := .exe
  SHARED_NAME     := $(NAME).dll
  LDFLAGS_SHARED   = -shared -Wl,--out-implib,$(@D)/lib$(NAME).dll.a
else ifeq ($(PLATFORM),macos)
  SHARED_NAME     := lib$(NAME).dylib
  LDFLAGS_SHARED   = -dynamiclib -install_name $(LIBDIR)/$(SHARED_NAME)
else
  CPPFLAGS_PLAT   := -D_DEFAULT_SOURCE
  SHARED_NAME     := lib$(NAME).so
  LDFLAGS_SHARED   = -shared
endif


#==============================================================================
# DIRECTORIES AND FILES
#==============================================================================

### Base directories
DIR_SRC      := src
DIR_INCLUDE  := include
DIR_EXAMPLES := examples
DIR_BUILD    := build
DIR_LIB      := lib
DIR_BIN      := bin

### Generation directories
DIR_BUILD_DEBUG   := $(DIR_BUILD)/debug
DIR_BUILD_RELEASE := $(DIR_BUILD)/release
DIR_LIB_DEBUG     := $(DIR_LIB)/debug
DIR_LIB_RELEASE   := $(DIR_LIB)/release
DIR_BIN_DEBUG     := $(DIR_BIN)/debug
DIR_BIN_RELEASE   := $(DIR_BIN)/release

### Source files
SOURCES := \
	${DIR_SRC}/platform.c \
	${DIR_SRC}/version.c

### Header files
HEADERS := $(wildcard $(DIR_INCLUDE)/$(NAME)/*.h)

### Object files
OBJ_STATIC_DEBUG   := $(patsubst $(DIR_SRC)/%.c,$(DIR_BUILD_DEBUG)/static/%.o,$(SOURCES))
OBJ_SHARED_DEBUG   := $(patsubst $(DIR_SRC)/%.c,$(DIR_BUILD_DEBUG)/shared/%.o,$(SOURCES))
OBJ_STATIC_RELEASE := $(patsubst $(DIR_SRC)/%.c,$(DIR_BUILD_RELEASE)/static/%.o,$(SOURCES))
OBJ_SHARED_RELEASE := $(patsubst $(DIR_SRC)/%.c,$(DIR_BUILD_RELEASE)/shared/%.o,$(SOURCES))

### Dependency files
DEPENDENCIES := \
	$(OBJ_STATIC_DEBUG:.o=.d)   \
	$(OBJ_SHARED_DEBUG:.o=.d)   \
	$(OBJ_STATIC_RELEASE:.o=.d) \
	$(OBJ_SHARED_RELEASE:.o=.d)

### Libraries
LIB_STATIC_DEBUG   := $(DIR_LIB_DEBUG)/lib$(NAME).a
LIB_SHARED_DEBUG   := $(DIR_LIB_DEBUG)/$(SHARED_NAME)
LIB_STATIC_RELEASE := $(DIR_LIB_RELEASE)/lib$(NAME).a
LIB_SHARED_RELEASE := $(DIR_LIB_RELEASE)/$(SHARED_NAME)

### Examples (one executable per source file)
EXAMPLES_SOURCES := $(wildcard $(DIR_EXAMPLES)/*.c)
EXAMPLES_DEBUG   := $(patsubst $(DIR_EXAMPLES)/%.c,$(DIR_BIN_DEBUG)/examples/%$(EXE_EXT),$(EXAMPLES_SOURCES))
EXAMPLES_RELEASE := $(patsubst $(DIR_EXAMPLES)/%.c,$(DIR_BIN_RELEASE)/examples/%$(EXE_EXT),$(EXAMPLES_SOURCES))


#==============================================================================
# TOOLCHAIN
#==============================================================================

### C Compiler
CC := gcc

### C standard and warnings
CSTD := -std=c99
WARN := -Wall -Wextra -Wpedantic -Wconversion -Wshadow

### Extra flags to give to the C preprocessor (e.g. -I, -D, -U ...)
CPPFLAGS += -I$(DIR_INCLUDE) $(CPPFLAGS_PLAT) -DCUDS_REVISION='"$(REVISION)"'

### Build mode specific C preprocessor flags
CPPFLAGS_DEBUG   := -D_CUDS_DEBUG
CPPFLAGS_RELEASE := -D_CUDS_RELEASE

### Shared library specific preprocessor flags 
CPPFLAGS_SHARED := -D_CUDS_SHARED -D_CUDS_BUILDING

### Extra flags to give to the C compiler
CFLAGS += $(CSTD) $(WARN) -fno-omit-frame-pointer

### Build mode specific C compiler flags
CFLAGS_DEBUG   := -O0 -g3 -DDEBUG
CFLAGS_RELEASE := -O2 -g0 -DNDEBUG
CFLAGS_SAN     := -fsanitize=address,undefined

### Dependency flags
DEPFLAGS := -MMD -MP

### Extra flags given to the linker (e.g. -L ...)
LDFLAGS +=

### Build mode specific linker flags
LDFLAGS_DEBUG   :=
LDFLAGS_RELEASE :=
LDFLAGS_SAN     := $(CFLAGS_SAN)

### Library names given to the linker (e.g. -l ...)
LDLIBS +=

### Archiver for static library
AR := ar

### Archiver flags
ARFLAGS := rcs


#==============================================================================
# SHELL
#==============================================================================

MKDIR   := mkdir -p
RM      := rm -f
RMDIR   := rm -rf
CP      := cp -R
INSTALL := install


#==============================================================================
# VERBOSITY ("make V=1" or "make verbose=1")
#==============================================================================

VERBOSE := $(or $(V),$(verbose))
ifeq ($(VERBOSE),)
  Q := @
else
  Q :=
endif


#==============================================================================
# BUILD MODE FLAGS APPENDS
#==============================================================================

$(DIR_BUILD_DEBUG)/%:   CPPFLAGS += $(CPPFLAGS_DEBUG)
$(DIR_BUILD_RELEASE)/%: CPPFLAGS += $(CPPFLAGS_RELEASE)
$(DIR_BIN_DEBUG)/%:     CPPFLAGS += $(CPPFLAGS_DEBUG)
$(DIR_BIN_RELEASE)/%:   CPPFLAGS += $(CPPFLAGS_RELEASE)

$(DIR_BUILD_DEBUG)/%:   CFLAGS += $(CFLAGS_DEBUG)
$(DIR_BUILD_RELEASE)/%: CFLAGS += $(CFLAGS_RELEASE)
$(DIR_BIN_DEBUG)/%:     CFLAGS += $(CFLAGS_DEBUG)
$(DIR_BIN_RELEASE)/%:   CFLAGS += $(CFLAGS_RELEASE)

$(DIR_LIB_DEBUG)/%:   LDFLAGS += $(LDFLAGS_DEBUG)
$(DIR_LIB_RELEASE)/%: LDFLAGS += $(LDFLAGS_RELEASE)
$(DIR_BIN_DEBUG)/%:   LDFLAGS += $(LDFLAGS_DEBUG)
$(DIR_BIN_RELEASE)/%: LDFLAGS += $(LDFLAGS_RELEASE)


#==============================================================================
# RECIPES
#==============================================================================

define RECIPE_CC_STATIC
	@$(MKDIR) $(dir $@)
	@echo "  CC  $@"
	$(Q)$(CC) $(CPPFLAGS) $(CFLAGS) $(DEPFLAGS) -c $< -o $@
endef

define RECIPE_CC_SHARED
	@$(MKDIR) $(dir $@)
	@echo "  CC  $@"
	$(Q)$(CC) $(CPPFLAGS) $(CPPFLAGS_SHARED) $(CFLAGS) $(CFLAGS_SHARED) $(DEPFLAGS) -c $< -o $@
endef

define RECIPE_AR
	@$(MKDIR) $(dir $@)
	@$(RM) $@
	@echo "  AR  $@"
	$(Q)$(AR) $(ARFLAGS) $@ $^
endef

define RECIPE_LD_SHARED
	@$(MKDIR) $(dir $@)
	@echo "  LD  $@"
	$(Q)$(CC) $(LDFLAGS) $(LDFLAGS_SHARED) -o $@ $^ $(LDLIBS)
	$(Q)$(SHARED_POSTLINK)
endef

define RECIPE_BIN
	@$(MKDIR) $(dir $@)
	@echo "  CC  $@"
	$(Q)$(CC) $(CPPFLAGS) $(CFLAGS) $< $(filter %.a,$^) $(LDFLAGS) $(LDLIBS) -o $@
endef


#==============================================================================
# RULES
#==============================================================================
.PHONY: all

all: debug release

### Internal rules protection
$(if $(filter __%,$(MAKECMDGOALS)),$(error Rules prefixed with "__" are only for internal use))


#------------------------------------------------------------------------------
# (Internal) Check configuration
#------------------------------------------------------------------------------
.PHONY: __check_conf 

__check_conf:
ifeq ($(VERSION_MAJOR)$(VERSION_MINOR)$(VERSION_PATCH),)
	$(error Cannot read the version from $(VERSION_H))
endif
ifeq ($(SOURCES),)
	$(error No source file found in $(DIR_SRC)/)
endif
ifneq ($(VERBOSE),)
	$(info Platform $(PLATFORM))
endif


#------------------------------------------------------------------------------
# Build (debug)
#------------------------------------------------------------------------------
.PHONY: debug debug-static debug-shared

debug: debug-static debug-shared

debug-static: __check_conf $(LIB_STATIC_DEBUG)

debug-shared: __check_conf $(LIB_SHARED_DEBUG)


#------------------------------------------------------------------------------
# Build (release)
#------------------------------------------------------------------------------
.PHONY: release release-static release-shared

release: release-static release-shared

release-static: __check_conf $(LIB_STATIC_RELEASE)

release-shared: __check_conf $(LIB_SHARED_RELEASE)


#------------------------------------------------------------------------------
# Build with sanitizers (debug)
#------------------------------------------------------------------------------
.PHONY: sanitize

sanitize: CFLAGS += $(CFLAGS_SAN)
sanitize: LDFLAGS += $(LDFLAGS_SAN)
sanitize: debug-static debug-shared


#------------------------------------------------------------------------------
# Archive / link libraries
#------------------------------------------------------------------------------

$(LIB_STATIC_DEBUG): $(OBJ_STATIC_DEBUG)
	$(RECIPE_AR)

$(LIB_STATIC_RELEASE): $(OBJ_STATIC_RELEASE)
	$(RECIPE_AR)

$(LIB_SHARED_DEBUG): $(OBJ_SHARED_DEBUG)
	$(RECIPE_LD_SHARED)

$(LIB_SHARED_RELEASE): $(OBJ_SHARED_RELEASE)
	$(RECIPE_LD_SHARED)


#------------------------------------------------------------------------------
# Compile C source files
#------------------------------------------------------------------------------

$(DIR_BUILD_DEBUG)/static/%.o: $(DIR_SRC)/%.c
	$(RECIPE_CC_STATIC)

$(DIR_BUILD_DEBUG)/shared/%.o: $(DIR_SRC)/%.c
	$(RECIPE_CC_SHARED)

$(DIR_BUILD_RELEASE)/static/%.o: $(DIR_SRC)/%.c
	$(RECIPE_CC_STATIC)

$(DIR_BUILD_RELEASE)/shared/%.o: $(DIR_SRC)/%.c
	$(RECIPE_CC_SHARED)


#------------------------------------------------------------------------------
# Examples (linked with the static library)
#------------------------------------------------------------------------------
.PHONY: examples examples-debug examples-release

$(DIR_BIN_DEBUG)/examples/%$(EXE_EXT): $(DIR_EXAMPLES)/%.c $(LIB_STATIC_DEBUG) $(HEADERS)
	$(RECIPE_BIN)

$(DIR_BIN_RELEASE)/examples/%$(EXE_EXT): $(DIR_EXAMPLES)/%.c $(LIB_STATIC_RELEASE) $(HEADERS)
	$(RECIPE_BIN)

examples: examples-debug examples-release

examples-debug: __check_conf $(EXAMPLES_DEBUG)

examples-release: __check_conf $(EXAMPLES_RELEASE)


#------------------------------------------------------------------------------
# (Internal) Installation
#------------------------------------------------------------------------------
.PHONY: __install_headers __install_static __install_shared __install_pkgconfig

__install_headers:
	$(Q)$(INSTALL) -d $(DESTDIR)$(INCLUDEDIR)/$(NAME)
	@echo "  INSTALL  $(NAME) headers in $(DESTDIR)$(INCLUDEDIR)/$(NAME)/"
	$(Q)$(CP) $(DIR_INCLUDE)/$(NAME)/. $(DESTDIR)$(INCLUDEDIR)/$(NAME)/

__install_static: release-static
	$(Q)$(INSTALL) -d $(DESTDIR)$(LIBDIR)
	@echo "  INSTALL  $(NAME) static library in $(DESTDIR)$(LIBDIR)/"
	$(Q)$(INSTALL) -m 644 $(LIB_STATIC_RELEASE) $(DESTDIR)$(LIBDIR)/

ifeq ($(PLATFORM),windows)
__install_shared: release-shared
	$(Q)$(INSTALL) -d $(DESTDIR)$(BINDIR) $(DESTDIR)$(LIBDIR)
	@echo "  INSTALL  $(NAME) shared library in $(DESTDIR)$(BINDIR)/"
	$(Q)$(INSTALL) -m 755 $(LIB_SHARED_RELEASE) $(DESTDIR)$(BINDIR)/
	@echo "  INSTALL  $(NAME) shared library in $(DESTDIR)$(LIBDIR)/"
	$(Q)$(INSTALL) -m 644 $(DIR_LIB_RELEASE)/lib$(NAME).dll.a $(DESTDIR)$(LIBDIR)/
else
__install_shared: release-shared
	$(Q)$(INSTALL) -d $(DESTDIR)$(LIBDIR)
	@echo "  INSTALL  $(NAME) shared library in $(DESTDIR)$(LIBDIR)/"
	$(Q)$(INSTALL) -m 755 $(LIB_SHARED_RELEASE) $(DESTDIR)$(LIBDIR)/
	@echo "  INSTALL  $(LIB_SHARED_RELEASE) symlinks"
	$(Q)$(INSTALL_LINKS)
endif

__install_pkgconfig:
	$(Q)$(INSTALL) -d $(DESTDIR)$(PKGCONFIGDIR)
	@echo "  INSTALL  $(NAME) pkgconfig in $(DESTDIR)$(PKGCONFIGDIR)/"
	$(Q)printf '%s\n' \
		'prefix=$(PREFIX)' \
		'libdir=$(LIBDIR)' \
		'includedir=$(INCLUDEDIR)' \
		'' \
		'Name: $(NAME)' \
		'Description: $(DESCRIPTION)' \
		'Version: $(VERSION)' \
		'Libs: -L$${libdir} -l$(NAME)' \
		'Cflags: -I$${includedir}' \
		> $(DESTDIR)$(PKGCONFIGDIR)/$(NAME).pc


#------------------------------------------------------------------------------
# Installation
#------------------------------------------------------------------------------
.PHONY: install uninstall

install: __install_headers __install_static __install_shared __install_pkgconfig

uninstall:
	@echo "  RM  $(NAME) headers in $(DESTDIR)$(INCLUDEDIR)/"
	@$(RMDIR) $(DESTDIR)$(INCLUDEDIR)/$(NAME)
	@echo "  RM  $(NAME) static library in $(DESTDIR)$(LIBDIR)"
	@$(RM) $(DESTDIR)$(LIBDIR)/lib$(NAME).a $(DESTDIR)$(LIBDIR)/lib$(NAME).dll.a
	@echo "  RM  $(NAME) shared library in $(DESTDIR)$(LIBDIR)"
	@$(RM) $(DESTDIR)$(LIBDIR)/lib$(NAME).so* $(DESTDIR)$(LIBDIR)/lib$(NAME).dylib 
	@echo "  RM  $(NAME) shared library in $(DESTDIR)$(BINDIR)"
	@$(RM) $(DESTDIR)$(BINDIR)/$(NAME).dll
	@echo "  RM  $(NAME) pkgconfig in $(DESTDIR)$(PKGCONFIGDIR)"
	@$(RM) $(DESTDIR)$(PKGCONFIGDIR)/$(NAME).pc


#------------------------------------------------------------------------------
# Clean generated files
#------------------------------------------------------------------------------
.PHONY: clean clean-debug clean-release distclean

clean: clean-debug clean-release

clean-debug:
	@for d in $(DIR_BUILD_DEBUG) $(DIR_LIB_DEBUG) $(DIR_BIN_DEBUG); do \
	    if [ -d $$d ]; then echo "  RM  $$d/"; $(RMDIR) $$d; fi; \
	done

clean-release:
	@for d in $(DIR_BUILD_RELEASE) $(DIR_LIB_RELEASE) $(DIR_BIN_RELEASE); do \
	    if [ -d $$d ]; then echo "  RM  $$d/"; $(RMDIR) $$d; fi; \
	done

distclean:
	@for d in $(DIR_BUILD) $(DIR_LIB) $(DIR_BIN); do \
	    if [ -d $$d ]; then echo "  RM  $$d/"; $(RMDIR) $$d; fi; \
	done


#------------------------------------------------------------------------------
# (Internal) Project version
#------------------------------------------------------------------------------
.PHONY: __version

__version:
	@echo "$(NAME) $(VERSION) ($(REVISION))"
	@echo "Built for $(PLATFORM)"
	@echo ""


#------------------------------------------------------------------------------
# Makefile helpers
#------------------------------------------------------------------------------
.PHONY: info version help

info: __version
	@echo "Informations:"
	@echo "  CC                $(CC)"
	@echo "  CPPFLAGS          $(CPPFLAGS)"
	@echo "  CPPFLAGS_DEBUG    $(CPPFLAGS_DEBUG)"
	@echo "  CPPFLAGS_RELEASE  $(CPPFLAGS_RELEASE)"
	@echo "  CPPFLAGS_SHARED   $(CPPFLAGS_SHARED)"
	@echo "  CFLAGS            $(CFLAGS)"
	@echo "  CFLAGS_DEBUG      $(CFLAGS_DEBUG)"
	@echo "  CFLAGS_RELEASE    $(CFLAGS_RELEASE)"
	@echo "  CFLAGS_SHARED     $(CFLAGS_SHARED)"
	@echo "  CFLAGS_SAN        $(CFLAGS_SAN)"
	@echo "  DEPFLAGS          $(DEPFLAGS)"
	@echo "  LDFLAGS           $(LDFLAGS)"
	@echo "  LDFLAGS_DEBUG     $(LDFLAGS_DEBUG)"
	@echo "  LDFLAGS_RELEASE   $(LDFLAGS_RELEASE)"
	@echo "  LDFLAGS_SHARED    $(LDFLAGS_SHARED)"
	@echo "  LDFLAGS_SAN       $(LDFLAGS_SAN)"
	@echo "  LDLIBS            $(LDLIBS)"
	@echo "  AR                $(AR)"
	@echo "  ARFLAGS           $(ARFLAGS)"
	@echo ""

version: __version
	@echo "===== MAKE ================================================="
	@$(MAKE) --version
	@echo ""
	@echo "===== CC ==================================================="
	@$(CC) --version
	@echo ""
	@echo "===== AR ==================================================="
	@$(AR) --version
	@echo ""

help: __version
	@echo "Build targets:"
	@echo "  debug              Build static + shared libraries (debug)"
	@echo "  debug-static       Build only the static library (debug)"
	@echo "  debug-shared       Build only the shared library (debug)"
	@echo "  release            Build static + shared libraries (release)"
	@echo "  release-static     Build only the static library (release)"
	@echo "  release-shared     Build only the shared library (release)"
	@echo ""
	@echo "Install targets:"
	@echo "  install            Install the release build files"
	@echo "  uninstall          Remove the installed files"
	@echo ""
	@echo "Clean targets:"
	@echo "  clean              Clean generated files (debug + release)"
	@echo "  clean-debug        Clean generated files (debug)"
	@echo "  clean-release      Clean generated files (release)"
	@echo "  distclean          Clean generated directories"
	@echo ""
	@echo "Example targets:"
	@echo "  examples           Build the examples (debug + release)"
	@echo "  examples-debug     Build the examples (debug)"
	@echo "  examples-release   Build the examples (release)"
	@echo ""
	@echo "Helper targets:"
	@echo "  help               Display help"
	@echo "  version            Display versions"
	@echo "  info               Display project informations"
	@echo ""
	@echo "Options:"
	@echo "  v=1, verbose=1     Enable verbose mode"
	@echo ""


#------------------------------------------------------------------------------
# Load dependency files
#------------------------------------------------------------------------------

-include $(DEPENDENCIES)
