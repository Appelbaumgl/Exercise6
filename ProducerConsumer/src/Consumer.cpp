/*
 * Consumer.cpp
 *
 *  Created on: Jan 20, 2018
 *      Author: cs3840
 */

#include "Consumer.h"

Consumer::Consumer(std::queue<Operation>* _queue, int _numThreads) {
	queue = _queue;
	numThreads = _numThreads;
	operationsConsumed = 0;
	exitOnEmptyQueue = false;
}

Consumer::~Consumer() {
	// TODO Auto-generated destructor stub
}

void Consumer::start() {

}

void Consumer::setExitOnEmptyQueue(bool _exitOnEmptyQueue) {
	exitOnEmptyQueue = _exitOnEmptyQueue;
}

