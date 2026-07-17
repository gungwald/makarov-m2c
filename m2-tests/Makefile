M2C=m2c

all: run

run: mayan-nums
	./mayan-nums

mayan-nums:
	$(M2C) -I/usr/local/include -o mayan-nums -make MayanNums.mod

clean:
	rm mayan-nums *.o
