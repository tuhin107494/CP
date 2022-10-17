/**    Tuhin ahmed                    **
*      Email:tuhin107494@gmail.com     *
*      university:comilla university  **
*/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;

#include<ext/pb_ds/tree_policy.hpp>
#define       ll                   long long int
using namespace __gnu_pbds;
typedef tree<pair<ll,ll>,null_type,less< pair<ll,ll> >,rb_tree_tag,
        tree_order_statistics_node_update>ordered_set;
#define TT ios::sync_with_stdio(false); cin.tie(0);cout.tie(0)
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
ll dx[]= {1,-1,0,0};
ll dy[]= {0,0,1,-1};
long double PI = acosl(-1);
///=============== Debugging ============================///
#define       debug(x) cerr << #x << " = " << x << endl
#define       debug2(x, y)             cerr << #x << ": " << x << "  " << #y << ": " << y << endl;
#define       debug3(x, y, z)          cerr << #x << ": " << x << "  " << #y << ": " << y << "  " << #z << ": " << z << endl;
#define       debug4(a, b, c, d)       cerr << #a << ": " << a << "  " << #b << ": " << b << "  " << #c << ": " << c << " | " << #d << ": " << d << endl;
///=====================Bitmask===================///
//ordered_set st;
//int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}
///========================================FUNCTION=========================================///
//bool check(int n){if(n==1) return false; for(int i=2; i*i<=n; i++){if(n%i==0) return false;} return true;}
//ll fact(ll n){if(n==0 or n==1)return 1; else return ((n%mod)*fact(n-1)%mod)mod;}
//ll big_mod(ll b,ll p,ll m ){ll res=1;while(p!=0){if(p&1)res=(res*b)%m;b=(b*b)%m;p=p>>1;}res=(res)%m;return res;}
//void seive(){for(ll i=2; i<mx6; i++){if(visit[i])continue;dv[i]=i;for(ll j=i*i; j<mx6; j+=i){dv[j]=i;visit[j]=true;}}}
//void build(int u,int b,int e){if(b==e){tr[u]=dif[b];return;}ll mid=(b+e)/2;build(2*u,b,mid);build(2*u+1,mid+1,e);tr[u]=gcd(tr[(2*u)],tr[(2*u)+1]);}
//ll quary(int u,int b,int e,int i,int j){if(e<i or b>j)return 0;else if(b>=i and e<=j){return tr[u];}int   mid=(b+e)/2;ll  left=quary(2*u,b,mid,i,j);ll right=quary((2*u)+1,mid+1,e,i,j);return  gcd(left,right);}
//void  update (int u,int b,int e,int i,int j,int x){if(e<i or b>j)return;else if(b>=i and e<=j){tr[u]=x;return;}int mid=(b+e)/2;update(2*u,b,mid,i,j,x);update((2*u)+1,mid+1,e,i,j,x);tr[u]=max(tr[2*u],tr[2*u +1]);}

//vector<ll> kmp_prefix_fun(string s){ll n=s.size();vector<ll>pi(n);for(ll i=1; i<n; i++){ll j=pi[i-1];while(j>0 and s[i]!=s[j])j=pi[j-1];if(s[i]==s[j])++j;pi[i]=j;}return pi;}
//void trie_add_string(string s){int cur=1;cnt[cur]++;for(int i=0; i<s.size(); i++){int  ch=s[i]-'a';if(!to[cur][ch])to[cur][ch]=++to_node;cur=to[cur][ch];cnt[cur]++;}track[cur]++;}
//int trie_quary(string s){int cur=1;for(int i=0; i<s.size(); i++){int ch=s[i]-'a';if(!to[cur][ch])return cnt[cur];cur=to[cur][ch];}return cnt[cur];}
//void sparse_table(){for(int i=1;i<=n;i++)table[i][0]=a[i];for(int k=1;k<20;k++){for(int i=1;i+(1<<k)-1<=n;i++){table[i][k]=min(table[i][k-1],table[i+(1<<(k-1))][k-1]);}}}
//int sparse_quary(int l,int r){int len=r-l+1;int k=log2(len);return min(table[l][k],table[r-(1<<k)+1][k]);}
///====================================StartHere=================////////////

ordered_set tr[4*mx5];
ll a[mx6];
void build(int u,int b,int e)
{
    if(b==e)
    {
        tr[u].insert({a[b],b});
        return;
    }
    ll mid=(b+e)/2;
    build(2*u,b,mid);
    build(2*u+1,mid+1,e);
    for(int i=b; i<=e; i++)tr[u].insert({a[i],i});
}

ll quary(int u,int b,int e,int i,int j,int val,int id)
{
    if(e<i or b>j)return 0;
    else if(b>=i and e<=j)
    {

        ll sz=tr[u].order_of_key({val+1,id});
        return sz;
    }
    int   mid=(b+e)/2;
    ll left=quary(2*u,b,mid,i,j,val,id);
    ll right=quary((2*u)+1,mid+1,e,i,j,val,id);
    return  left+right;
}
void  update_delete (int u,int b,int e,int i,int j,int val,int id)
{

    if(e<i or b>j)return;
    else if(b>=i and e<=j)
    {
        tr[u].erase(tr[u].find({val,id}));
        return;
    }
    int mid=(b+e)/2;
    update_delete(2*u,b,mid,i,j,val,id);
    update_delete((2*u)+1,mid+1,e,i,j,val,id);
    tr[u].erase(tr[u].find({val,id}));
}
void  update_add(int u,int b,int e,int i,int j,int x,int id)
{
    if(e<i or b>j)return;
    else if(b>=i and e<=j)
    {
        tr[u].insert({x,id});
        return;
    }
    int mid=(b+e)/2;
    update_add(2*u,b,mid,i,j,x,id);
    update_add((2*u)+1,mid+1,e,i,j,x,id);
    tr[u].insert({x,id});

}

void input()
{
    ll n,m,res=0,l,r;
    sc(n);
    for(int i=1; i<=n; i++)
    {

        sc(a[i]);
       update_add(1,1,mx5,i,i,a[i],i);

    }
    //build(1,1,n);
    sc(m);
    while(m--)
    {
        ll check,l,r,k,x,v;
        sc(check);
        if(check==1)
        {
            sc(v);
            a[++n]=v;
            update_add(1,1,mx5,n,n,v,n);
        }
        else if(check==2)
        {
            update_delete(1,1,mx5,n,n,a[n],n);
            a[n--]=0;
        }
        else
        {
            ll L,R;
            sc(L),sc(R),sc(k);
            k=(R-L+1)-k+1;

            l=1,r=mx9;
            ll f=0;
            while(l<=r)
            {
                if(l==r)
                {
                    f++;
                    if(f==2)break;
                }

                ll mid=(l+r)/2;
                if(quary(1,1,mx5,L,R,mid,mx18)>=k)
                {
                    r=mid;
                }
                else l=mid+1;
            }

            printf("%lld\n",l);

        }

    }

}
int main()
{
    TT;
    int t=1;
    //cin>>t;
    while(t--)
    {
        input();

    }
    return 0;
}


/*
input 
3
7 3 5 
7
3 1 3 2
1 10
3 1 4 2
2
2
1 1
3 2 3 2


output 
5
7
1
*/
