#include"Stack.h"
#include<iostream>
#include<string>
#include<queue>
#include"Utility.h"
using namespace std;


int main(int argc, char** argv)
/* Post: The program has executed simple arithmetic commands entered by the user.
Uses: The class Stack and functions introduction, instructions, do command,
and get command. */

{	
	if(argc == 1){
		string str, str2;
		float temp=0;
		char c;
		Stack store_numbers2;
		do{
			cout << "Insert postfix equation: ";
			getline(cin, str);
			while (!str.empty()) {
				str2 = getSubString(str);
				if (isNumber(str2)) store_numbers2.push(stof(str2));
				else {
					c = str2[0];
					do_command(c, store_numbers2);
				}
			}
			if(c=='q') return false;
			store_numbers2.top(temp);
			cout << "Result: " << temp << endl;
		}while (true);
	}
	else if (argv[1][0] == '-' && argv[1][1] == 'p') {
		Stack stored_numbers;
		while (do_command(get_command(), stored_numbers));
	}

	return 0;	
}