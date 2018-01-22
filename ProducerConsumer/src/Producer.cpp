/*
 * Producer.cpp
 *
 *  Created on: Jan 20, 2018
 *      Author: cs3840
 */

#include "Producer.h"
#include "Consumer.h"

int operationsProduced;

std::queue<Operation>* producerQueue;

void printOperationsProduced(int signal) {
	std::cout << "Status: Produced " << operationsProduced << " operations and " << producerQueue->size() << " are in the queue.\n";
	std::cout.flush();
}

Producer::Producer(std::queue<Operation>* _queue, int _numThreads, int _numOperations, int _queueMaxSize, Consumer* _consumer) {
	producerQueue = _queue;
	numThreads = _numThreads;
	operationsProduced = 0;
	consumer = _consumer;
	threads = new std::thread[numThreads];
	queueMaxSize = _queueMaxSize;
	numOperations = _numOperations;
	std::signal(SIGUSR1, printOperationsProduced);
}

Producer::~Producer() {

}

void Producer::start() {
	for(int i = 0; i < numThreads; i++) {
		threads[i] = std::thread(produce, producerQueue, numOperations, queueMaxSize, &operationsProduced, &mutex);
	}
}

int Producer::getOperationsProduced() {
	return operationsProduced;
}

void Producer::wait() {
	for(int i = 0; i < numThreads; i++) {
		threads[i].join();
	}
	consumer->setExitOnEmptyQueue(true);
}

void produce(std::queue<Operation>* queue, int numOperations, unsigned int queueMaxSize, int* operationsProduced, std::mutex* mutex) {
	for(int i = 0; i < numOperations; i++) {
		Operation* op = new Operation();
		mutex->lock();
		while(queue->size() == queueMaxSize) {
			std::this_thread::yield();
		}
		queue->push(*op);
		(*operationsProduced)++;
		mutex->unlock();
		//std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 10));
	}

}

