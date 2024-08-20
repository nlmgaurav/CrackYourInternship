class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
      
        int ans=0,avl=0,idx=0;
        priority_queue<int>pq;
        pq.push(startFuel);
        while(!pq.empty())
        {
            int cur=pq.top();
            pq.pop();
            avl+=cur;
            if(avl>=target)return ans;
            while(idx<stations.size() && avl>=stations[idx][0])
            {
                pq.push(stations[idx][1]);
                idx++;
                    
            }
            ans++;
            
        }
        return -1;
        
        
    }
};