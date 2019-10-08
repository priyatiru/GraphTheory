#include <iostream>
#include <string.h>
#include<vector>
using namespace std;
int M,N;
bool bpm(vector <vector<int>> bpGraph, int u,bool seen[], int matchR[])
{
	for (int v = 0; v < N; v++)
	{
		if (bpGraph[u][v] && !seen[v])
		{
			seen[v] = true;
			if (matchR[v] < 0 || bpm(bpGraph, matchR[v],seen, matchR))
			{
				matchR[v] = u;
				return true;
			}
		}
	}
	return false;
}
int maxBPM(vector <vector<int>> bpGraph)
{
	int matchR[N];
	memset(matchR, -1, sizeof(matchR)); //all jobs available
	int result = 0;
	for (int u = 0; u < M; u++)
	{
		bool seen[N];
		memset(seen, 0, sizeof(seen));  //all jobs unseen
		if (bpm(bpGraph, u, seen, matchR))
			result++;
	}
	return result;
}
int main()
{
  cout<<"Enter number of vertices in first partite :";
  cin>>M;
  cout<<endl;
  cout<<"Enter number of vertices for second partite :";
  cin>>N;
  cout<<endl;
	vector <vector<int>> graph(M);
  cout<<"Enter Matrix:"<<endl;
  for(int i=0;i<M;i++)
    for(int j=0;j<N;j++)
    {
      int temp;
      cin>>temp;
      graph[i].push_back(temp);
    }
	cout << "Maximum number Bipartite matching is "<< maxBPM(graph)<<endl;

	return 0;
}
