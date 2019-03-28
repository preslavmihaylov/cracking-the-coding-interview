#include <bits/stdc++.h>

using namespace std;

void turnToAlternatingSequence(vector<int>& nums);
bool isPeak(vector<int>& nums, int index);
bool isValley(vector<int>& nums, int index);
void swap(vector<int>& nums, int fIndex, int sIndex);
void print(vector<int>& nums);

int main(int argc, char *argv[])
{
    vector<int> nums;

    string line;
    getline(cin, line);
    istringstream iss(line);
    while (!iss.eof())
    {
        int num;
        iss >> num;

        nums.push_back(num);
    }

    turnToAlternatingSequence(nums);
    print(nums);
}

void turnToAlternatingSequence(vector<int>& nums)
{
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if ((isPeak(nums, i) && isPeak(nums, i + 1)) ||
            (isValley(nums, i) && isValley(nums, i + 1)))
        {
            swap(nums, i, i + 1);
        }
    }
}

bool isPeak(vector<int>& nums, int index)
{
    if (index == 0) return true;

    return nums[index] > nums[index - 1];
}

bool isValley(vector<int>& nums, int index)
{
    if (index == 0) return true;

    return nums[index] < nums[index - 1];
}

void swap(vector<int>& nums, int fIndex, int sIndex)
{
    int tmp = nums[fIndex];
    nums[fIndex] = nums[sIndex];
    nums[sIndex] = tmp;
}

void print(vector<int>& nums)
{
    if (nums.size() == 0) return;

    cout << nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        cout << " " << nums[i];
    }

    cout << endl;
}
