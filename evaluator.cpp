/*
 * Title:		Implementation evaluate from postfix to infix using stack ADT
 * Purpose:		The purpose of this project is familiar with postfix to infix and then calculate to get
 *              final answer.
 * Author:		Hung Tran
 * Date:		May 21, 2020
 */

#include "evaluator.h"
#include "stack"
#include <sstream>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;
/**
 *Evaluate postfix input as string and return infix calculate.
 * @param postfix is the string postfix
 * @param error is checked out of bound of stack.
 * @return total value of postfix formular after transfer to infix
 */
double Evaluate(const string& postfix, bool& error) {
    stack<double> myStack;
    double result = 0.0;
    double value1 = 0.0;
    double value2 = 0.0;
    error = false;
    istringstream iss(postfix);
    while (iss) {
        string retVal;
        iss >> retVal;
        if (isNumber(retVal)) {
            double checked = 0;
            for (char c : retVal) {
                checked = (checked * 10) + (c - '0');
            }
            myStack.push(checked);
        } else if (retVal == "*" || retVal == "/" || retVal == "+" || retVal == "-" || retVal == "^") {
            if (retVal == "+") {
                if (!myStack.empty()) {
                    value1 = myStack.top();
                    myStack.pop();
                    if (!myStack.empty()) {
                        value2 = myStack.top();
                        myStack.pop();
                        result = value2 + value1;
                    } else {
                        error = true;
                        return -1;
                    }
                }
            } else if (retVal == "-") {
                if (!myStack.empty()) {
                    value1 = myStack.top();
                    myStack.pop();
                    if (!myStack.empty()) {
                        value2 = myStack.top();
                        myStack.pop();
                        result = value2 - value1;
                    } else {
                        error = true;
                        return -1;
                    }
                }
            } else if (retVal == "*") {
                if (!myStack.empty()) {
                    value1 = myStack.top();
                    myStack.pop();
                    if (!myStack.empty()) {
                        value2 = myStack.top();
                        myStack.pop();
                        result = value2 * value1;
                    } else {
                        error = true;
                        return -1;
                    }
                }
            } else if (retVal == "/") {
                if (!myStack.empty()) {
                    value1 = myStack.top();
                    myStack.pop();
                    if (!myStack.empty()) {
                        value2 = myStack.top();
                        myStack.pop();
                        result = value2 / value1;
                    } else {
                        error = true;
                        return -1;
                    }
                }
            }else if (retVal == "^") {
                if (!myStack.empty()) {
                    value1 = myStack.top();
                    myStack.pop();
                    if (!myStack.empty()) {
                        value2 = myStack.top();
                        myStack.pop();
                        result = pow(value2, value1);
                    } else {
                        error = true;
                        return -1;
                    }
                }
            }
            myStack.push(result);
        }
        else if(!isNumber(retVal)){
            error = true;
            return -1;
        }
    }
    myStack.pop();
    return myStack.top();

}
/**
 * check is number or not
 * @param s to check each character is digit
 * @return true if is number
 * @return false if not a number.
 */
bool isNumber(string s)
{
    for (size_t i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;

    return true;
}