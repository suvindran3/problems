#include <vector>
#include <iostream>
#include <set>
using namespace std;

void printArr(vector<int> &arr)
{
    string formattedResult = "[";
    for (size_t i = 0; i < size(arr); i++)
    {
        formattedResult += to_string(arr[i]);
        formattedResult += ", ";
    }
    formattedResult += "]";
    cout << formattedResult << "\n";
}

vector<int> bubbleSort(vector<int> &nums)
{
    int swapCount = -1;
    int i = 0, j = 1;
    while (true)
    {
        if (nums[i] > nums[j])
        {
            swapCount++;
            if (swapCount == 0)
            {
                swapCount++;
            }
            const int a = nums[i];
            nums[i] = nums[j];
            nums[j] = a;
        }
        i++;
        j++;
        if (j == size(nums))
        {
            i = 0;
            j = 1;
            if (swapCount == -1)
            {
                break;
            }
            swapCount = -1;
        }
        // printArr(nums);
    }
    return nums;
}

vector<vector<int>> threeSum(vector<int> &nums)
{
    bubbleSort(nums);
    int j, k;
    set<vector<int>> s; 
    vector<vector<int>> result = {};

    for (size_t i = 0; i < size(nums) - 2; i++)
    {
        j = i + 1;
        k = nums.size() - 1;
        while (j < k)
        {
            const int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0)
            {
                vector<int> localSum = {nums[i], nums[j], nums[k]};
                s.insert(localSum);
                j++;
                k--;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    for (auto e: s) {
        result.push_back(e);
    }
    return result;
}

int main()
{
    vector<int> nums = {0, 0, 0};
    string formattedResult = "[";
    const vector<vector<int>> result = threeSum(nums);

    for (size_t i = 0; i < size(result); i++)
    {
        formattedResult += "[";
        for (size_t j = 0; j < size(result[i]); j++)
        {
            formattedResult += to_string(result[i][j]);
            formattedResult += ", ";
        }
        formattedResult += "]";
    }
    formattedResult += "]";
    cout << "Result: " << formattedResult << "\n";
}