  long long ans=LLONG_MAX;
      if(n==0 || m==0)return -1;
      
      if(m>n)return -1;
      sort(a.begin(),a.end());
      for(int i=0;i+m-1<n;i++)
      {
          long long diff=a[i+m-1]-a[i];
          ans=min(ans,diff);
      }
      
         return ans;