#include <bits/stdc++.h>
#include <pstructs/stack.h>

using namespace std;

template<class T>
class stack_min
{
    static const int INIT_CAP = 4;
    T *data;
    int size;
    int capacity;
    pstructs::stack<T> minsStack;
    
    void copyStack(const stack_min& other)
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
    stack_min() : data(new T[INIT_CAP]), size(0), capacity(INIT_CAP) {}
    
    ~stack_min() 
    {
        delete[] this->data;
    }

    stack_min(const stack_min& other)
    {
        this->copyStack(other);
    }

    stack_min& operator=(const stack_min& other)
    {
        delete[] this->data;
        this->copyStack(other);

        return *this;
    }

    T pop()
    {
        if (size <= 0) throw std::invalid_argument("size is zero");

        T element = data[--size];
        if (minsStack.getSize() > 0 && minsStack.peek() == element)
        {
            minsStack.pop();
        }
        
        return element;
    }

    void push(T element)
    {
        if (size >= this->capacity) this->growStack();
    
        data[size++] = element;
        if (minsStack.getSize() == 0 || minsStack.peek() >= element)
        {
            minsStack.push(element);
        }
    }

    T peek()
    {
        if (size <= 0) throw std::invalid_argument("size is zero");

        return data[size - 1];
    }

    T getMin() 
    {
        if (size <= 0) throw std::invalid_argument("Size is zero");

        return minsStack.peek();
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

int main()
{
    string cmd;
    int val;
   
    stack_min<int> st;
    while (true)
    {
        cin >> cmd;
        if (cmd == "push")
        {
            cin >> val;
            st.push(val); 
        }
        else if (cmd == "pop")
        {
            st.pop();
        }
        else if (cmd == "min")
        {
            cout << st.getMin() << endl;
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
