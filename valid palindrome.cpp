class Solution {
private:
    bool ispal(string s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;  
            }
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int start = 0;
        int end = s.length()-1;
        while(start<=end){
            if(s[start]==s[end]){
                start++;end--;
            }
            else{
                return ispal(s,start+1,end) || ispal(s,start,end-1);
            }
        }
        return true;
    }
};