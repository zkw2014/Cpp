.PHONY : all clean

CXX = g++
CPPFLAGS = -Wall -g

BIN = main
OBJS = test_Thread.o Thread.o

all : $(BIN)

$(BIN) : $(OBJS)
	$(CXX) $(CPPFLAGS) $^ -o $@ -lpthread -std=C++0x
%.o : %.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

clean :
	rm -f $(BIN) *.o

