#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>


int copy_file(char *from, char *to);
void print_usage(void);
void error_read(char *file);
void error_write(char *file);
void error_close(int fd);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);


#endif