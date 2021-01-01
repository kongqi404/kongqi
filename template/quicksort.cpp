#include<iostream>
#include<vector>

using namespace std;

void quick_sort(vector<int> &q,int l,int r)
{
  if(l>=r) return;
  int x=q[l],int i=l-1,j=r+1;
  while(i<j)
  {
    while(q[++i]<x);
    while(q[--j>x]);
    if(i<j) swap(q[i],q[j]);
   }
   quick_sort(q,l,j);
   quick_sort(q,j+1,r);
  
}

int main()
{
  int n,c;
  vector<int> q;
  cin>>n;
  for(int i=0;i<n;i++) 
  {
    cin>>c;
    q.push_back(c);
  }
  quick_sort(q,0,q.size()-1);
  for(int i=0;i<q.size();i++) cout<<q[i]<<" ";

}
