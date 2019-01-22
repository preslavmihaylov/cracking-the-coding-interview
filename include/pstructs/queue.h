#ifndef PSTRUCTS_QUEUE_H
#define PSTRUCTS_QUEUE_H

#include <stdexcept>
#include <iostream>

namespace pstructs
{
    template<class T>
    class queue
    {
        static const int INIT_CAP = 4;
        T *data;
        int head;
        int tail;
        int size;
        int capacity;
       
        void copyQueue(const queue& other)
        {
            this->size = other.size;
            this->capacity = other.capacity;
            this->head = other.head;
            this->tail = other.tail;
            
            this->data = new T[this->capacity];
            for (int i = 0; i < this->capacity; i++)
            {
                this->data[i] = other.data[i];
            }
        }


        void growQueue()
        {
            int newCapacity = this->capacity * 2;
            T *newData = new T[newCapacity];
            
            int newDataIndex = 0;
            for (int i = this->head; newDataIndex < this->size; i = (i + 1) % this->size)
            {
                newData[newDataIndex++] = this->data[i];
            }

            T *oldData = this->data;
            this->data = newData;
            delete[] oldData;
            
            this->head = 0;
            this->tail = this->size;
            this->capacity = newCapacity;
        }
    public:
        queue() : data(new T[INIT_CAP]), head(0), tail(0), size(0), capacity(INIT_CAP) {}
        
        ~queue()
        {
            delete[] this->data;
        }

        queue(const queue& other)
        {
            this->copyQueue(other);
        }

        queue& operator=(const queue& other)
        {
            delete[] this->data;
            this->copyQueue(other);

            return *this;
        }

        T dequeue()
        {
            if (this->size == 0) throw std::invalid_argument("size is zero");

            T element = this->data[this->head];
            this->head = (this->head + 1) % this->capacity;
            this->size--;

            return element;
        }

        void enqueue(T element)
        {
            if (this->size == this->capacity) this->growQueue();
            

            this->data[this->tail] = element;
            this->tail = (this->tail + 1) % this->capacity;

            this->size++;
        }

        T peek()
        {
            if (this->size == 0) throw std::invalid_argument("size is zero");

            return this->data[this->head];
        }

        int getSize()
        {
            return this->size;
        }

        bool isEmpty()
        {
            return this->size == 0;
        } 
    };
}

#endif
