/*
 * Title:		Implementation evaluate from postfix to infix using stack ADT
 * Purpose:		declare functions to ready for transfering postfix to infix.
 * Author:		Hung Tran
 * Date:		May 21, 2020
 */
#ifndef EVALUATOR_H
#define EVALUATOR_H


#include <string>
using std::string;

double Evaluate(const string& postfix, bool& error);
bool isNumber(string s);
#endif
