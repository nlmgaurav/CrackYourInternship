class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int>> st;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                set<long long> hash;
                for (int k = j + 1; k < n; k++) {
                    long long remaining = (long long)target - (long long)nums[i] - (long long)nums[j] - (long long)nums[k];
                    if (hash.find(remaining) != hash.end()) {
                        st.insert({nums[i], nums[j], (int)remaining, nums[k]});
                    }
                    hash.insert(nums[k]);
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }

};