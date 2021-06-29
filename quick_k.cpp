#include<bits/stdc++.h>

using namespace std;
const int N  =1010;
int a[N],de[N/5][5],c[N];

int insert_sort(int *a,int n)
{
    for(int i=1;i<n;i++)
    {
        for(int j=i;j>0;j--)
        {
            if(a[j]<a[j-1]) swap(a[j],a[j-1]);
        }
    }
    return a[n/2];
}
int select(int *a,int p,int q,int po)
{
    if(p>q) return 0;
    if(p==q&&p==po-1) return a[p];
    int x = a[(p+q)>>1];
    int i=p-1,j=q+1;
    while(i<j)
    {
        while(a[++i]<x);
        while(a[--j]>x);
        if(i<j)
        {
            swap(a[i],a[j]);
        }
    }
    if(j>=po-1) return select(a,p,j,po);
    else return select(a,j+1,q,po);
}

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        de[i/5][i%5] = a[i];
    }
    int x =0;

    for(int i=0;i<n/5;i++)
    {
        c[i]=insert_sort(de[i],5);
        x++;
    }
    if(n%5!=0) c[n/5] = insert_sort(de[n/5],n%5),x++;  //T(n)
    int cell = select(c,0,x-1,(x-1)/2+1);   //T(3n/10+6)
    
    int i=-1,j=n;
    int res;
    while(i<j)   //T(n)
    {
        while(a[++i]<cell);
        while(a[--j]>cell);
        if(i<j) swap(a[i],a[j]);
    }
    if(j>=k-1) res=select(a,0,j,k);  //T(7n/10+6)
    else res = select(a,j+1,n-1,k);
    cout<<res<<endl;
    return 0;
}
