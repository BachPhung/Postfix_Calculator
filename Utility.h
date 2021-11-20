#pragma once
#include"Stack.h"
#include<string>
using namespace std;
char get_command();
bool do_command(char command, Stack& numbers);
bool isNumber(string);
string getSubString(string&);
