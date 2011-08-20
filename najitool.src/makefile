

#  --------  #
#  makefile  #
#  --------  #

#  najitool makefile #

#  this makefile is a part    #
#  of najitool version 0.8.3  #

#  from najitool version 0.2.0 and  #
#  above najitool will use libnaji  #
#  this version uses libnaji 0.6.3  #

#  both najitool and libnaji  #
#  are public domain and are  #
#  made by the same author    #
#  please read license.txt    #

#  made by NECDET COKYAZICI   #


cc = gcc
ld = ld
clib = -lm
cflags = -ansi -pedantic -Wall -s
output = najitool

sources = najitool.c najihelp.c

objects = najitool.o najihelp.o

all:

	$(cc) -c $(cflags) $(sources)
	$(cc) $(cflags) $(objects) $(clib) libnaji.a -o $(output)

clean:
	
	touch $(objects)
	touch $(output)
	rm -f $(objects)
	rm -f $(output)
