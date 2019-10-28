#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_CHAR 15

int word_id = 0;

void str_copy(char* des, char* src) {
	while (*src != '\0') *des++ = *src++;
	*des = '\0';
}

void sentence_parser(const char* sentence) {
	char* word = new char[MAX_CHAR];
	int charIdx = 0;
	int sentIdx = 0;

	while (sentence[sentIdx] != '\0') {
		if (sentence[sentIdx] == ' ') {
			word[charIdx] = '\0';
			word_id++;
			char* parsedWord = new char[MAX_CHAR];
			str_copy(parsedWord, word);
			printf("%d: %s\n", word_id, parsedWord);

			word = new char[MAX_CHAR];
			charIdx = 0;
			sentIdx++;
		}
		word[charIdx] = sentence[sentIdx];
		charIdx++;
		sentIdx++;
	}
	word[charIdx] = '\0';
	word_id++;
	char* parsedWord = new char[MAX_CHAR];
	str_copy(parsedWord, word);
	printf("%d: %s\n", word_id, parsedWord);
}

int main() {
	sentence_parser("Hello darkness my old friend");
	return 0;
}