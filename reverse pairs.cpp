class Solution {
public:
    int countAndMerge(vector<int>& nums, int l, int m, int r){
        int i = l, j = m + 1, countRevPairs = 0;
        vector<int> temp;
        
        // Count reverse pair process - O(N)
        while(i <= m && j <= r){
            if(nums[i] > (double) 2 * nums[j]){
                countRevPairs += (m - i + 1);
                j++;
            }
            else
                i++;
        }
        
        // merge process of mergeSort - O(N)
        i = l, j = m + 1;
        
        while(i <= m && j <= r){
            if(nums[i] <= nums[j])
                temp.emplace_back(nums[i++]);
            else
                temp.emplace_back(nums[j++]);
        }
        
        while(i <= m)
            temp.emplace_back(nums[i++]);
        while(j <= r)
            temp.emplace_back(nums[j++]);
        
        for(int k = l;k <= r;++k)
            nums[k] = temp[k - l];
        
        return countRevPairs;
    }
    
    int reversePairsUtil(vector<int>& nums, int l, int r){
        int countRevPairs = 0;
        if(l < r){
            int m = (l + r) / 2;
            countRevPairs += reversePairsUtil(nums, l, m);
            countRevPairs += reversePairsUtil(nums, m + 1, r);
            countRevPairs += countAndMerge(nums, l, m, r);
        }
        return countRevPairs;
    }
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return reversePairsUtil(nums, 0, n - 1);
    }
};