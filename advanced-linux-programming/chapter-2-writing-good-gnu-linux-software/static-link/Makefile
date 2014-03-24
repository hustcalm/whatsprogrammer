app: app.o libtest
	gcc -o app app.o -L. -ltest

app.o: app.c
	gcc -c app.c

libtest: test.c
	gcc -c test.c
	gcc -shared -fPIC -o libtest.so test.o

clean: 
	rm -f *.o app libtest.so
