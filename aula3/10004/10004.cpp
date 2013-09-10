#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef pair<int, int> ii;      
typedef vector<ii> vii;      
typedef vector<int> vi;   

#define DFS_WHITE -1 
#define DFS_BLACK -2 
#define DFS_COLOR1 0
#define DFS_COLOR2 1

vector<vii> AdjList;

vi dfs_num;     
bool bicolorable;

void dfs(int u,int color) {          
    dfs_num[u] = color % 2; // 0 || 1
    color++;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];                      
        if (dfs_num[v.first] == DFS_WHITE) {        
            dfs(v.first, color);
        }
        else if (dfs_num[v.first] == dfs_num[u]) {
            bicolorable=false;
        } 
    }
}

int main() {

    int v,e,v1,v2;
    while (1) {
        bicolorable=true;
        cin >> v;
        if (v == 0) break;
        AdjList.assign(v,vii());
        dfs_num.assign(v,DFS_WHITE);
        cin >> e;
        for (int i = 0; i < e; i++) {
            cin >> v1 >> v2;
            AdjList[v1].push_back(ii(v2,0));
            AdjList[v2].push_back(ii(v1,0));
        }
        dfs(v1, DFS_COLOR1);
        if (bicolorable) {
            cout << "BICOLORABLE." << endl;
        }
        else {
            cout << "NOT BICOLORABLE." << endl;

        }
    }

    return 0;
}
