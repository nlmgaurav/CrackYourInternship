 vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
               unordered_map<string,vector<string>> m; 

        
        for(int i=0;i<n;i++) {
            string x,t=contact[i];
            for(int j=0;j<t.size();j++) {
                x+=t[j];
                bool c=0;
                for(auto it:m[x])  
                /* TO REMOVE DUPLICATES, CHECKING WHETHER STRING T EXISTS
                     IN MAP OR NOT*/
                
                if(it==t) {c=1; break;}
                if(!c) m[x].push_back(t);
            }
        }
        string x;
        vector<vector<string>> ans;
        for(auto i:s) {
            x+=i;
            vector<string> res;
            if(m[x].empty())  /* IF PREFIX VALUE DOESN'T EXISTS WE NEED "0" RIGHT */
                res.push_back({"0"});
            else {
                for(auto j:m[x]) res.push_back(j);
                sort(res.begin(),res.end());  /* TO GET BACK LEXOGRAPHICALLY SMALLER */
            }
            ans.push_back(res);
        }
        return ans;
    }