#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "func.c"

int main(int argc, char **argv)
{
    char ctxt[] = "EPQSGVQRRPLIPICVDDQQGCVLHPLTPLCPAPYDTRRPICVDDQQGCEVVSBPARJUCQSPJEQXPSCVDDQLPQYSUOVZYDTSPGQKQUCVDDQKQSBTLWREPITGRQLCPJQCBQLIOVYREKTREETGGTGRPYIVRGVVLQORPYCVDTLWZLIPYREPCQYPVOETGGRPADVREPYCVDDQREPSQIKQGQOOVYIPIGVDPGTDTSQYVAAVYRZLTRTPGOVYSPQYLTLWIVRETGOTYGRDQGRPYTLTLITQLQKQGQXPSIVYGPUIVRREPGVYRVOPIZCQRTVLITGAPLGPIJUETDCVDDQQLIREPCTYCZDGRQLCPGZLIPYKETCETRKQGWTHPLCVDDQQYPIPGCYTJPIJUDYIVRKQYIEIVRSQDVLCVDDQQRVLPRTDPSTLCVSLGSQKAQYRLPYQRGAYTLWOTPSICVDDQTSSTLVTG";

    char abc[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    makeLowerCase(ctxt, strlen(ctxt));
    //exportAsCSV(ctxt, strlen(ctxt), "cipher_text.csv");
/*
    char *strings[4];
    int i;
    for (i = 0; i < 4; i++) {
        strings[i] = (char *) malloc(1024);
    }
    divide(ctxt, strlen(ctxt), strings, 4);
    
    for (i = 0; i < 4; i++) {
        puts("\n============================\n");
        puts(strings[i]);
        free(strings[i]);
    }
*/
    //printSimpleShifts(ctxt, strlen(ctxt));
    
    
    char *temp = (char *)calloc(strlen(ctxt) + 1, sizeof(char));
    strcpy(temp, ctxt);
    
    char new[] = "abcdefghijklmnopqrstuvwxyz";
    char old[] = "qjcipowetnbsdlvafygrzhkmux";
    replace(temp, strlen(temp), old, new, strlen(old));
    puts(temp);
    free(temp);


    char old1[] = "repqvtgldshi";
    char new1[] = "theaoisnrlvd";
    replace(ctxt, strlen(ctxt), old1, new1, strlen(old1));
    puts(ctxt);
    //printPermutation(ctxt, strlen_ctxt, old, new, strlen(old), 0, strlen(old) - 1);
}
