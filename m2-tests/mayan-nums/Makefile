M2C=m2c
PGM=mayan-nums

all: run

run: mayan-nums
	chmod a+x $(PGM)
	./$(PGM)

mayan-nums: MayanNums.mod
	$(M2C) -C -g -o $(PGM) -make MayanNums.mod

clean:
	rm -f $(PGM) *.o

