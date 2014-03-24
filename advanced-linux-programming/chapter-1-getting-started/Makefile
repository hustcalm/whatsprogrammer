reciprocal: main.o reciprocal.o
	g++ $(CFLAGS) -o reciprocal main.o reciprocal.o

main.o: main.c 
	gcc $(CFLAGS) -c main.c

reciprocal.o: reciprocal.cpp 
	g++ $(CFLAGS) -c reciprocal.cpp

clean:
	rm -f *.o reciprocal
