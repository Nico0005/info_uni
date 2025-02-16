esamec.o: esameh.h esamec.C
	g++ -c esamec.C

esamecp.o: esamecp.cpp
	g++ -c esamecp.cpp

esamecp.x: esamecp.o esamec.o
	g++ esamecp.o esamec.o -o esamecp.x

clean:
	rm *.o *.x


compila: esamecp.x 

esegui: esamecp.x
	./esamecp.x