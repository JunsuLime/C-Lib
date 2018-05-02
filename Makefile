CC = gcc
CXXFLAGS = -Wall -g -Os -I$(INC) -lpthread

TARGET = test.out

SRCS := $(wildcard src/*.c)
OBJS := $(SRCS:.cpp=.o)
BIN = ./bin/
INC = ./include/
SRC = ./src/
LIB = ./lib/


TARGET: $(OBJS)
	$(CC) $(CXXFLAGS) -o $(BIN)$(TARGET) $(OBJS) # -L$(INC)

# test:
# 	echo "Hello World"
#
# install: all
# 	echo "Install is  called"
# 
# uninstall:
# 	echo "Uninstall is called"
# 
clean:
	# echo $(OBJS)
	rm $(BIN)$(TARGET) 

# documentation:
# 	echo "make docs"
# 
# clean-documentation:
# 	echo "clean docs"

