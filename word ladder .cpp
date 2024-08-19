class Solution {
public:
    int ladderLength(string startWord, string targetWord, vector<string>& wordList) {
          set<string> st;

        for(auto it: wordList){

            st.insert(it);

        }

        queue<pair<string,int>> q;

        q.push({startWord,0});

        st.erase(startWord);

        while(!q.empty()){

            string s = q.front().first;

            int dist = q.front().second;

            q.pop();

            if(s==targetWord) return dist+1;

            for(int i=0;i<s.length();i++){

                string temp=s;

                for(char c='a';c<='z';c++){

                    temp[i]=c;

                    if(st.count(temp)){

                        st.erase(temp);

                        q.push({temp,dist+1});

                    }

                }

            }

        }

        return 0;
    }
};