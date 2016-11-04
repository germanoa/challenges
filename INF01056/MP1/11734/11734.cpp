#include <iostream>
#include <stdio.h>

using namespace std;


int main() {

    int n;
    cin >> n;
    string null;
    getline(cin,null);
    for (int i = 0;i<n;i++) {
        string line1,line2,nline1,nline2;
        getline(cin,line1);
        getline(cin,line2);


        if (line1.compare(line2) == 0) {
            cout << "Case " << i+1 << ": " << "Yes" << endl;
        }
        else {

            for (unsigned int j=0; j<line1.size(); j++) {
                if (line1[j] != ' ') {
                    nline1.push_back(line1[j]);
                }
            }

            for (unsigned int j=0; j<line2.size(); j++) {
                if (line2[j] != ' ') {
                    nline2.push_back(line2[j]);
                }
            }
            if (nline1.size() != nline2.size()) {
                cout << "Case " << i+1 << ": " << "Wrong Answer" << endl;
            }
            else {
                bool err;
                err=false;
                for (unsigned int j=0; j<nline1.size(); j++) {
                    if (nline1[j] != nline2[j]) {
                        cout << "Case " << i+1 << ": " << "Wrong Answer" << endl;
                        err=true;
                        break;
                    }
                } 
                if (!err) {
                    cout << "Case " << i+1 << ": " << "Output Format Error" << endl;
                }
            }
        }

    }


}
