class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> prefixSum(nums.size() + 1);
        for (int i = 0; i < nums.size(); ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        set<long long> sortedSums = {0}; // Include 0 for subarrays starting from index 0
        for (long long sum : prefixSum) {
            sortedSums.insert(sum);
            sortedSums.insert(sum - lower);
            sortedSums.insert(sum - upper);
        }
        
        // Create a compressed map for faster index lookup
        unordered_map<long long, int> compressed;
        int index = 0;
        for (long long num : sortedSums) {
            compressed[num] = index++;
        }
        
        vector<int> segmentTree(4 * index, 0);
        
        int count = 0;
        for (long long sum : prefixSum) {
            int left = compressed[sum - upper];
            int right = compressed[sum - lower];
            count += query(segmentTree, 1, 0, index - 1, left, right);
            update(segmentTree, 1, 0, index - 1, compressed[sum]);
        }
        
        return count;
    }
    
    void update(vector<int>& segmentTree, int node, int start, int end, int idx) {
        if (start == end) {
            segmentTree[node]++;
        } else {
            int mid = start + (end - start) / 2;
            if (idx <= mid) {
                update(segmentTree, 2 * node, start, mid, idx);
            } else {
                update(segmentTree, 2 * node + 1, mid + 1, end, idx);
            }
            segmentTree[node] = segmentTree[2 * node] + segmentTree[2 * node + 1];
        }
    }
    
    int query(vector<int>& segmentTree, int node, int start, int end, int left, int right) {
        if (left > end || right < start) {
            return 0;
        }
        if (left <= start && right >= end) {
            return segmentTree[node];
        }
        int mid = start + (end - start) / 2;
        return query(segmentTree, 2 * node, start, mid, left, right) +
               query(segmentTree, 2 * node + 1, mid + 1, end, left, right);
    }
};