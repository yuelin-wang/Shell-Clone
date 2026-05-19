#include <stdio.h>
#if __STDC_VERSION__ < 202311L
#include <stdbool.h>
#endif
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    // forever loop
    while (true) {
        // print prompt
        char * user = malloc(256);
        char * PWD = malloc(256);
        strcpy(user, getenv("USER"));
        getcwd(PWD, 256);
        fprintf(stdout, "%s:%s$", user, PWD);

        // receive user input
        char * input = malloc(256);
        fgets(input, 256, stdin);

        // handle EOF
        if (strlen(input) == 0 && feof(stdin)) {
            fputc('\n', stdout);
            return 0;
        }

        // tokenize input
        char * endl = input;
        while (*endl != '\n') {
            endl ++;
        }
        *endl = '\0';
        char * arguments [16] = {};
        size_t index = 0;
        char * argument = strtok(input, " ");
        while (argument) {
            arguments[index] = argument;
            index++;
            argument = strtok(NULL, " ");
        }
        arguments[index] = NULL;
        if (index == 0) {
            continue;
        }

        // handle `exit` and `cd`
        if (!strcmp("exit", arguments[0])) {
            if (arguments[1]) {
                return atoi(arguments[1]);
            }
            continue;
        } else if (!strcmp("cd", arguments[0])) {
            if (!arguments[1]) {
                chdir(getenv("HOME"));
            } else if (chdir(arguments[1])) {
                fprintf(stderr, "mush: cd: no such file or directory '%s'\n", arguments[1]);
            }
            continue;
        }

        // handle non-builtins
            // fork
            pid_t pid = fork();
            int status;
            // child
            if (pid == 0){
                // execute command
                int ret = execvp(arguments[0], arguments);
                // handle errors
                if (ret == -1) {
                    fprintf(stderr, "mush: command '%s' not found\n", arguments[0]);
                }
            }
            // parent
            else {
                // wait for child
                waitpid(pid, &status, WCONTINUED);
            }
    }
    return 0;
}
