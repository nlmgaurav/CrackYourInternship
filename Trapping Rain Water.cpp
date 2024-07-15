class Solution {
public:
    int trap(vector<int>& height) {
      
        /*  O(N^2)
        
        
        int n=height.size();
          int waterTrapped = 0;
  for (int i = 0; i < n; i++) {
    int j = i;
    int leftMax = 0, rightMax = 0;
    while (j >= 0) {
      leftMax = max(leftMax, height[j]);
      j--;
    }
    j = i;
    while (j < n) {
      rightMax = max(rightMax, height[j]);
      j++;
    }
    waterTrapped += min(leftMax, rightMax) - height[i];
  }
  return waterTrapped;
*/
        
        /*
        O(3N) sc=o(2N)
        
        int n=height.size();
        int prefix[n],suffix[n];
        prefix[0]=height[0];
        for(int i=1;i<n;i++){
            prefix[i]=max(prefix[i-1],height[i]);
        }
        suffix[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=max(suffix[i+1],height[i]);
        }
        int water=0;
        for(int i=0;i<n;i++){
            water+=min(suffix[i],prefix[i])-height[i];
        }
        return water;
        */
        //we will use two pointer approach
        int n = height.size();
  int left = 0, right = n - 1;
  int res = 0;
  int maxLeft = 0, maxRight = 0;
  while (left <= right) {
    if (height[left] <= height[right]) {
      if (height[left] >= maxLeft) {
        maxLeft = height[left];
      } else {
        res += maxLeft - height[left];
      }
      left++;
    } else {
      if (height[right] >= maxRight) {
        maxRight = height[right];
      } else {
        res += maxRight - height[right];
      }
      right--;
    }
  }
  return res;
    }
};