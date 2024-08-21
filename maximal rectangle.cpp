class Solution {
public:

 /* key point ye hai ki jo rectangle hai usme rows ko seprtaely
 histogram bnalenge then same question bnn jayega example

 1st test case  
    row0 ka histogram  1 0 1 0 0  area=1
    row1(row0+row1)    2 0 2 1 1   area=3
    row2(row0+r1+r2)   3 1 3 2 2   area=6
    row3(0+1+2+3)      4 0 0 3 0  area=4


     so max area=  6 ans
     */
    





     // function for finding max. area of histogram
    
    int find_max_area(vector<int>& arr)
    {
        int n = arr.size();
        
        // find the next smaller on left side
        
        vector<int> left_smaller(n, -1);
        
        stack<int> st;
        
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            
            if(st.empty())
                left_smaller[i] = -1;
            
            else
                left_smaller[i] = st.top();
            
            st.push(i);
        }
        
        while(!st.empty())
        {
            st.pop();
        }
        
        // find the next smaller on right
        
        vector<int> right_smaller(n, n);
        
        for(int i = n - 1; i >= 0; i--)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            
            if(st.empty())
                right_smaller[i] = n;
            
            else
                right_smaller[i] = st.top();
            
            st.push(i);
        }
        
        // find the max area
        
        int max_area = 0;
        
        for(int i = 0; i < n; i++)
        {
            int width = right_smaller[i] - left_smaller[i] - 1;
            
            int height = arr[i];
            
            int curr_area = width * height;
            
            max_area = max(max_area, curr_area);
        }
        
        return max_area;
    }
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        
        int m = matrix[0].size();
        
        vector<int> height(m, 0);
        
        int max_area = 0;
        
        for(int i = 0; i < n; i++)
        {
            // update the height array
            
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == '1')
                {
                    height[j]++;
                }
                else
                {
                    height[j] = 0;
                }
            }
            
            // find the max. area
            
            int curr_area = find_max_area(height);
            
            max_area = max(max_area, curr_area);
        }
        
        return max_area;
    }
};