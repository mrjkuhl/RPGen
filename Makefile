#!/usr/bin/make -f

CC=gcc
INSTALLDATA= install -c -m 644
CONFDIR= /etc/rpgen

SOURCES= src/main.c src/generate.c src/file.c src/error.c
OBJECTS= $(SOURCES:.c=.o)
EXECUTABLE= rpgen

MAN= rpgen.1.gz
MANSRC= rpgen.1

all:
	cd src/ && $(MAKE)
	$(CC) $(OBJECTS) -o $(EXECUTABLE)

.PHONY : install
install : installbin installconfig installinfo

.PHONY : installbin
installbin:
	install -c $(EXECUTABLE) /usr/local/bin

.PHONY : installconfig
installconfig :
	-mkdir $(CONFDIR)
	$(INSTALLDATA) rpgen.conf $(CONFDIR)

.PHONY : installinfo
installinfo : makeman
	$(INSTALLDATA) $(MAN) /usr/share/man/man1

.PHONY : makeman
makeman :
	gzip -c $(MANSRC) > $(MAN)

.PHONY : clean
clean :
	-rm $(MAN) $(OBJECTS) $(EXECUTABLE)
