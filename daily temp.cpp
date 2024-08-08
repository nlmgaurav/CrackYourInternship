 vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> s;
        vector<int> result(temperatures.size(),0);
        for(int i=0;i<temperatures.size();i++) {
            while(!s.empty() && (s.top().first < temperatures[i])) {
                result[s.top().second] = i - s.top().second;
                s.pop();
            }
            s.push({temperatures[i],i});
        }
        return result;
    }