class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        //we will firstly find sum of first window(size==k) sum
        //then we will keep removing one ele from cur window and add one 
        //element from whichever sum is greater we will return that
        
        int n=cp.size();
        int ans=0;
        for(int i=0;i<k;i++)ans+=cp[i];
        int cur=ans;
        for(int i=k-1;i>=0;i--)
        {
            cur-=cp[i];
            cur+=cp[cp.size()-k+i];
            ans=max(ans,cur);
        }
        return ans;
    }
};