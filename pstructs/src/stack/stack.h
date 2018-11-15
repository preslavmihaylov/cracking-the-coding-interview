#ifndef PSTRUCT_STACK_H
#define PSTRUCT_STACK_H

#include <stdexcept>

#define INIT_CAP 4

namespace pstructs
{
    template<class T>
    class stack
    {
        T *data;
        int size;
        int capacity;
        
        void growStack()
        {
            int newCapacity = this->capacity * 2;
            T *newData = new T[newCapacity];
            for (int i = 0; i < this->capacity; i++)
            {
                newData[i] = this->data[i];
            }
            
            T *oldData = this->data;
            this->data = newData;
            this->capacity = newCapacity;

            delete[] oldData;
        }
    public:
        stack() : data(new T[INIT_CAP]), size(0), capacity(INIT_CAP) {}

        T pop()
        {
            if (size <= 0) throw std::invalid_argument("size is zero");

            T element = data[--size];

            return element;
        }

        void push(T element)
        {
            if (size >= this->capacity) this->growStack();

            data[size++] = element;
        }

        T peek()
        {
            if (size <= 0) throw std::invalid_argument("size is zero");

            return data[size - 1];
        }

        int getSize()
        {
            return size;
        }

        bool isEmpty()
        {
            return size == 0;
        }
    };
}

#endif
