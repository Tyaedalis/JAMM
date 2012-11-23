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
            uint32 _size;
            void* memBank;
        public:
            _memBank(size_t memInitialSize);
            ~_memBank();
    };

    // =================================================================================

    class MemoryPool : public _memBank // Memory pool class, contains functionality for a memory pool
    {
        protected:
            uint32 _objSize;
        public:
            MemoryPool(size_t objSize, size_t bankSizeMultiple);
            ~MemoryPool();

            template <class T>
            void* alloc();

            bool free(void* obj);
    };

    template <class T>
    void* MemoryPool::alloc()
    {
        if (sizeof(T) > _objSize)
            ExitWithError("Attempted to allocate oversized object in memory pool.");

        int32 test = 10;

        return &test;
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