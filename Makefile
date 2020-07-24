all:	main.cpp fifo.cpp lfu.cpp lru.cpp ran.cpp algorithms.h fifo.h lfu.h lru.h ran.h 
	g++ -w -o P4 main.cpp fifo.cpp lfu.cpp lru.cpp ran.cpp

clean:
	rm -rf *.o *~ P4 core

