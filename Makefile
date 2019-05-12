BIN     := .
CPP     := gcc
CFLAGS  := -O -pipe -W -Wall

all: fsmd4_xop.bin fsmd4_sse2.bin fsmd4_xop_debug.bin fsmd4_sse2_debug.bin

clean:
	rm -f fsmd4_xop.bin fsmd4_sse2.bin fsmd4_xop_debug.bin fsmd4_sse2_debug.bin

fsmd4_xop.bin: fsmd4.c
	$(CPP) $(CFLAGS) -o $@ $^ -mxop

fsmd4_xop_debug.bin: fsmd4.c
	$(CPP) $(CFLAGS) -o $@ $^ -mxop  -DDEBUG

fsmd4_sse2.bin: fsmd4.c
	$(CPP) $(CFLAGS) -o $@ $^ -msse2

fsmd4_sse2_debug.bin: fsmd4.c
	$(CPP) $(CFLAGS) -o $@ $^ -msse2 -DDEBUG
