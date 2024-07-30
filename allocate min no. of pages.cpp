//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool possible(int barrier,int arr[],int n,int students)
    {
        int allocatedStudents=1,pages=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>barrier)return false;
            if(pages+arr[i]>barrier)
            {
                allocatedStudents++;
                pages=arr[i];
            }else pages+=arr[i];
        }
        return allocatedStudents<=students;
    }
    int findPages(int arr[], int n, int students) 
    {
        //code here
        if(students>n)return -1;
        int low=arr[0],high=0;
        for(int i=0;i<n;i++)
        {
            high+=arr[i];
            low=min(low,arr[i]);
        }
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(possible(mid,arr,n,students)){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return low;
    }
};