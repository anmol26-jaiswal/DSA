#include<bits/stdc++.h>
using namespace std;
#define F(i, n)     for(int i=0; i<n; i++)

// TopoLogical_Sort using BFS ( Kahn's Algorithm )
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
        int indegree[V]={0};
        F(i,V)
        {
            for( auto it: adj[i])
                indegree[it]++;
        }
        queue<int> q;
        F(i, V)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int> topo;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            // node is in your topo sort
            // so please remove it from the indegree

            for(auto it: adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        return topo;
    }
};

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/

int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    F(i, V){
        map[res[i]] = i;
    }
    F(i, V){
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) 
    {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        F(i, E){
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}