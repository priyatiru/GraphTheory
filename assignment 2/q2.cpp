#include<iostream>
#include<bits/stdc++.h>
#define N 20
using namespace std;

int determinantOfMatrix(int mat[][N], int n) ;
void getCofactor(int mat[][N], int temp[][N], int p, int q, int n) ;
void undir(int a[][N],int n);
void dir(int a[][N],int n);

int main()
{ int u,v,n,choice;
  int a[20][20];
  char c;
  cout<<"Enter the no. of vertices in the Graph G ?\n";
  cin>>n;
  int t=n*(n-1)/2;
  cout<<"For the graph G Enter the edges:\n";	
  for(int i=0;i<n;i++)
     {  for(int j=0;j<n;j++)// initializing matrix
          {
            a[i][j]= 0;
           }
      }	
  for(int i=0;i<t;i++)
     { cout<<"Enter the edge"<<i+1<<"\n";
       cin>>u>>v;
       a[u][v]=1;
       a[v][u]=1;
       cout<<"Do you want to continue entering edges for the graph(y/n)?\n";
       cin>>c;
       if(c=='n'||c=='N')
       {break;}
      }
  cout<<"Computing the no. of Spanning trees...\n";
  undir(a,n);
  return 0;	
}
void undir(int a[][N],int n)
{ int s,d[n];
  for(int i=0;i<n;i++)
     {    d[i]=0;
          for(int j=0;j<n;j++)
          {
            d[i]=d[i]+a[i][j];
           }
      }
  for(int i=0;i<n;i++)
     { for(int j=0;j<n;j++)
          { if(i==j)
              { a[i][j]=d[i];}
            if(a[i][j]==1 && i!=j)
              {a[i][j]=-1;}
              
           }
      }
  s=determinantOfMatrix(a,n-1) ;
  cout<<"The No. of Spanning trees for this graph is:"<< s<<"\n";
}

void getCofactor(int mat[][N], int temp[][N], int p, int q, int n) 
{ 
    int i = 0, j = 0; 
    for (int row = 0; row < n; row++) 
    { 
        for (int col = 0; col < n; col++) 
        { 
            if (row != p && col != q) 
            { 
                temp[i][j++] = mat[row][col]; 
                if (j == n - 1) 
                { 
                    j = 0; 
                    i++; 
                } 
            } 
        } 
    } 
} 
int determinantOfMatrix(int mat[][N], int n) 
{ 
    int D = 0;
    if (n == 1) 
        return mat[0][0]; 
    int temp[N][N]; 
    int sign = 1;  
    for (int f = 0; f < n; f++) 
    { 
        getCofactor(mat, temp, 0, f, n); 
        D += sign * mat[0][f] * determinantOfMatrix(temp, n - 1); 
 
        sign = -sign; 
    } 
  
    return D; 
} 
  
