#ifndef PSTRUCTS_MIN_HEAP_H
#define PSTRUCTS_MIN_HEAP_H

#include <vector>
#include <memory>
#include <functional>

namespace pstructs
{
    template<class T>
    class heap
    {
    public:
        void push(const T& val)
        {
            data.push_back(val);

            int index = data.size() - 1;
            while (parentIndex(index) != NOT_FOUND && comp(data[index], data[parentIndex(index)]))
            {
                swap(index, parentIndex(index));
                index = parentIndex(index);
            }
        }

        T pop()
        {
            if (data.size() <= 1) throw std::invalid_argument("size is zero");

            T popped = data[1];
            int index = 1;
            data[index] = data[data.size() - 1];

            data.erase(data.begin() + (data.size() - 1));
            
            while ((lNodeIndex(index) != NOT_FOUND && comp(data[lNodeIndex(index)], data[index])) || 
                   (rNodeIndex(index) != NOT_FOUND && comp(data[rNodeIndex(index)], data[index])))
            {
                int lnIndex = lNodeIndex(index);
                int rnIndex = rNodeIndex(index);

                int swapIndex;
                if (lnIndex == NOT_FOUND)
                {
                    swapIndex = rnIndex;
                }
                else if (rnIndex == NOT_FOUND)
                {
                    swapIndex = lnIndex;
                }
                else
                {
                    swapIndex = comp(data[lnIndex], data[rnIndex]) ? lnIndex : rnIndex;
                }
                
                swap(index, swapIndex);
                index = swapIndex;
            }

            return popped;
        }

        T peek()
        {
            if (data.size() <= 1) throw std::invalid_argument("size is zero");

            return data[1];
        }

        int getSize()
        {
            return data.size() - 1;
        }

        bool isEmpty()
        {
            return getSize() == 1;
        }

    protected:
        heap(std::function<bool(T, T)> comp) : data{ T() }, comp(comp) {}

    private:
        std::vector<T> data;
        std::function<bool(const T&, const T&)> comp;
        static const int NOT_FOUND = -1;

        int lNodeIndex(int index)
        {
            size_t res = index * 2;
            if (res >= data.size()) return NOT_FOUND;

            return res;
        }

        int rNodeIndex(int index)
        {
            size_t res = index * 2 + 1;
            if (res >= data.size()) return NOT_FOUND;

            return res;
        }

        int parentIndex(int index)
        {
            int res = index / 2;
            if (res <= 0) return NOT_FOUND;

            return res;
        }

        void swap(int index1, int index2)
        {
            T tmp = data[index1];
            data[index1] = data[index2];
            data[index2] = tmp;
        }
    };

    template<class T>
    class min_heap : public heap<T>
    {
    public:
        min_heap() : heap<T>([](const T& a, const T& b) { return a < b; }) {}
    };

    template<class T>
    class max_heap : public heap<T>
    {
    public:
        max_heap() : heap<T>([](const T& a, const T& b) { return a > b; }) {}
    };
}

#endif
