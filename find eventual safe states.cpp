class Solution {
public:
// anyone who are part of cycle wont be safe node
// anyone who leads to cycle wont he safe node

     bool dfs(int node,vector<vector<int>>& graph,vector<int>& vis, vector<int>& pathvis,vector<int> & safe){
         vis[node]=1;
         pathvis[node]=1;
          for(auto it : graph[node]){
              if(vis[it]!=1){   //Unvisited node 
                   if(dfs(it,graph,vis,pathvis,safe)==true){ // Cycle detected
                         safe[it]=0; 
                        return true;
                   }
              }
              else if(pathvis[it]==1){ // Should not unmark from pathvis
                         safe[it]=0;                         //Marked in both means is in current cycle
                        return true;
              }
          }
         safe[node]=1;   // Marked as safe
         pathvis[node]=0;  //Unmarked from pathvis
         return false;   // No cycle detected
     }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n+1,0);  // Stores visited node
        vector<int> pathvis(n+1,0); // Visited in the current dfs
        vector<int> safe(n+1,0); // Safe nodes marked in it
        vector<int> safenode; // Final Answer computed after traversing safe
        //Traversing the graph vector for all nodes
        for(int i=0;i<n;i++){
             if(vis[i]!=1){
                 dfs(i,graph,vis,pathvis,safe);
             }
        }
        //Traversing the safe vector to find safe nodes
        for(int i=0;i<n;i++){
            if(safe[i]==1){
                safenode.push_back(i);
            }
        }
        return safenode;
    }
};