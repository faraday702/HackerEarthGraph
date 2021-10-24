#include<iostream>
#include<vector>
#include<map>
using namespace std;

void dfs(int i, vector<int> adj[], int n, vector<bool> &visited, vector<int> &person, int icecream, int &temp_c)
{
	visited[i] = true;

	person[i] = icecream;
	temp_c++;

	for (auto iter = adj[i].begin();iter!=adj[i].end();iter++)
	{
		if(!visited[*iter])
			{
				dfs(*iter, adj, n, visited, person,icecream, temp_c);
			}
	}
}

int main()
{
	int n,m,q;
	cin>>n>>m>>q;

	vector<int> costs(m+1);
	vector<int> adj[n+1];
	vector<int> person(n+1);
	map<int,int> person_icecream;

	for(int i=0;i<m;i++)
	{
		cin>>costs[i+1];
	}

	for(int i=0;i<q;i++)
	{
		int type;
		cin>>type;

		if(type==1)
		{
			int x,k;
			cin>>x>>k;
			person_icecream[x]=k;	
		}
		else
		{
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}

	vector<bool> visited(n+1,0);
	int count =0;
	
	vector<int> ice_to_person_count(m+1,0);
	
	for (auto i=person_icecream.begin(); i!=person_icecream.end(); i++)
	{
	    int x = i->first;
	    int y = i->second;

		if(!visited[x])
		{
			int temp_c = 0;
			dfs(x, adj, n, visited, person, y, temp_c);
			ice_to_person_count[y] = temp_c;
			count++;
		}
	}

    cout<<count<<endl;

	for(int i=1;i<person.size();i++)
	{
		
		double res = (double)costs[person[i]]/(double)ice_to_person_count[person[i]];
		printf("%0.8f\n",res);
	}
	return 0;
}