// Tutorial Link: https://youtu.be/JE0JE8ce1V0?si=eV611RgHwCqSCe2I

#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int dfs(int indx, int isV, vector<vector<int>>&v, int n, vector<vector<int>> &dp)
{
    if(dp[indx][isV]!=-1)return dp[indx][isV];
    int high = (1<<n)-1;
    if(isV==high){
        return v[indx][0];
    }
    int mn = INT_MAX;
    for(int i=0; i<n; i++)
    {
        if((1<<i)&isV);
        else{
            mn = min(mn, v[indx][i]+dfs(i, (1<<i)|isV, v, n, dp));
        }
    }
    return dp[indx][isV] = mn;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>>v(n+2, vector<int>(n+2));
        int r = (1<<n)+2;
        vector<vector<int>>dp(n+2, vector<int>(r, -1));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>v[i][j];
            }
        }
        int cost = dfs(0, 1, v, n, dp);
        cout<<cost<<endl;
    }
}