#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
vvi matrix;

void print_matrix(int bi, int ei, int bj, int ej) {
  for (int i=bi-1;i<=ei;++i) {
      printf("%2d|",i);
  }
  printf("\n");
  for (int j=bj;j<=ej;++j) {
    printf("%2d|",j);	
    for (int i=bi;i<=ei;++i) {
      printf("%2d|",matrix[j][i]);
    }
    printf("\n");
  }
}

int n,k,ret; 

int ways(int n, int k) {
	if (matrix[n+1][k+1]!=0) {
		return matrix[n+1][k+1];
	}
  else if (k==1) {
    return matrix[n+1][k+1] = 1;
  }
  else {
		int sum = 0;
		for (int x=0;x<=n;++x) {
				sum = sum + ways(n-x,k-1);
			}
		return matrix[n+1][k+1] = (sum % 1000000);
		}
  }

int main() {
  while (cin >> n) {
    cin >> k;
    if (n==0 && k==0) {
      break;
    }
    else {
      matrix.clear();
      matrix.assign(n+5,vi());
      for (int i=0;i<(int)matrix.size();++i) {
        matrix[i].assign(k+5,0);
      }
      //print_matrix(0,k,0,n);
      ret = ways(n,k);
      //print_matrix(0,k,0,n);
      cout << ret << endl;
    }
  }
}
