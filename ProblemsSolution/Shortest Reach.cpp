#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
#define loop(n)     for(int i=1;i<=(n);i++)
#define loopzero(n)     for(int j=0;j<(n);j++)
#define MP          make_pair
#define all(a)      a.begin(), a.end()
#define MAXIN       1000
#define clr(x,val)  memset(x,val,sizeof(x)) 
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


///            <---- solution------>
 vi bfs(int n, int m, vector<vi> edges, int s) {
  vector<vi> graph (n+9);
  vi distances(n+9,-1);
  
  loopzero(m){
      graph[edges[j][0]].push_back(edges[j][1]);
      graph[edges[j][1]].push_back(edges[j][0]);
  }

  distances[s]=0;
  queue<int> q;
  q.push(s);
  while(!q.empty()){
       int node = q.front();   q.pop();
        int cost = distances[node];

        for(int child: graph[node])     if(distances[child]== -1)
        {
            q.push(child);
            distances[child] = cost+6;
        }

  }
  vi f;
  for(int i=1;i<=n;i++){
      if(i!=s)
     f.push_back(distances[i]);
  }
    
  return f;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        vector<vector<int>> edges(m);

        for (int i = 0; i < m; i++) {
            edges[i].resize(2);

            string edges_row_temp_temp;
            getline(cin, edges_row_temp_temp);

            vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int edges_row_item = stoi(edges_row_temp[j]);

                edges[i][j] = edges_row_item;
            }
        }

        string s_temp;
        getline(cin, s_temp);

        int s = stoi(ltrim(rtrim(s_temp)));

        vector<int> result = bfs(n, m, edges, s);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
