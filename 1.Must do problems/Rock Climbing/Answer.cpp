#include<iostream>
#include<vector>
using namespace std;
bool ans = false;
int n, m;
void dfs(int i, int j, int l, vector<vector<int>> &v, vector<vector<int>> &vis)
{
    if(vis[i][j])return;
    if(v[i][j]==3){
        ans = true;
        return;
    }
    vis[i][j]=true;
    if((j+1)<m && v[i][j+1]!=0 && vis[i][j+1]==false)
    {
        dfs(i, j+1, l, v, vis);
    }
    if((j-1)>=0 && v[i][j-1]!=0 && vis[i][j-1]==false)
    {
        dfs(i, j-1, l, v, vis);
    }
    
    for(int h=0; h<=l; h++)
    {
        if(i-h>=0 && v[i-h][j]!=0 && vis[i-h][j]==false)
        {
            dfs(i-h, j, l, v, vis);
        }
        if((i+h)<n && v[i+h][j]!=0 && vis[i+h][j]==false)
        {
            dfs(i+h, j, l, v, vis);
        }
    }
}
int main()
{ 
    cin>>n>>m;
    vector<vector<int>>v(n+2, vector<int>(m+2));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>v[i][j];
        }
    }
    for(int l=0; l<n; l++)
    {
        vector<vector<int>>vis(n+2, vector<int>(m+2, false));
        dfs(n-1, 0, l, v, vis);
        if(ans)
        {
            cout<<l<<endl;
            break;
        }
    }
}