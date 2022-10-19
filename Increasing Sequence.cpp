
/**    Tuhin ahmed                    **
*      Email:tuhin107494@gmail.com     *
*      university:comilla university  **
*/
#include<bits/stdc++.h>
using namespace std;
#define TT ios::sync_with_stdio(false); cin.tie(0);cout.tie(0)
#define       ll                   long long int
#define       ull                  unsigned long long int
#define       vi                   vector<int>
#define       vc                   vector<char>
#define       vs                   vector<string>
#define       vll                  vector<long long int>
#define       vp                   vector<  pair<int,int> >
#define       pb                   push_back
#define       pob                  pop_back
#define       pll                  pair<long long  int, long long int>
#define       F                    first
#define       S                    second
#define       sc(x)                scanf("%lld",&x)
#define       sci(x)                scanf("%d",&x)
#define       sc2(x,y)             scanf("%lld %lld",&x,&y)
#define       pf                   printf
#define       min3(a,b,c)          min(a,b<c?b:c)
#define       max3(a,b,c)          max(a,b>c?b:c)
#define       all(v)               v.begin(), v.end()
#define       rall(v)               v.rbegin(), v.rend()
///============ CONSTANT ===============///
#define mx18  1000000000000000000
#define mx9   1000000007
#define mx8   100000007
#define mx7   10000006
#define mx6   1000056
#define mx5   200005
#define mx4   10005
#define inf   1<<30
#define eps   1e-9
#define mod   mx9
vector<ll>v;
ll b[mx6],a[mx6],i;
void bs(ll m)
{
    ll l=0,r=v.size()-1;
    while(l<r)
    {
        ll mid=(l+r-1)/2;
        if(v[mid]>=m)r=mid;
        else l=mid+1;
    }
    if(v[r]==m)
    {
        b[i]=r;
    }
    else if(v[r]<m)
    {
        v.pb(m);
        b[i]=r+1;
    }
    else
    {
       v[r]=min(m,v[r]);
       b[i]=r;
    }
}
void solve()
{
    ll n,ma=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    v.pb(a[0]);
    for( i=1;i<n;i++)
    {
        bs(a[i]);
    }
    for(i=0;i<n;i++)ma=max(ma,b[i]);
    cout<<ma+1<<endl;
}

int main()
{
    TT;
    int t=1;

    while(t--)
    {
        //input();
        solve();

    }
    return 0;
}
