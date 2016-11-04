#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;


vvii g;

int prim(int n) {
  priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > q;
  bool vis[n]; for (int i=0; i<n; ++i) {vis[i] = 0;};
  pair<int,int> p; int v,w, ret = 0;
  q.push( make_pair(0,0) );
  while (!q.empty()) {

    p = q.top(); q.pop();
    v = p.second;
    w = p.first;
    if (vis[v] != 0) continue;
    vis[v] = 1;
    ret += w;

    for (int i = 0; i < g[v].size(); ++i) {
      if ( !vis[ g[v][i].first ] ) {
          q.push( make_pair( g[v][i].second, g[v][i].first ) ); //cost rules priority in queue so its the first element
      }
    }
  }
  return ret;
}


int main() {


  bool first=true;
  int n,k,m,v1,v2,c;

  while (cin >> n) {
    int r1=0,r2=0;

    g.assign(n,vii());
    //The set T of previously chosen
    for (int i=0; i<n-1; ++i) {
      cin >> v1 >> v2 >> c;
      r1 += c;
    }

    cin >> k;

    //new high-speed lines
    for (int i=0; i<k; ++i) {
      cin >> v1 >> v2 >> c;
      g[v1-1].push_back(make_pair(v2-1,c));
      g[v2-1].push_back(make_pair(v1-1,c));
    }

    cin >> m;

    //originally available high-speed lines
    for (int i=0; i<m; ++i) {
      cin >> v1 >> v2 >> c;
      g[v1-1].push_back(make_pair(v2-1,c));
      g[v2-1].push_back(make_pair(v1-1,c));
    }
    
    r2 = prim(n);

    if (!first) {
      cout << endl;
    }

    cout << r1 << endl;
    cout << r2 << endl;


    for (int i=0; i<g.size(); ++i) {
      g[i].clear();
    }
    g.clear();

    first=false;
  }


}
