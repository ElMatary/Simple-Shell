#ifndef SHELLMAIN_H
#define SHELLMAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;
void env(void);
char *finding_location(char *command);
void exec_cmd(char **argv);
void _interactive(char *prompt);
void non_interactive(void);
void user_process(char *user_input);
void process_non_inter(char *user_input);
#endif
