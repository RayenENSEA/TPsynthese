#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


# define BUFFER_SIZE 256

int main() {
	
	char *welcomeMessage = "Bienvenue dans le Shell ENSEA.\n Pour quitter, tapez 'exit'.\n";
	char *prompt = "enseash %";
	char *error = "Command not found\n";
	char *bye = "Bye bye ...\n"; // bye bye message 
	char buffer[BUFFER_SIZE];
	    
	int command_len;
	int status;
	    
	write(STDOUT_FILENO, welcomeMessage, strlen(welcomeMessage));
	
	while(1){
		
		write(STDOUT_FILENO, prompt, strlen(prompt));
		command_len=read(STDIN_FILENO, buffer, sizeof(buffer));
		buffer[command_len-1]='\0';
		if(strncmp(buffer,"exit",4)==0){ 	// if the command "exit" is asked
			write(STDOUT_FILENO, bye, strlen(bye)); 	// display goodbye message
			exit(EXIT_SUCCESS); 	// exit the program succesfully
		}
	    
	    pid_t pid;
		pid=fork();
	
		if(pid==0){
			
				execlp(buffer, buffer, NULL);
				write(STDOUT_FILENO, error, strlen(error));
				exit(EXIT_FAILURE);
			
		}

		else{
			wait(&status);

		}
	}
	return 0;
}
