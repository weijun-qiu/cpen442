#define TOLERATE 50

typedef struct {
    char key[5];
    double log;
} tetra;

void apply(char *, char *);
int getIdx(char *, char);
double test(char *, int);
void initialize_wordlist(char *);
void random_key(char *);
size_t nth_zero(char *, int, int);
void modify_key(char *, char *, int *);
void random_shift(char *);
void random_swap(char *);
void printkey(char *);
void initialize_tetragram(char *);
void print_table(tetra *, size_t);
void print_calc_counter(int, double);



int transpose[] = {25, 24, 23, 22, 21,
                   20, 19, 18, 17, 16,
                   15, 14, 13, 12, 11,
                   10,  9,  8,  7,  6,
                   5,   4,  3,  2,  1};

int dia_shift[] = {1, 6, 11, 16, 21,
                       2, 3, 4,  5, 22,
                       7, 8, 9, 10, 23,
                       12, 13, 14, 15, 24,
                       17, 18, 19, 20, 25};

