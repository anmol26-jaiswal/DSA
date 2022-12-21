#include<bits/stdc++.h>
using namespace std;
#define F(i, n)     for(int i=0; i<n; i++)

class Solution
{
    private:
    bool dfs(int start, int col, vector<int> adj[], int color[])
    {
        color[start]=col;
        for(auto it: adj[start])
        {
            if(color[it]==-1)
            {
                if(dfs(it, !col, adj, color)==false)
                    return false;
            }
            else if(color[it]==col)
                return false;
        }
        return true;
    }
    public:
    bool bipartitieGraph(int V, vector<int> adj[])
    {
        int color[V];
        F(i, V)
            color[i]= -1;
        F(i, V)
        {
            if(color[i]==-1)
            {
                if(dfs(i, 0, adj, color)==false)
                    return false;
            }
        }
        return true;
    }
};


int main()
{
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.bipartitieGraph(V, adj);    
		if(ans)cout << "\n1\n";
		else cout << "\n0\n";  
	}
	return 0;
}
