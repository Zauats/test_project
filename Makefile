all: giveCreditPlease


giveCreditPlease: main.o Record.o Node.o liblist.a liblogic.so
	gcc -o giveCreditPlease main.c Record.h Node.h -L. -llist -llogic -Wl,-rpath,.

main.o: main.c
	gcc -c main.c

Node.o: Node.h
	gcc -c Node.h

Record.o: Record.h
	gcc -c Record.h

liblogic.so: logicLibrary.o
	gcc -shared -o liblogic.so logicLibrary.o

logicLibrary.o: logicLibrary.c
	gcc -c -fPIC logicLibrary.c

listLibrary.o: listLibrary.c
	gcc -c listLibrary.c

liblist.a: listLibrary.o
	ar cr liblist.a listLibrary.o

test.o: test.c list.h; gcc -c test.c
test: test.o list.o; gcc -otest test.o list.o Unity/src/unity.c
runtests: test ./testS

clean:
	rm --force *.o *.a *.so giveCreditPleaseS



