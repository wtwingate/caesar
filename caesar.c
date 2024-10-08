#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *s, char *t, int k);
void decrypt(char *s, char *t, int k);

int main(int argc, char *argv[])
{
	if (argc == 2 && strcmp(argv[1], "--help") == 0) {
		printf("Usage: caesar [option] [key] [message]\n\n");
		printf("Options:\n");
		printf("--help     display the help menu\n");
		printf("-e, --encrypt  encrypt message using key\n");
		printf("-d, --decrypt  decrypt message using key\n");
		return 0;
	}

	if (argc < 4) {
		printf("Usage: caesar [option] [key] [message]\n");
		return 1;
	}

	int key = atoi(argv[2]);
	char *from = argv[3];
	char *to = malloc(strlen(from) * sizeof(char));

	if (!strcmp(argv[1], "--encrypt") || !strcmp(argv[1], "-e")) {
		encrypt(from, to, key);
	} else if (!strcmp(argv[1], "--decrypt") || !strcmp(argv[1], "-d")) {
		decrypt(from, to, key);
	} else {
		printf("Error: invalid option flag\n");
		return 1;
	}

	printf("%s\n", to);
	return 0;
}

/* Encrypt string s with key k; copy result into string t */
void encrypt(char *s, char *t, int k)
{
	int i, c;

	for (i = 0; (c = s[i]) != '\0'; i++) {
		if (c >= 'A' && c <= 'Z') {
			t[i] = 'A' + (((c - 'A') + k) % 26);
		} else if (c >= 'a' && c <= 'z') {
			t[i] = 'a' + (((c - 'a') + k) % 26);
		} else {
			t[i] = c;
		}
	}
	t[i] = s[i];	
}

/* Decrypt string s with key k; copy result into string t */
void decrypt(char *s, char *t, int k)
{
	int i, c;

	for (i = 0; (c = s[i]) != '\0'; i++) {
		if (c >= 'A' && c <= 'Z') {
			t[i] = 'A' + (((c - 'A') + (26 - k)) % 26);
		} else if (c >= 'a' && c <= 'z') {
			t[i] = 'a' + (((c - 'a') + (26 - k)) % 26);
		} else {
			t[i] = c;
		}
	}
	t[i] = s[i];
}
