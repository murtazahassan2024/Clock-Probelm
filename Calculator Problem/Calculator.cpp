#include "Calculator.h"
#include "CalculatorUI.h"
#include <iostream>
#include <math.h>
#include <stack>
using namespace std;

/*
 * Process the calculator command assuming post-fix notation
 *    commands - a vector that is assured to be numbers (doubles) or valid operators
 *  returns a string that is either the computed number or the INVALID_MESSAGE constant
 */
string processCommand(vector<string> commands)
{
	stack<double> stack;
	int commandslength = commands.size();
	for (int i = 0; i < commandslength; i++)
	{
		if (isDouble(commands[i]))
		{
			stack.push(stod(commands[i]));
		}
		else
		{
			if (stack.size() == 1)
			{
				return INVALID_MESSAGE;
			}

			double num1 = stack.top();
			stack.pop();
			double num2 = stack.top();
			stack.pop();


			if (commands[i] == "^")
			{
				stack.push(pow(num2,num1));
			}

			else if (commands[i] == "*")
			{
				stack.push(num1 * num2);
			}

			else if (commands[i] == "/")
			{
				stack.push(num2/num1);
			}

			else if (commands[i] == "+")
			{
				stack.push(num1 + num2);
			}

			else if (commands[i] == "-")
			{
				stack.push(num2 - num1);
			}

			else
			{
				return INVALID_MESSAGE;
			}
		}
	}
	if(stack.size() != 1)
	{
		return INVALID_MESSAGE;
	}
	return to_string(stack.top());
}


// Use a stack to process the incoming user command
// The user entry has been broken into a vector of strings.  Each string is assured to be
//  1.) a number
//  2.) a valid operator from the operators above
// The inputs will NOT BE invalid themselves, but they may not amount to a valid command.
// For instance, 2+2 would be blocked, but 2 + 2 could come through and would be invalid
// since it is not in post-fix notation.
//
//  Your task is to process the command into a single numerical response and return that response
//  as a string (no formatting required).  If the command is invalid, return the constant INVALID_MESSAGE
