#include <iostream>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#define ADD 1
#define DEL 2
 
vector< pair<int,int> > cmds;
bool s,q,pq,i,ns;

bool can_be_stack(vector< pair<int,int> > cmds) {
    stack<int> s;
    for (unsigned int i=0; i<cmds.size();i++) {
        if (cmds[i].first == ADD ) {
            s.push(cmds[i].second);
        }
        else if (cmds[i].first == DEL) {
            if (s.empty()) {
                return false;
            }
            if (cmds[i].second == s.top()) {
                s.pop();
            }
            else {
                return false;
            }
        }
        else { 
            //printf("error.\n");
            return false;
        }
    }
    //printf("!stack!\n");
    return true;
}

bool can_be_queue(vector< pair<int,int> > cmds) {
    queue<int> q;
    for (unsigned int i=0; i<cmds.size();i++) {
        if (cmds[i].first == ADD ) {
            q.push(cmds[i].second);
        }
        else if (cmds[i].first == DEL) {
            if (q.empty()) {
                return false;
            }
            if (cmds[i].second == q.front()) {
                q.pop();
            }
            else {
                return false;
            }
        }
        else { 
            //printf("error.\n");
            return false;
        }
    }
    //printf("!queue!\n");
    return true;
}

bool can_be_pqueue(vector< pair<int,int> > cmds) {
    priority_queue<int> q;
    for (unsigned int i=0; i<cmds.size();i++) {
        if (cmds[i].first == ADD ) {
            q.push(cmds[i].second);
        }
        else if (cmds[i].first == DEL) {
            if (q.empty()) {
                return false;
            }
            if (cmds[i].second == q.top()) {
                q.pop();
            }
            else {
                return false;
            }
        }
        else { 
            //printf("error.\n");
            return false;
        }
    }
    //printf("!pqueue!\n");
    return true;
}

int main() {

    unsigned int n,i;
    int cmd,x;
    while(cin >> n) {
        for (i=0; i<n;i++) {
            cin >> cmd >> x;
            cmds.push_back(make_pair(cmd,x));
        }
        
        s = can_be_stack(cmds);
        q = can_be_queue(cmds);
        pq = can_be_pqueue(cmds);
        i = !s && !q && !pq;
        ns = ( (int)s + (int)q + (int)(pq) > 1 );

        if (i) { cout << "impossible\n"; }
        else if (ns) { cout << "not sure\n"; }
        else if (s) { cout << "stack\n"; }
        else if (q) { cout << "queue\n"; }
        else if (pq) { cout << "priority queue\n"; }

        cmds.clear();
    }
}
