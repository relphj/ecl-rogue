#  This is the Makefile for ECL Rogue.
#
#-------------  Configure these items ----------------#
#

# What do you call your C compiler?
#CC = cc

# Where do you want Rogue to be installed?  This CANNOT be the
# current directory (where you unpacked the distribution)
BINDIR = /usr/bin/

# Where do you want documentation to be installed?
DOCDIR = /usr/share/doc/

#--------YOU SHOULDN'T HAVE TO CHANGE ANYTHING BELOW THIS LINE.-------------

TARFILES = \
	README LICENCE TODO BUGS Makefile rogue.h rogue.c rogue.html rogue.txt

LDFLAGS = -lcurses -ltermcap
CFLAGS = -g -Wall
# -I../lib

rogue: rogue.o
	$(CC) -o $@ $@.o $(LDFLAGS)

rogue.o: rogue.h

clean:
	$(RM) rogue.o rogue

install: rogue
	@echo ""
	@echo "To be written."

rogue.tar.gz: $(TARFILES)
	tar cvfz rogue.tar.gz $(TARFILES)

tar: rogue.tar.gz
