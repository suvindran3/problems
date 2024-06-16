#include <iostream>
#include <math.h>
using namespace std;

bool is_palindrome(int num)
{
    string converted = to_string(num);
    string reversed;
    for (int i = converted.length() - 1; i >= 0; i--)
        reversed += converted[i];
    cout << "Original: " << converted << " Reversed: " << reversed << "\n";
    if (converted == reversed)
    {
        return true;
    }
    return false;
}

float solution(int n)
{
    int palindrome = 0;
    long int high = pow(10, n) - 1;
    long int low = pow(10, n - 1);
    for (int i = high; i >= low; i--)
    {
        if (i * high < palindrome) {
            break;
        }
        for (int j = high; j >= low; j--)
        {
            cout << "a = " << i << " b = " << j << "\n";
            int cal = i * j;
            if (palindrome > cal) {
                break;
            }
            if (is_palindrome(cal) && palindrome < cal)
            {

                palindrome = cal;
            }
        }
    }
    return palindrome % 1337;
}

int main()
{

    float palindrome = solution(6);
    cout << "Result: " << palindrome << "\n";
    return 0;
}