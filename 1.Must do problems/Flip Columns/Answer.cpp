//Similar problem Tutorial(not exactly same): https://youtu.be/fnfIHOXfgdc?si=u5EBD0VtLyuIPT_e

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
int main()
{
    int n, m, k;
    cin>>n>>m>>k;
    unordered_map<string, int>mp;
    for(int i=0; i<n; i++)
    {
        string s="";
        int nf=0;
        for(int j=0; j<m; j++)
        {
            int x;
            cin>>x;
            if(x==1)s.push_back('1');
            else{
                s.push_back('0');
                nf++;
            }
        }
        int re = k%nf;
        if(k>=nf && re%2==0)
        {
            mp[s]++;
        } 
    }
    int ans = 0;
    for(auto it: mp)
    {
        ans = max(ans, it.second);
    }
    cout<<ans<<endl;
}