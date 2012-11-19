/*
	MemoryManager.h
	Header file for the memory manager component. Contains class MemoryManager.
*/

#include <iostream>

namespace JAMM
{
    class MemoryManager
    {
        public:
            MemoryManager(); // Default constructor

            int Initialize();
            int Shutdown();
        private:

    };
}