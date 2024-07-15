
// https://leetcode.com/problems/find-the-duplicate-number/description/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7



class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // jump technique (linkd)
         int slow=nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
           }
        while(slow!=fast);
        fast=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};