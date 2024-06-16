#include <vector>
#include <string>
#include <iostream>
using namespace std;

void printNumArr(vector<int> &arr, bool newLine)
{
    string formattedResult = "[";
    for (auto s : arr)
    {
        formattedResult += to_string(s);
        formattedResult += ", ";
    }
    formattedResult += "]";
    cout << formattedResult;
    if (newLine)
    {
        cout << "\n";
    }
}

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int a = 0, b = numbers.size() - 1;
        while (a < b)
        {
            const int total = numbers[a] + numbers[b];
            if (total == target)
            {
                return {a + 1, b + 1};
            }
            if (total > target)
            {
                b--;
            }
            else
            {
                a++;
            }
        }
        return {};
    }
};

int main()
{
    vector<int> numbers = {2, 3, 4};
    const int target = 6;
    vector<int> sol = Solution().twoSum(numbers, target);
    cout << "Solution: ";
    printNumArr(sol, true);
}