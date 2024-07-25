class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
              int n=s.length();
        int h=p.length();
        
        //window does not exists when h>n
        //-1 case:
        
        if(h>n){
            return "-1";
        }
        
        //1)what we can do is store occurences of p in one map first and then of s in another
        //when all elements of p comes in s, wait and try to decrease window size
        //start trimming characters from the beginning
        //check removing elements that p elements are still there in substring or not
        //start index would tell us staring point
        //We use two pointer tchnique
        
        //store occurences in hash tables
        int sh[26]={0};
        int ph[26]={0};
        
        //Step 1)
        for(int i=0;i<h;i++){
            ph[p[i]-'a']++;
        }
        
        //making pointers
        int c=0;
        int start=0, sind=-1,len=0,minlen=INT_MAX;
        
        for(int i=0;i<s.length();i++){
            sh[s[i]-'a']++;
            
            if(ph[s[i]-'a']!=0 && sh[s[i]-'a']<=ph[s[i]-'a']){
                //if count of current character in string s is equal to or less than in string p, we increase current len
                c++;
            }
            
            if(c==h){
                //means one substring is found
                
                //trim from start
                while(sh[s[start]-'a']>ph[s[start]-'a'] || ph[s[start]-'a']==0){
                    if(sh[s[start]-'a']>ph[s[start]-'a']){
                        sh[s[start]-'a']--;
                    }
                    start++; //move to next element
                }
                
                len=i-start+1;
                
                if(len<minlen){
                    sind=start;
                    minlen=len;
                }
            }
        }
        
        if(sind==-1){
            return "-1";
        }
        
        else return s.substr(sind,minlen); 
    }
};