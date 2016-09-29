#include <stdio.h>
#include <string.h>

void makeLowerCase(char *str, size_t len)
{
    int i;
    for (i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
}

void printSimpleShifts(char *str, int len)
{
    char temp[len+1];
    memset(temp, 0, len+1);
    strcpy(temp, str);

    int c, i;
    for (c = 0; c < 26; c++) {
        for (i = 0; i < len; i++) {
            temp[i] = (((temp[i] - 'a') + 25) % 26) + 'a';
        }
        puts(temp);
        puts("=========================");
    }
}

void replace(char *str, int len, char *old, char *new, int sub_len)
{
    int i, j;
    for (i = 0; i < len; i++) {
        for (j = 0; j < sub_len; j++) {
            if (str[i] == old[j]) {
                str[i] = new[j];
                break;
            }
        }
    }
}

void printPermutation(char *ctxt, size_t ctxt_len, char *old, char *newPermu, int sub_len, int start, int end)
{
    if (start == end) {
        char temp[ctxt_len];
        strcpy(temp, ctxt);
        replace(temp, strlen(temp), old, newPermu, sub_len);

        char old1[] = "repqtlwhvt";
        char new1[] = "theaingvoi";
        replace(temp, strlen(temp), old1, new1, strlen(old1));
        
        static int i = 0;
        printf("\n==================================%d=====================================\n", ++i);
        puts(temp);
        
    } else {
        int i, j;
        for (i = start; i <= end; i++) {
            printPermutation(ctxt, ctxt_len, old, newPermu, sub_len, start+1, end);
            char t = newPermu[start];
            for (j = start + 1; j <= end; j++) {
                newPermu[j-1] = newPermu[j];
            }
            newPermu[end] = t;
        }
    }
}

void exportAsCSV(char *str, size_t len, char *filename)
{
    FILE *fp;
    fp = fopen(filename, "w");
    
    if (!fp) {
        puts("failed to open the file");
        return;
    }

    int i;
    for (i = 0; i < len; i++) {
        fputc(str[i], fp);
        fputc('\n', fp);
    }
    
    fclose(fp);
}

void divide(char *str, size_t len, char **result, int num)
{
    int i;
    for (i = 0; i < len; i++) {
        result[i%num][i/num] = str[i];
    }
}
 
        

    

