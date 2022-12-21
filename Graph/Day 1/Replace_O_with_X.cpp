#include <bits/stdc++.h>
using namespace std;

#define F(i, n) for(int i=0; i<n; i++)

class Solution
{
    private:
    void dfs(int row, int col, vector<vector<char>>&mat, vector<vector<int>>&vis, int delrow[], int delcol[])
    {
        vis[row][col]=1;
        int n=mat.size();
        int m=mat[0].size();

        for(int i=0; i<4; i++)
        {
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol]=='O')
            {
                dfs(nrow, ncol, mat, vis, delrow, delcol);
            }
        }
    }
    public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>>vis(n, vector<int>(m, 0));

        int delrow[]={-1, 0, 1, 0};
        int delcol[] = {0, +1, 0, -1};

        // traverse colums
        F(col, m)
        {
            if(mat[0][col]=='O' && !vis[0][col])
                dfs(0, col, mat, vis, delrow, delcol);
            if(mat[n-1][col]=='O' && !vis[n-1][col])
                dfs(n-1, col, mat, vis, delrow, delcol);
        }

        // traverse rows
        F(row, n)
        {
            if(mat[row][0]=='O' && !vis[row][0])
                dfs(row, 0, mat, vis, delrow, delcol);
            if(mat[row][m-1]=='O' && !vis[row][m-1])
                dfs(row, m-1, mat, vis, delrow, delcol);
        }

        F(i, n)
        {
            F(j, m)
            {
                if(!vis[i][j] && mat[i][j]=='O')
                {
                    vis[i][j]=1;
                    mat[i][j]='X';
                }   
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        cout<<"\n";
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}