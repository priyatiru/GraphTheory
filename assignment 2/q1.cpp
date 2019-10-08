#include<iostream>
#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

int d[100];
int counter=0;
void hakimi(int d[],int n)
{int j,sum,flag=0;
 ++counter;
 std::sort(d,d+n,greater<int>());
 int k=d[0];
 if(k==0)
   {cout<<"No. of recursive calls are "<<counter<<"\n";
    exit(1);
    }
    
 int m; 
 for(m=1;m<=k;m++)
 { d[m]=d[m]-1;
   if(d[m]<0)
      { cout<<"Not a degree sequence\n";
        flag=-1;
        exit(1);}
 }
 if(flag!=-1)
   {
      for(j=0;j<n;j++)
         {d[j]=d[j+1];}
      d[n-1]=0;
      for(j=0;j<n;j++)
         {sum=sum+d[j];}
      if(sum==0)
      {cout<<"It is a possible degree sequence\n";
       }
   }
   
 if(n>1)
 {hakimi(d,n-1);}
}
     
int main()
{int n;
cout<<"Enter the no. of vertices for the graph\n";
cin>>n;
cout<<"Enter the Degree sequence of the graph\n";
for(int i=0;i<n;i++)
{ cin>>d[i];
}
hakimi(d,n);
//cout<<"No. of recursive calls are"<<counter-2<<"\n";
return 0;
}
