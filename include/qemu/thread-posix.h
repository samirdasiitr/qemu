#ifndef __QEMU_THREAD_POSIX_H
#define __QEMU_THREAD_POSIX_H 1
#include "pthread.h"
#include <semaphore.h>

struct QemuMutex {
    pthread_mutex_t lock;
    pthread_t owner;
    char name[32];
};

struct QemuCond {
    pthread_cond_t cond;
    char name[32];
};

struct QemuSemaphore {
#if defined(__APPLE__) || defined(__NetBSD__)
    pthread_mutex_t lock;
    pthread_cond_t cond;
    unsigned int count;
#else
    sem_t sem;
#endif
};

struct QemuEvent {
#ifndef __linux__
    pthread_mutex_t lock;
    pthread_cond_t cond;
#endif
    unsigned value;
};

struct QemuThread {
    pthread_t thread;
};

#endif
