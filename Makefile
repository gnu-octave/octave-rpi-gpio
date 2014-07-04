# handwritten Makefile
# 14.1.2013 Andreas weber

.PHONY: clean

bcm2835.oct: bcm2835oct.cpp
	mkoctfile -v $^ -Wall -Wextra -lbcm2835 -o $@

clean:
	rm -f bcm2835.oct bcm2835oct.o
	rm -f octave-core
