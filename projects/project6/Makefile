TARGET = proj6
LIBS = -lm #Math Library, just a placeholder
HEADERS = DataType.h ArrayList.h NodeList.h
OBJECTS = proj6.o DataType.o ArrayList.o NodeList.o
CXX = g++
CXX_FLAGS = -Wall -g -std=c++11 #C++11 just for reference, not necessary

.PHONY: default all clean

default: $(TARGET)
all: default

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CXX) $(CXX_FLAGS) $(OBJECTS) $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)
