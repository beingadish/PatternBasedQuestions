#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        if (n == 0 || n == 1)
            return n;
        int len = 0;
        int i = 0;
        int j = 1;
        vector<int> mp(255, -1);
        mp[s[0]] = 0;
        while (j < n)
        {
            if (mp[s[j]] != -1 && mp[s[j]] >= i)
            { // Seen
                len = max(len, (j - i));
                i = mp[s[j]] + 1;
            }
            mp[s[j]] = j;
            j++;
        }

        len = max(len, j - i);

        return len;
    }
};