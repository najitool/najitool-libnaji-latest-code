

#  --------  #
#  makefile  #
#  --------  #

#  libnaji makefile #

#  this makefile is a part  #
#  of libnaji version 0.6.3 #

#  libnaji is based on    #
#  the original najitool  #

#  both najitool and libnaji  #
#  are public domain and are  #
#  made by the same author    #
#  please read license.txt    #

#  made by NECDET COKYAZICI   #


cc = gcc
ld = ld
clib =
cflags = -ansi -pedantic -Wall -s
output = libnaji.a

sources = najio.c najascii.c naji_bit.c naji_bmp.c naji_cmp.c najicat.c \
najiconv.c najierr.c najigen.c najihexi.c najihtml.c najijoin.c najilang.c \
najimath.c najiprog.c naji_uni.c najstdin.c naji_str.c najistat.c naji_db.c \
najhtmdb.c najisort.c najcrypt.c najiedit.c najifrmt.c najpatch.c naji_uu.c \
naji_len.c najigame.c najitime.c najifind.c naji_mp3.c najicomp.c naji_afg.c \
naji16bm.c najilist.c

objects = najio.o najascii.o naji_bit.o naji_bmp.o naji_cmp.o najicat.o \
najiconv.o najierr.o najigen.o najihexi.o najihtml.o najijoin.o najilang.o \
najimath.o najiprog.o naji_uni.o najstdin.o naji_str.o najistat.o naji_db.o \
najhtmdb.o najisort.o najcrypt.o najiedit.o najifrmt.o najpatch.o naji_uu.o \
naji_len.o najigame.o najitime.o najifind.o naji_mp3.o najicomp.o naji_afg.o \
naji16bm.o najilist.o

all:
	$(cc) -c $(cflags) $(sources)
	ar -rs libnaji.a $(objects) 

clean:
	
	touch $(objects)
	touch $(output)
	rm -f $(objects)
	rm -f $(output)
