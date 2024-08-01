class Solution {
public:
      void helper(vector<int>&v,int index,int &count)
    {
        if(index==v.size())
        {
            count++;
        }
        for(int i=index;i<v.size();i++)
        {
            swap(v[i],v[index]);
            if(v[index]%(index+1)==0 || (index+1)%v[index]==0)
            {
                helper(v,index+1,count);
            }
            swap(v[i],v[index]);
        }
    }
    int countArrangement(int n) 
    {
        int count=0;
        vector<int>v;
        for(int i=1;i<=n;i++)
        {
            v.push_back(i);
        }
        helper(v,0,count);
        return count;
    }
};