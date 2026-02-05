#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0, j = i + 1;
        while (j < n)
        {

            while (j < n && nums[i] == nums[j])
            {
                j++;
            }

            if (j != n && nums[i] != nums[j])
            {
                nums[++i] = nums[j];
            }
        }
        return i + 1;
    }
};