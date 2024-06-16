#include <iostream>
#include <vector>
using namespace std;

void assignCadies() {}

int candy(vector<int> &ratings)
{
    int candies = ratings.size();
    int lastAssignedCandy = 1;
    for (int i = 0; i < ratings.size(); i++)
    {
        bool condtion1 = false, condition2 = false; 
       if (i > 0) {
        if (ratings[i - 1] < ratings[i]) {
            condtion1 = true;
        }
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
