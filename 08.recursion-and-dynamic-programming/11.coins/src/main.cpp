#include <bits/stdc++.h>

using namespace std;

void waysToGet(vector<int>&& currentCoins, int coinsLeft, int coinIndex);
void waysToGet(vector<int>& currentCoins, int coinsLeft, int coinIndex);

vector<int> coins = { 25, 10, 5, 1 };

int main()
{
    int n;
    cin >> n;

    waysToGet(vector<int>(), n, 0);
}

void waysToGet(vector<int>&& currentCoins, int coinsLeft, int coinIndex)
{
    waysToGet(currentCoins, coinsLeft, coinIndex);
}

void waysToGet(vector<int>& currentCoins, int coinsLeft, int coinIndex)
{
    if (coinsLeft < 0) return;
    else if (coinsLeft == 0) 
    {
        for (int i = 0; i < currentCoins.size(); i++)
        {
            int coin = currentCoins[i];

            cout << coin;
            if (i < currentCoins.size() - 1)
            {
                cout << " ";
            }
        }

        cout << endl;

        return;
    }

    for (int i = coinIndex; i < coins.size(); i++)
    {
        int coin = coins[i];

        currentCoins.push_back(coin);
        waysToGet(currentCoins, coinsLeft - coin, i);
        currentCoins.erase(currentCoins.begin() + currentCoins.size() - 1);
    }
}

