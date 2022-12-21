#include <bits/stdc++.h>
using namespace std;

#define F(i, n) for(int i=0; i<n; i++)

class Solution
{
    private:
    bool bfs(int src, vector<int> adj[], int vis[])
    {
        vis[src]=1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        while(!q.empty())
        {
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto adjNode: adj[node])
            {
                if(!vis[adjNode])
                {
                    vis[adjNode]=1;
                    q.push({adjNode, node});
                }
                else if(parent!=adjNode)                    // already visited and not parent, so cycle exist in graph
                    return true;
            }
        }
        return false;
    }
    public:
    bool isCycle(int V, vector<int> adj[])
    {
        int vis[V]={0};
        F(i, V)
        {
            if(!vis[i])
            {
                if(bfs(i, adj, vis)==true)
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
