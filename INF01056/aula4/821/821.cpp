#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>

using namespace std;


set<int> v;

float t,p,a;


float fat(float f) {
  if (f==1.0) {
    return 1.0;
  }
  f = f * fat(f-1.0);
  return f;
}

int main() {

  int c,n1,n2,null;
  c=1;
  float matrix[100][100];  

  while (cin >> n1) {

    //stop
    if (n1 == 0) {
      cin >> null;
      break;
    }
    cin >> n2;

    //input/init
    for (int i=0; i<100;i++) {
      for (int j=0;j<100;j++) {
          matrix[i][j]=101;
      }
    }
    t=0;
    v.clear();
    matrix[n1-1][n2-1]=1;
    v.insert(n1);
    v.insert(n2);
    while (cin >> n1) {
      if (n1 == 0) {
        cin >> null;
        break;
      }
      cin >> n2;
      matrix[n1-1][n2-1]=1.0;
      v.insert(n1);
      v.insert(n2);
    }


    //algorithm
 //   cout << v.size() << endl;
    p=v.size()*(v.size()-1);
    //p=fat(float(v.size()));

    for (int k=0; k<100;k++) {
      for (int j=0; j<100;j++) {
        for (int i=0;i<100;i++) {
          if (i!=j) {
          if ((matrix[i][k] + matrix[k][j] > 0) && \
             (matrix[i][k] + matrix[k][j] < matrix[i][j])) {
            matrix[i][j] = matrix[i][k] + matrix[k][j];
          //  printf("%d,%d - comparando: %d,%d e %d,%d\n",i,j,i,k,k,j);
          //  printf("%d,%d = %f\n",i,j,matrix[i][j]);
          }
          }
        }
      }
    }
    
    for (int i=0; i<100;i++) {
      for (int j=0;j<100;j++) {
          if (matrix[i][j] < 101) {
            t = matrix[i][j] + t;
          }
      }
    }
//    if (p>1) {
//      p = p/2;
//    }
 //   printf ("t: %f p: %f\n",t,p);
    a = t/p;
    //output
    printf("Case %d: average length between pages = %.3f clicks\n",c,a);
    c++; 
    
}  



}

