#include <vector>
#include <iostream>
using namespace std;

int arrSum(vector<int> &arr, int start, int end)
{
    int sum = 0;
    for (size_t i = start; i < end + 1; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int minSubArrayLen(int target, vector<int> &nums)
{
    int length = 0;
    int a = 0;
    float b = -1;
    int sum = 0;
    while (a < size(nums))
    {

        while (sum < target && b < size(nums))
        {
            b++;
            cout << "A = " << a << " B = " << b << "\n";
            sum += nums[b];
        }
        const int localLength = (b - a) + 1;
        if ((localLength < length || length == 0) && sum >= target)
        {
            length = localLength;
        }
        if (a == b)
        {
            b++;
            a = b;
        }
        else
        {
            a = b;
            b = a - 1;
        }
        sum = 0;
    }
    return length;
}

int main()
{

    vector<int> nums = {2,3,1,2,4,3};
    const int target = 7;
    const int result = minSubArrayLen(target, nums);
    cout << "The minimal sub array size is: " << result << "\n";
}
