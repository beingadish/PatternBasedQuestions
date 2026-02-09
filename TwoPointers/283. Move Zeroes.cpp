#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        int zeroPointer = 0;
        while (zeroPointer < n && nums[zeroPointer] != 0)
            zeroPointer++;
        int j = zeroPointer + 1;
        while (j < n)
        {
            if (nums[j] != 0)
            {
                swap(nums[zeroPointer], nums[j]);
                while (nums[zeroPointer] != 0)
                    zeroPointer++;
            }
            j++;
        }
    }
};