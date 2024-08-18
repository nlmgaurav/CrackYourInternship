class Solution {
public:
    int nthUglyNumber(int n) {
       set<long long>st;
        st.insert(1);
        long long cur;
        while(n--)
        {
            auto it=st.begin();
            cur=*it;
            st.erase(it);
            st.insert(2*cur);
            st.insert(3*cur);
            st.insert(5*cur);
        }
        return cur;
    }
};