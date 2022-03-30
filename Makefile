SRC := $(wildcard *.c)
OBJS = $(SRC:.c=.o)

MAIN = program
CFLAGS = -Wall
INCLUDES = -I./include

all: $(MAIN)

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) *.o *~ $(MAIN)
