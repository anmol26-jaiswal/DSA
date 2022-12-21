#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
        // DFS Algorithm
        void dfs(int node, vector<int> adj[], int vis[], vector<int> &res)
        {
            vis[node]=1;
            res.push_back(node);
            for(auto it: adj[node])
            {
                if(!vis[it])
                    dfs(it, adj, vis, res);
            }
        }
    public:
        vector<int> dfsOfGraph(int V, vector<int> adj[]){
            int vis[V]={0};
            vector<int> ans;
            for(int i=0; i<V; i++)
            {
                if(!vis[i])
                    dfs(i, adj, vis, ans);
            }
            return ans;
        }
};

int main()
{
    int tc;
    cin>>tc;
    while(tc--){
        int V, E;
        cin>>V>> E;

        vector<int> adj[V];
        for(int i=0; i<E; i++)
        {
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for(int i=0; i<ans.size(); i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
