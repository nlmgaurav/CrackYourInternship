	int minSwaps(vector<int>&nums)
	{
         int swaps=0;
         vector<pair<int,int>>v;
         for(int i=0;i<nums.size();i++)
         {
             v.push_back({nums[i],i});
         }
         sort(v.begin(),v.end());
         for(int i=0;i<nums.size();i++)
         {
             pair<int,int>p=v[i];
             int value=p.first;
             int idx=p.second;
             if(idx!=i)
             {
                 swaps++;
                 swap(v[idx],v[i]);
                 i--;
             }
         }
	   return swaps; 
	}