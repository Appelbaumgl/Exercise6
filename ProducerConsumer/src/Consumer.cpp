/*
 * Consumer.cpp
 *
 *  Created on: Jan 20, 2018
 *      Author: cs3840
 */

#include "Consumer.h"

int operationsConsumed;
std::queue<Operation>* consumerQueue;


void printOperationsConsumed(int signal) {
	std::cout << operationsConsumed << " Operations Consumed\n" << consumerQueue->size() << " In Queue\n";
	std::cout.flush();
}

Consumer::Consumer(std::queue<Operation>* _queue, int _numThreads) {
	consumerQueue = _queue;
	numThreads = _numThreads;
	operationsConsumed = 0;
	exitOnEmptyQueue = false;
	threads = new std::thread[numThreads];
	std::signal(SIGUSR2, printOperationsConsumed);
}

Consumer::~Consumer() {
	// TODO Auto-generated destructor stub
}

void Consumer::start() {
	for(int i = 0; i < numThreads; i++) {
		threads[i] = std::thread(consume, consumerQueue, &exitOnEmptyQueue, &operationsConsumed, &mutex);
	}
}

void Consumer::wait() {
	for(int i = 0; i < numThreads; i++) {
		threads[i].join();
	}
}

int Consumer::getOperationsConsumed() {
	return operationsConsumed;
}

void Consumer::setExitOnEmptyQueue(bool _exitOnEmptyQueue) {
	exitOnEmptyQueue = _exitOnEmptyQueue;
}

void consume(std::queue<Operation>* queue, bool* exitOnEmptyQueue, int* operationsConsumed, std::mutex* mutex) {
	while(!(*exitOnEmptyQueue) || queue->size() > 0) {
		Operation op;
		mutex->lock();
		if(queue->size() > 0) {
			op = queue->front();
			queue->pop();
			(*operationsConsumed)++;
		} else {
			std::this_thread::yield();
		}
		mutex->unlock();
		op.solve();
		std::cout << "Queue size = "<< consumerQueue->size() << '\n';
	}
}

