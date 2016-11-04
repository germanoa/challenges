#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef pair<string,string> ss;
typedef pair<int,ss> iss;
typedef vector<iss> viss;
typedef pair<int,viss> iviss;
typedef map<string,iviss> miviss; // {language: cost,vector<word_size,word,language>}

int m; //how much words

miviss g;
miviss::iterator it;


int dijkstra_modificado(string a, string b)
{
  priority_queue< iss, viss, greater< iss > > q;
  iss p; string language,word; int w;
  q.push( make_pair(0,make_pair("",a)) );
  bool trivial=true;
  while (!q.empty())
    {

      p = q.top(); q.pop();
      language = p.second.second;
      word = p.second.first;
      w = p.first;

      //cout << "language: " << language << " ; word: " << word << "; w: " << w << endl;

      if ( g[language].first != 0 && trivial) continue;
      if (language == b) return w;
      g[language].first = w;

      //cout << "possibilidades: " << g[language].second.size() << endl;      
      for (int i = 0; i < g[language].second.size(); ++i) {
          //cout << "possibilidade:  " << g[language].second[i].second.first << endl;
        if ((g[language].second[i].second.first != word) && (g[language].second[i].second.first[0] == word[0])) {
          trivial=false;
        }
        else if (g[g[language].second[i].second.second].first == 0)
        {
        //  cout << "\t\tempilha " << g[language].second[i].second.first << endl;
          q.push( make_pair( w+g[language].second[i].first, g[language].second[i].second ) );
        }
      }
      
    }
  return -1;
}


int main() {

  while (cin >> m) {

    string src,tgt,l1,l2,w;
    int ret;

    if (m==0) {
      break;
    }

    cin >> src;
    cin >> tgt;

    g.clear();

    for (int i=0; i<m; ++i) {
      cin >> l1 >> l2 >> w;

      if (g.count(l1)==0) {
        g[l1] = make_pair(0,viss());
      }
      g[l1].second.push_back(make_pair(w.size(),make_pair(w,l2)));

      if (g.count(l2)==0) {
        g[l2] = make_pair(0,viss());
      }
      g[l2].second.push_back(make_pair(w.size(),make_pair(w,l1)));
      
    }

      
      ret = dijkstra_modificado(src,tgt);
  
      if (ret == -1) {
        cout << "impossivel" << endl;
      }
    if (ret!= -1) {
      cout << ret << endl;
    }
  }
}
