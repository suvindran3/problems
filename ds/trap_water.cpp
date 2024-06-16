#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int> &height)
{
    if (height.size() < 3)
    {
        return 0;
    }
    if (height.size() == 3)
    {
        return max(0, min(height[0], height.back()) - height[1]);
    }
    int startPos = -1;
    int startHeight = -1;
    int lastHeight = -1;
    int lastPos = -1;
    int amount = 0;
    int i = 0;
    while (i < height.size())
    {
        if (startHeight > -1)
        {
            if (height[i] >= startHeight)
            {
                startPos = i;
                startHeight = height[i];
                lastHeight = -1;
                lastPos = -1;
            }
            else
            {
                if (lastHeight <= height[i] || height[i] > height[i - 1])
                {
                    lastHeight = height[i];
                    lastPos = i;
                }
                amount += startHeight - height[i];
            }
        }
        else
        {
            if (height[i] > 0)
            {
                startHeight = height[i];
                startPos = i;
            }
        }
        i++;
    }
    if (lastHeight != -1)
    {
        for (int i = height.size() - 1; i > startPos; i--)
        {
            if (i >= lastPos)
            {
                amount -= (startHeight - height[i]);
            }
            else
            {
                if (lastHeight < height[i])
                {
                    lastHeight = height[i];
                }
                const int balance = max((startHeight - height[i]) - max((lastHeight - height[i]), 0), 0);
                amount -= balance;
            }
        }
    }
    return amount;
}

int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int amount = trap(height);
    cout << "Trapped water: " << amount << "\n";
}