CC := gcc
CFLAGS := -Wall -g -O0

OBJS = main.o

all: abcd

abcd: $(OBJS)
	@$(CC) -o $@ $(CFLAGS) $(OBJS)

$(OBJS) : %.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

.PHONY:
clean:
	@rm -f *.o abcd
	@echo clear
