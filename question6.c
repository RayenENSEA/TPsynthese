#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>

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
    long seconds;
    long nanoseconds;
    long elapsed;
        
    write(STDOUT_FILENO, welcomeMessage, strlen(welcomeMessage));
    
    while(1){
        if(i==0){
            write(STDOUT_FILENO, prompt, strlen(prompt));
        }
        command_len=read(STDIN_FILENO, buffer, sizeof(buffer));
        buffer[command_len-1]='\0';
        if(strncmp(buffer,"exit",4)==0){
            write(STDOUT_FILENO, bye, strlen(bye));
            exit(EXIT_SUCCESS);
        }
        struct timespec start, end;
        clock_gettime(CLOCK_MONOTONIC, &start);
        pid_t pid;
        pid=fork();
    
        if(pid==0){
            //  strtok divise la commande en tokens
            char *token = strtok(buffer, " ");
            char *args[10];  // ajuste la taille en fonction du nombre maximum d'arguments
            int arg_count = 0;
            while (token != NULL && arg_count < 9) {
                args[arg_count++] = token;
                token = strtok(NULL, " ");
            }
            args[arg_count] = NULL;  // marqueur de fin pour execlp
            
            execvp(args[0], args); // le tableau args contient à la fois la commande et les arguments associés
            
            // execlp(argv[1],argv[2], NULL); // cette écriture permetrait d'éxécuter une commande complexe dès l'éxécution avec "int argc, char *argv[]"
            
            // dans le cas où execvp échoue
            write(STDOUT_FILENO, error, strlen(error));
            exit(EXIT_FAILURE);    
        }

        else{
            waitpid(pid, &status, 0);
            clock_gettime(CLOCK_MONOTONIC, &end);
            seconds = end.tv_sec - start.tv_sec;
            nanoseconds = end.tv_nsec - start.tv_nsec;
            elapsed = seconds*1000 + nanoseconds/1e6;
            if(WIFEXITED(status)){
                snprintf(status_exit,100,"enseash [exit:%d | %ld ms] %%", WEXITSTATUS(status),elapsed);
                write(STDOUT_FILENO, status_exit, strlen(status_exit));
                    
            }
            else if(WIFSIGNALED(status)){
                snprintf(status_sign,100,"enseash [sign:%d | %ld ms] %%", WTERMSIG(status),elapsed);
                write(STDOUT_FILENO, status_sign, strlen(status_sign));
                    
            }
        }
        i++;
    }
    return 0;
}
