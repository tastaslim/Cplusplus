#include<bits/stdc++.h>
using namespace std;
class Edges
{
   public:
   int sv;
   int ev;
   int weight;
};

bool WeightWise(Edges e1, Edges e2)
{
  return e1.weight < e2.weight;
}

int findParent(int v, int *parent)
{
  if(v==parent[v])
     return v;
  return findParent(parent[v],parent);
}


int main()
{
 int n,e;
 cin>>n>>e;
 Edges *input=new Edges[e]; 
 for(int i=0;i<e;i++)
 {
   int s,e,w;
   cin>>s>>e>>w; 
   input[i].sv=s;
   input[i].ev=e;
   input[i].weight=w;
 }
 sort(input,input+n,WeightWise);
 Edges *output=new Edges[n-1];
 int *parent=new int[n];
 
 for(int i=0;i<n;i++)
 {
   parent[i]=i;
 }
 
 int count=0,i=0;
 while(count<n-1)
 {
   int p1=findParent(input[i].sv,parent);
   int p2=findParent(input[i].ev,parent);
   if(p1!=p2)
   {
    output[count++]=input[i];
    parent[input[i].ev]=input[i].sv;
   }
   i++;
 }
 
 for(int i=0;i<count;i++)
 {
    cout<<output[i].sv<<" "<<output[i].ev<<" "<<output[i].weight<<endl;
 }
 
}
