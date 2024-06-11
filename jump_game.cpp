#include <iostream>
#include <vector>
using namespace std;

int isSequential(vector<int> nums, int start)
{
    for (int i = start; i < nums.size() - 1; i++)
    {
        if (nums[i] - nums[i + 1] == 1)
        {
            if (nums[i + 1] == 0)
            {
                return i + 2;
            }
        }
        else
        {
            return -1;
        }
    }
    return -1;
}

bool canJump(vector<int> &nums)
{
    if (nums.size() == 1)
        return true;
    if (nums[0] == 0)
    {
        return false;
    }
    int i = 0;
    while (i < nums.size() - 1)
    {

        if (nums[i] + i >= nums.size() - 1)
        {
            return true;
        }
        cout << "Could not reach " << nums.size() << " from index " << i << " with value " << nums[i] << "\n";
        const int isDecreasing = isSequential(nums, i + 1);
        if (isDecreasing != -1)
        {
            if (isDecreasing == nums.size())
            {
                return true;
            }
            if (isDecreasing == nums.size() - 1)
            {
                return false;
            }
            if (nums[isDecreasing] == 0 || nums[i] < isDecreasing)
            {
                return false;
            }
            i = isDecreasing;
        }
        if (isDecreasing + 1 == nums.size() -1 ) {
            continue;
        }

        for (int j = 1; j <= nums[i]; j++)
        {
            if (nums[j + i] == 0 && j == nums[i])
            {
                cout << "Zero value error\n";
                return false;
            }
            if (nums[j + i] != 0)
            {
                cout << "Found non-zero value " << nums[i + j] << " at " << j + i << " from " << i << "\n";
                i += j;
                break;
            }
            cout << "Next value is zero so incrementing from " << i + j << "\n";
        }
    }
    return false;
}

int main()
{
    vector<int> nums = {4,2,0,0,1,1,4,4,4,0,4,0};
    bool isPossible = canJump(nums);
    cout << "We can jump: " << isPossible << "\n";
    // int d = isSequential(nums, 1);
    // cout<<d;
}