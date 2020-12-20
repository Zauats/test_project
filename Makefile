all: giveCreditPlease





giveCreditPlease: main.o logic.o Record.o liblist.a
	gcc -o giveCreditPlease main.o -L. -llist logic.h Record.h

main.o: main.c
	gcc -c main.c

liblist.a: listLibrary.o
	ar cr liblist.a listLibrary.o

listLibrary.o: listLibrary.h
	gcc -c listLibrary.h

logic.o: logic.h
	gcc -c logic.h

Record.o: Record.h
	gcc -c Record.h


test.o: test.c list.h; gcc -c test.c
test: test.o list.o; gcc -otest test.o list.o Unity/src/unity.c
runtests: test ./testS


clean:
	rm --force *.o *.a *.a giveCreditPleaseS