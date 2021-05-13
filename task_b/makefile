

MAINS= main2_1 main2_2 main2_3 main2_4
CC=gcc


all: $(MAINS)

#c files are compiled to o files authomaticlly.

main2_1: main2_1.o 
	$(CC) -o main2_1 main2_1.o


main2_2: main2_2.o 
	$(CC) -o main2_2 main2_2.o
	
main2_3: main2_3.o 
	$(CC) -o main2_3 main2_3.o
	
main2_4: main2_4.o 
	$(CC) -o main2_4 main2_4.o

.PHONY: clean all
clean:
	rm *.o $(MAINS) 

