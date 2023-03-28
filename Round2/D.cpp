#include <bits/stdc++.h>

using namespace std;

int n,c[10100],t[10100],l[10100],r[10100];

int possible(int T)
{
    for (int i=1;i<=n;i++) l[i]=r[i]=0;
    for (int i=0;i<n;i++) l[max(1,c[i]-T/t[i])]++, r[min(n,c[i]+T/t[i])]++;

    for (int i=1;i<=n;i++)
    {
        l[i]+=l[i-1]; r[i]+=r[i-1];
        if (l[i]<i || r[i]>i) return 0;
    }
    return 1;
}

int main()
{
    cin >> n;
    for (int i=0;i<n;i++) cin >> c[i] >> t[i];

    int low=0,high=100000000,ans=high;
    while (low<=high)
    {
        int mid=(low+high)>>1;
        if (possible(mid)) ans=mid, high=mid-1;
        else low=mid+1;
    }
    cout << ans << endl;
}