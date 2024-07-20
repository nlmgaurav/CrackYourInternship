class Solution {
public:
    int maxArea(vector<int>& h) {
        int n=h.size();
        int ans=0;
        int l=0,r=n-1;
        while(l<r)
        {
            int w=r-l;
            int ht=min(h[l],h[r]);
            int area=w*ht;
            ans=max(ans,area);
            if(h[l]<h[r])l++;
            else if(h[l]>h[r])r--;
            else l++,r--;
        }
        return ans;
    }
};