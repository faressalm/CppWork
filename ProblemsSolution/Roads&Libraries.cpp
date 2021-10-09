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
#define MAXIN 100000 + 9
#define clr(x, val) memset(x, val, sizeof(x))
#define fast                \
    cin.sync_with_stdio(0); \
    cin.tie(0);             \
    cout.tie(0);
#define endl '\n'
bool hasLibrary[MAXIN];
vector<vi> edges(MAXIN);
pi pathsAndLibraries; /// first---> num Libraries     second----> num paths
void reset(){
    hasLibrary =stepHasLibrary;
    edges = stepEdges;
    pathsAndLibraries = MP(0, 0);
}

void dfs(int node)
{
    
    for (int neighbor : edges[node])
        if (!hasLibrary[neighbor])
        {
            hasLibrary[neighbor] = true;
            pathsAndLibraries.second++;
            dfs(neighbor);
        }
}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities)
{   
    reset();
    long coast = 0;
    if(c_lib<=c_road){
        coast=c_lib;
        coast*=(long)n;
        return coast;
    }

    
    int fromCity, toCity;
    // intialize the map
    loopzero(cities.size())
    {
        fromCity = cities[j][0];
        toCity = cities[j][1];

        edges[fromCity].PB(toCity);
        edges[toCity].PB(fromCity);
    }

    loop(n){
        if(!hasLibrary[i]){
            hasLibrary[i] = true;
             pathsAndLibraries.first++;
            dfs(i);
        }
    }
    coast=((long)pathsAndLibraries.first*(long)c_lib)+((long)pathsAndLibraries.second*(long)c_road);
    return coast;
}




int main()
{
    fast;
    return 0;
}
