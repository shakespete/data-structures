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

int str_compare(const char* a, const char* b) {
	while (*a != '\0' || *b != '\0') {
		if (*a < *b) return 0;
		else if (*a > * b) return 1;
		else {
			++a;
			++b;
		}
	}
	return 0;
}

int main() {
	char source[] = "insurmountable";
	printf("%d: %s\n", source, source);

	char* destination = new char[21];
	str_copy(destination, source);
	printf("%d -> %d: %s\n", &destination, destination, destination);

	delete destination;

	destination = new char[21];
	str_copy(destination, source);
	printf("%d -> %d: %s\n", &destination, destination, destination);

	printf("\n");

	printf("%d\n", str_compare("to be", "or not to be"));
	printf("%d\n", str_compare("whether", "whether"));
	printf("%d\n", str_compare("tis nobler in", "tis nobler"));
	printf("%d\n", str_compare("the mind ", "the mind"));
	return 0;
}