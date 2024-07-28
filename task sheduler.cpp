class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (auto ch : tasks) freq[ch - 'A']++;
        
        int max_count = *max_element(freq.begin(), freq.end());
        
        int res = (max_count-1) * (n+1);
        for (auto f : freq) if (f == max_count) res++;
        return max(res, (int)tasks.size());
        
    }
};