#include<iostream>
#include<string>
using namespace std;
const int n=100;
class Kmp
{
    public:
    Kmp(string  a,string b)  //输入字符串
    {
        this->s1=a;
        this->s2=b;
    }
    int kmp()
    {
        int i=0,j=0;
        get_next();    //初始化next
        while(i<s1.size())
        {
            if(j==-1||s1[i]==s2[j])
            {
                i++;j++;
            }
            else
            {
                j=next[j];
            }
            if(j==s2.size())
            {
                return i-j;
            }
            
        }
        return -1;
    }
    
    private:
    string s1,s2;
    int next[n]={0};
    void get_next()
    {
        int i=0,j=-1;
        next[i]=j;
        while(i<s2.size())
        {
            if(j==-1||s2[i]==s2[j])
            {
                i++;j++;
                next[i]=j;
            }
            else
            {
                j=next[j];
            }
        }
    }
};

int main()
{
    string a,b;
    cin>>a;
    cin>>b;
    Kmp k= Kmp(a,b);
    cout<<k.kmp()<<endl;


}
