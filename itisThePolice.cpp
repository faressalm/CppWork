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
#define MAXIN       2*1e5+9
#define clr(x,val)  memset(x,val,sizeof(x))
#define fast cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

using namespace std;

int main()
{
    fast;
    int n,m;
    cin>>n>>m;
    vector<vi> squares(n+1);
    vector<int> police(n+1,1);
    loop(m){
    int s1,s2;
    cin>>s1>>s2;
    squares[s1].PB(s2);
    squares[s2].PB(s1);
    }
    int maxsize=MAXIN;
    int index=0;
    loop(n){
    if(squares[i].size()< maxsize){
        maxsize=squares[i].size();
        index=i;
    }
    }
    police[index]=0;
    for(int squ:squares[index]){
        police[squ]=0;
    }

    loop(n){
    cout<<police[i]<<" ";
    }
    return 0;
}
