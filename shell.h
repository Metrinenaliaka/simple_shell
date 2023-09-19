#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdbool.h>

extern char **environ;

/*string.h*/
int str_len(char *s);
char *str_cpy(char *dest, char *src);
char *str_cat(char *dest, const char *src);
char *str_dup(char *str);
char *_strstr(char *haystack, char *needle);
int str_cmp(const char *s1, const char *s2);
int strn_cmp(const char *str1, const char *str2, size_t n);
int _atoi(char *s);
/*environment*/
char *get_env(char *name);
void noComments(char *line);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void shell_loop(void);
void printEnv(void);
int custom_exit(int status, char *command, char **argv);
void executeCommand(char **argv);
void parsing(char *command);
int main(int ac, char **av);
char *findpath(char *command);
char *searchCommand(char *command, char **argv);
void noComments(char *line);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
#endif
