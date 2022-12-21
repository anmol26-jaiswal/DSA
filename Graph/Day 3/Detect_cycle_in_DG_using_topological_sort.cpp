#include<bits/stdc++.h>
using namespace std;
#define F(i, n)     for(int i=0; i<n; i++)

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	bool isCyclic(int V, vector<int> adj[]) 
    {
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
        int cnt=0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it: adj[node])
            {
                inedge[it]--;
                if(inedge[it]==0)
                    q.push(it);
            }
        }
        if(cnt==V)
            return false;
        return true;
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
        cout << endl<< obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
