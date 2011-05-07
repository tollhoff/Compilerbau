#
# Makefile for SLPL interpreter
#

CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -g
LDLIBS = -lm

SRCS = main.c utils.c slpl.c table.c prog.c
OBJS = $(patsubst %.c,%.o,$(SRCS))
BIN = slpl

.PHONY:		all run depend clean dist-clean

all:		$(BIN)

run:		$(BIN)
		./$(BIN)

$(BIN):		$(OBJS)
		$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o:		%.c
		$(CC) $(CFLAGS) -o $@ -c $<

-include depend.mak

depend:
		$(CC) $(CFLAGS) -MM $(SRCS) > depend.mak

clean:
		rm -f *~ *.o

dist-clean:	clean
		rm -f $(BIN) depend.mak
