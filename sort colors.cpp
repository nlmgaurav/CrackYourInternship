#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n,q;
    cin>>n>>q;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int>ps(n+1,0);
    //ps[0]=a[0];
    for(int i=1;i<=n;i++)ps[i]=ps[i-1]+a[i-1];
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        
        cout<<ps[b]-ps[a-1]<<"\n";
    }
}
