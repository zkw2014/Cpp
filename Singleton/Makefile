.PHONY : all clean

CXX = g++
CPPFLAGS = -Wall -g

BIN = main
OBJS = Singleton.o test.o

all : $(BIN)

$(BIN) : $(OBJS)
	$(CXX) $(CPPFLAGS) $^ -o $@
%.o : %.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

clean :
	rm -f $(BIN) *.o

