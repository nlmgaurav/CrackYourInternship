     vector<vector<int>> minCashFlow(vector<vector<int>> &t, int n)
        {
            vector<int>frds(n+1);
            int mini=INT_MAX;
            for(int i=0;i<n;i++)
            {
               for(int j=0;j<n;j++)
               {
                   frds[i]+=t[j][i]-t[i][j];
               }
            }
            int minIndex=distance(frds.begin(),min_element(frds.begin(),frds.end()));
            int maxIndex=distance(frds.begin(),max_element(frds.begin(),frds.end()));
            vector<vector<int>>ans(n,vector<int>(n));
            while(frds[minIndex]!=frds[maxIndex] && frds[minIndex]!=0)
            {
                int mini=min(-frds[minIndex],frds[maxIndex]);
                ans[minIndex][maxIndex]+=mini;
                frds[minIndex]+=mini;
                frds[maxIndex]-=mini;
                minIndex=distance(frds.begin(),min_element(frds.begin(),frds.end()));
                maxIndex=distance(frds.begin(),max_element(frds.begin(),frds.end()));
            }
            return ans;
        }