#include<bits/stdc++.h>
using namespace std;

#define F(i, n)  for(int i=0; i<n; i++)

class Solution{
    private:
    void dfs(int node, vector<int> adjLs[], int vis[])
    {
        vis[node] = 1;
        for(auto it: adjLs[node])
        {
            if(!vis[it])
                dfs(it, adjLs, vis);
        }
    }
    public:
    int numProvinces(vector<vector<int>> adj, int V)
    {
        vector<int> adjs[V];
        F(i, V)
        {
            F(j, V)
            {
                if(adj[i][j]==1 && i!=j)
                {
                    adjs[i].push_back(j);
                    adjs[j].push_back(i);
                }
            }
        }
        int vis[V] = {0};
        int cnt=0;
        F(i, V)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(i, adjs, vis);
            }
        }
        return cnt;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends