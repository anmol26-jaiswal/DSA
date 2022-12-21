#include <bits/stdc++.h>
using namespace std;
#define F(i, n)     for(int i=0; i<n; i++)

class Solution {
    private:
    void topoSort(int node,vector<pair<int, int>> adjList[], int vis[], stack<int>&st )
    {
        vis[node]=1;
        for(auto it: adjList[node])
        {
            int v = it.first;
            if(!vis[v])
                topoSort(v, adjList, vis, st);
        }
        st.push(node);
    }
  public:
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges)
    {
       vector<pair<int, int>> adjList[N];
       int src = 0;
       F(i, M)
       {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adjList[u].push_back({v, wt});
       } 

       // find the topo Sort
       stack<int> st;
       int vis[N]={0};
       F(i, N)
       {
            if(!vis[i])
                topoSort(i, adjList, vis, st);
       }

       // step 2 do the distance thing
       vector<int> dist(N, 1e9);
        dist[src]=0;                    // if source given then we will assign 0 to that
        while(!st.empty())
        {
            int node = st.top();
            st.pop();

            if(dist[node]!=1e9)
            {
                for(auto it: adjList[node])
                {
                    if(dist[node]+it.second < dist[it.first])
                        dist[it.first] = (dist[node]+it.second);
                }
            }
        }
        F(i, 9)
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
            F(i, 3){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        cout<<"\nShortest path of DAG: ";
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}