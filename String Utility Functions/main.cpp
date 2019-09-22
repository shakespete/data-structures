#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


char* str_copy(char* destination, char* src) {
	if (destination == NULL) return NULL;
	char* ptr = destination;
	while (*src != '\0') *destination++ = *src++;
	*destination = '\0';
	return ptr;
}

int str_len(char* str) {
	int l = 0;
	while (str[l] != '\0') l++;
	return l;
}

bool str_equal(char* a, char* b) {
	while (*a == *b) {
		if (*a == '\0') return true;
		++a;
		++b;
	}
	return false;
}

int main() {

	return 0;
}