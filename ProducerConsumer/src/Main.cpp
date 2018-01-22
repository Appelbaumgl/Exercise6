
#include <iostream>
#include <queue>
#include <thread>
#include "Operation.h"
#include "Consumer.h"
#include "Producer.h"

std::queue<Operation>* queue;


int main(int argc, char* argv[]) {
	int queueMaxSize = atoi(argv[1]);
	int numOperations = atoi(argv[2]);
	int numProducerThreads = atoi(argv[3]);
	int numConsumerThreads = atoi(argv[4]);
	std::queue<Operation> queue = std::queue<Operation>();
	Consumer* consumer = new Consumer(&queue, numConsumerThreads);
	Producer* producer = new Producer(&queue, numProducerThreads, numOperations, queueMaxSize, consumer);
	producer->start();
	consumer->start();
	producer->wait();
	consumer->wait();
	std::cout << "Produced=" << producer->getOperationsProduced() << " Consumed=" << consumer->getOperationsConsumed() << '\n';
	return 0;
}

