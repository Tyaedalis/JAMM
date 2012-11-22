/*
	MemoryManager.cpp
	Implementation file for the memory manager component. Contains class MemoryManager.
*/

#include <iostream>

#include "MemoryManager.h"

using namespace JAMM;

// ======================= _memBank Implementation =======================
_memBank::_memBank(size_t memInitialSize)
{
    memBank = malloc(memInitialSize); // Allocate the specified number of bytes and set the pointer to memBank
}

// ======================= MemoryPool Implementation =======================
MemoryPool::MemoryPool(size_t objSize, size_t bankSizeMultiple)
    : _memBank(objSize * bankSizeMultiple) 
{ 
    _objSize = objSize;
}

bool MemoryPool::free(void* obj) // TODO: Enable freeing of individual blocks in the memory pool
{
    return true;
}

// ======================= MemoryManager Implementation =======================

// Default constructor
MemoryManager::MemoryManager() { }

int MemoryManager::Initialize()
{
    return 1;
}

int MemoryManager::Shutdown()
{
    return 1;
}