#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

long long matrix[5][30001];
int coins[5]={1,5,10,25,50};

void print_matrix(int begin, int end) {
  for (int i=begin;i<=end;++i) {
      printf("%2d|",i);
  }
  printf("\n");
  for (int j=0;j<5;++j) {
    for (int i=begin;i<=end;++i) {
      printf("%2d|",matrix[j][i]);
    }
    printf("\n");
  }
}

long long ways(int coin, int n) {
  if (n==0) { return 1; }
  if (n<0 || coin>4) { return 0; }
  if (matrix[coin][n] != -1) { return matrix[coin][n]; }
  matrix[coin][n] = ways(coin+1, n) + ways(coin,n - coins[coin]);
  return matrix[coin][n];
}

int main() {

  long long ret;
  int n;

  memset(matrix,-1,sizeof(matrix));
  
  while (cin >> n) {

    ret = ways(0,n);

    if (ret==1) {
      cout << "There is only 1 way to produce " << n << " cents change." << endl;
    }
    else {
      cout << "There are " << ret << " ways to produce " << n << " cents change." << endl;
    }

  }
    //print_matrix(0,17);
}
