#include <vector>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void printStrArr(vector<string> &arr, bool newLine)
{
    string formattedResult = "[\n";
    for (auto s : arr)
    {
        formattedResult += s;
        formattedResult += ",\n";
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
    string genSpace(int length)
    {
        string space = "";
        while (space.length() != length)
        {
            space += " ";
        }
        return space;
    }

    string joinArr(vector<string> &words)
    {
        string joined = "";
        for (auto w : words)
        {
            joined += w;
        }
        return joined;
    }

    void padSpaceEqually(vector<string> &words, int space, bool leftJustify)
    {
        if (words.size() == 1) {
            words[0] = words[0] + genSpace(space);
            return;
        }
        if (leftJustify) {
            words[words.size() - 1] = words[words.size() - 1] + genSpace(space);
            return;
        }
        int count = words.size() - 1;
        int spaceLeft = space;

        for (size_t i = 0; i < words.size() - 1; i++)
        {
            int spaceLength = 0;

            if (spaceLeft % count == 0)
            {
                spaceLength = spaceLeft / count;
            }
            else
            {
                spaceLength = floor(spaceLeft / count) + 1;
            }
            words[i] = words[i] + genSpace(spaceLength);
            spaceLeft -= spaceLength;
            count--;
        }
    }

    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> sol = {};
        int i = 0;
        string concat = "";
        vector<string> concatArr = {};
        while (i < words.size())
        {
            if (concat.length() + words.at(i).length() <= maxWidth)
            {
                const string word = words.at(i) + " ";
                concatArr.push_back(word);
                concat += word;
                i++;
            }
            else
            {   
                concat = concat.substr(0, concat.length() - 1);
                concatArr[concatArr.size() - 1] = words.at(i - 1);
                if (concat.length() != maxWidth)
                {
                    padSpaceEqually(concatArr, maxWidth - concat.length(), false);
                }
                sol.push_back(joinArr(concatArr));
                concat = "";
                concatArr = {};
            }
        }
        if (concat.length() != 0) {
            concat = concat.substr(0, concat.length() - 1);
                concatArr[concatArr.size() - 1] = words.at(i - 1);
                if (concat.length() != maxWidth)
                {
                    padSpaceEqually(concatArr, maxWidth - concat.length(), true);
                }
                sol.push_back(joinArr(concatArr));
                concat = "";
                concatArr = {};
        }
        return sol;
    }
};

int main()
{
    vector<string> words = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    const int maxWidth = 20;
    vector<string> solution = Solution().fullJustify(words, maxWidth);
    printStrArr(solution, true);
}