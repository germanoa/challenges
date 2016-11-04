#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int ret,n,r,v1,v2,c,s,d,t;

vvii g;

int min(int a, int b) {
  if (a < b) {
    return a;
  }
  else {
    return b;
    }

}


int dijkstra(int a, int b)
{
  //priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > q;
  priority_queue< pair<int,int>, vector< pair<int,int> > > q;
  vector< int > d(n, -1);
  pair<int,int> p; int v,w;
  q.push( make_pair(0,a) );
  while (!q.empty())
    {
      p = q.top(); q.pop();
      v = p.second;
      w = p.first;
      if ( d[v] != -1 ) continue;
      if (v == b) return w;
      d[v] = w;      

      for (int i = 0; i < (int)g[v].size(); ++i)
  if ( d[ g[v][i].first ] == -1 )
    {
      if (w==0) q.push( make_pair( g[v][i].second, g[v][i].first ) );
      else q.push( make_pair( min(w,g[v][i].second), g[v][i].first ) );
    }
      
    }
  return -1;
}

int main() {

  int ret2;
  bool first=true;
  int count=1;

  while (cin >> n) {
    cin >> r;
  
    if (n==0 && r==0) {
      break;
    }

    g.assign(n,vii());
    //The set T of previously chosen
    for (int i=0; i<r; ++i) {
      cin >> v1 >> v2 >> c;
      g[v1-1].push_back(make_pair(v2-1,c));
    }

    cin >> s >> d >> t;

    if (!first) {
      cout << endl;
      first=false;
    }
    
    ret = dijkstra(s-1,d-1);
    ret2=1;
    if(ret>0) {
      ret--; //motorista
      ret2 = t/ret;
      if (t%ret!=0) ret2++;
    }
    

    cout << "Scenario #" << count++ << endl;
    cout << "Minimum Number of Trips = " << ret2 << endl;

    //clear g
    for (int i=0; i<n; ++i) {
      g[i].clear();
    }
    g.clear();
  }

}

