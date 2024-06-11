#include <iostream>
#include <vector>
using namespace std;

void assignCadies() {}

int candy(vector<int> &ratings)
{
    int candies = ratings[0] < ratings[1]? 1 : 2;
    int lastAssignedCandy = 1;
    for (int i = 1; i < ratings.size(); i++)
    {
        if (ratings[i - 1] != ratings[i])
        {
            if ((i == 1 && ratings[i - 1] < ratings[i]) || (i > 1 && ratings[i - 1] < ratings[i]))
            {
                lastAssignedCandy++;
            }
            cout << ratings[i - 1] << " & " << ratings[i] << " are not equal so +" << lastAssignedCandy << "\n";
            candies += lastAssignedCandy;
        }
        else
        {
            cout << ratings[i - 1] << " & " << ratings[i] << " are equal so +1\n";
            candies++;
            lastAssignedCandy = 1;
        }
    }
    return candies;
}

int main()
{
    vector<int> nums = {1,3,2,2,1};
    const int candyRequired = candy(nums);
    cout << "Number of candies required: " << candyRequired << "\n";
}
