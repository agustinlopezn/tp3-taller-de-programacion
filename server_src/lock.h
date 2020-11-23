#ifndef __LOCK_H
#define __LOCK_H

#include <mutex>

// Class que aplica RAII para bloquear/desbloquear el mutex

class Lock {
 private:
    std::mutex &m;
    Lock(const Lock&) = delete;
    Lock& operator=(const Lock&) = delete;
    Lock(Lock&&) = delete;
    Lock& operator=(Lock&&) = delete;
 public:
    // Constructor y destructor
    explicit Lock(std::mutex &m);
    ~Lock();
};

#endif  // LOCK_H_
