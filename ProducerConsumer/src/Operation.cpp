/*
 * Operation.cpp
 *
 *  Created on: Jan 20, 2018
 *      Author: cs3840
 */

#include "Operation.h"

Operation::Operation() {
	n0 = rand() % 1000 + 1;
	n1 = rand() % 1000 + 1;
	operation = operations[rand() % 4];
}

Operation::~Operation() {
	// TODO Auto-generated destructor stub
}

void Operation::solve() {
	double solution;
	switch(operation) {
	case '+':
		solution = n0 + n1;
		break;
	case '-':
		solution = n0 - n1;
		break;
	case '*':
		solution = n0 * n1;
		break;
	case '/':
		solution = n0 / n1;
		break;
	}
	std::cout << n0 << operation << n1 << '=' << solution << " PID=" << getpid() << " TID=" << std::this_thread::get_id() << '\n';
	std::cout.flush();
}
