libstatistica.o: libstatistica.h libstatistica.C
	g++ -c libstatistica.C

libstatisort_float.o: libsort_float.h libsort_float.C
	g++ -c libsort_float.C

es_24.o: es_24.cpp
	g++ -c es_24.cpp

es_24.x: es_24.o libstatistica.o libsort_float.o
	g++ es_24.o libstatistica.o libsort_float.o -o es_24.x

clean:
	rm *.o *.x


compila: es_24.x 

esegui: es_24.x
	./es_24.x

