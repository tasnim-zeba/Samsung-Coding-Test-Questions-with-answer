//Tutorial Link: https://youtu.be/Yz4LlDSlkns?si=8wZ7Akt6yUPC_efV
#include<iostream>
#include<vector>
using namespace std;
int burst(int i, int j, vector<int> &v, vector<vector<int>> &dp)
{
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int mx = 0;
    for(int in=i; in<=j; in++)
    {
        if(i==1 && j==(int)v.size()-2)
        {
            mx = max(mx, v[in] + burst(i, in-1, v, dp)+burst(in+1, j, v, dp));
        }
        else
        {
            mx = max(mx, v[i-1]*v[j+1]+burst(i, in-1, v, dp)+burst(in+1, j, v, dp));
        }
    }
    return dp[i][j]=mx;
}
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    v.push_back(1);
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    v.push_back(1);
    vector<vector<int>>dp(n+4, vector<int>(n+4, -1));
    int ans = burst(1, n, v, dp);
    cout<<ans<<endl;
}