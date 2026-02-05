#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 0);
        int i = n - 1;
        int L = 0, R = n - 1;
        while (L <= R)
        {
            int LSQR = pow(abs(nums[L]), 2);
            int RSQR = pow(abs(nums[R]), 2);
            if (LSQR >= RSQR)
            {
                ans[i--] = LSQR;
                L++;
            }
            else
            {
                ans[i--] = RSQR;
                R--;
            }
        }

        return ans;
    }
};