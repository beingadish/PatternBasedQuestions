#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 && i < n && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n - 2; j++)
            {
                if (j > i + 1 && j < n && nums[j] == nums[j - 1])
                    continue;
                int k = j + 1;
                unordered_set<long long> seen;
                while (k < n)
                {
                    long long remain =
                        (long long)target - nums[i] - nums[j] - nums[k];
                    if (seen.count(remain))
                    {
                        ans.push_back({nums[i], nums[j], (int)remain, nums[k]});
                        seen.insert(nums[k]);
                        k++;
                        while (k < n && nums[k] == nums[k - 1])
                            k++;
                    }
                    else
                    {
                        seen.insert(nums[k]);
                        k++;
                    }
                }
            }
        }

        return ans;
    }
};