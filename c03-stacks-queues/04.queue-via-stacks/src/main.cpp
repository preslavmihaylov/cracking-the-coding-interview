#include <bits/stdc++.h>
#include <pstructs/stack.h>

using namespace std;

template<class T>
class queue_via_stacks
{
public:
    void enqueue(T element)
    {
        enqueueStack.push(element);
    }

    T dequeue()
    {
        if (dequeueStack.isEmpty())
        {
            fillDequeueStack();
        }

        return dequeueStack.pop();
    }
    T peek()
    {
        if (dequeueStack.isEmpty())
        {
            fillDequeueStack();
        }
        
        return dequeueStack.peek();
    }

    bool isEmpty()
    {
        return dequeueStack.isEmpty() && enqueueStack.isEmpty();
    }

private:
    pstructs::stack<T> dequeueStack;
    pstructs::stack<T> enqueueStack;

    void fillDequeueStack()
    {
        while (!enqueueStack.isEmpty())
        {
            dequeueStack.push(enqueueStack.pop());
        }
    }
};

int main()
{
    int n;
    queue_via_stacks<int> que;
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;

        que.enqueue(val);
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << que.dequeue() << endl;
    }
}

