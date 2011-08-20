make = make

all:
	$(make) -C libnaji.src
	cp libnaji.src/libnaji.a najitool.src
	cp libnaji.src/libnaji.h najitool.src
	$(make) -C najitool.src

clean:
	$(make) -C libnaji.src clean
	$(make) -C najitool.src clean
