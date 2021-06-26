#include<bits/stdc++.h>

using namespace std;
const int N = 2097152;

complex<double> s1[N],s2[N];
int c[N];
int n=1;
void fft(complex<double> a[],int n,int inv)
{
    for(int i=0;i<n;i++)
    {
        if(i<c[i]) swap(a[i],a[c[i]]);
    }
    for(int i=1;i<n;i<<=1)
    {
        complex<double> x(cos(M_PI/i),inv*sin(M_PI/i));
        for(int r= i<<1,j=0;j<n;j+=r)
        {
            complex<double> w(1,0);
            for(int k=0;k<i;k++,w*=x)
            {
                complex<double> a1 = a[j+k],a2=w*a[i+j+k];
                a[j+k]=a1+a2;
                a[i+j+k]=a1-a2;
            }
        }
    }

}


int main()
{
    string a,b;
    cin>>a>>b;
    for(int i=0;i<a.size();i++)
    {
        s1[i]=a[i]-'0';
    }
    reverse(s1,s1+a.size());
    for(int i=0;i<b.size();i++)
    {
        s2[i]=b[i]-'0';
    }
    reverse(s2,s2+b.size());
    int k=0;
    while(n<a.size()+b.size())
    {
        n<<=1;
        k++;

    }
    for(int i=0;i<n;i++) c[i]=(c[i>>1]>>1)|((i&1)<<(k-1));


    fft(s1,n,-1),fft(s2,n,-1);
    for(int i=0;i<n;i++)
    {
        s1[i]*=s2[i];
    }
    fft(s1,n,1);
    for(int i=0;i<n;i++)
    {
        s1[i]/=n;
    }
    vector<int> res;
    for(int i=0,t=0;i<n||t;i++)
    {
        int x = i<n?(int)(s1[i].real()+0.5)+t:t;
        res.push_back(x%10);
        t=x/10;
    }
    while(res.back()==0&&res.size()>0) res.pop_back();
    reverse(res.begin(),res.end());
    for(int i=0;i<res.size();i++) cout<<res[i];
    cout<<endl;
    return 0;
}
