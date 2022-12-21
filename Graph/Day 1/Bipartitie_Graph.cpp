#include<bits/stdc++.h>
using namespace std;
#define F(i, n)     for(int i=0; i<n; i++)

class Solution
{
    private:
    bool check(int start, vector<int>adj[], int color[])
    {
        queue<int> q;
        color[start]=0;
        q.push(start);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(auto it: adj[node])
            {
                if(color[it]==-1)
                {
                    color[it] = !color[node];
                    q.push(it);
                }
                else if(color[it]==color[node])
                    return false;
            }
        }
        return true;
    }
    public:
	bool isBipartite(int V, vector<int>adj[])
    {
        int color[V];
        F(i, V)
            color[i] = -1;
        
        F(i, V)
        {
            if(color[i]==-1)
            {
                if(check(i, adj, color)==false)
                    return false;
            }
        }
        return true;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}