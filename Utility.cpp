#include"Utility.h"
#include<iostream>
#include<string>
#include<math.h>
#include<iostream>
using namespace std;

char get_command()
{
	
		char command;
		bool waiting = true;
		cout << "Select command and press < Enter > :";
		while (waiting) {
			cin >> command;
			command = tolower(command);
			if (command == '?' || command == '=' || command == '+' || command == '-' || command == '*' || command == '/' || command == 'q' || command == 'x' || command == 'a' || command == 's') waiting = false;
			else {
				cout << "Please enter a valid command:" << endl
					<< "[?]push to stack [=]print top" << endl
					<< "[+] [−] [*] [/] are arithmetic operations" << endl
					<< "[Q]uit." << endl;
			}
		}
		return command;
	
	
}

bool do_command(char command, Stack& numbers)
/* Pre: The first parameter specifies a valid calculator command.
Post: The command specified by the first parameter has been applied to the Stack
of numbers given by the second parameter. A result of true is returned unless
command == 0
q0
.
Uses: The class Stack. */
{
	float p, q;
	int size;
	switch (command) {
	case '?':
		cout << "Enter a real number: " << flush; cin >> p;
		if (numbers.push(p) == overflow)
			cout << "Warning: Stack full, lost number" << endl; break;
	case '=':
		if (numbers.top(p) == underflow) cout << "Stack empty" << endl;
		else cout << p << endl; break;
	case '+':
		
			if (numbers.top(p) == underflow) cout << "Stack empty" << endl;
			else {
				numbers.pop();
				if (numbers.top(q) == underflow) {
					cout << "Stack has just one entry" << endl;
					numbers.push(p);
				}
				else {
					numbers.pop();
					if (numbers.push(q + p) == overflow)
						cout << "Warning: Stack full, lost result" << endl;
				}
			} break;
		
	case '-':
		if (numbers.top(p) == underflow) cout << "Stack empty" << endl;
		else {
			numbers.pop();
			if (numbers.top(q) == underflow) {
				cout << "Stack has just one entry" << endl;
				numbers.push(p);
			}
			else {
				numbers.pop();
				if (numbers.push(q - p) == overflow)
					cout << "Warning: Stack full, lost result" << endl;
			}
		} break;
	case '*':
		if (numbers.top(p) == underflow) cout << "Stack empty" << endl;
		else {
			numbers.pop();
			if (numbers.top(q) == underflow) {
				cout << "Stack has just one entry" << endl;
				numbers.push(p);
			}
			else {
				numbers.pop();
				if (numbers.push(q * p) == overflow)
					cout << "Warning: Stack full, lost result" << endl;
			}
		} break;
	case '/':
		if (numbers.top(p) == underflow) cout << "Stack empty" << endl;
		else {
			numbers.pop();
			if (numbers.top(q) == underflow) {
				cout << "Stack has just one entry" << endl;
				numbers.push(p);
			}
			else {
				numbers.pop();
				if (numbers.push(q / p) == overflow)
					cout << "Warning: Stack full, lost result" << endl;
			}
		} break;
	case '%':
		if (numbers.top(p) == underflow) cout << "Stack empty" << endl;
		else {
			numbers.pop();
			if (numbers.top(q) == underflow) {
				cout << "Stack has just one entry" << endl;
				numbers.push(p);
			}
			else {
				numbers.pop();
				if (numbers.push(fmod(q , p)) == overflow)
					cout << "Warning: Stack full, lost result" << endl;
			}
		} break;
	case '^':
		if (numbers.top(p) == underflow) cout << "Stack empty" << endl;
		else {
			numbers.pop();
			if (numbers.top(q) == underflow) {
				cout << "Stack has just one entry" << endl;
				numbers.push(p);
			}
			else {
				numbers.pop();
				if (numbers.push(pow(q,p)) == overflow)
					cout << "Warning: Stack full, lost result" << endl;
			}
		} break;
	case 'v':
		if (numbers.top(p) == underflow) cout << "Stack empty" << endl;
		else {
			numbers.pop();
			numbers.push(sqrt(p));
		} break;
	case 'x':
		if (numbers.top(p) == underflow) cout << "Stack empty" << endl;
		else {
			numbers.pop();
			if (numbers.top(q) == underflow) {
				cout << "Stack has just one entry" << endl;
				numbers.push(p);
			}
			else {
				numbers.pop();
				numbers.push(p);
				numbers.push(q);
			}
		} break;
	case 's':
		size = numbers.size();
		for (int i = 1; i < size; i++) {
			if (numbers.top(p) == underflow) cout << "Stack empty" << endl;
			else {
				numbers.pop();
				if (numbers.top(q) == underflow) {
					cout << "Stack has just one entry" << endl;
					numbers.push(p);
				}
				else {
					numbers.pop();
					if (numbers.push(q + p) == overflow)
						cout << "Warning: Stack full, lost result" << endl;
				}
			}
		}
		break;
	case 'a':
		size = numbers.size();
		for (int i = 1; i < size; i++) {
			if (numbers.top(p) == underflow) cout << "Stack empty" << endl;
			else {
				numbers.pop();
				if (numbers.top(q) == underflow) {
					cout << "Stack has just one entry" << endl;
					numbers.push(p);
				}
				else {
					numbers.pop();
					if (numbers.push(q + p) == overflow)
						cout << "Warning: Stack full, lost result" << endl;
				}
			}
		}
		if (numbers.top(p) == underflow) cout << "Stack empty" << endl;
		else {
			numbers.pop();
			numbers.push(p / size);
		}
		break;
	case 'q':
		cout << "Calculation finished.\n"; return false;
	} return true;
}

bool isNumber(string str) {
	if (str == "+" || str == "-" || str == "*" || str == "/" || str == "%" || str == "^" || str == "v" || str == "x" || str == "s" || str == "a" || str == "q") {
		return 0;
	}
	return 1;
}

string getSubString(string& originStr) {
	int size = originStr.size();
	string resultStr;
	if (originStr[0] == ' ') {
		originStr.erase(0, 1);
	}
	if ((originStr[0] == '+' || originStr[0] == '-' || originStr[0] == '*' || originStr[0] == '/' || originStr[0] == '%' || originStr[0] == '^' || originStr[0] == 'v' || originStr[0] == 'x' || originStr[0] == 's' || originStr[0] == 'a' || originStr[0] == 'q') /*&& !isNumber(string(1, originStr[1]))*/) {
		if (!isNumber(string(1, originStr[1])) && originStr[1]==' ') {
			resultStr.resize(1);
			resultStr = originStr[0];
			originStr.erase(0, 1);
			return resultStr;
		}
		else {
			int i = 1;
			resultStr.resize(1);
			resultStr[0] = originStr[0];
			while (i < size) {
				if ((originStr[i] >= '0' && originStr[i] <= '9') || originStr[i]=='.') {
					resultStr.resize(i + 1);
					resultStr[i] = originStr[i];
				}
				else break;
				i++;
			}
			originStr.erase(0, i);
			return resultStr;
		}
	}
	
	int i = 0;
	while (i < size) {
		 if ((originStr[i] >= '0' && originStr[i] <= '9') || originStr[i]=='.') {
			resultStr.resize(i + 1);

			resultStr[i] = originStr[i];
		}
		else {
			break;
		}
		i++;
	}
	
	originStr.erase(0, i);
	return resultStr;
}
