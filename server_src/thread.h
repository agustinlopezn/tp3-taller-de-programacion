#ifndef SERVER_SRC_THREAD_H_
#define SERVER_SRC_THREAD_H_

#include <thread>
#include <utility>

class Thread {
 private:
    std::thread thread;

 public:
    Thread();
    virtual ~Thread();
    virtual void run() = 0;
    virtual void stop() = 0;
    virtual bool isAlive() = 0;
    void start();
    void join();
    Thread(const Thread&) = delete;
    Thread& operator=(const Thread&) = delete;
    Thread(Thread&& other);
    Thread& operator=(Thread&& other);
};

#endif  // SERVER_SRC_THREAD_H_
