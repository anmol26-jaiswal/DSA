#include <bits/stdc++.h>
using namespace std;

#define F(i, n) for(int i=0; i<n; i++)

class Solution
{
    public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n=grid.size();
        int m = grid[0].size();

        int vis[n][m];
        queue<pair< pair<int, int>, int>> q;
        int cntFresh = 0;
        F(i, n)
        {
            F(j, m)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
                if(grid[i][j]==1)
                    cntFresh++;
            }
        }
        int tm=0;
        int drow[]={-1, 0, +1, 0};
        int dcol[]={0, +1, 0, -1};
        int cnt=0;
        
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(tm, t);

            for(int i=0; i<4; i++)
            {
                int nrow = r+drow[i];
                int ncol = c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1)
                {
                    q.push({{nrow, ncol}, t+1});
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }

        // to check all oranges are rotten or not;
        if(cnt!=cntFresh)
            return -1;
        return tm;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
        cout<<endl;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}