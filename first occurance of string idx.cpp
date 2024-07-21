class Solution {
public:
    int strStr(string haystack, string needle) {
        	int i=1,j=0,n=needle.length();
		vector<int> kmp(n);
		while(i<n) {
			if(needle[i]==needle[j]) {
				kmp[i++]=++j;
			}
			else {
				if(j!=0) j=kmp[j-1];
				else i++;
			}
		}
		i=0,j=0;
		int m=haystack.length();
		while(i<m) {
			if(needle[j]==haystack[i]) {
				i++,j++;
				if(j==n){
					return i-n;
				}
			}
			else {
				if(j!=0) j=kmp[j-1];
				else i++;
			}
		}
		return -1;
    }
};