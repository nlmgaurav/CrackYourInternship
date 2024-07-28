class Solution {
public:
    
    int bfss(vector<int> g[], int node,int time,int change )
    {
      vector<int>vis(node+1,0);
      vector<int>dist(node+1,0);
      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>qq; //min heap
      qq.push({0,0});
        bool chk = false;
      while(qq.size()>0)
      {
          auto it = qq.top();
          qq.pop();
          auto tim = it.first;
          auto vertex = it.second;
          int chkk = tim/change;
          if(chkk%2!=0)
          {
              // red
              tim = ((change*(chkk+1)) );
          }
          for(auto pp: g[vertex])
          {
              if(dist[pp]!= tim+time && vis[pp]<2)
              {
                  qq.push({tim+time,pp});
                  vis[pp]++;
                  dist[pp] = tim+time;
                  if(pp==node && chk==false)
                  {  
                      chk = true;
                  }
                 else if(pp==node && chk == true)
                  {
                      return tim+time;
                  }
              }
          }  
      }
           
        return -1;
    }
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) 
    
    {
         vector<int>g[n];
        for(int i=0;i<edges.size();i++)
        {
            auto it1 =  edges[i][0];
            auto it2 = edges[i][1];
            g[it1-1].push_back(it2-1);
            g[it2-1].push_back(it1-1);
        }
        int ans = bfss(g,n-1,time,change);
        return ans;
        
    }
};