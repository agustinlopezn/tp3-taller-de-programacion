#ifndef __THREAD_H
#define __THREAD_H

#include <thread>
#include <utility>

class Thread {
 private:
    std::thread thread;

 public:
    Thread();
    virtual ~Thread();
    virtual void run() = 0;
    void start();
    void join();
    Thread(const Thread&) = delete;
    Thread& operator=(const Thread&) = delete;
    Thread(Thread&& other);
    Thread& operator=(Thread&& other);
};

#endif  // THREAD_H_
