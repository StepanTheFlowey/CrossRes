all: CrossRes.o
	ar rcs libCrossRes.a CrossRes.o

CrossRes.o:
	g++ -g3 -c CrossRes.cpp

clean:
	rm CrossRes.o libCrossRes.a
