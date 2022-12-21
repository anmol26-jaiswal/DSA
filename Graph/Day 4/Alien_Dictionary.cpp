#include<bits/stdc++.h>
using namespace std;
#define F(i, n)     for(int i=0; i<n; i++)

/*
Additional Cases:- When the order is not possible?
Case 1- 
s1 = abcd
s2 = abc    
Reason - string "s2" all character mataching with "s1" and any how "s2" will larger than "s1" so order is not possible.

Case 2-
s1 = abc 
s2 = bad 
s3 = ade
Reason - if we take s1 & s2 then order a<b but if we take third string in consideration, order is not possible.
*/

class Solution
{
    private:
    vector<int>  topologicalSort(int V, vector<int> adj[])
    {
        int indegree[V]={0};
        for(int i=0; i<V; i++)
        {
            for(auto it: adj[i])
                indegree[it]++;
        }
        queue<int> q;
        for(int i=0; i<V; i++)
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
            for(auto it: adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        return topo;
    }
    public:
    string findOrder(string dict[], int N, int K) 
    {
        vector<int> adj[K];
        F(i,N-1)
        {
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.length(), s2.length());
            F(i, len)
            {
                if(s1[i]!=s2[i])
                {
                    adj[s1[i]-'a'].push_back(s2[i]-'a');
                    break;
                }
            }
        }
        vector<int> topo = topologicalSort(K, adj);
        string ans = "";
        for(auto it: topo)
            ans = ans + char(it+'a');
            
        return ans;
    }
};


string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) 
        return a.size() < b.size();

    return p1 < p2;
}

int main() {
    int t;
    cin >> t;
    while (t--) 
    {
        int N, K;
        cin >> N >> K;
        string dict[N];
        F(i, N)
            cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        cout<<"\nOrder: "<<ans<<endl;
        order = "";

        F(i, ans.size()) 
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        F(i, N)
            if (dict[i] != temp[i]) 
                f = false;
        cout<<"Result: ";
        if(f)
            cout << 1;
        else 
            cout << 0;
        cout << endl;
    }
    return 0;
}