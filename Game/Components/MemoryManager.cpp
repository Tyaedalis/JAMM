/*
	MemoryManager.cpp
	Implementation file for the memory manager component. Contains class MemoryManager.
*/

#include "MemoryManager.h"

using namespace JAMM;

// ======================= _memBank Implementation =======================

// Constructor
_memBank::_memBank(size_t memInitialSize)
{
    string sNumBytes = NumToStr<size_t>(memInitialSize);
    string error = string("Failed to allocate ") + sNumBytes + " bytes of memory for memory bank.";

    memBank = malloc(memInitialSize); // Allocate the specified number of bytes and set the pointer to memBank
    if (memBank == NULL)
        ExitWithError(error.c_str());

    Log << "*Allocated a " << memInitialSize << " byte memory bank at 0x" << memBank << "\n";

    _size = memInitialSize;
}

// Destructor
_memBank::~_memBank()
{
    // Release memory bank
    free(memBank);

    Log << "*Released " << _size << " byte memory bank at 0x" << memBank << "\n";

    // Set pointer to null
    memBank = NULL;
}

// ======================= MemoryPool Implementation =======================
MemoryPool::MemoryPool(size_t objSize, size_t bankSizeMultiple)
    : _memBank((objSize * bankSizeMultiple) + (bankSizeMultiple * 4))
{ 
    _objSize = objSize;
}

bool MemoryPool::free(void* obj) // TODO: Enable freeing of individual blocks in the memory pool
{
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