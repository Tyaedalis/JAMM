/*
	MemoryManager.h
	Header file for the memory manager component. Contains class MemoryManager.
*/

#pragma once

#include <iostream>
#include "Debug\Debug.h"

namespace JAMM
{

    // =================================================================================

    class _memBank // Base memory bank class, to be derived from with other classes
    {
        protected:
            unsigned int _size;
            void* memBank;
        public:
            _memBank(size_t memInitialSize);
    };

    // =================================================================================

    class MemoryPool : public _memBank // Memory pool class, contains functionality for a memory pool
    {
        protected:
            unsigned int _objSize;
        public:
            MemoryPool(size_t objSize, size_t bankSizeMultiple);

            template <class T>
            void* alloc();

            bool free(void* obj);
    };

    template <class T>
    void* MemoryPool::alloc()
    {
        if (sizeof(T) > _objSize)
            ExitWithError("Attempted to allocate oversized object in memory pool.");

        int test = 10;

        return &test;
    }

    // =================================================================================

    class MemoryManager
    {
        public:
            MemoryManager(); // Default constructor

            int Initialize();
            int Shutdown();
        private:

    };
}