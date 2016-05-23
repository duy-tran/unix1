OBJECTS = $(patsubst %.cpp,%.o,$(wildcard *.cpp)) 
CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall -o
run: $(OBJECTS)
		$(CC) $(LFLAGS) run $(OBJECTS)

main.o: main.cpp functions.h
		$(CC) $(CFLAGS) main.cpp

functions.o: functions.cpp functions.h
		$(CC) $(CFLAGS) functions.cpp

.PHONY: clean # when file clean already exists => call command "clean"
clean:
		rm -rf *.o