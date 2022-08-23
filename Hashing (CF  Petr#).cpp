/**
Simple Library for String Hashing
Uses Rolling Double Hash.
Hash(abc........z) = a*p^n + b*p^(n-1) + ...... + z
Cautions:
1.  You may assign any integer values to characters.
    Common is 'a' = 1, 'b' = 2 ..........
    Here the ascii values of characters is used.
    But never assign any character the value 0.
    For example if 'a' = 0; 'abc' and 'bc' has the same hash.
2.  Single Hashing with an unusual mod is often enough,
    but will surely fail for good enough judge-data.
    In order to convert to Single Hash -
        o Delete operator overloads (optional)
        o Replace all PLL with LL
        o Change mp pairs to appropriate value
Some Primes:
1000000007, 1000000009, 1000000861, 1000099999      ( < 2^30 )
1088888881, 1111211111, 1500000001, 1481481481      ( < 2^31 )
2147483647 (2^31-1),
**/

#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;

const PLL M=mp(1000000007, 1000000009);   ///Should be large primes
const LL base=347;              ///Should be a prime larger than highest value
const int N = 1e6+7;            ///Highest length of string

ostream& operator<<(ostream& os, PLL hash)
{
    return os<<"("<<hash.ff<<", "<<hash.ss<<")";
}

PLL operator+ (PLL a, LL x)
{
    return mp(a.ff + x, a.ss + x);
}
PLL operator- (PLL a, LL x)
{
    return mp(a.ff - x, a.ss - x);
}
PLL operator* (PLL a, LL x)
{
    return mp(a.ff * x, a.ss * x);
}
PLL operator+ (PLL a, PLL x)
{
    return mp(a.ff + x.ff, a.ss + x.ss);
}
PLL operator- (PLL a, PLL x)
{
    return mp(a.ff - x.ff, a.ss - x.ss);
}
PLL operator* (PLL a, PLL x)
{
    return mp(a.ff * x.ff, a.ss * x.ss);
}
PLL operator% (PLL a, PLL m)
{
    return mp(a.ff % m.ff, a.ss % m.ss);
}

PLL power (PLL a, LL p)
{
    if (p==0)   return mp(1,1);
    PLL ans = power(a, p/2);
    ans = (ans * ans)%M;
    if (p%2)    ans = (ans*a)%M;
    return ans;
}

///Magic!!!!!!!
PLL inverse(PLL a)
{
    return power(a, (M.ff-1)*(M.ss-1)-1);
}

PLL pb[N];      ///powers of base mod M
PLL invb;

///Call pre before everything
void hashPre()
{
    pb[0] = mp(1,1);
    for (int i=1; i<N; i++)
        pb[i] = (pb[i-1] * base)%M;
    invb = inverse(pb[1]);
}

///Calculates Hash of a string
PLL Hash (string &s)
{
    PLL ans = mp(0,0);
    for (int i=0; i<s.size(); i++)
        ans=(ans*base + s[i])%M;
    return ans;
}

///appends c to string
PLL append(PLL cur, char c)
{
    return (cur*base + c)%M;
}

///prepends c to string with size k
PLL prepend(PLL cur, int k, char c)
{
    return (pb[k]*c + cur)%M;
}

///replaces the i-th (0-indexed) character from right from a to b;
PLL replace(PLL cur, int i, char a, char b)
{
    cur = (cur + pb[i] * (b-a))%M;
    return (cur + M)%M;
}

///Erases c from the back of the string
PLL pop_back(PLL hash, char c)
{
    return (((hash-c)*invb)%M+M)%M;
}

///Erases c from front of the string with size len
PLL pop_front(PLL hash, int len, char c)
{
    return ((hash - pb[len-1]*c)%M+M)%M;
}

///concatenates two strings where length of the right is k
PLL concat(PLL left, PLL right, int k)
{
    return (left*pb[k] + right)%M;
}

///Calculates hash of string with size len repeated cnt times
///This is O(log n). For O(1), pre-calculate inverses
PLL repeat(PLL hash, int len, LL cnt)
{
    PLL mul = (pb[len*cnt] - 1) * inverse(pb[len]-1);
    mul = (mul%M+M)%M;
    PLL ans = (hash*mul)%M;

    if (pb[len].ff == 1)    ans.ff = hash.ff*cnt;
    if (pb[len].ss == 1)    ans.ss = hash.ss*cnt;
    return ans;
}

///Calculates hashes of all prefixes of s including empty prefix
string a,b,c;
vector<PLL>ha,hb,hc;

vector<PLL> hashList(string &s)
{
    int n = s.size();
    vector<PLL> ans(n+1);
    ans[0] = mp(0,0);

    for (int i=1; i<=n; i++)
        ans[i] = (ans[i-1] * base + s[i-1])%M;
    return ans;
}

///Calculates hash of substring s[l..r] (1 indexed)
PLL substringHash(const vector<PLL> &hashlist, int l, int r)
{
    int len = (r-l+1);
    return ((hashlist[r] - hashlist[l-1]*pb[len])%M+M)%M;
}

///Solves LightOJ 1255-Substring Frequency
///You are given two strings A and B. You have to find
///the number of times B occurs as a substring of A.
char buffer[N];
vector<PLL>ma;
int main()
{
    hashPre();
    // if string contains digit , base=10,s[i-1]-'0'

    int n,ans=0;

    scanf("%s",buffer);
    a=buffer;
    scanf("%s",buffer);
    b=buffer;
    scanf("%s",buffer);
    c=buffer;

    ha=hashList(a);
    PLL hb_val=Hash(b);
    PLL hc_val=Hash(c);
    int size_a=a.size(),size_b=b.size(),size_c=c.size();

    vector<int>vb,vc;
    for(int i=0; i<=(size_a-size_b); i++)
    {
        if(substringHash(ha,i+1,i+size_b)==hb_val)vb.push_back(i);
    }
    for(int i=0; i<=(size_a-size_c); i++)
    {
        if(substringHash(ha,i+1,i+size_c)==hc_val)vc.push_back(i+size_c);
    }

    int j=0;
    for(int i=0; i<vb.size(); i++)
    {   bool flag=false;
        int in=j;
        for(; j<vc.size(); j++)
        {

            if(vc[j]-size_c<vb[i] or vb[i]+size_b>vc[j])continue;
            PLL p=substringHash(ha,vb[i]+1,vc[j]);
           ma.push_back(p);


            if(vb[i]>vc[j]){in=j;}

        }
        j=in;
    }
    sort(ma.begin(),ma.end());
    ma.erase(unique(ma.begin(),ma.end()),ma.end());


    printf("%d\n",ma.size());



}
