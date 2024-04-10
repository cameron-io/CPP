#ifndef PARALLELISM
#define PARALLELISM

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>

class Parallelism {
public:
  static void nmap(int n_threads, void* (*fun) (void*), const char* msg)
  {
    pthread_t threads[n_threads];
    
    for (int i = 0; i < n_threads; i++)
    {
      pthread_t thread;
      int iret = pthread_create(&thread, NULL, fun, (void*) msg);
      std::cout << "Thread " << i << " returns: " << iret << std::endl;
      threads[i] = thread;
    }

    for (pthread_t thread : threads)
    {
      pthread_join(thread, NULL);
    }
  }
};

#endif
