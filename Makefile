CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lncurses

TARGET = program.out

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $^ $(LDFLAGS) $(CFLAGS) -o $@ 

%.o: %.c
	$(CC) $(LDFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
