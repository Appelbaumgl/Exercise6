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
#include <mutex>
#include <chrono>
#include <csignal>
#include "Operation.h"

class Consumer;

class Producer {

private:
	int numThreads;
	Consumer* consumer;
	std::thread* threads;
	unsigned int queueMaxSize;
	int numOperations;
	std::mutex mutex;

public:
	Producer(std::queue<Operation>*, int, int, int, Consumer*);
	virtual ~Producer();
	void start();
	int getOperationsProduced();
	void wait();
};

void produce(std::queue<Operation>*, int, unsigned int, int*, std::mutex*);

#endif /* SRC_PRODUCER_H_ */
