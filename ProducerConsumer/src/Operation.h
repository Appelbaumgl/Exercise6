/*
 * Operation.h
 *
 *  Created on: Jan 20, 2018
 *      Author: cs3840
 */

#ifndef SRC_OPERATION_H_
#define SRC_OPERATION_H_

#include <cstdlib>
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <thread>
#include <string>

class Operation {
private:
	char operations[4] = {'+','-','*','/'};
	int n0;
	int n1;
	char operation;

public:
	Operation();
	virtual ~Operation();
	void solve();
};

#endif /* SRC_OPERATION_H_ */
