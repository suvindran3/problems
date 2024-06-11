#include <iostream>
#include <vector>
using namespace std;

int calFactors(int n, int k)
{
    if (k == 1)
    {
        return 1;
    }
    int found = 1;
    int cursor = 2;
    while (cursor <= n)
    {
        if (n % cursor == 0)
        {
            found += 1;
        }
        if (k == found)
        {
            return cursor;
        }
        cursor = cursor + 1;
    }
    return -1;
}

int main()
{
    int factor = calFactors(12, 3);
    cout << "Kth Factor of n: " << factor;
    cout << "\n";
    return 0;
}
