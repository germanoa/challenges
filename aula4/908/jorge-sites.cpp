#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

typedef pair<int, int> ii;      // In this chapter, we will frequently use these
typedef vector<ii> vii;      // three data type shortcuts. They may look cryptic
typedef vector<int> vi;   // but shortcuts are useful in competitive programming

vector< vector< pair<int,int> > > g;

int prim(int n)
{
  priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > q;
  //bool vis[n] = {0};
  bool vis[n]; for(int i=0; i<n; ++i) vis[i] = 0;
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

int main() {

	int N, M, K, x, y, z, i;

	while(cin >> N) {

		i = N-1;

		int custoAntigo = 0, novoCusto = 0;

		while(i--) {
			
			cin >> x >> y >> z;

			// CALCULAR CUSTO ANTIGO
		
			custoAntigo += z;

		}

		g.assign(N, vii()); // assign blank vectors of pair<int, int>s to

		cin >> K;

		i = K;
	
		while(i--) {

			cin >> x >> y >> z;

			// inserir no grafo

			g[x-1].push_back(ii(y-1, z));

		}

		cin >> M;

		i = M;
		
		while(i--) {

			cin >> x >> y >> z;

			// inserir no grafo

			g[x-1].push_back(ii(y-1, z));

		}

		// PRIM

		novoCusto = prim(N);

		cout << custoAntigo << endl << novoCusto << endl << endl;
	
	}

	return 0;
}
