.PHONY : all clean

CXX = g++
CPPFLAGS = -Wall -g

BIN = main
OBJS = main.o SmartPtr.o Student.o

all : $(BIN)

$(BIN) : $(OBJS)
	$(CXX) $(CPPFLAGS) $^ -o $@
%.o : %.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

clean :
	rm -f $(BIN) *.o

