bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
       
       vector<int>graph[N];
       int sz=prerequisites.size();
       vector<int>idg(N,0);
      // vector<int>v;
      int ans=0;
      for(int i=0;i<sz;i++)
       {
           graph[prerequisites[i].second].push_back(prerequisites[i].first);
           idg[prerequisites[i].first]++;
       }
       queue<int>q;
       for(int i=0;i<N;i++)
       {
           if(idg[i]==0)q.push(i);
       }
       
       while(!q.empty())
       {
           auto cur=q.front();
           q.pop();
         //  v.push_back(cur);
         ans++;
           for(auto &nbr:graph[cur])
           {
               idg[nbr]--;
               if(idg[nbr]==0)q.push(nbr);
           }
       }
       return ans==N;
       
	}