#ifndef PSTRUCTS_STACK_H
#define PSTRUCTS_STACK_H

namespace pstructs
{
    #include <stdexcept>
    
    template<class T>
    class stack
    {
        static const int INIT_CAP = 4;
        T *data;
        int size;
        int capacity;
        
        void copyStack(const stack& other)
        {
            this->size = other.size;
            this->capacity = other.capacity;

            this->data = new T[this->capacity];
            for (int i = 0; i < this->capacity; i++)
            {
                this->data[i] = other.data[i];
            }
        }
        
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
        
        ~stack() 
        {
            delete[] this->data;
        }

        stack(const stack& other)
        {
            this->copyStack(other);
        }

        stack& operator=(const stack& other)
        {
            delete[] this->data;
            this->copyStack(other);

            return *this;
        }

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
