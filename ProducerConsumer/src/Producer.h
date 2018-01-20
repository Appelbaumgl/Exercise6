/*
 * Producer.h
 *
 *  Created on: Jan 20, 2018
 *      Author: cs3840
 */

#ifndef SRC_PRODUCER_H_
#define SRC_PRODUCER_H_

#include <queue>
#include <thread>
#include "Operation.h"
#include "Consumer.h"

class Producer {

private:
	std::queue<Operation>* queue;
	int numThreads;
	int operationsProduced;
	Consumer* consumer;
	std::thread* threads;

public:
	Producer(std::queue<Operation>*, int, Consumer*);
	virtual ~Producer();
	void start();
};

void produce();

#endif /* SRC_PRODUCER_H_ */
