class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>ms,mt;
        for(int i=0;i<t.size();i++)mt[t[i]]++;

         int req=0,left=0,start_idx=-1,min_len=INT_MAX;

         for(int right=0;right<s.size();right++)
         {
             ms[s[right]]++;
             // means this character in t so required hai esliye req++
             if(ms[s[right]]<=mt[s[right]])req++;
             // required size milchuka hai but there might 
             // be some charcter greater than as required so decreasing
             if(req==t.size()){
                 while(ms[s[left]]>mt[s[left]]){
                     ms[s[left]]--;
                     left++;
                 }
                 if(min_len>(right-left+1)){
                     min_len=right-left+1;
                     start_idx=left;
                 }
             }
         }
  if(start_idx==-1)return "";
  return s.substr(start_idx,min_len);

    }
};