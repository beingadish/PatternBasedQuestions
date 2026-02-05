#include <vector>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string newString = "";
        for (char ch : s)
        {
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            {
                newString += tolower(ch);
            }
            else if (ch >= '0' && ch <= '9')
            {
                newString += ch;
            }
        }

        int n = newString.size();
        int i = 0;
        int j = n - 1;
        while (i <= j)
        {
            if (newString[i] != newString[j])
                return false;
            i++;
            j--;
        }

        return true;
    }
};