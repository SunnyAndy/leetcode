ALL:main exe 
main: main.o
	@g++ -o a.out  main.o
main.o:
	@g++  -c main.cpp   -D DEBUG

exe:
	@./a.out

clean:
	@rm *.o
	@rm a.out
