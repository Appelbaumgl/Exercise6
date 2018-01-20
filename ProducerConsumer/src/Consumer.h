/*
 * Consumer.h
 *
 *  Created on: Jan 20, 2018
 *      Author: cs3840
 */

#ifndef SRC_CONSUMER_H_
#define SRC_CONSUMER_H_

#include <queue>
#include "Operation.h"

class Consumer {

private:
	std::queue<Operation>* queue;
	int numThreads;
	int operationsConsumed;
	bool exitOnEmptyQueue;

public:
	Consumer(std::queue<Operation>*, int);
	virtual ~Consumer();
	void start();
	void setExitOnEmptyQueue(bool);
};

#endif /* SRC_CONSUMER_H_ */
