#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

void display_prompt(void);
char *read_input(void);
void execute_command(char *cmd);

#endif /* MAIN_H */
