#include <bits/stdc++.h>

using namespace std;

template<class T>
class multi_stack
{
public:
    multi_stack() 
    {
        int dataSize = 0;
        for (int i = 0; i < STACKS_CNT; i++)
        {
            dataSize += INIT_CAP;
        }

        data = shared_ptr<T[]>(new T[dataSize]);
        for (int i = 0; i < STACKS_CNT; i++)
        {
            sizes[i] = 0;
            capacities[i] = INIT_CAP;
        }
    }

    multi_stack(const multi_stack<T>& other) 
    {
        copyThreeStack(other);
    }
    
    multi_stack<T> operator=(const multi_stack<T>& other)
    {
        copyThreeStack(other);
    }

    void push(int sIndex, T element)
    {   
        if (sizes[sIndex] >= capacities[sIndex]) grow(sIndex);
        
        data[getDataIndex(sIndex) + 1] = element;
        sizes[sIndex]++;
    }

    T pop(int sIndex)
    {
        if (sizes[sIndex] <= 0) throw invalid_argument("size is 0");

        T element = data[getDataIndex(sIndex)];
        sizes[sIndex]--;

        return element;
    }

    T peek(int sIndex)
    {
        if (sizes[sIndex] <= 0) throw invalid_argument("size is 0");

        return data[getDataIndex(sIndex)];
    }

    int getSize(int sIndex)
    {
        return sizes[sIndex];
    }

private:
    static const int INIT_CAP = 4;
    static const int STACKS_CNT = 3;    

    shared_ptr<T[]> data;
    int sizes[STACKS_CNT];
    int capacities[STACKS_CNT];

    int calculateDataSize(const int *givenCapacities)
    {
        int dataSize = 0;
        for (int i = 0; i < STACKS_CNT; i++)
        {
            dataSize += givenCapacities[i];
        }

        return dataSize;
    }

    int calculateDataOffset(int sIndex)
    {
        int offset = 0;
        for (int i = 0; i < sIndex; i++)
        {
            offset += capacities[i];
        }

        return offset;
    }

    int getDataIndex(int sIndex)
    {
        return calculateDataOffset(sIndex) + (sizes[sIndex] - 1);
    }

    void grow(int sIndex)
    {
        int oldCapacities[STACKS_CNT];
        std::copy(std::begin(capacities), std::end(capacities), std::begin(oldCapacities)); 

        capacities[sIndex] = capacities[sIndex] * 2;
        shared_ptr<T[]> oldData = data;

        int dataSize = calculateDataSize(capacities);
        data = shared_ptr<T[]>(new T[dataSize]);

        for (int i = 0; i < STACKS_CNT; i++)
        {
            copyData(i, oldData, oldCapacities);
        }
    }
   
    void copyThreeStack(const multi_stack<T>& other)
    {
        int dataSize = calculateDataSize(other.capacities);
        data = shared_ptr<T[]>(new T[dataSize]);

        std::copy(std::begin(other.sizes), std::end(other.sizes), std::begin(sizes));
        std::copy(std::begin(other.capacities), std::end(other.capacities), std::begin(capacities));

        for (int i = 0; i < STACKS_CNT; i++)
        {
            copyData(i, other.data, other.capacities);
        }
    }
    
    void copyData(int sIndex, const shared_ptr<T[]>& otherData, const int * otherCaps)
    {
        int otherOffset = 0;
        for (int j = 0; j < sIndex; j++)
        {
            otherOffset += otherCaps[j];
        }

        for (int i = 0; i < sizes[sIndex]; i++)
        {
            data[calculateDataOffset(sIndex) + i] = otherData[otherOffset + i];
        }
    }
};

int main()
{
    string cmd;
    int stackIndex;
    int val;
   
    multi_stack<int> st;
    while (true)
    {
        cin >> cmd;
        if (cmd == "push")
        {
            cin >> stackIndex;
            cin >> val;
            st.push(stackIndex, val); 
        }
        else if (cmd == "pop")
        {
            cin >> stackIndex;
            cout << st.pop(stackIndex) << endl;
        }
        else if (cmd == "exit")
        {
            return 0;
        }
        else
        {
            throw invalid_argument("unrecognized command");
        }
    }
}
