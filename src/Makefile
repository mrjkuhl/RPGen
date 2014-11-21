#!/usr/bin/make -f

CC=gcc

SOURCES= main.c generate.c file.c error.c
OBJECTS= $(SOURCES:.c=.o)

all: $(SOURCES) $(OBJECTS)

%.o : %.c
	$(CC) -c $<
