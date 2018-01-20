/*
 * Producer.cpp
 *
 *  Created on: Jan 20, 2018
 *      Author: cs3840
 */

#include "Producer.h"

Producer::Producer(std::queue<Operation>* _queue, int _numThreads, Consumer* _consumer) {
	queue = _queue;
	numThreads = _numThreads;
	operationsProduced = 0;
	consumer = _consumer;
	threads = new std::thread[numThreads];
}

Producer::~Producer() {
	// TODO Auto-generated destructor stub
}

void Producer::start() {
	for(int i = 0; i < numThreads; i++) {
		threads[i] = std::thread(produce);
	}
	consumer->setExitOnEmptyQueue(true);
}

void produce() {

}

