CXX := g++
CXXFLAGS := -std=c++17 -O2 -pipe -s
LDFLAGS :=

all: code

code: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o code $(LDFLAGS)

clean:
	rm -f code *.o

.PHONY: all clean
