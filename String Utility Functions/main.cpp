#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void str_copy(char* des, const char* src) {
	while (*src != '\0') *des++ = *src++;
	*des = '\0';
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

void some_fn(const char* src) {
	char* destination = new char[11];
	str_copy(destination, src);

	printf("%s ", destination);
}

int main() {
	some_fn("Well");
	some_fn("hello");
	some_fn("there");
	printf("\n");
	return 0;
}