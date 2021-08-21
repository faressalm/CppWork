#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pi;
typedef pair<int,string> path;
typedef vector<int> vi;
#define loop(n)     for(int i=1;i<=(n);i++)
#define loopzero(n)     for(int j=0;j<(n);j++)
#define MP          make_pair
#define all(a)      a.begin(), a.end()
#define MAXIN       1000
#define clr(x,val)  memset(x,val,sizeof(x))
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
ll rouds[MAXIN+9][MAXIN+9];
int size_N=0;
/**
*first is num
*second is zeros
*/
pi get_trailingzeros(ll num){
 int count=0;
 while(num!=0&&num%10==0){
    count++;
    num/=10;
 }
return make_pair(num,count);
}
path soluiton(ll num,pi index,string way,int zeros){
    pi temp1,temp2;

if(index.first==size_N&&index.second==size_N){
    return make_pair(zeros,way);
}else if(index.first<size_N&&index.second<size_N){
    ///go right
    temp1=get_trailingzeros(rouds[index.first][index.second+1]);
    temp2=get_trailingzeros(temp1.first*num);
    path x=soluiton(temp2.first,make_pair(index.first,index.second+1),way+"R",zeros +temp1.second+temp2.second);
    ///go down
    temp1=get_trailingzeros(rouds[index.first+1][index.second]);
    temp2=get_trailingzeros(temp1.first*num);
    path y=soluiton(temp2.first,make_pair(index.first+1,index.second),way+"D",zeros +temp1.second+temp2.second);
    if(y.first<=x.first){
        return y;
    }else{
    return x;
    }
}else if(index.second<size_N){
    ///go right
    temp1=get_trailingzeros(rouds[index.first][index.second+1]);
    temp2=get_trailingzeros(temp1.first*num);
    return soluiton(temp2.first,make_pair(index.first,index.second+1),way+"R",zeros +temp1.second+temp2.second);
}else if(index.first<size_N){
    ///go down
    temp1=get_trailingzeros(rouds[index.first+1][index.second]);
    temp2=get_trailingzeros(temp1.first*num);
    return soluiton(temp2.first,make_pair(index.first+1,index.second),way+"D",zeros +temp1.second+temp2.second);
}

}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
   cin>>size_N;
    for(int j=1;j<=size_N;j++){
        loop(size_N){
        cin>>rouds[j][i];
        }
    }
 pi x=get_trailingzeros(rouds[1][1]);
 path sol =soluiton(x.first,make_pair(1,1),"",x.second);

 cout<<sol.first<<"\n"<<sol.second;
    return 0;
}
