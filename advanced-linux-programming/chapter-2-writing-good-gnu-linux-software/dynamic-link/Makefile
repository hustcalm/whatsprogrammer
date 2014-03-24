app: app.o libtest
	gcc -o app app.o -L. -ltest

	# The blow would fail
	#gcc -o app -L. -ltest app.o

app.o: app.c
	gcc -c app.c

libtest: test.c
	gcc -c test.c
	ar cr libtest.a test.o

clean: 
	rm -f *.o app libtest.a
