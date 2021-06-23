#include<bits/stdc++.h>
#ifndef N
#define N 32768
#endif
#ifndef complex 
#include<complex>
#endif
#ifndef iostream
#include<iostream>
#endif
#ifndef cmath
#include<cmath>
#endif
#ifndef algorithm
#include<algorithm>
#endif

using namespace std;
class FFT
{
    public:
    complex<double> s1[N],s2[N];
    FFT(string a,string b)                     //初始化
    {
        try
        {
            for(int i=0;i<a.size();i++)
            {
                s1[i]=a[i]-'0';
            }
            reverse(s1,s1+a.size());  //反转
            for(int i=0;i<b.size();i++)
            {
                s2[i]=b[i]-'0';
            }
            reverse(s2,s2+b.size());
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    vector<int> cal()  //计算
    {
        fft(s1,N,-1),fft(s2,N,-1);   //对两个序列进行傅里叶变换
        for(int i=0;i<N;i++)
        {
            s1[i]*=s2[i];       //求卷积
        }
        idft(s1,N);    //逆变换为序列
        vector<int> res;
        for(int i=0,t=0;i<N||t;i++)
        {
            int x = i<N?(int)(s1[i].real()+0.5)+t:t;   //防止精度+0.5
            res.push_back(x%10);
            t=x/10;
        }
        while(res.back()==0) res.pop_back();                //去0
        reverse(res.begin(),res.end());   //反转
        return res;
    }
    void fft(complex<double> a[], int n, int j)     //fft
    {
        if(n==1) return;
        int mid = n/2;
        static complex<double> b[N]; 
        for(int i=0;i<mid;i++)b[i]=a[i*2],b[i+mid]=a[i*2+1];           //分奇偶
        memcpy(a,b,sizeof(complex<double>)*n);
        fft(a,mid,j),fft(a+mid,mid,j);           //递归
        for(int i=0;i<mid;i++)
        {
            complex<double> x(cos(2*M_PI*i/n),j*sin(2*M_PI*i/n));          //dft
            b[i]=a[i]+x*a[i+mid];
            b[i+mid]=a[i]-x*a[i+mid];
        }
        memcpy(a,b,sizeof(complex<double>)*n);
    }
    void idft(complex<double> a[], int n)  //逆变换
    {
        fft(a,n,1);
        for(int i=0;i<n;i++) a[i]/=n;
    }

};

// class FHT{                       //fht有问题
//     public:
//     double s1[N],s2[N];
//     FHT(string a,string b)
//     {
//         try
//         {
//             for(int i=0;i<a.size();i++)
//             {
//                 s1[i]=a[i]-'0';
//             }
//             reverse(s1,s1+a.size());
//             for(int i=0;i<b.size();i++)
//             {
//                 s2[i]=b[i]-'0';
//             }
//             reverse(s2,s2+b.size());
//         }
//         catch(const std::exception& e)
//         {
//             std::cerr << e.what() << '\n';
//         }
//     }
//     void fht(double a[],int n)
//     {
//         if(n==2) return;
//         int mid = n/2;
//         static double b[N];
//         for(int i=0;i<mid;i++) b[i]=a[i*2],b[i+mid]=a[i*2+1];
//         memcpy(a,b,sizeof(double)*n);
//         fht(a,mid),fht(a+mid,mid);
//         for(int i=0;i<mid/2;i++)
//         {
//             double cos_x = cos(2*M_PI/n*i),sin_x= sin(2*M_PI/n*i);
//             b[i]=a[i]+cos_x*a[i+mid]+sin_x*a[i+mid];
//             b[i+mid] = a[i]-(cos_x*a[i+mid]+sin_x*a[i+mid]);
           
//         }
//         memcpy(a,b,sizeof(double)*n);
//     }
//     void ifht(double a[],int n)
//     {
//         fht(a,n);
//         for(int i=0;i<n;i++) a[i]/=n;
//     }
//     vector<int> cal()
//     {
//         fht(s1,N),fht(s2,N);
//         for(int i=0;i<N;i++)
//         {
//             s1[i]*=s2[i];
//         }
//         ifht(s1,N);
//         vector<int> res;
//         for(int i=0,t=0;i<N||t;i++)
//         {
//             int x = i<N?(int)s1[i]+0.5+t:t;
//             res.push_back(x%10);
//             t=x/10;
//         }
//         while(res.back()==0) res.pop_back();
//         reverse(res.begin(),res.end());
//         return res;
//     }
// };
int main()
{
    string a,b;
    cin>>a>>b;
    auto x=FFT(a,b).cal();
    for(auto i:x) cout<<i;
    cout<<endl;
    return 0;

    
    
    
}
