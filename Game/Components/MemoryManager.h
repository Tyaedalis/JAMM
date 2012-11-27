/*
	MemoryManager.h
	Header file for the memory manager component. Contains class MemoryManager.
*/

#pragma once

#include <iostream>
#include <string>
#include <sstream>

#include "Game\Debug\Debug.h"

/*
==========================
template <typename T>
std::wstring NumToStrw(T Number)

Helper function that takes a variable of any type T and attempts to convert it to a wide string
==========================
*/
template <typename T>
std::wstring NumToStrw(T Number)
{
    std::wostringstream ss;
    ss << Number;
    return ss.str();
}

/*
==========================
template <typename T>
std::string NumToStrw(T Number)

Helper function that takes a variable of any type T and attempts to convert it to a string
==========================
*/
template <typename T>
std::string NumToStr(T Number)
{
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}

namespace JAMM
{

    /*
    ==========================
    class _memBank
	Base memory bank class, to be derived from with other classes
    ==========================
    */
    class MemoryAllocator
    {
        protected:
            constPtr32 _baseAddr;
            const uint32 _size;
        public:
            MemoryAllocator(uint32 memInitialSize);
            virtual ~MemoryAllocator();
    };

    /*
    ==========================
    class MemoryPool, derives from class _memBank
	Memory pool class, contains functionality for a memory pool allocator
    ==========================
    */
    class MemoryPool : public MemoryAllocator
    {
        protected:
            ptr32 _freeObjLinkedListRoot;
            const uint32 _objSize;

            void _generateFreeList();
        public:
            MemoryPool(uint32 objSize, uint32 bankSizeMultiple);
            virtual ~MemoryPool();

            template <class T>
            T* Alloc();

            bool Free(ptr32 obj, bool checkAlreadyFreed = true);
    };

    /*
    ==========================
    template <class T> T* MemoryPool::Alloc()

	Member function of the MemoryPool class
    Returns pointer to a valid memory chunk within the pool as long as sizeof(T) is less than or equal to the pool size
    ==========================
    */
    template <class T>
    T* MemoryPool::Alloc()
    {
        if (sizeof(T) > _objSize)
            ExitWithError("Attempted to allocate oversized object in memory pool.");

        if (_freeObjLinkedListRoot != NULL)
        {
            ptr32 memBlock = _freeObjLinkedListRoot;
            _freeObjLinkedListRoot = reinterpret_cast<ptr32>(*memBlock);
            *memBlock = NULL;

            return reinterpret_cast<T*>(memBlock);
        }
        else
            return NULL;
    }

     /*
    ==========================
    class MemoryManager
	Keeps track and properly disposes of any created memory allocators
    ==========================
    */
    class MemoryManager
    {
        public:
            MemoryManager(); // Default constructor

            int32 Initialize();
            int32 Shutdown();
        private:

    };
}