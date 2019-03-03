OBJDIR    =   ../../build
OBJ       =   $(addprefix $(OBJDIR)/, $(patsubst %.cpp, %.o, $(wildcard *.cpp)))
TARGET    =   myApp
CC        =   g++
CPPFLAGS  =   -I./include/ -I../observerDesignPattern/include



CC = g++

.SUFFIXES = .cpp

$(TARGET): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

.cpp.o:
	$(CC) $(CPPFLAGS) -c $*.cpp

clean:
	rm -f *~ $(OBJS) $(PROG)



