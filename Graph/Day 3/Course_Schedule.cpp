#include<bits/stdc++.h>
using namespace std;
#define F(i, n)     for(int i=0; i<n; i++)

class Solution
{
	public:
    vector<int> findOrder(int V, int m, vector<vector<int>> prerequisites) 
    {
        vector<int> adj[V];
        for(auto it: prerequisites)
            adj[it[1]].push_back(it[0]);

        int inedge[V]={0};
        F(i, V)
        {
            for(auto it: adj[i])
                inedge[it]++;
        }

        queue<int> q;
        F(i, V)
        {
            if(inedge[i]==0)
                q.push(i);
        }
        vector<int> topo;
        while(!q.empty())
        {
            int node =q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adj[node])
            {
                inedge[it]--;
                if(inedge[it]==0)
                    q.push(it);
            }
        }
        if(topo.size()==V)
            return topo;
        return {};
    }
};

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        cout<<"\nAns: ";
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}