#include <bits/stdc++.h>
using namespace std;

#define F(i, n) for(int i=0; i<n; i++)

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        queue<pair<int, int>> q;

        int n=grid.size();
        int m = grid[0].size();

        int vis[n][m]={0};
        
        F(i, n)
        {
            F(j, m)
            {
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    if(grid[i][j]==1)
                    {
                        q.push({i, j});
                        vis[i][j]=1;
                    }
                }
            }
        }
        
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            F(i, 4)
            {
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1)
                {
                    q.push({nrow, ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
        int cnt=0;
        F(i, n)
        {
            F(j, m)
            {
                if(grid[i][j]==1 && vis[i][j]==0)
                    cnt++;
            }
        }
        return cnt;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        F(i, n)
        {
            F(j, m)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}