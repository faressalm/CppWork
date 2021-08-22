#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
#define PB push_back
#define loop(n) for (int i = 1; i <= (n); i++)
#define loopzero(n) for (int j = 0; j < (n); j++)
#define MP make_pair
#define all(a) a.begin(), a.end()
#define MAXIN 1e5
#define clr(x, val) memset(x, val, sizeof(x))
#define fast                \
    cin.sync_with_stdio(0); \
    cin.tie(0);             \
    cout.tie(0);
#define endl '\n'
vector<pair<vi, int>> vertices(MAXIN + 9);
int resturants = 0;
int m;
void sol(int index, int consicutivOnes,int parent)
{
    int cat = vertices[index].second;
    if (cat)
    {
        if (cat + consicutivOnes > m)
            return;
        else
            consicutivOnes++;
    }
    else
    {
        consicutivOnes = 0;
    }
    if (vertices[index].first.empty()||(vertices[index].first.size()==1&&vertices[index].first[0]==parent))
    {
        resturants++;
        return;
    }

    loopzero(vertices[index].first.size())
    {
        int child=vertices[index].first[j];
        if(parent==child)
            continue;
        sol(child,consicutivOnes,index);
    }
}
int main()
{
    fast;
    int n;
    cin >> n >> m;

    loopzero(n)
    {
        cin >> vertices[j].second;
    }
    loopzero(n - 1)
    {
        int from, to;
        cin >> from >> to;
        vertices[from-1].first.PB(to-1);
        vertices[to-1].first.PB(from-1);
    }
    sol(0,0,0);
    cout<<resturants;
    return 0;
}
