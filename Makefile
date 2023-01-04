CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic
RM=rm -rf
VALGRIND=valgrind
VFLAGS= --leak-check=full --show-leak-kinds=all

TARGET0=bubble
SRC0=	0-bubble_sort.c \
	0-main.c \
	print_array.c

TARGET1=insertion
SRC1=	1-main.c \
	1-insertion_sort_list.c \
	print_list.c

TARGET2=select
SRC2=	2-main.c \
	2-selection_sort.c \
	print_array.c

TARGET3=quick
SRC3=	3-main.c \
	3-quick_sort.c \
	print_array.c

all: 0 1 2 3

0:
	$(CC) $(CFLAGS) $(SRC0) -o $(TARGET0)

1:
	$(CC) $(CFLAGS) $(SRC1) -o $(TARGET1)

2:
	$(CC) $(CFLAGS) $(SRC2) -o $(TARGET2)

3:
	$(CC) $(CFLAGS) $(SRC3) -o $(TARGET3)

clean:
	$(RM) *~ \#*\# \.\#* \
        $(TARGET0) $(TARGET1) $(TARGET2) $(TARGET3)

re: clean all

betty:
	betty 0-bubble_sort.c 1-insertion_sort_list.c 2-selection_sort.c 3-quick_sort.c 

val0:
	$(VALGRIND) $(VFLAGS) ./bubble

val1:
	$(VALGRIND) $(VFLAGS) ./insertion

val2:
	$(VALGRIND) $(VFLAGS) ./select

val3:
	$(VALGRIND) $(VFLAGS) ./quick
