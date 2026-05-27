#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;
int p=0, ans = INT_MAX, n;
void distanceWalk(int indx, int cost, int cnt, vector<int>&gateNo, vector<int>&fisherman)
{
    if(cnt==p)
    {
        ans = min(ans, cost);
        return;
    }
    if(indx>n)return;
    for(int i=1; i<=3; i++)
    {
        if(fisherman[i]>0)
        {
            fisherman[i]--;
            distanceWalk(indx+1, abs(gateNo[i]-indx)+1+cost, cnt+1, gateNo, fisherman);
            fisherman[i]++;
        }
    }
    distanceWalk(indx+1, cost, cnt, gateNo, fisherman);
}
int main()
{
    cin>>n;
    vector<int>gateNo(4), fisherman(4);
    for(int i=1; i<=3; i++)
    {
        cin>>gateNo[i];
    }
    for(int i=1; i<=3; i++)
    {
        cin>>fisherman[i];
        p=p+fisherman[i];
    }
    distanceWalk(1, 0, 0, gateNo, fisherman);
    cout<<ans<<endl;
}
