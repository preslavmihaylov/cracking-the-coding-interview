#include <bits/stdc++.h>
#include <pstructs/stack.h>

using namespace std;

template<class T>
class sort_stack : public pstructs::stack<T>
{
public:
    void sort()
    {
        sort_stack<T> tmpStack;
        while (!this->isEmpty())
        {
            int poppedItemsCnt = 0;
            T el = this->pop();

            while (!tmpStack.isEmpty() && tmpStack.peek() < el)
            {
                this->push(tmpStack.pop());
                poppedItemsCnt++;
            }

            tmpStack.push(el);
            for (int i = 0; i < poppedItemsCnt; i++)
            {
                tmpStack.push(this->pop());
            }
        }

        *this = tmpStack;
    }
};

int main()
{
    int n;
    int val;
    sort_stack<int> st;
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        st.push(val);
    }
    
    st.sort();

    for (int i = 0; i < n; i++)
    {
        cout << st.pop() << endl;
    }
}
