class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
             int curr_petrol=0,start=0,avliable =0;
       int n=cost.size();
       for(int i = 0;i<n;i++){
           curr_petrol+= gas[i]-cost[i];
           avliable+=gas[i]-cost[i];
           if(avliable<0) {
               start = i+1;

               avliable= 0;
           }
       }
       return curr_petrol<0 ? -1:start;
    }
};