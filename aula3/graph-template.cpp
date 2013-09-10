#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef pair<int, int> ii;      
typedef vector<ii> vii;      
typedef vector<int> vi;   

#define DFS_WHITE -1 
#define DFS_BLACK 1
#define DFS_COLOR1 2
#define DFS_COLOR2 3

vector<vii> AdjList;

vi dfs_num;     
int numCC;

void dfs(int u) {          
  printf(" %d", u);                                    
  dfs_num[u] = DFS_BLACK;      
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    ii v = AdjList[u][j];                      
    if (dfs_num[v.first] == DFS_WHITE)         
      dfs(v.first);      
} }

int main() {

    return 0;
}
