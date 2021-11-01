compile:
	g++ --std=c++11 ./*.cpp -o output
	./output
emcc:
	emcc --bind -s USE_PTHREADS=1 -s PTHREAD_POOL_SIZE=2 -s ALLOW_MEMORY_GROWTH=1 -o mthreadSort.js *.cpp