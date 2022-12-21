#include<bits/stdc++.h>
using namespace std;
#define F(i, n)     for(int i=0; i<n; i++)

class Solution
{
    private:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, vector<pair<int, int>> &vec, int row0, int col0)
    {
        vis[row][col]=1;
        vec.push_back({row-row0, col-col0});
        int n = grid.size();
        int m= grid[0].size();

        int delrow[]={-1, 0, +1, 0};
        int delcol[]={0, +1, 0, -1};

        for(int i=0; i<4; i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol])
                dfs(nrow, ncol, grid, vis, vec, row0, col0);
        }
    }
    public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m= grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));

        set<vector<pair<int, int>>> st;
        F(i, n)
        {
            F(j, m)
            {
                if(!vis[i][j]&& grid[i][j]==1)
                {
                    vector<pair<int, int>>vec;
                    dfs(i, j, grid, vis, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};

int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n, m;
        cin>>n>>m;
        vector<vector<int>>grid(n, vector<int>(m));
        F(i, n)
        {
            F(j, m)
            {
                cin>>grid[i][j];
            }
        }
        Solution ob;
        cout<<endl<<ob.countDistinctIslands(grid)<<endl;
    }
    return 0;
}