#include <iostream>
#include <vector>
using namespace std;

string intToRoman(int num, int nums[], char values[])
{
    string sol;
    int remaining = num;
    vector<int> split = {};
    while (remaining > 0)
    {
        for (int i=0; i < 7; i++) {
            cout<<i<<"\n";
        }
        remaining = 0;
    }
    return sol;
}

int main()
{
    int nums[7] = {1, 5, 10, 50, 100, 500, 1000};
    char values[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    const string roman = intToRoman(20, nums, values);
    cout << "Roman number: " << roman << "\n";
}