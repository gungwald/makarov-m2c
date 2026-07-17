M2C=m2c
PGM=MayanNums
MOD=$(PGM).mod
C_FILE= $(PGM).c

all: $(PGM)

run: $(PGM)
	chmod a+x $(PGM)
	./$(PGM)

debug: $(PGM).dbg
	gdb --symbols=../../m2lib.a --directory=../.. ./$(PGM).dbg

$(PGM): $(MOD)
	$(M2C) -v -g -o $(PGM) -make $(MOD)

$(PGM).dbg: $(C_FILE)
	$(CC) -v -g -std=c99 -Wno-implicit-function-declaration -Wno-implicit-int -o $(PGM).dbg $(C_FILE) -lm /usr/local/lib/m2c/InOut.o /usr/local/lib/m2c/String.o /usr/local/lib/m2c/ShellVars.o /usr/local/lib/m2c/ASCII.o /usr/local/lib/m2c/NumConv.o /usr/local/lib/m2c/Terminal.o /usr/local/lib/m2c/Files.o /usr/local/lib/m2c/m2lib.a

$(C_FILE): $(MOD)
	$(M2C) -v -C -g -o $@ -make $(MOD)

clean:
	rm -f $(PGM) *.o $(C_FILE) *.c~ *.h~ *.o~ core mayan-nums

