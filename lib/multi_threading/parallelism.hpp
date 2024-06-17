#ifndef PARALLELISM
#define PARALLELISM

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>

class Parallelism {
public:
  static void nmap(int n_threads, void* (*fun) (void*), const char* msg);
};

#endif
