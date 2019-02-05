#include <bits/stdc++.h>
#include <pstructs/bit_ops.h>

using namespace std;
using namespace pstructs;

int main()
{
    string input1;
    string input2;
    cin >> input1 >> input2;
        
    int num1 = bit_ops::binaryStringToNumber(input1);
    int num2 = bit_ops::binaryStringToNumber(input2);

    int cnt = 0;
    for (int diff = num1 ^ num2; diff > 0; diff &= (diff - 1))
    {
        cnt++;
    }

    cout << cnt << endl;
}

