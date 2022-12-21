#include <bits/stdc++.h>
using namespace std;

#define F(i, n) for(int i=0; i<n; i++)

class Solution
{
    private:
    void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis, int delrow[], int delcol[])
    {
        vis[row][col]=1;
        queue<pair<int, int>> q;
        q.push({row, col});

        int n=grid.size();
        int m=grid[0].size();

        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(int delrow=-1; delrow<=1; delrow++)
            {
                for(int delcol=-1; delcol<=1; delcol++)
                {
                    int nrow=r+delrow;
                    int ncol = c+delcol;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1')
                    {
                        q.push({nrow, ncol});
                        vis[nrow][ncol]=1;
                    }
                }
            }
        }
    }
    public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n= grid.size();
        int m= grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt=0;

        int delrow[]={-1, 0, +1, 0};
        int delcol[]={0, +1, 0, -1};

        F(row, n)
        {
            F(col, m)
            {
                if(!vis[row][col] && grid[row][col]=='1')
                {
                    cnt++;
                    bfs(row, col, grid, vis, delcol, delrow);
                }
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin>>n>>m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        F(i, n)
        {
            F(j, m)
                cin>>grid[i][j];
        }
        Solution obj;
        int ans= obj.numIslands(grid);
        cout<<ans<<'\n';
    }
    return 0;
}

