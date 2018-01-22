
CC=g++

main.o: main.cpp Operation.h Consumer.h Producer.h
Operation.o: Operation.h
Producer.o: Producer.h Operation.h
Consumer.o: Consumer.h Operation.h

all: ProducerConsumer
ProducerConsumer: main.o Operation.o Consumer.o Producer.o
	$(CC) -Wall -pthread -o ProducerConsumer main.o Operation.o Consumer.o Producer.o

clean:
	rm -f *.o
	rm -f ProducerConsumer

%.o: %.cpp
	$(CC) -c $<
