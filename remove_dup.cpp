#include <iostream>
#include <vector>
using namespace std;

void shiftRight(vector<int> &arr, int pos)
{
    if (pos > arr.size() - 1)
    {
        return;
    }
    for (int i = pos; i < arr.size() - 1; i++)
    {
        const int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
}

int removeDuplicates(vector<int> &nums)
{
    int dups = 0;
    long int index = 0;
    long int current = nums[0];
    int counter = 0;
    while (index < nums.size() - dups)
    {
        if (nums[index] == current && counter < 2)
        {
            counter++;
            index++;
        }
        else if (nums[index] != current)
        {
            current = nums[index];
            counter = 1;
            index++;
        }
        else
        {
            dups++;
            shiftRight(nums, index);
        }
    }
    return nums.size() - dups;
}

int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    const int dups = removeDuplicates(nums);
    // shiftRight(nums, 3);
    cout << "Modifed array: ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << "\n";
    cout << "Duplicate count: " << dups << "\n";
}
