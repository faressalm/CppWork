#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
#define PB push_back
#define loop(n)     for(int i=1;i<=(n);i++)
#define loopzero(n)     for(int j=0;j<(n);j++)
#define MP          make_pair
#define all(a)      a.begin(), a.end()
#define MAXIN       1000000
#define clr(x,val)  memset(x,val,sizeof(x))
#define fast cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
vi bfs( vector<vi> shops, int s)
{
    vi distances(shops.size()+1,-1);
    distances[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        int cost = distances[node];

        for(int child: shops[node])
            if(distances[child]== -1)
            {
                q.push(child);
                distances[child] = cost+1;
            }

    }

    return distances;
}

int main()
{
    freopen("jumping.in", "r", stdin);
    fast;
    int tests;
    cin>>tests;
    while (tests--)
    {
        int N;
        cin>>N;
        vector<vi> shops (N+1);
        vi distances(N+1);
        loop(N)
        {
            int p;
            cin>>p;
            int u = i+p, v = i-p;
            if(v>=1)
                shops[v].PB(i);
            if(u<=N)
                shops[u].PB(i);
        }
        distances=bfs(shops,N);
        for(int j=1; j<=N; j++)
            cout<<distances[j]<<endl;
    }


    return 0;
}
