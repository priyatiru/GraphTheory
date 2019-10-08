#include <bits/stdc++.h>
#define pb push_back

using namespace std;

vector<int> v;
vector<vector<int> > g;

void edge(int a, int b)
{
    g[a].pb(b);


}

bool bfs(int u)
{
    queue<int> q;

    q.push(u);
    v[u] = 1;

    while (!q.empty()) {

        int f = q.front();
        q.pop();


      //  cout << f << " ";

        for (auto i = g[f].begin(); i != g[f].end(); i++) {
            if (v[*i]==-1) {
                q.push(*i);
                v[*i] = 1 - v[f];
              //  cout< <"vp[i] is"<<v[*i]<<" and v[f]"<<v[f]<<endl;
            }
            else if (v[*i]==v[f])
                return false;
        }
    }

    return true;
}


int main()
{
    int n, e;
    int check=1;
    int bp=1;
    std::cout << "\n\t Enter the number of vertices and edges : ";
    cin >> n >> e;

    v.assign(n,1);
    for(int i=0;i<n;i++){
              v[i]=-1;
            //  cout<<v[i];
            }
    g.assign(n, vector<int>());

    int a, b;
    for (int i = 0; i < e; i++) {
        std::cout << "\n\t Enter edge u->v : ";
        cin >> a >> b;
        if(a==b){
                cout<<"not possible since self loop";
                bp=0;
                check=0;
                break;
                }
        edge(a, b);
    }

  if(check){

    for (int i = 0; i < n; i++) {

        if (v[i]==-1){
            if(bfs(i)== false){
                bp=0;
                cout<<"not possible";
                break;}
                }
    }
  }

    int a1[n];
    int a2[n];
    int m=0;
    int l=0;
    if(bp==1)
    {
          cout<<"bipartite possible";
        //  for(int i=0;i<n;i++)
              //  cout<<"\t"<<v[i];
          for(int i=0;i<n;i++){
                  if(v[i]==0){
                        a1[m]=i;m++;}
                  else
                      if(v[i]==1){
                        a2[l]=i;l++;}
                      }
          sort(a1,a1+m);
          sort(a2,a2+l);
          cout<<endl;
          cout<<"bipartite set 1"<<endl;
          for(int i=0;i<m;i++)
                    cout<<a1[i]<<"\t";
          cout<<endl;
          cout<<"bipartite set 2"<<endl;
          for(int i=0;i<l;i++)
                    cout<<a2[i]<<"\t";



    }

    return 0;
}
