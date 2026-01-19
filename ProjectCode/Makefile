CC=g++

DEBUG ?= 1

ifeq ($(DEBUG),1)
   OPTFLAGS=-g
else
   OPTFLAGS=-O3
endif

# See if this is in a MSYS session under Windows, and if so, declare declspec properly.
ifeq ($(OS),Windows_NT)
CPPDEFINES=-DPROJECTCODEDLL_EXPORTS
endif

CFLAGS=-I. -I../include/ProjectCode -std=c++20 -Wall -Werror -shared $(OPTFLAGS) $(CPPDEFINES)

PROJDIR := $(realpath $(CURDIR)/..)
BUILDDIR := $(PROJDIR)/Output

DIRS = ProjectCode

SOURCEDIRS = $(foreach dir, $(DIRS), $(addprefix $(PROJDIR)/, $(dir)))
TARGETDIRS = $(foreach dir, $(DIRS), $(addprefix $(BUILDDIR)/, $(dir))) ../bin
VPATH = $(SOURCEDIRS)
SOURCES = $(foreach dir, $(SOURCEDIRS), $(wildcard $(dir)/*.cpp))

OBJ := $(subst $(PROJDIR),$(BUILDDIR), $(SOURCES:.cpp=.o))

define generateRules
$(1)/%.o: %.cpp
	$(CXX) -c -o $$@ $$< $$(CFLAGS)
endef


$(foreach targetdir, $(TARGETDIRS), $(eval $(call generateRules, $(targetdir))))

directories:
	mkdir -p $(TARGETDIRS)


ifeq ($(OS),Windows_NT)

../bin/libProjectCode.dll: $(OBJ)
	$(CXX) -shared -o ../bin/libProjectCode.dll $(OBJ)

all: directories ../bin/libProjectCode.dll

else

../bin/libProjectCode.so: $(OBJ)
	$(CXX) -shared -o ../bin/libProjectCode.so $(OBJ)

all: directories ../bin/libProjectCode.so

endif

clean:
	rm -rf $(TARGETDIRS)
	rm -rf $(BUILDDIR)
