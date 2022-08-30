#include<bits/stdc++.h>
#define sc(n) scanf("%lld",&n)
#define ll  long long int
#define pb  push_back
#define mod  1000000007
using namespace std;

ll t,n,d=0,u,u1,k=0,l=0,mid,x=0,i=0,m,f=0,j=0,r,c=0,s1=0;


ll mn[400005],a[400005];
map<ll,ll>ma;
vector<ll>v;
void setall2()
{

    ma.clear();
    v.clear();
    memset(mn,0,sizeof(mn));


}
void build(ll u,ll b,ll e)
{

    if(b==e)
    {
        mn[u]=0;

        return ;
    }
    ll mid=(b+e)/2;
    build(2*u,b,mid);
    build((2*u)+1,mid+1,e);


    mn[u]=mn[2*u]+mn[(2*u) +1];

}
ll quary (ll u,ll b,ll e,ll i,ll j)
{

    if(e<i or b>j)return 0;
    if(b>=i && e<=j)return mn[u];
    ll mid=(b+e)/2;
    ll l_mn=quary(2*u,b,mid,i,j);
    ll r_mn=quary(2*u+1,mid+1,e,i,j);

    return ((l_mn+r_mn)%mod+mod)%mod;

}
void update(ll  u,ll  b,ll  e,ll  l,ll  x)
{

    if( l>e or l<b)
    {
        return ;
    }
    else if(l<=b && e<=l)
    {

        mn[u]=((mn[u]+x)%mod+mod)%mod;


        return ;
    }
    ll  mid=(b+e)/2;
    update(2*u,b,mid,l,x);
    update(2*u+1,mid+1,e,l,x);
    mn[u]=((mn[2*u]+mn[(2*u)+1])%mod+mod)%mod;
}
void setall()
{

    sort(v.begin(),v.end());

    v.erase(unique(v.begin(),v.end()),v.end());



    for(i=0; i<v.size(); i++)
    {
        ma[v[i]]=i+1;


    }
build(1,1,v.size());
}
void solve()
{

    for(i=0; i<n; i++)
    {
        ll s=quary(1,1,v.size(),1,ma[a[i]]-1)+1;

        update(1,1,v.size(),ma[a[i]],s);
    }

    printf("Case %lld: %lld\n",++f,mn[1]);

}
void input()
{

    sc(t);
    while(t--)
    {
        setall2();

        sc(n);
        for(i=0; i<n; i++)
        {

            sc(a[i]);
            v.pb(a[i]);
        }

        setall();
        solve();
    }

}
int main()
{


    input();


    return 0;
}
