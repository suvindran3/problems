#include <iostream>
#include <vector>
using namespace std;

void printNumArr(vector<int> &nums)
{
    cout << "Rotated array: [ ";
    for (auto ele : nums)
    {
        cout << ele << ", ";
    }
    cout << "]"
         << "\n";
}

void rotate(vector<int> &nums, int k)
{

    if (k == nums.size() || k % nums.size() == 0 || nums.size() == 1)
        return;

    k = k > nums.size() ? k % nums.size() : k;
    int index = 0;
    int swap = k;
    int totalSwap = 0;

    while (totalSwap < nums.size())
    {

        const int temp = nums[index];
        nums[index] = nums[index + swap];
        nums[index + swap] = temp;
        totalSwap++;
        swap += k;
        if (swap >= nums.size())
        {
            swap = swap - nums.size();
        }
        if (swap == 0)
        {
            index++;
        }
    }
}

int main()
{
    vector<int> nums = {1, 2};
    rotate(nums, 1);
    printNumArr(nums);
}