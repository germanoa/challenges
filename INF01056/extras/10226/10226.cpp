#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <map>

using namespace std;

int main() {

    map<string,float> woods;
    map<string,float>::iterator it;
    string line,null;
    int n;
    float c;
    cin >> n;
    for (int i=0; i<n;i++) {
        woods.clear();
        c = 0;
        getline(cin,null); // remove first blank line
        getline(cin,null); // remove first blank line
        
        do {
            line.clear();
            getline(cin,line);
            if (line == "") {
                break;
            }
            c++;
            woods[line]++;
        } while (1);
        for (it = woods.begin(); it != woods.end(); it++) {
            cout << it->first << " " << setiosflags(ios::fixed) << setprecision(4) << it->second/c*100 << endl;
        }
    }    

}   
