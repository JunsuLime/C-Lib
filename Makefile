CC = gcc
CFLAGS = -g -Wall

SRC = src
BIN = bin
INCLUDES = includes

SAMPLE_SRC = $(SRC)/samples

TARGETS = arraylist
TARGET_OBJS := $(addprefix $(SRC)/, $(TARGETS))
TARGET_OBJS := $(addsuffix .o, $(TARGET_OBJS))

SAMPLES := $(addprefix $(BIN)/, $(TARGETS))
SAMPLE_OBJS := $(addprefix $(SAMPLE_SRC)/sample_, $(TARGETS))
SAMPLE_OBJS := $(addsuffix .o, $(SAMPLE_OBJS))

all: $(SAMPLES)

$(SAMPLES): $(SAMPLE_OBJS) $(TARGET_OBJS)
	mkdir -p $(BIN)
	$(foreach TARGET, $(TARGETS),\
		$(CC) $(CFLAGS) -I $(INCLUDES) -o $(BIN)/$(TARGET) \
		$(SRC)/$(TARGET).o $(SAMPLE_SRC)/sample_$(TARGET).o;\
		)

.c.o:
	$(CC) $(CFLAGS) -I $(INCLUDES) $^ -c -o $@

clean:
	rm $(TARGET_OBJS)
	rm $(SAMPLE_OBJS)
	rm $(SAMPLES)
