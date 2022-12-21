#include<bits/stdc++.h>
using namespace std;
#define F(i, n)     for(int i=0; i<n; i++)

// Graph with odd length is non-Bipartitie Graph
class Solution
{
    private:
    bool bfs(int start, vector<int> adj[], int color[])
    {
        color[start]=0;
        queue<int>q;
        q.push(start);

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto it: adj[node])
            {
                // if the adjacent node is yet not colored 
                // you will give the opposite color of the node
                if(color[it]==-1){
                    color[it] = !color[node];
                    q.push(it);
                }
                // if the adjacent guy having the same color
                // someone did color it one some other path
                else if(color[it]==color[node])
                    return false;
            }
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
                if(bfs(i, adj, color)==false)
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
