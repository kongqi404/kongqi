#include<iostream>

using namespace std;

const int LOG = 25, N = 2000010;
int f[N][LOG],log[N];
void pre()
{
    log[1]=0;
    log[2]=1;
    for(int i=3;i<N;i++)
    {
        log[i]=log[i/2]+1;
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>f[i][0];
    pre(); 
    for(int j=1;j<=LOG;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        int s = log[r-l+1];
        cout<<max(f[l][s],f[r-(1<<s)+1][s]) <<endl;
    }
}
