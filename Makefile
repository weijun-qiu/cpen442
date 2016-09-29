pfdecipher: pfdecipher.c pfdecipher.h
	gcc -o pfdecipher -g -std=c99 pfdecipher.c

decipher: decipher.c func.c
	gcc -o decipher -g -std=c99 decipher.c
