/*
	MemoryManager.h
	Header file for the memory manager component. Contains class MemoryManager.
*/

#pragma once

#include <iostream>
#include <string>
#include <sstream>

#include "Debug\Debug.h"

template <typename T>
string NumToStr(T Number)
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

namespace JAMM
{

    // =================================================================================

    class _memBank // Base memory bank class, to be derived from with other classes
    {
        protected:
            ptr32 _baseAddr;
            uint32 _size;
        public:
            _memBank(uint32 memInitialSize);
            ~_memBank();
    };

    // =================================================================================

    class MemoryPool : public _memBank // Memory pool class, contains functionality for a memory pool
    {
        protected:
            ptr32 _freeObjLinkedListRoot;
            uint32 _objSize;

            void generateFreeList();
        public:
            MemoryPool(uint32 objSize, uint32 bankSizeMultiple);
            ~MemoryPool();

            template <class T>
            ptr32 alloc();

            bool free(ptr32 obj, bool checkAlreadyFreed = true);
    };

    template <class T>
    ptr32 MemoryPool::alloc()
    {
        if (sizeof(T) > _objSize)
            ExitWithError("Attempted to allocate oversized object in memory pool.");

        if (_freeObjLinkedListRoot != NULL)
        {
            ptr32 memBlock = _freeObjLinkedListRoot;
            _freeObjLinkedListRoot = (ptr32)*memBlock;
            *memBlock = NULL;

            return memBlock;
        }
        else
            return NULL;
    }

    // =================================================================================

    class MemoryManager
    {
        public:
            MemoryManager(); // Default constructor

            int32 Initialize();
            int32 Shutdown();
        private:

    };
}