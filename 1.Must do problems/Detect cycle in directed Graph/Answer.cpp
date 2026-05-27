///Similar Tutorial: https://youtu.be/9twcmtQj4DU?si=3KpBv2awNW8aV2tS

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
vector<int>ans;
int s;
int pathSum(vector<int> &path)
{
    int c=0;
    for(auto ch: path)
    {
        c=c+ch;
    }
    return c;
}
void detect(int u, vector<vector<int>> &g,vector<int> &pathVis, vector<int> &path)
{
    pathVis[u] = true;
    //vis[u] = true;
    path.push_back(u);
    for(auto v: g[u])
    {
        if(pathVis[v])
        {
            if(path[0]==v)
            {
                if(pathSum(path)<s)
                {
                    ans = path;
                    s=pathSum(path);
                  
                }
            }
            else{
                continue;
            }
        }
        else{
            detect(v, g, pathVis, path);
        }
        // if(vis[v])continue;
        
        
    }
    path.pop_back();
    pathVis[u]=false;
    
}
int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>>g(n+2);
    
    for(int i=1; i<=m; i++)
    {
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
    }
    s=INT_MAX;
    for(int i=1; i<=n; i++)
    {
        vector<int>pathVis(n+2, false), path;
        detect(i, g, pathVis, path);
    }
    sort(ans.begin(), ans.end());
    for(auto ch: ans)
    {
        cout<<ch<<" ";
    }
}