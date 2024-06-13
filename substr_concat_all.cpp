#include <iostream>
#include <vector>
#include <set>
using namespace std;

void printNumArr(vector<int> &arr)
{
    string formattedResult = "[";
    for (auto s : arr)
    {
        formattedResult += to_string(s);
        formattedResult += ", ";
    }
    formattedResult += "]";
    cout << formattedResult << "\n";
}

void printCharArr(vector<char> &arr)
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

void printStrArr(vector<string> &arr, bool newLine)
{
    string formattedResult = "[";
    for (auto s : arr)
    {
        formattedResult += s;
        formattedResult += ", ";
    }
    formattedResult += "]";
    cout << formattedResult;
    if (newLine)
    {
        cout << "\n";
    }
}

void printCharSet(set<char> &arr)
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

class Solution
{
public:
    vector<string> splitArrByInterval(string s, int interval)
    {
        vector<string> split = {};
        int a = 0;
        while (a <= s.size() - interval)
        {
            split.push_back(s.substr(a, interval));
            a += interval;
        }
        return split;
    }

    int findElementInArr(vector<string> &arr, string element) {
        for (size_t i = 0; i < arr.size(); i++)
        {
            if (arr.at(i) == element) {
                return i;
            }
        }
        return -1;
        
    }

    bool compareArr(vector<string> &arr1, vector<string> arr2)
    {
        vector<string> arr2Copy;
        for (size_t i = 0; i < arr1.size(); i++)
        {
            const int index = findElementInArr(arr2, arr1.at(i));
            if (index == -1)
            {
                return false;
            }
            else {
                arr2.erase(next(arr2.begin(), index));
            }
        }
        return true;
    }

    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> sol = {};
        if (words.size() == 0)
        {
            return sol;
        }
        const int windowSize = words.at(0).size() * words.size();
        // cout << "Window size: " << windowSize << "\n";
        set<char> starters = {};
        for (auto w : words)
        {
            starters.insert(w.at(0));
        }
        // printCharSet(starters);
        int a = 0;
        int b = windowSize;
        while (b <= s.size())
        {
            // cout << "A = " << a << " B = " << b << "\n";
            const string subStr = s.substr(a, windowSize);
            // cout<<"Sub string: "<<subStr<<"\n";
            if (starters.count(subStr.at(0)) > 0)
            {
                vector<string> split = splitArrByInterval(subStr, words.at(0).size());
                // cout << "Comparing: ";
                // printStrArr(split, false);
                // cout<< " & ";
                // printStrArr(words, true);
                const bool areSame = compareArr(split, words);
                if (areSame)
                {
                    sol.push_back(a);
                }
            }
            a++;
            b++;
        }
        return sol;
    }
};

int main()
{
    const string s = "wordgoodgoodgoodbestword";
    vector<string> words = {"word","good","best","good"};
    vector<int> sol = Solution().findSubstring(s, words);
    cout << "Solution: ";
    printNumArr(sol);
}