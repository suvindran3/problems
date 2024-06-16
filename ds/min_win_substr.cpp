#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool checkSubStr(string main, string &sub)
    {
        int i = 0;
        while (i < sub.size())
        {
            if (main.find(sub.at(i)) == string::npos)
            {
                return false;
            }
            i++;
        }
        return true;
    }

    string minWindow(string s, string t)
    {
        int a = 0;
        int b = t.size();
        int x = 0;
        int y = s.size() + 1;
        if (t.size() > s.size())
        {
            return "";
        }
        if (t.size() == s.size() && !checkSubStr(t, s))
        {
            return "";
        }
        while (b <= s.size())
        {
            string sub = s.substr(a, b - a);
            const bool containsSub = checkSubStr(t, sub);
            cout << "Sub string: " << sub << "\nMain string: " << t << "\nResult: " << containsSub << "\n\n";
            if (containsSub)
            {
                if (y - x > b - a)
                {
                    x = a;
                    y = b;
                }
                a++;
            }
            else
            {
                b++;
                if (b - a > y - x && a >= t.size())
                {
                    a++;
                }
            }
        }
        cout << "A = " << x << " B = " << y << "\n";
        if (y == s.size() + 1)
        {
            return "";
        }
        return s.substr(x, y);
    }
};

int main()
{
    string s;
    string t;
    cout << "Enter value of s: ";
    cin >> s;
    cout << "Enter value of t: ";
    cin >> t;
    const string sol = Solution().minWindow(s, t);
    cout << "Solution: " << sol << "\n";
}