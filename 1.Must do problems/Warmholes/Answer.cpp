//https://youtu.be/ze8COJwx-KA?si=kj7k5VML332OaAcy

#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
class Hole{
    public:
    int fx, fy, lx, ly, c;
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int sx, sy, ex, ey;
        cin>>sx>>sy>>ex>>ey;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<Hole>v;
        v.push_back({sx, sy, sx, sy, 0});
        vector<int>dis(2*n+2, 1e9);
        for(int i=1; i<=n; i++)
        {
            int fx, fy, lx, ly, c;
            cin>>fx>>fy>>lx>>ly>>c;
            v.push_back({fx, fy, lx, ly, c});
            v.push_back({lx, ly, fx, fy, c});
        }
        v.push_back({ex, ey, ex, ey, 0});
        dis[0]=0;
        pq.push({0, 0});
        while(pq.size())
        {
            int d = pq.top().first, node = pq.top().second;
            pq.pop();
            for(int i=0; i<2*n+2; i++)
            {
                //distance from node to i
                int d2 = abs(v[node].lx-v[i].fx)+abs(v[node].ly-v[i].fy)+v[i].c;
                if(d+d2<dis[i])
                {
                    dis[i]=d+d2;
                    pq.push({dis[i], i});
                }
            }
        }
        cout<<dis[2*n+1]<<endl;
    }
}