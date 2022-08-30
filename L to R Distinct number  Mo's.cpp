#include<bits/stdc++.h>
using namespace std;

long long int res[100005],sz,cs=0;

struct quary
{
    long long int l,r,qid;
    bool operator <  ( const quary &q )const
    {
        if(q.l/sz!=l/sz)
        {
            return l<q.l;
        }
        return r<q.r;
    }
} Q[100005];
long long int a[100005],disticnt=0,freq[100005];
void add(long long int idx)
{
    if(freq[a[idx]] ==0)
    {
        disticnt++;
    }
    freq[a[idx]]++;
}
void del(long long int idx)
{
    if(freq[a[idx]]==1)
    {
        disticnt--;
    }
    freq[a[idx]]--;

}

int main()
{
    long long int mod,t,i,m,x,k,l,j=0,c=0,r=0,w,s,d=0,f=0,sum=0,mul,s12=0,mx=1,s2=0;

    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&x,&m);
        sz=sqrt(x);
        for(i=0; i<x; i++)
        {

            scanf("%lld",&a[i]);
        }



        for(i=0; i<m; i++)
        {

            scanf("%lld %lld",&Q[i].l,&Q[i].r);
            Q[i].l--;
            Q[i].r--;
            Q[i].qid=i;

        }
        sort(Q,Q+m);

        long long int L=0;
        long long  R=-1;
        for(i=0; i<m; i++)
        {

            l=Q[i].l;
            r=Q[i].r;
            //cout<<"l= "<<l<<" cl= "<<L<<" r = "<<r<<" c_R= "<<R<<" id= "<<Q[i].qid<<endl;
            while(l<L)
            {
                add(--L);
            }
            while(l>L)
            {
                del(L++);
            }
            while(r<R)
            {
                del(R--);
            }
            while(r>R)
            {
                add(++R);
            }



            res[Q[i].qid]=disticnt;
        }


         printf("Case %lld:\n",++cs);
        for(i=0; i<m; i++)
        {

            printf("%lld\n",res[i]);
        }
        disticnt=0;
        for(int i=0;i<=100000;i++)
        {
            res[i]=0;
            freq[i]=0;
        }
    }

    return 0;
}
