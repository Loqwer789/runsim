#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
		
	if(argc > 2){	
		fprintf(stderr, "Error, too many arguments %d\n", argc-1);
		return 1;
		}

	else if(argc < 2)
	   	 { 
		fprintf(stderr, "Error, too little arguments %d\n", argc-1);
		return 1;
		}	
		
	int n = atoi(argv[1]);
	int i;
	
	pid_t childpid = 0 ;
	
	for (i=1 ; i < n; i++)
	{
		if ((childpid = fork()) <= 0 )
		{
			break;
		}	

	}	
	
	fprintf(stderr, "i = %d, process ID: %d, parent ID: %d, child ID: %d \n", i, getpid(), getppid(), childpid);

	return 0; 
	
}	
