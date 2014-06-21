#DEBUG	= -g -O0
DEBUG	= -O3
CC	= gcc
LINKER	= gcc
INCLUDE	= -I/usr/local/include -I./$(SRCDIR)/include
CFLAGS	= $(DEBUG) -Wall $(INCLUDE) -Winline -pipe
LDFLAGS	= -L/usr/local/lib
LDLIBS = -lwiringPi -lwiringPiDev -lpthread -lm

BINDIR = bin/
SRCDIR = src/
OBJDIR = obj/

SOURCES = $(wildcard $(SRCDIR)*.c)
OBJECTS := $(SOURCES:$(SRCDIR)%.c=$(OBJDIR)%.o)
TARGETS := $(SOURCES:$(SRCDIR)%.c=$(BINDIR)%)

all: $(TARGETS)

$(OBJECTS): $(OBJDIR)%.o : $(SRCDIR)%.c
	@echo "[CC]"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" succesfully!"

$(TARGETS): $(BINDIR)% : $(OBJDIR)%.o
	@echo "[LD]"
	@$(LINKER) $(LDFLAGS) $< -o $@ $(LDLIBS)
	@echo "Linked "$@" succesfully!"

clean:
	@rm $(OBJDIR)*.o $(BINDIR)*
	@echo "Done cleaning"
