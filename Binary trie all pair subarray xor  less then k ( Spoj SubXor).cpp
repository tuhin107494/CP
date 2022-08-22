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
#define mod   mx18
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
int to[mx6][2],to_node=1;
int node[mx6];
void trie_add_string(bitset<30> s)
{
    int cur=1;
    node[cur]++;
    for(int i=29; i>=0; i--)
    {

        int  ch=s[i];
        if(!to[cur][ch])to[cur][ch]=++to_node;
        cur=to[cur][ch];
        node[cur]++;

    }

}
void trie_delete_string(bitset<30> s)
{
    int cur=1;

      node[cur]--;



    for(int i=29; i>=0; i--)
    {

        int  ch=s[i];
        if(!to[cur][ch])return;
        cur=to[cur][ch];
        node[cur]--;

    }

}
int trie_quary(bitset<30> s,bitset<30> l)
{
    int cur=1,ans=0;

    for(int i=29; i>=0; i--)
    {
        int chs=s[i];

         int chl=l[i];
         if(chl==1)
         {
             ans+=node[to[cur][chs]];
             cur=to[cur][chs^1];
         }
         else
         {
             cur=to[cur][chs];
         }

    }
    return ans;

}

void input()
{
    int n,l,r,m;
    sci(n);
    sci(m);
    bitset<30>mm(m);
    bitset<30>zero(0);
    trie_add_string(zero);
    int pre=0;
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        sci(l);
        pre^=l;
        bitset<30>ma(pre);
        ans+=1ll*trie_quary(ma,mm);
        trie_add_string(ma);

    }

   printf("%lld\n",ans);

}
int main()
{
    TT;
    int t=1;
    sci(t);
    while(t--)
    {
        input();
        memset(to,0,sizeof(to));
        memset(node,0,sizeof(node));
        to_node=1;

    }
    return 0;
}
