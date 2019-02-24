#include <bits/stdc++.h>

using namespace std;

int rec_multiply(int term1, int term2);
int rec_multiply_prv(int term1, int term2);

int main()
{
    int a, b;
    cin >> a >> b;
    cout << rec_multiply(a, b) << endl;
}

int rec_multiply(int term1, int term2)
{
    int bigger = term1 > term2 ? term1 : term2;
    int smaller = term1 <= term2 ? term1 : term2;

    return rec_multiply_prv(bigger, smaller);
}

int rec_multiply_prv(int bigger, int smaller)
{
    if (smaller == 1) return bigger;
    if (smaller == 0) return 0;
    if (smaller < 0) return -rec_multiply_prv(bigger, -smaller);

    if (smaller % 2 == 0) return rec_multiply_prv(bigger << 1, smaller / 2);

    return bigger + rec_multiply_prv(bigger, smaller - 1);
}

