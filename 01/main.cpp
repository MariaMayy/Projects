#include "allocator.hpp"
#include <cassert>

using namespace std;

void testMakeAllocator(size_t size) {
    Allocator tmpAll;
    char *tmp;

    tmpAll.makeAllocator(size);
    tmp = tmpAll.alloc(size);
    
    assert(tmp != nullptr);
}

void testAlloc() {
    Allocator tmpAll;
    size_t size = 10;

    tmpAll.makeAllocator(size);
    
    for (int i = 0; i < 10; i++) {
        assert(tmpAll.alloc(1) != nullptr);
    }
    assert(tmpAll.alloc(1) == nullptr);
}

void testReset() {
    Allocator tmpAll;
    char *tmp1, *tmp2;
    
    tmpAll.makeAllocator(100);
    tmp1 = tmpAll.alloc(60);
    tmpAll.reset();
    tmp2 = tmpAll.alloc(10);
    assert(tmp1 == tmp2);
}

int main() {
    testMakeAllocator(50);
    cout << "MakeAllocator success:)\n";

    testAlloc();
    cout << "Alloc success:)\n";

    testReset();
    cout << "Reset success:)\n";

    return 0;
}