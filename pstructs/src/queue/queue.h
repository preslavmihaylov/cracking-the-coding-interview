#ifndef PSTRUCT_STACK_H
#define PSTRUCT_STACK_H

#define INIT_CAP 4

namespace pstructs
{
    template<class T>
    class queue
    {
        T data[INIT_CAP];
        int size;
    public:
        T pop()
        {
            T element = data[--size];

            return element;
        }

        void push(T element)
        {
            data[size++] = element;
        }

        T peek()
        {
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
