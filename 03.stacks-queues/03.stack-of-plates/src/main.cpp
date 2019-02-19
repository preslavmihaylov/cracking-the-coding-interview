#include <bits/stdc++.h>
#include <pstructs/stack.h>

using namespace std;

template<class T>
class stack_set
{
public:
    stack_set() : stacks(vector<pstructs::stack<T> >())
    {
        stacks.push_back(pstructs::stack<T>());
    }

    void push(T value)
    {
        int currentStackSize = stacks[stacks.size() - 1].getSize();
        if (currentStackSize >= CAPACITY)
        {
            stacks.push_back(pstructs::stack<T>());
        }

        stacks[stacks.size() - 1].push(value);
    }

    T pop()
    {
        if (stacks.size() == 0)
        {
            throw invalid_argument("stack_set is empty");
        }

        T result = stacks[stacks.size() - 1].pop();

        int currentStackSize = stacks[stacks.size() - 1].getSize();
        if (currentStackSize == 0)
        {
            stacks.erase(stacks.begin() + stacks.size() - 1);
        }

        return result;
    }

    T peek()
    {
        return stacks[stacks.size() - 1].peek();
    }

private:
    static const int CAPACITY = 4;
    vector<pstructs::stack<T> > stacks;
};

int main()
{
    string cmd;
    int val;
   
    stack_set<int> st;
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
            cout << st.pop() << endl;
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
