class Solution {
public:
    string removeKdigits(string num, int k) {
            string ans = "";  
       
        for (char c : num) {
           
    // make sure digits in ans are in ascending order remove one char
            while (ans.length() && ans.back() > c && k) {
                ans.pop_back();         
                k--;                   
            }
           
            // can't have leading '0'
            if (ans.length() || c != '0') {
                ans.push_back(c); 
            }  
        }
        
        // make sure remove k digits in total
        while (ans.length() && k--) {
            ans.pop_back(); 
        } 
        if(ans.empty()){
            return "0";
        }
        return ans;
    }
};