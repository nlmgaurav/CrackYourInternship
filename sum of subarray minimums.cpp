class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        stack<int>st;
        int n=arr.size();
        vector<int>left(n),right(n);
        // finding ple   left[i]=is distance between ple and arr[i]
        st.push(0);
        left[0]=1;
        for(int i=1;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>arr[i])st.pop();
            if(st.empty())left[i]=i+1;
            else left[i]=i-st.top();

            st.push(i);
        }

        while(!st.empty())st.pop();

        // nle   right[i]  is distance between nle and arr[i];

        st.push(n-1);
        right[n-1]=1;

        for(int i=n-2;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
            if(st.empty())right[i]=n-i;
            else right[i]=st.top()-i;

            st.push(i);
        }

        int mod=1e9+7;
        int ans=0;
        for(int i=0;i<n;i++){
            long long prod=(left[i]*right[i])%mod;
            prod=(prod*arr[i])%mod;
            ans=(ans+prod)%mod;
        }
        return ans%mod;

    }
};