#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int i = 0, j = n - 1;
        int maxArea = INT_MIN;
        while (i < j)
        {
            int dist = (j - i); // max @ start
            int maxHeight = min(height[i], height[j]);
            int area = (dist * maxHeight);
            maxArea = max(maxArea, area);
            if (height[i] >= height[j])
                j--;
            else
                i++;
        }
        return maxArea;
    }
};