#include <vector>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> maxLeft(n, INT_MIN);
        vector<int> maxRight(n, INT_MIN);
        maxLeft[0] = height[0];
        maxRight[n - 1] = height[n - 1];
        for (int i = 1; i < n - 1; i++)
        {
            maxLeft[i] = max(height[i], maxLeft[i - 1]);
            maxRight[n - 1 - i] = max(height[n - 1 - i], maxRight[n - i]);
        }

        int trappedWater = 0;
        for (int i = 1; i < n - 1; i++)
        {
            trappedWater += (min(maxRight[i], maxLeft[i]) - height[i]);
        }

        return trappedWater;
    }
};