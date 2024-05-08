#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *s, char *t, int k);
void decrypt(char *s, char *t, int k);

int main(int argc, char *argv)
{
	if (argc < 4) {
		printf("Usage: caesar [option] [key] [string]");
		return 1;
	}

	int key = (int) argv[2];
	char *from = argv[3];
	char *to = malloc(strlen(*from) * sizeof(char));

	if (argv[1] == "--encrypt" || argv[1] == "-e") {
		encrypt(from, to, key);
	} else if (argv[1] == "--decrypt" || argv[1] == "-d") {
		decrypt(from, to, key);
	} else {
		printf("Error: invalid option");
		return 1;
	}

	printf("%s", *to);
	return 0;
}

/* Encrypt string s with given key k; copy result into string t */
void encrypt(char *s, char *t, int k) {}

/* Decrypt string s with given key k; copy result into string t */
void decrypt(char *s, char *t, int k) {}
