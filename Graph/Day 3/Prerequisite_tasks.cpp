#include<bits/stdc++.h>
using namespace std;
#define F(i, n)     for(int i=0; i<n; i++)

class Solution
{
	public:
    bool isPossible(int V, vector<pair<int, int> >& prerequisites) 
    {
        int inedge[V]={0};
        vector<int> adj[V];
        F(i, V)
        {
            for(auto it: prerequisites)
                adj[it.first].push_back(it.second);
        }
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
	        int node = q.front();
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
	        return true;
	   return false;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        cout<<endl;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
