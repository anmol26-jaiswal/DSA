#include<bits/stdc++.h>
using namespace std;
#define F(i, n)     for(int i=0; i<n; i++)

class Solution
{
	public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) 
    {
        vector<int> adjRev[V];
        int inedge[V]={0};
        F(i, V)
        {
            for(auto it: adj[i])
            {
                adj[it].push_back(i);
                inedge[i]++;
            }
        }
        queue<int> q;
        for(int i=0; i<V; i++)
        {
            if(inedge[i]==0)
                q.push(i);
        }
        vector<int> safeNodes;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for(auto it: adjRev[node])
            {
                inedge[it]--;
                if(inedge[it]==0)
                    q.push(it);
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        cout<<"\nNumber of Eventual Safe States- ";
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

