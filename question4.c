#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


# define BUFFER_SIZE 256

int main() {
	
	char *welcomeMessage = "Bienvenue dans le Shell ENSEA.\n Pour quitter, tapez 'exit'.\n";
	char *prompt = "enseash %";
	char status_exit[100];
	char status_sign[100];
	char *error = "Command not found\n";
	char *bye = "Bye bye ...\n";
	char buffer[BUFFER_SIZE];
	    
	int command_len;
	int status;
	int i=0;
	    
	write(STDOUT_FILENO, welcomeMessage, strlen(welcomeMessage));
	
	while(1){
		if(i==0){
			write(STDOUT_FILENO, prompt, strlen(prompt)); 	// display the shell prompt initially
		}
		command_len=read(STDIN_FILENO, buffer, sizeof(buffer));
		buffer[command_len-1]='\0';
		if(strncmp(buffer,"exit",4)==0){
			write(STDOUT_FILENO, bye, strlen(bye));
			exit(EXIT_SUCCESS);
		}
	    
	    pid_t pid;
		pid=fork();
	
		if(pid==0){
			
				execlp(buffer, buffer, NULL);
				write(STDOUT_FILENO, error, strlen(error));
				exit(EXIT_FAILURE);
			
		}

		else{ 	// entering the parent process
			waitpid(pid, &status, 0);
			
			if(WIFEXITED(status)){ 		// if the child process exited normally
				snprintf(status_exit,100,"enseash [exit:%d] %%", WEXITSTATUS(status));
				write(STDOUT_FILENO, status_exit, strlen(status_exit)); 	// display the exit status
					
			}
			else if(WIFSIGNALED(status)){ 	// if the child process was terminated by a signal
				snprintf(status_sign,100,"enseash [sign:%d] %%", WTERMSIG(status));
				write(STDOUT_FILENO, status_sign, strlen(status_sign)); 	// display signal
					
			}
		}
		i++;
	}
	return 0;
}
