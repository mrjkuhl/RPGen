#!/usr/bin/make -f

CC=gcc

SOURCES= main.c generate.c config.c file.c char.c error.c
OBJECTS= $(SOURCES:.c=.o)

all: $(SOURCES) $(OBJECTS)

%.o : %.c
	$(CC) -c $<
