#include <iostream>
#include <set>
#include <vector>
using namespace std;

void printArr(vector<char> &arr)
{
    string formattedResult = "[";
    for (auto s : arr)
    {
        formattedResult += s;
        formattedResult += ", ";
    }
    formattedResult += "]";
    cout << formattedResult << "\n";
}

bool checkDupes(vector<char> arr)
{
    set<char> holder = {};
    for (auto s : arr)
    {
        holder.insert(s);
    }
    return arr.size() == holder.size();
}

int lengthOfLongestSubstring(string s)
{
    if (s.size() == 0)
    {
        return 0;
    }
    else if (s.size() == 1)
    {
        return 1;
    }
    int a = 0, b = 1;
    int longest = 1;
    vector<char> holder = {};
    holder.push_back(s.at(a));
    while (true)
    {
        holder.push_back(s.at(b));
        printArr(holder);
        if (checkDupes(holder))
        {
            cout << "Longest: " << longest << "\n";
            longest = holder.size();
            b++;
        }
        else
        {
            holder.erase(holder.begin());
            a++;
            b++;
        }
        if (b == s.size())
        {
            break;
        }
    }
    return longest;
}

int main()
{
    string input;
    cout << "Enter the input: ";
    cin >> input;
    const int result = lengthOfLongestSubstring(input);
    cout << "Result: " << result << "\n";
}