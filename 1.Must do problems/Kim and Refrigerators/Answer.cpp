//Similar to Travelling SalesPerson Problem
#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;
int dfs(int indx, int mask, vector<pair<int,int>> &v, vector<vector<int>> &dp, int n)
{
    if(mask == ((1<<n)-1))
    {
        int dis = abs(v[indx].first-v[n].first) + abs(v[indx].second-v[n].second);
        return dis;
    }
    if(dp[indx][mask]!=-1) return dp[indx][mask];
    int mn=INT_MAX;
    for(int i=0; i<n; i++)
    {
        if(i==indx)continue;
        else if((1<<i)&mask);
        else{
            int dis = abs(v[indx].first-v[i].first) + abs(v[indx].second-v[i].second);
            mn = min(mn, dis + dfs(i, (1<<i)|mask, v, dp, n));
        }
    }
    return dp[indx][mask]=mn;
}
int main()
{
    for(int t=1; t<=10; t++)
    {
        int n;
        cin>>n;
        int sx, sy, ex, ey;
        cin>>sx>>sy>>ex>>ey;
        vector<pair<int,int>>v;
        int high = (1<<(n+3));
        vector<vector<int>>dp(n+3, vector<int>(high, -1));
        v.push_back({sx, sy});
        for(int i=0; i<n; i++)
        {
            int x, y;
            cin>>x>>y;
            v.push_back({x, y});
        }
        v.push_back({ex, ey});
        int ans = dfs(0, 1, v, dp, n+1);
        cout<<"# "<<t<<" "<<ans<<endl;
    }
    
}