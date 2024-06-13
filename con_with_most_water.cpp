#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int a = 0, b = height.size() - 1, water = 0;
        int leftMax = a, rightMax = b;
        while (a < b)
        {
            const int localWater = min(height[a], height[b]) * (b - a);
            if (localWater > water)
            {
                water = localWater;
                leftMax = a;
                rightMax = b;
            }
        
            if (height[a] < height[b])
            {
                a++;
            }
            else
            {
                b--;
            }
            cout << "A = " << a << " B = " << b << " Left Max = " << leftMax << " Right Max = " << rightMax << " Water = " << water << "\n";
        }

        return water;
    }
};

int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    const int solution = Solution().maxArea(height);
    cout << "Solution is: " << solution << "\n";
}
