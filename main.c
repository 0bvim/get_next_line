#include "get_next_line_bonus.h"
#include <stdio.h>
#include <stdlib.h>
# include <fcntl.h>


int main()
{
    char *name = "test.txt";

    int fd = open(name, O_RDONLY);
    /* 1 */ char *t = get_next_line(fd);
    printf("%s", t);
    free(t);
    close(fd);
//    /* 2 */ t = get_next_line(fd);
//    printf("%s", t);
//    free(t);
//    // set the next read call to return -1
//
//    if (BUFFER_SIZE > 100) {
//        char *temp;
//        do {
//            temp = get_next_line(fd);
//            free(temp);
//        } while (temp != NULL);
//    }
//    /* 3 */ t = get_next_line(fd);
//    printf("%s", t);
//    free(t);
//    close(fd);
//
//    fd = open(name, O_RDONLY);
//    /* 4 */ t = get_next_line(fd);
//    printf("%s", t);
//    free(t);
//    /* 5 */ t = get_next_line(fd);
//    printf("%s", t);
//    free(t);
//    /* 6 */ t = get_next_line(fd);
//    printf("%s", t);
//    free(t);
//    /* 7 */ t = get_next_line(fd);
//    printf("%s", t);
//    free(t);
//    /* 8 */ t = get_next_line(fd);
//    printf("%s", t);
//    free(t);
//
//    printf("%s", t);
}
