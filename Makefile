all: main.o realize.o sqlite3.o base_sqlite.o sorts.o
	g++ -g main.o realize.o sqlite3.o base_sqlite.o sorts.o -o all -ldl -lpthread
	
main.o: main.cpp
	g++ -g -c main.cpp
	
sqlite3.o: sqlite3.c
	gcc -c sqlite3.c -ldl -lpthread
	
base_sqlite.o: base_sqlite.cpp
	g++ -g -c base_sqlite.cpp
	
sorts.o: sorts.cpp
	g++ -g -c sorts.cpp

realize.o: realize.cpp
	g++ -g -c realize.cpp

clean:
	rm -rf *.o *.exe
