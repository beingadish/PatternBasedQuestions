// Bad Code
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); // Because sorting does not affects Triplets
        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue; // Skips the duplicate values (same together)
            unordered_set<int> seen;
            for (int j = i + 1; j < n; j++)
            {
                int target = -nums[i] - nums[j];
                if (seen.count(target) >= 1)
                { // Valid Triplet Found
                    ans.push_back({nums[i], target, nums[j]});

                    while (j + 1 < n && nums[j] == nums[j + 1])
                        j++; // Skips the duplicate values (same together)
                }
                seen.insert(nums[j]);
            }
        }

        return ans;
    }
};

// Good Code (Two Pointers)
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),
             nums.end()); // Because sorting does not affects Triplets
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum > 0)
                {
                    k--;
                }
                else if (sum < 0)
                {
                    j++;
                }
                else
                {
                    ans.push_back({nums[i], nums[j++], nums[k--]});
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }
        return ans;
    }
};