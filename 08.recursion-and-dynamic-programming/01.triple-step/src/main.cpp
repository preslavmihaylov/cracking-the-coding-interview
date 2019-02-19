#include <bits/stdc++.h>

using namespace std;

int countPaths(int totalSteps, int currentStep, vector<int>&& memo);
int countPaths(int totalSteps, int currentStep, vector<int>& memo);

int main()
{
    int totalSteps;
    cin >> totalSteps;
    
    cout << countPaths(totalSteps, 0, vector<int>(totalSteps + 1)) << endl;
}

int countPaths(int totalSteps, int currentStep, vector<int>&& memo)
{
    return countPaths(totalSteps, currentStep, memo);
}

int countPaths(int totalSteps, int currentStep, vector<int>& memo)
{
    if (currentStep > totalSteps) return 0;

    if (currentStep == totalSteps)
    {
        memo[currentStep] = 1;
        return 1;
    }

    if (memo[currentStep] != 0)
    {
        return memo[currentStep];
    }
    
    int pathsCnt = 0;
    pathsCnt += countPaths(totalSteps, currentStep + 1, memo);
    pathsCnt += countPaths(totalSteps, currentStep + 2, memo);
    pathsCnt += countPaths(totalSteps, currentStep + 3, memo);

    memo[currentStep] = pathsCnt;

    return pathsCnt;
}

