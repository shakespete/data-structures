#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdexcept>
#include <vector>

typedef int E;

class Stack {
public:
	int size() const;
	bool empty() const;
	const E& top() const;
	void push(const E& e);
	void pop();
private:
	std::vector<E> S;
};

int Stack::size() const { return (int)S.size(); }
bool Stack::empty() const { return S.empty(); }
const E& Stack::top() const {
	if (empty()) throw std::underflow_error("top of empty stack");
	return S.back();
}
void Stack::push(const E& e) { S.push_back(e); }
void Stack::pop() {
	if (empty()) throw std::underflow_error("pop of empty stack");
	S.pop_back();
}

int main() {
	Stack st;
	st.push(5);
	st.push(4);
	st.push(3);
	st.push(2);
	st.push(1);
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
