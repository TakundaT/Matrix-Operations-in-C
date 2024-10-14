CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = math_matrix
SRCS = math_matrix.c functions.c
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)
