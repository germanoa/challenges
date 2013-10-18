#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;


int matrix[1001][1001];


int max(int a, int b) {
  if (a>b) { return a; }
  else { return b; }
}

int main() {


  string s1,s2,line;

  do {
    getline(cin,s1);
    if (s1.empty()) {
      getline(cin,line);
      if (!cin.eof()) {
        cout << "0" << endl; 
      }
    }
    else {
      getline(cin,s2);

//      cout << "testando: " << s1 << " " << s2 << endl;

      memset(matrix,0,sizeof(matrix));
      for (int i=0;i<=s1.size();++i) {
        for (int j=0;j<=s2.size();++j) {
          if (i==0 || j==0) {
            matrix[i][j]=0;
          }
          else {
            if (s1[i-1]==s2[j-1]) {
//              printf ("%c e %c\n",s1[i-1],s2[j-1]);
              matrix[i][j]=matrix[i-1][j-1]+1;
            }
            else {
              matrix[i][j]=max(matrix[i][j-1],matrix[i-1][j]);
            }
          }
        }
      }
      cout << matrix[(int)s1.size()][(int)s2.size()] << endl;
    }
  } while (!cin.eof());



}
