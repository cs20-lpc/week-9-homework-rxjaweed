// QueueFactory.hpp
#ifndef QUEUEFACTORY_HPP
#define QUEUEFACTORY_HPP

#include "ArrayQueue.hpp"
#include "LinkedQueue.hpp"

class QueueFactory {
public:
    // If maxSize == -1 → return linked list queue
    // If maxSize > 0 → return array queue

    template <typename T>
    static Queue<T>* GetQueue(int maxSize = -1) {
        if (maxSize == -1) {
            return new LinkedQueue<T>();
        } else {
            return new ArrayQueue<T>(maxSize);
        }
    }
};

#endif
