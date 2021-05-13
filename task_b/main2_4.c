

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



int main()
{
	pid_t pid=fork();
	if(pid==0)//child
	{
		char *args[2]={"./main2_1",NULL};
		execvp(args[0],args);
	}
	
	else
	{
		printf("1: %d\n",pid);
		pid_t pid=fork();
		if(pid==0)//child
		{
			char *args[2]={"./main2_2",NULL};
			execvp(args[0],args);
		}
		else
		{
			printf("2: %d\n",pid);
			pid_t pid=fork();
			if(pid==0)//child
			{
				char *args[2]={"./main2_3",NULL};
				execvp(args[0],args);
			}
			else
			{
				printf("3: %d\n",pid);
				printf("created all three proccses\n");
			}
		}
		
	}
	//this loop is so this procces wouldn't close too fast and we could see it.
	for(int i=0;i<10000000000;i++)
	{
		usleep(1000);
	}

	
		
	
	return 0;
}
					
