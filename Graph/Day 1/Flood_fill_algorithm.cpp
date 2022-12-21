#include <bits/stdc++.h>
using namespace std;

#define F(i, n) for(int i=0; i<n; i++)

class Solution
{
    private:
    void dfs(int row, int col, vector<vector<int>>&image, int initColor, int newColor, int delrow[], int delcol[], vector<vector<int>>&res)
    {
        res[row][col]=newColor;
        int n=image.size();
        int m=image[0].size();

        for(int i=0; i<4; i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==initColor && res[nrow][ncol]!=newColor)
                dfs(nrow, ncol, image, initColor, newColor, delrow, delcol, res);
        }
    }
    public:
    vector<vector<int>> floodFill(vector<vector<int>>&image, int sr, int sc, int newColor)
    {
        int init=image[sr][sc];
        int delrow[]={-1, 0, +1, 0};
        int delcol[]={0, -1, 0, +1};

        vector<vector<int>> ans=image;
        dfs(sr, sc, image, init, newColor, delrow, delcol, ans);
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin>>n>>m;
        vector<vector<int>>image(n, vector<int>(m, 0));
        F(i,n)
        {
            F(j,m)
            {
                cin>>image[i][j];
            }
        }
        int sr, sc, newColor;
        cin>>sr>>sc>>newColor;
        
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        cout<<endl;
        for(auto i:ans)
        {
            for(auto j: i)
                cout<<j<<" ";
            cout<<"\n";
        }
    }
    return 0;
}