class Solution {
private:
    vector<vector<int>>memo;
public:


    bool canCross(vector<int>& stones) {
        int n=stones.size();
        unordered_map<int,int>mp;
        memo = vector<vector<int>>(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
            mp[stones[i]]=i;
        return solve(0,1,stones,mp);
    }


    bool solve(int i, int next, vector<int>&stones, unordered_map<int,int>&mp){
        if(i==stones.size()-1)
            return true;
        // check if we can go to any next stone by taking next steps?
        int nex = stones[i]+next;
		// check if we have already gone from **ith** stone by taking **next** number of jumps
        if(memo[i][next]!=-1)
            return memo[i][next];
        if(!mp.count(nex) || mp[nex]==i)
            return false;
		// update memo[i][next] also
        return memo[i][next] = solve(mp[nex],next-1,stones,mp) || solve(mp[nex],next,stones,mp) || solve(mp[nex],next+1,stones,mp);
    }
};