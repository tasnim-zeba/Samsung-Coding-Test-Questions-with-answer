#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dfs(int i, int j, vector<vector<int>> &v, int n, bool canBomb)
{
    if(i<0 || i>n || j<0 || j>=5)return 0;
    int ans = 0;
    if(v[i][j]==1)ans++;
    else if(v[i][j]==2)return 0;
    int op1=0, op2=0, op3=0, ans1=0, ans2=0;
    if(canBomb)
    {
        //will use bomb
        vector<vector<int>>tmp = v;
        for(int k=max((i-5), 0); k<i; k++)
        {
            for(int k2=0; k2<5; k2++)
            {
                if(tmp[k][k2]==2)
                {
                    tmp[k][k2]=0;
                }
            }
        }
        
        if((j-1)>=0)
        {
            op1 = dfs(i-1, j-1, tmp, n, false);
        }
        if((j+1)<5)
        {
            op2 = dfs(i-1, j+1, tmp, n, false);
        }
        op3 = dfs(i-1, j, tmp, n, false);
        ans1 = max({op1, op2, op3})+ans;
        
        //will not use bomb
        if((j-1)>=0)
        {
            op1 = dfs(i-1, j-1, v, n, true);
        }
        if((j+1)<5)
        {
            op2 = dfs(i-1, j+1, v, n, true);
        }
        op3 = dfs(i-1, j, v, n, true);
        
        ans2 = max({op1, op2, op3})+ans;
        
        return max(ans1, ans2);
        
    }
    else{
         //if can not use bomb
        if((j-1)>=0)
        {
            op1 = dfs(i-1, j-1, v, n, false);
        }
        if((j+1)<5)
        {
            op2 = dfs(i-1, j+1, v, n, false);
        }
        op3 = dfs(i-1, j, v, n, false);
        ans2 = max({op1, op2, op3})+ans;
        return ans2;
    }
   
}
int main()
{
    int t;
    cin>>t;
    for(int k=1; k<=t; k++)
    {
        int n;
        cin>>n;
        vector<vector<int>>v(n+2, vector<int>(5));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<5; j++)
            {
                cin>>v[i][j];
            }
        }
        for(int j=0; j<5; j++)
        {
            v[n].push_back(0);
        }
        int ans = dfs(n, 2, v, n, true);
        cout<<"#"<<k<<" "<<ans<<endl;
    }
}