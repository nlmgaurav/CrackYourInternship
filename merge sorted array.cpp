class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    /*   // O(M+N)
        int k=(m+n)-1;
	int i=m-1,j=n-1;
	while(i>=0 && j>=0)
	{
		if(nums1[i]>=nums2[j])
			nums1[k--]=nums1[i--];
		else
			nums1[k--]=nums2[j--];
	}

	//check if nums2 elemnt is left
	while(j>=0)
	{
		nums1[k--]=nums2[j--];
	}
        
        
        */
      //  m+nLOG(m+n);
        for(int i=0;i<n;i++){
            nums1[m+i]=nums2[i];
        }
        sort(nums1.begin(),nums1.end());
        
    }
};