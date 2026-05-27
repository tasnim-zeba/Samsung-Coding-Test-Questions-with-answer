// Tutorial Link: https://youtu.be/OJX1umVCsJc?si=zHdAHq7ltHbCvZt4
#include<iostream>
#include<vector>
using namespace std;
bool isLeft(int x)
{
    if(x==1||x==3||x==6||x==7)return true;
    else return false;
}
bool isRight(int x)
{
    if(x==1||x==3||x==4||x==5)return true;
    else return false;
}
bool isUp(int x)
{
    if(x==1||x==2||x==4||x==6)return true;
    else return false;
}
bool isDown(int x)
{
    if(x==1||x==2||x==5||x==6)return true;
    else return false;
}
void paths(int x, int y, int n, int m, int l, vector<vector<int>>&v, vector<vector<int>> &vis)
{
    if(l==0 || x<0 || x>=n || y<0 || y>=m)return;
    vis[x][y]=1;
    if((x+1)<n && isDown(v[x][y]) && isUp(v[x+1][y]))
    {
        paths(x+1, y, n, m, l-1, v, vis);
    }
    if((x-1)>=0 && isUp(v[x][y]) && isDown(v[x-1][y]))
    {
        paths(x-1, y, n, m, l-1, v, vis);
    }
    if((y+1)<m && isRight(v[x][y]) && isLeft(v[x][y+1]))
    {
        paths(x, y+1, n, m, l-1, v, vis);
    }
    if((y-1)>=0 && isLeft(v[x][y]) && isRight(v[x][y-1]))
    {
        paths(x, y-1, n, m, l-1, v, vis);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m, x, y, l;
        cin>>n>>m>>x>>y>>l;
        vector<vector<int>>v(n+1, vector<int>(m+1)), vis(n+1, vector<int>(m+1, 0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>v[i][j];
            }
        }
        paths(x, y, n, m, l, v, vis);
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(vis[i][j]==1)ans++;
            }
        }
        cout<<ans<<endl;
    }
}
