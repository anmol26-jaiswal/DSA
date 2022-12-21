#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> bfsOfGraph(int V, vector<int> adj[]){
            int vis[V]={0};
            vis[0]=1;

            vector<int> bfs;
            
            queue<int> q;
            q.push(0);
            while(!q.empty())
            {
                int node = q.front();
                bfs.push_back(node);
                q.pop();
                for(auto it: adj[node])
                {
                    if(!vis[it])
                    {
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }
            return bfs;
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
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for(int i=0; i<ans.size(); i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
