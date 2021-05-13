 #include <unistd.h>
 #include <stdio.h>
 
 #define CYCLE 1000
 void print (const char * process_name)
 {
  	for(int i=0;i<CYCLE;i++)
  	{
  		printf("hello from %s\n",process_name);
  		usleep(10000);	
  	}
  	
}
  
int main()
 {

  pid_t pid;

  pid = fork();

  if(pid < 0) 
  	printf("failed to creat a first child process\n");
  else if (pid == 0)           /* child*/
  {
	pid = fork();
	
	if(pid< 0) 
  		printf("failed to creat a first child process\n");
  	else if (pid == 0)           /* child*/
  		print("grandchild ;)");
  	else	/* parent */
		print("child:)" );
  }
  else   /* parent */
  {
	print("parent :-)");
  }
  
  return 0;
}

