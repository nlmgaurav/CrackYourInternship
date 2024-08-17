class Solution {
public:
// in out dp

vector<vector<int>>tree;
vector<int>indp,outdp,subTree;
int N;

void indfs(int src,int par)
{
    subTree[src]=1;
    for(auto child:tree[src])
    {
        if(child!=par)
        {
            indfs(child,src);
            subTree[src]+=subTree[child];
            indp[src]+=indp[child]+subTree[child];
        }
    }
}

void outdfs(int src,int par)
{
    if(par==-1)outdp[src]=0;
    else
    {
        outdp[src]=outdp[par]+indp[par]-(indp[src]+subTree[src])+(N-subTree[src]);
    }
    for(auto child:tree[src])
    {
        if(child!=par)outdfs(child,src);
    }
}
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N=n;
        indp.resize(n+1);
        outdp.resize(n+1);
        subTree.resize(n+1);
        tree.resize(n+1);
        
        for(auto & e: edges){
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        
      indfs(0,-1);
      outdfs(0,-1);
      vector<int>ans(n);
      for(int i=0;i<n;i++)ans[i]=indp[i]+outdp[i];
      return ans;
    }
};