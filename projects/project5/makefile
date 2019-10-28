OBJ_FILES=proj5.o mystring.o
all: $(OBJ_FILES)
	g++ -g -Wall $(OBJ_FILES) -o proj5
proj5.o: proj5.cpp
	g++ -c -g -Wall proj5.cpp -o proj5.o
mystring.o: mystring.cpp mystring.h
	g++ -c -g -Wall mystring.cpp -o mystring.o
clean:
	rm *.o proj5
