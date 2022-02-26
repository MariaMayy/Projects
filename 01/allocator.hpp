#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP

#include <iostream>

class Allocator {
    public:
        Allocator();
        ~Allocator();
        
        void makeAllocator(size_t maxSize);
        char* alloc(size_t size);
        void reset();

    private:
        size_t CurOffset; // current offset
        size_t memorySize;
        char *pStart; // pointer of start

};

#endif