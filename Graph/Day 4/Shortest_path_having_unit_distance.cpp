#include <bits/stdc++.h>
using namespace std;
#define F(i, n)     for(int i=0; i<n; i++)

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src)
    {
        // code here
        vector<int> adj[N];
        for(auto it: edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> dist(N, 1e9);
        dist[src] = 0;

        queue<int> q;
        q.push(src);

        while(!q.empty())
        {
            int nod = q.front();
            q.pop();
            if(dist[nod]!=1e9)
            {
                for(auto it: adj[nod])
                {
                    if(dist[nod]+1 < dist[it])
                    {
                        dist[it] = 1 + dist[nod];
                        q.push(it);
                    }
                }
            }
        }
        F(i, N)
        {
            if(dist[i]==1e9)
                dist[i]=-1;
        }
        return dist;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) 
    {
        int n, m; 
        cin >> n >> m;
        vector<vector<int>> edges;

        F(i, m)
        {
            vector<int> temp;
            F(i, 2){
                int x; 
                cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; 
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);
        cout<<"\nShortest path of DAG having unit distance: ";
        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}
