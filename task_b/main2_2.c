#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10000
#define CYCLE 1000000
#define SECOND_TO_SLEEP 100000
char child_stack[STACK_SIZE+1];
int child1(void *params);
int child2(void *params);


void print (const char * process_name)
{
	for(int i=0;i<CYCLE;i++)
	{
		printf("Hello from %s\n",process_name);
		usleep(SECOND_TO_SLEEP);
	}
}
int child1(void *params)
{
	int result=clone(child2,child_stack+STACK_SIZE,CLONE_PARENT,0);
	printf("clone result 2 =%d\n",result);
	print("child 1");
}
int child2(void *params)
{
	print("child 2");
}


int main()
{
	int result=clone(child1,child_stack+STACK_SIZE,CLONE_PARENT,0);
	
	printf("clone result 1 =%d\n",result);
	print("parent");
	
	return 0;
}
					
