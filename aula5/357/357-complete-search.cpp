#include <iostream>

using namespace std;

//1,5,10,25,50
int complete_search(int n) {
  int ret=0;
  for (int i=0; i<=n;++i) {
    for (int j=0; j<=n;++j) {
      for (int k=0; k<=n;++k) {
        for (int l=0; l<=n;++l) {
          for (int m=0; m<=n;++m) {
            if ((i+(j*5)+(k*10)+(l*25)+(m*50))==n) { ++ret; }
          }
        }
      }
    }
  }
  return ret;
}


int main() {

  int n,ret;
  while (cin >> n) {

    ret = complete_search(n);

    if (ret==1) {
      cout << "There is only 1 way to produce " << n << " cents change." << endl;
    }
    else {
      cout << "There is " << ret << " ways to produce " << n << " cents change." << endl;
    }
  }
}
