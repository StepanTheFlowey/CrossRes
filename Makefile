CXXFLAGS =

release: CXXFLAGS += -O2 -g0
release: all

debug: CXXFLAGS += -g3
debug: all

all: libCrossRes.a

libCrossRes.a: main.o
	ar rcs libCrossRes.a main.o

main.o:
	g++ $(FLAGS) -c main.cpp

install: release
	cp libCrossRes.a /usr/local/lib
	cp main.hpp /usr/local/include/CrossRes.hpp

uninstall:
	rm -f /usr/local/lib/libCrossRes.a
	rm -f /usr/local/include/CrossRes.hpp

clean:
	rm -f main.o libCrossRes.a
