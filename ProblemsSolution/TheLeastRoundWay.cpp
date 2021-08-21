#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pi;
typedef vector<int> vi;
#define loop(n)     for(int i=1;i<=(n);i++)
#define loopzero(n)     for(int j=0;j<(n);j++)
#define MP          make_pair
#define all(a)      a.begin(), a.end()
#define MAXIN       1000
#define clr(x,val)  memset(x,val,sizeof(x))
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int rouds[MAXIN+9][MAXIN+9];
pi dp[MAXIN+9][MAXIN+9]; /// first : product of numbers      second: count of trailing zeros
int size_N=0;

pi get_trailingzeros(ll num)
{
    int count=0;
    while(num!=0&&num%10==0)
    {
        count++;
        num/=10;
    }
    return make_pair(num,count);     /// first : product of numbers      second: count of trailing zeros
}

pi sol(int i, int j)
{
    if(i==size_N-1 && j==size_N-1)
        return get_trailingzeros(rouds[i][j]);
    if(i==size_N || j==size_N)
        return make_pair(1,INT_MAX);
    if(i==j&&j==0) {}
    else if(dp[i][j].second != -1)
        return dp[i][j];
    pi temp = get_trailingzeros(rouds[i][j]);
    pi s1,s2;
    s1=sol(i+1, j);
    s2=sol(i, j+1);
    pi temp1,temp2;
    temp1=get_trailingzeros(temp.first*s1.first);
    temp2=get_trailingzeros(temp.first*s2.first);
    if(s1.second+temp1.second<=s2.second+temp2.second)
    {
        temp1.second=+temp1.second+temp.second+s1.second;
        return dp[i][j] =temp1;
    }
    else
    {
        temp2.second=temp2.second+temp.second+s2.second;
        return dp[i][j] =temp2;
    }
}

void print(int i, int j)
{
    if(i==size_N-1 && j==size_N-1)
        return;

    pi ans = sol(i, j);
    if(i==0&&j==0)
        cout<<ans.second<<endl;
    pi temp = get_trailingzeros(rouds[i][j]);
    pi solu = sol(i+1, j);
    if(ans.second == get_trailingzeros(temp.first*solu.first).second +temp.second+solu.second)
    {
        cout << "D";
        print(i+1, j);
    }

    else
    {
        cout << "R";
        print(i, j+1);
    }
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>size_N;
    for(int i=0; i<size_N; i++)
    {
        loopzero(size_N)
        {
            cin>>rouds[i][j];
        }
    }
    for(int i=0; i<size_N; i++)
    {
        loopzero(size_N)
        {
            dp[i][j].first=1;
            dp[i][j].second=-1;
        }
    }

    dp[0][0]=get_trailingzeros(rouds[0][0]);
    print(0,0);
    cout<<endl;
    for(int i=0; i<size_N; i++)
    {
        loopzero(size_N)
        {
            cout<<"("<<dp[i][j].first<<","<<dp[i][j].second<<") ";
        }
        cout<<endl;
    }
    return 0;
}
