/*
 * Consumer.h
 *
 *  Created on: Jan 20, 2018
 *      Author: cs3840
 */

#ifndef SRC_CONSUMER_H_
#define SRC_CONSUMER_H_

#include <queue>
#include <mutex>
#include <thread>
#include <csignal>
#include "Operation.h"

class Consumer {

private:
	int numThreads;
	bool exitOnEmptyQueue;
	std::thread* threads;
	std::mutex mutex;

public:
	Consumer(std::queue<Operation>*, int);
	virtual ~Consumer();
	void start();
	void setExitOnEmptyQueue(bool);
	int getOperationsConsumed();
	void wait();

};

void consume(std::queue<Operation>*, bool*, int*, std::mutex*);

#endif /* SRC_CONSUMER_H_ */
