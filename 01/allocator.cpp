#include <iostream>
#include "allocator.hpp"

Allocator::Allocator() {
    pStart = nullptr;
    CurOffset = 0; 
    memorySize = 0; 
}

Allocator::~Allocator() {
    delete [] pStart; 
    memorySize = 0;
}

void Allocator::makeAllocator(size_t maxSize) {
    // when calling makeAllocator again
    if (pStart != nullptr) {
        delete [] pStart;
        pStart = nullptr;
    }

    pStart = new char[maxSize];
    CurOffset = 0;
    memorySize = maxSize;
}

char* Allocator::alloc(size_t size) {
    char *tmp;
    if (memorySize < size + CurOffset) {
        return nullptr;
    }

    tmp = pStart + CurOffset;
    CurOffset += size;
    return tmp;
}

void Allocator::reset() {
    CurOffset = 0;
}