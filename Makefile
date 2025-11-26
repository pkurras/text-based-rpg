# ==========================================
# CONFIGURATION
# ==========================================
CONFIG ?= GameDebug

# Select compiler:
#   make CXX=g++
#   make CXX=clang++
#   make CXX=cl       (MSVC)
CXX ?= g++

# ==========================================
# OS DETECTION
# ==========================================
ifeq ($(OS),Windows_NT)
    PLATFORM := windows
    EXE := .exe
    RM := del /Q
    RMDIR := rmdir /S /Q
    MKDIR := mkdir
else
    PLATFORM := linux
    EXE :=
    RM := rm -f
    RMDIR := rm -rf
    MKDIR := mkdir -p
endif

# ==========================================
# DIRECTORIES
# ==========================================
BINDIR := bin/$(CONFIG)
OBJDIR := build/$(CONFIG)
TARGET := $(BINDIR)/game$(EXE)

# ==========================================
# FILES
# ==========================================
SRCS := $(shell find src -name "*.cpp")
OBJS := $(patsubst src/%.cpp,$(OBJDIR)/%.o,$(SRCS))

$(shell $(MKDIR) $(BINDIR) $(OBJDIR) >nul 2>&1)

# ==========================================
# BASE FLAGS
# ==========================================
INCLUDES := -Isrc
CXXFLAGS := -std=c++17 -Wall -Wextra $(INCLUDES)
LDFLAGS :=
LIBS :=

# ==========================================
# PLATFORM DEFINES
# ==========================================
ifeq ($(PLATFORM),windows)
    CXXFLAGS += -D_WINDOWS -D_WIN32
    LIBS += Bcrypt.lib
else
    CXXFLAGS += -D_LINUX
endif

# ==========================================
# CONFIG-SPECIFIC FLAGS
# ==========================================
ifeq ($(CONFIG), GameDebug)
    CXXFLAGS += -O0 -g -DGAME_DEFINE_DEBUG
endif

ifeq ($(CONFIG), GameRelease)
    CXXFLAGS += -O2 -DNDEBUG -DGAME_DEFINE_RELEASE
endif

ifeq ($(CONFIG), GameShipping)
    CXXFLAGS += -O3 -DNDEBUG -DGAME_DEFINE_RELEASE -DGAME_DEFINE_SHIPPING
    CXXFLAGS := $(filter-out -g,$(CXXFLAGS))   # Remove debug symbols
endif

# ==========================================
# TOOLSET-SPECIFIC FLAGS
# ==========================================
# GCC / Clang
ifeq ($(CXX),g++)
    CXXFLAGS += -fsanitize=address -mrdseed
endif
ifeq ($(CXX),clang++)
    CXXFLAGS += -fsanitize=address -mrdseed
endif

# MSVC / cl.exe (No sanitizers)
ifeq ($(CXX),cl)
    CXXFLAGS := /EHsc /std:c++17 /W4 /I src
    ifeq ($(CONFIG), GameDebug)
        CXXFLAGS += /Zi /MDd /D GAME_DEFINE_DEBUG
    endif
    ifeq ($(CONFIG), GameRelease)
        CXXFLAGS += /O2 /MD /D GAME_DEFINE_RELEASE
    endif
    ifeq ($(CONFIG), GameShipping)
        CXXFLAGS += /O2 /MD /D GAME_DEFINE_RELEASE /D GAME_DEFINE_SHIPPING
    endif

    OBJ := .obj
else
    OBJ := .o
endif

# Fix object filenames for MSVC pathing
OBJS := $(patsubst src/%.cpp,$(OBJDIR)/%.o,$(SRCS))
ifeq ($(CXX),cl)
    OBJS := $(patsubst %.o,%.obj,$(OBJS))
endif

# ==========================================
# BUILD RULES
# ==========================================
.PHONY: all clean run rebuild

all: $(TARGET)

# ---------- LINKING ----------
ifeq ($(CXX),cl)
$(TARGET): $(OBJS)
	@echo [LINK] $@
	link /OUT:$@ $(OBJS) $(LIBS)
else
$(TARGET): $(OBJS)
	@echo [LINK] $@
	$(CXX) $(OBJS) -o $@ $(LDFLAGS) $(LIBS)
endif

# ---------- COMPILING ----------
ifeq ($(CXX),cl)
$(OBJDIR)/%.obj: src/%.cpp
	@echo [CL ] $<
	@$(MKDIR) $(dir $@) >nul 2>&1
	cl $(CXXFLAGS) /c $< /Fo$@
else
$(OBJDIR)/%.o: src/%.cpp
	@echo [CXX] $<
	@$(MKDIR) $(dir $@) >nul 2>&1
	$(CXX) $(CXXFLAGS) -c $< -o $@
endif

# ---------- RUN ----------
run: $(TARGET)
	$(TARGET)

# ---------- CLEAN ----------
clean:
ifeq ($(PLATFORM),windows)
	@echo [CLEAN]
	@$(RMDIR) bin\$(CONFIG) 2>nul || true
	@$(RMDIR) build\$(CONFIG) 2>nul || true
else
	@echo [CLEAN]
	@$(RMDIR) bin/$(CONFIG) build/$(CONFIG)
endif

rebuild: clean all