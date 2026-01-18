CC=g++

DEBUG ?= 1

ifeq ($(DEBUG),1)
   OPTFLAGS=-g
else
   OPTFLAGS=-O3
endif

CFLAGS=-I. -I../include/ProjectCode -std=c++20 -Wall -Werror -shared $(OPTFLAGS)

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

libProjectCode.so: $(OBJ)
	ar rcs libProjectCode.so $(OBJ)
	ranlib libProjectCode.so

all: directories libProjectCode.so

clean:
	rm -rf $(TARGETDIRS)
	rm -rf $(BUILDDIR)
