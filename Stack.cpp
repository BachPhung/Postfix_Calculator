#include"Stack.h"
#include<iostream>
using namespace std;

Stack::Stack() {
	this->count = 0;
	*entry = 1;
}

Error_code Stack::pop() {
	Error_code outcome = success;
	if (count == 0) outcome = underflow;
	else --count;
	return outcome;
}

Error_code Stack::push(const Stack_entry& item) {
	Error_code outcome = success;
	if (count == maxStack) outcome = overflow;
	else {
		entry[count] = item;
		count++;
	}
	return outcome;
}

Error_code Stack::top(Stack_entry& item) const {
	Error_code outcome = success;
	if (count == 0) outcome = underflow;
	else {
		item = entry[count-1];
	}
	return outcome;
}

bool Stack::empty() const {
	return count == 0;
}

void Stack::clear() {
	this->count=0;
}

bool Stack::full() const {
	return count == maxStack;
}

int Stack::size() const {
	return count;
}
