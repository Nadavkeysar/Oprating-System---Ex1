
FLAGS= -Wall -g
MAINS= main1_1 main1_2 main1_3



all: $(MAINS)


main1_1: main1_1.o hello_ariel.o
	gcc $(FLAGS) -o main1_1 main1_1.o hello_ariel.o
	
main1_2: main1_2.o libhello_ariel.so
	export LD_LIBRARY_PATH=.
	gcc $(FLAGS) -o main1_2 main1_2.o -L. ./libhello_ariel.so 
	
main1_3: main1_3.o libhello_ariel.so
	gcc $(FLAGS) -o main1_3 main1_3.o -ldl

main1_1.o: main1_1.c hello_ariel.h
	gcc $(FLAGS) -c main1_1.c 
	
main1_3.o: main1_3.c hello_ariel.h
	gcc $(FLAGS) -c main1_3.c 
	
main1_2.o: main1_1.c hello_ariel.h
	gcc $(FLAGS) -c main1_2.c 

hello_ariel.o: hello_ariel.c hello_ariel.h
	gcc $(FLAGS) -c -fPIC hello_ariel.c
	
libhello_ariel.so: hello_ariel.c hello_ariel.h
	gcc -shared -o libhello_ariel.so hello_ariel.o

.PHONY: clean all
clean:
	rm *.o $(MAINS) *.so

