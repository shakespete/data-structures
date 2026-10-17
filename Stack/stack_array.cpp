#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdexcept>

typedef int E;

class Stack {
	enum { DEF_CAP = 4 };
public:
	Stack(int cap = DEF_CAP);
	~Stack();
	Stack(const Stack&) = delete;
	Stack& operator=(const Stack&) = delete;
	int size() const;
	bool empty() const;
	const E& top() const;
	void push(const E& e);
	void pop();
private:
	void grow();
	E* S;
	int n;
	int capacity;
};

Stack::Stack(int cap) : n(0), capacity(cap < 1 ? 1 : cap) { S = new E[capacity]; }
Stack::~Stack() { delete[] S; }
int Stack::size() const { return n; }
bool Stack::empty() const { return n == 0; }
const E& Stack::top() const {
	if (empty()) throw std::underflow_error("top of empty stack");
	return S[n - 1];
}
void Stack::push(const E& e) {
	if (n == capacity) grow();
	S[n++] = e;
}
void Stack::pop() {
	if (empty()) throw std::underflow_error("pop of empty stack");
	--n;
}
void Stack::grow() {
	int newCap = capacity * 2;
	E* T = new E[newCap];
	for (int i = 0; i < n; ++i) T[i] = S[i];
	delete[] S;
	S = T;
	capacity = newCap;
}

int main() {
	Stack st(2);
	for (int i = 1; i <= 10; ++i) st.push(i);
	printf("size: %d\n", st.size());

	while (!st.empty()) {
		printf("%d ", st.top());
		st.pop();
	}
	printf("\n");

	try {
		st.pop();
	} catch (const std::underflow_error& ex) {
		printf("caught: %s\n", ex.what());
	}
	return 0;
}
