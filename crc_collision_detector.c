#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "crc_collision_detector.h"

int main(int argc, char **argv)
{
    srand(time(0));
    unsigned int target = crc32f((unsigned char *)"3CA6DCF7BE5715BD655E2569C3867389");
    char try[65] = {0};
    int i = 0;

    printf("target == %x\n", target);

    while (!increment_string(try, 64)) {
        if (! (i++ % 100000000))
            puts(try);
            //print_chars(try, 64);
        
        if (crc32f((unsigned char *)try) == target &&
            (strcmp(try, "apple") != 0)) {
            printf("found %s\n", try);
            //print_chars(try, 64);
            printf("crc == %x\n", crc32f((unsigned char *)try));
            return 0;
        }
    }
    printf("didn't find anything\n");

    return 0;
}

void print_chars(char *c, int len)
{
    int i;
    for (i = 0; i < len; i++) {
        printf("%2x", c[i]);
    }
    putc('\n', stdout);
}

int increment_string(char *str, int len)
{
    int i = 0;
    while (increment_char(&str[i++]) && i < len);
    if (i == len)
        return 1;
    
    return 0;
}


int increment_char(char *c)
{
    if (*c == 0) {
        *c = '0';
    } else if (*c < '9') {
        (*c)++;
    } else if (*c == '9') {
        *c = 'a';
    } else if (*c < 'z') {
        (*c)++;
    } else { // *c == 'z'
        *c = '0';
        return 1;
    }
    return 0;
}
