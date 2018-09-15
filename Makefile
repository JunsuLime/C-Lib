CC=gcc
CFLAGS=-g -Wall

SRC=src
BIN=bin
INCLUDES=includes

TARGETS = list stack queue
TEST_PROGRAMS := $(addsuffix _main.c, $(TARGETS))
TEST_PROGRAMS := $(addprefix $(SRC)/, $(TEST_PROGRAMS))
TEST_OBJECTS := $(TEST_PROGRAMS:.c=.o)

MODULE_SOURCES := $(addsuffix .c, $(TARGETS))
MODULE_SOURCES := $(addprefix $(SRC)/, $(MODULE_SOURCES))
MODULE_OBJECTS := $(MODULE_SOURCES:.c=.o)

all: $(TARGETS)

$(TARGETS):	$(TEST_OBJECTS) $(MODULE_OBJECTS)
	mkdir -p $(BIN)
	$(foreach target, $(TARGETS), $(CC) $(CFLAGS) -I $(INCLUDES) -o $(BIN)/$(target) $(SRC)/$(target)_main.o $(SRC)/$(target).o;)

.c.o:
	$(CC) $(CFLAGS) -I $(INCLUDES) $^ -c -o $@

clean:
	rm $(SRC)/*.o
	rm $(BIN)/*
