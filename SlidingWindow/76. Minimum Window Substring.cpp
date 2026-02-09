#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.size();             // total size
        int countRequired = t.size(); // kitna chahiye
        if (countRequired >
            n) // agr jayde chahiye, possible nahi return kar jao
            return "";
        unordered_map<char, int>
            mp; // store krenge frequency (kon kitni bar dikha)
        for (char ch : t)
        {
            mp[ch]++;
        }

        // Safar par nikalte hai
        int i = 0;
        int j = 0;
        int minWindowSize = INT_MAX; // starting me max size lenge
        int start_i = 0;

        // j nikla safar par
        while (j < n)
        {

            char ch = s[j];
            // count girate jao agr > 0 hai to
            if (mp[ch] > 0)
            {
                countRequired--;
            }

            // yeh to minus hmesha hota rhega jaise jaise visit krenge
            mp[ch]--;

            // agar sab mil gya to shrink krne ki koshish krenge jab tk kuch kho
            // na jaye
            while (countRequired == 0)
            {
                int currWindowSize = j - i + 1; // current window ka size nikalo
                if (currWindowSize < minWindowSize)
                {                                   // agr kam milgya
                    minWindowSize = currWindowSize; // to kam wala store krdo
                    start_i = i;                    // kaha se mila woh bhi store krlo
                }
                mp[s[i]]++; // fir uski value bdha do, qki ab woh window me nahi
                            // rhega
                if (mp[s[i]] > 0)
                {                    // agr uska size > 0 hogya, matlab jo
                                     // chahiye tha uska count bdh gya
                    countRequired++; // count required bdhao
                }
                i++; // i to safar me chal raha tha to bdhega
            }
            j++; // j bhi apne safar me bdhega
        }

        return (minWindowSize == INT_MAX)
                   ? "" // agr kabhi window chhoti ni hui, matlab kuch ni mila
                   : s.substr(start_i,
                              minWindowSize); // agar mil gya, to string banao
                                              // ar return krdo
    }
};