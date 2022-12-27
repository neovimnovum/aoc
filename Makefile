# Compiler flags
CC      := clang
CFLAGS := -g -O0 -Wall -Werror -Wextra -Iinc
LFLAGS := -Llib -laoc

# Directories
SRCDIR := src
OBJDIR := obj
INCDIR := inc

LIBDIR   := lib
LIBLIST  := $(subst .c,,$(wildcard $(SRCDIR)/*.c))
LIBOBJ   := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%.o,$(LIBLIST))
LIBRARIES  := $(LIBDIR)/libaoc.dylib

WORKROOT := solutions
WORKBIN := $(WORKROOT)/bin
WORKARG := $(WORKROOT)/input
WORKSRC := $(WORKROOT)/src
WORKOBJ := $(WORKROOT)/obj

WORKLIST  := $(subst $(WORKSRC)/,,$(subst .c,,$(wildcard $(WORKSRC)/*.c)))
WORKLIST1 := $(subst $(WORKSRC)/,,$(subst .c,,$(wildcard $(WORKSRC)/*-1.c)))
WORKLIST0 := $(subst $(WORKSRC)/,,$(subst .c,,$(wildcard $(WORKSRC)/*-0.c)))
BINLIST   := $(patsubst %,$(WORKBIN)/%,$(WORKLIST))
WORKOBJLIST := $(patsubst %,$(WORKOBJ)/%.o,$(WORKLIST))

.PHONY: all libraries solutions libaoc $(WORKLIST)

all : libraries solutions
libraries : $(LIBRARIES)
lib/libaoc.dylib : $(LIBOBJ)
	$(CC) -shared -Wl,-install_name,'@rpath/lib/libaoc.dylib' $< -o lib/libaoc.dylib
solutions : $(BINLIST)
$(LIBOBJ) : $(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@
$(WORKLIST1) : %-1 : $(WORKOBJ)/%-1.o $(WORKARG)/%.txt
$(WORKLIST0) : %-0 : $(WORKOBJ)/%-0.o $(WORKARG)/%.txt
$(BINLIST) : $(WORKBIN)/% : $(WORKOBJ)/%.o
	$(CC) $(CFLAGS) $(LFLAGS) -Wl,-rpath,'@executable_path/../..' $< -o $@
$(WORKOBJLIST) : $(WORKOBJ)/%.o : $(WORKSRC)/%.c
	$(CC) -c $(CFLAGS) $< -o $@
