.PHONY : all clean

CXX = g++
CPPFLAGS = -Wall -g

BIN = main
OBJS = main.o Buffer.o Queue.o MutexLock.o Condition.o Factory.o Thread.o

all : $(BIN)

$(BIN) : $(OBJS)
	$(CXX) $(CPPFLAGS) $^ -o $@ -lpthread -std=c++0x
%.o : %.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

clean :
	rm -f $(BIN) *.o

