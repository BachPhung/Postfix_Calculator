#pragma once
typedef float Stack_entry;
enum Error_code { success, overflow, underflow };
const int maxStack = 50;   
class Stack {
private:
	int count=0;
	Stack_entry entry[maxStack];
public:
	Stack();
	Error_code pop();
	Error_code push(const Stack_entry& item);
	Error_code top(Stack_entry& item) const;
	bool empty() const;
	void clear();
	bool full() const;
	int size() const;
};