
#include <syslog.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>




int main()
{
	pid_t pid=fork();
	if(pid==0)//child
	{
		//move to root dir
		chdir("/");
		
		//move child to another session so we can close parent
		setsid();
		
		printf("start deamon\n");
		
		//close IO chanels
		close(stdout);
		close(stdin);
		close(stderr);
		
		//open log
		openlog("myAnsDeamon",LOG_PID,LOG_DAEMON);
		syslog(LOG_NOTICE,"daemon started!");
		usleep(4000000);
		syslog(LOG_NOTICE,"daemon waiting!");
		usleep(4000000);
		syslog(LOG_NOTICE,"daemon finisied!");
		usleep(4000000);
		
	}
	else
		printf("daemon PID %d \n",pid);
		
	
	return 0;
}
					
