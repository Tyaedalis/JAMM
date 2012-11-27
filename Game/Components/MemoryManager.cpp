/*
	MemoryManager.cpp
	Implementation file for the memory manager component. Contains class MemoryManager.
*/

#include "Game\Components\MemoryManager.h"

using namespace JAMM;

// ======================= _memBank Implementation =======================

// Constructor
_memBank::_memBank(uint32 memInitialSize)
    : _baseAddr(static_cast<ptr32>(malloc(memInitialSize))), // Allocate the specified number of bytes and initialize the _baseAddr pointer
      _size(memInitialSize) // Initialize memory bank size constant
{
    std::string sNumBytes = NumToStr<uint32>(memInitialSize);
    std::string error = std::string("*Failed to allocate ") + sNumBytes + " bytes of memory for memory bank.";

    if (_baseAddr == NULL)
        ExitWithError(error.c_str());

    Log << L"*Allocated a " << memInitialSize << L" byte memory bank at 0x" << _baseAddr << L"\n";
}

// Destructor
_memBank::~_memBank()
{
    // Release memory bank
    free(const_cast<ptr32>(_baseAddr));

    Log << L"*Released " << _size << L" byte memory bank at 0x" << _baseAddr << L"\n";
}

// ======================= MemoryPool Implementation =======================
MemoryPool::MemoryPool(uint32 objSize, uint32 bankSizeMultiple)
    : _memBank(objSize % sizeof(ptr32) == 0 ? objSize * bankSizeMultiple : bankSizeMultiple * (objSize += sizeof(ptr32) - objSize % sizeof(ptr32))), // Ensure object size is a multiple of sizeof(ptr32), then pass result to base class
      _objSize(objSize) // Initialize object size constant
{ 
    if (objSize < sizeof(ptr32))
        ExitWithError(std::string("Attempted to create memory pool for objects smaller than " + NumToStr<uint32>(sizeof(ptr32)) + " bytes.").c_str());

    generateFreeList();
}

// Uses the free blocks of memory in the pool to store a linked list containing all of the free blocks
void MemoryPool::generateFreeList()
{
    uint32 step = _objSize / sizeof(ptr32);

    _freeObjLinkedListRoot = const_cast<ptr32>(_baseAddr);

    const int32 slots = (_size / _objSize) - 1;

    ptr32 lastObjPtr;

    for (int32 i = 0; i < slots; i++)
    {
        ptr32 objPtr = const_cast<ptr32>(_baseAddr) + (i * step);
        ptr32 nextObjPtr = objPtr + step;
        lastObjPtr = nextObjPtr;


        ASSERT(nextObjPtr <= const_cast<ptr32>((_baseAddr + ((_size - _objSize) / sizeof(ptr32)))), L"Value of next ptr shouldn't exceed last slot in memory pool.");

        // Log << "current item " << objPtr << "\n"; // DEBUG
        // Log << "next item    " << nextObjPtr << "\n"; // DEBUG

        *objPtr = reinterpret_cast<uint32>(nextObjPtr);

        // Log << "value cur    " << (ptr32)*objPtr << "\n\n"; // DEBUG

        ASSERT(reinterpret_cast<ptr32>(*objPtr) == nextObjPtr, L"Value of pointer should equal address of next.");
    }

    *lastObjPtr = NULL; // Set the last item in the list to a null pointer

}

bool MemoryPool::free(ptr32 obj, bool checkAlreadyFreed) // TODO: Enable freeing of individual blocks in the memory pool
{
    // Ensure that the pointer is not NULL, is not out of the range of the allocated block, and is a multiple of _objSize
    if (obj == NULL || obj < _baseAddr || obj > (_baseAddr + ((_size - _objSize) / sizeof(ptr32))) || ((obj - _baseAddr) * sizeof(ptr32)) % _objSize != 0)
    {
        DEBUG_BREAK; // Uh-oh! A NULL or invalid (out of range) address was passed to the function. You might want to check on that...
        return false;
    }

    ptr32 slotPtr;

    if (checkAlreadyFreed && _freeObjLinkedListRoot != NULL)
    {
         slotPtr = _freeObjLinkedListRoot;

        // Look through the linked list of freed blocks for the same memory address that obj is pointing to
        do
        {
            if (slotPtr == obj) // Found it! obj was already freed.
                return false;

            slotPtr = reinterpret_cast<ptr32>(*slotPtr);
        } while (slotPtr != NULL);

        // Looks like it wasn't freed yet
    }

    slotPtr = _freeObjLinkedListRoot; // Store the current address of _freeObjLinkedListRoot
    _freeObjLinkedListRoot = obj; // Set the address of _freeObjLinkedListRoot to the freed obj
    *_freeObjLinkedListRoot = reinterpret_cast<uint32>(slotPtr); // Complete the link

    obj = NULL;

    return true;
}

MemoryPool::~MemoryPool() { }

// ======================= MemoryManager Implementation =======================

// Default constructor
MemoryManager::MemoryManager() { }

int32 MemoryManager::Initialize()
{
    return 1;
}

int32 MemoryManager::Shutdown()
{
    return 1;
}