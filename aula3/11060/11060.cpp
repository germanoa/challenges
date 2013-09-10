#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

typedef vector<int> vi;      
typedef vector<string> vs;      
vector<vs>AdjList;
vector<vs>::iterator it;

map<string,pair<int,int> > beverages;
map<string,pair<int,int> >::iterator itb;
map<int,string> beverages_inv;

vector<string> final;
int c;

void print_bev() {
    for (itb = beverages.begin(); itb != beverages.end(); itb++) {
        cout << itb->first << " ";
    }
    cout << endl;
}

void print_adjlist(int y) {
    for (int i=0; i<(int)AdjList[y].size();i++) {
        cout << " "<< AdjList[y][i];
    }
    cout << endl;
}


void print_final() {
    cout << "Case #" << c << ": Dilbert should drink beverages in this order:" ; 
    for (int i=0; i<(int)final.size();i++) {
        cout << " "<< final[i];
    }
    cout << "." << endl;
}

void remove_node_adjlist(int i) {
    //print_adjlist(i);
    for (int j=0; j < (int)AdjList[i].size();j++) {
        beverages[AdjList[i][j]].second--;
        //cout << beverages_inv[beverages[AdjList[i][j]].first] << ": l" << beverages[AdjList[i][j]].second << endl;
    }
    //AdjList.erase(AdjList.begin()+i);
    //print_bev();
    //cout << "removing " << i << ": " << beverages_inv[i] << endl;
    beverages.erase(beverages_inv[i]);
    //print_bev();
    beverages_inv.erase(i);
}


int main() {

    int n,m;
    string null,beverage,b1,b2;
    priority_queue<int> l0;
    c=1;

    while(cin >> n) {
        // nodes
        for (int i=0; i<n; i++) {
            cin >> beverage;
            beverages[beverage].first=i; //index
            beverages[beverage].second=0; // init: level 0
            beverages_inv[i]=beverage; //will be used at working
        }
        // adjlist
        AdjList.assign(n,vs()); //init
        cin >> m;
        for (int i=0; i<m; i++) {
            cin>>b1;
            cin>>b2;
            AdjList[beverages[b1].first].push_back(b2);
            beverages[b2].second++; // inclevel, so >l0
        }

        // push to queue just level 0 - first round
        for (itb = beverages.begin(); itb != beverages.end(); itb++) {
            if (itb->second.second == 0) {
                l0.push(itb->second.first * -1);
                itb->second.second--;
            }
        }
    
        while (!l0.empty()) {
            // working
            int x;
            x = l0.top() * -1;
            //cout << x << endl;
            l0.pop();
            final.push_back(beverages_inv[x]);
            if (AdjList.size() > 0) {
                remove_node_adjlist(x);
            }
            // push to queue just level 0 - first round
            for (itb = beverages.begin(); itb != beverages.end(); itb++) {
                if (itb->second.second == 0) {
                    l0.push(itb->second.first * -1);
                    itb->second.second--;
                }
            }
        }
                
        print_final();
        c++;
        AdjList.clear();
        beverages.clear();
        beverages_inv.clear();
        final.clear();
        getline(cin,null);
        cout << endl;
    }

    return 0;
}
