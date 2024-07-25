CXX=g++
CXXFLAGS=-std=c++17 -Wall -Werror -Wextra
BINARY = build/s21_smartcalc

all: build 

qmake:
	mkdir -p build && cd build && qmake .. 

build: qmake
	cd build && make

.PHONY: tests
tests:
	$(CXX) $(CXXFLAGS) ./tests/test.cpp ./Model/checker.cpp ./Model/parser.cpp -lgtest -o test
	./test
	
install: build
	mkdir $(HOME)/Desktop/SmartCalc_v2.0/
	cp $(BINARY) $(HOME)/Desktop/SmartCalc_v2.0/
	make clean

clean:
	rm -rf build ./*.tar test *.dvi *.log

style: 
	clang-format -i ./Model/* ./Controller/* ./View/* *.cpp 

uninstall:
	rm -rf build
	rm -rf $(HOME)/Desktop/SmartCalc_v2.0

dist:
	tar cvf $(HOME)/Desktop/SmartCalc_v2.0.tgz  .

dvi:
	texi2dvi readme.texi
