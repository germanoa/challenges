vector< vector< pair<int,int> > > g;

int prim()
{
  priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > q;
  bool vis[n] = {0};
  pair<int,int> p; int v,w, ret = 0;
  q.push( make_pair(0,0) );
  while (!q.empty())
    {
      p = q.top(); q.pop();
      v = p.second;
      w = p.first;
      if (vis[v] != 0) continue;
      vis[v] = 1;
      ret += w;

      for (int i = 0; i < g[v].size(); ++i)
  if ( !vis[ g[v][i].first ] )
    {
      q.push( make_pair( g[v][i].second, g[v][i].first ) );
    }
      
    }
  return ret;
}

int dijkstra(int a, int b)
{
  priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > q;
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
      

      for (int i = 0; i < g[v].size(); ++i)
  if ( d[ g[v][i].first ] == -1 )
    {
      q.push( make_pair( w+g[v][i].second, g[v][i].first ) );
    }
      
    }
  return -1;
}
