#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int matrix[100][100];

void print_matrix(int begin, int end) {
  for (int i=begin;i<=end;++i) {
      printf("%2d|",i);
  }
  printf("\n");
  for (int j=begin;j<end;++j) {
    for (int i=begin;i<end;++i) {
      printf("%2d|",matrix[j][i]);
    }
    printf("\n");
  }
}

int main() {

  int n,bigger;

  memset(matrix,-1,sizeof(matrix));
  
  while (cin >> n) {

    for (int i=0;i<n;++i) {
      for (int j=0;j<n;++j) {
        cin >> matrix[i][j];
      }
    }
    print_matrix(0,n);

    bigger=matrix[0][0];
    for (int i=1;i<n;++i) {
      for (int j=1;j<n;++j) {
        int temp=0;
        if (matrix[i-1][j]>0)  {temp = matrix[i-1][j]; }
        if (matrix[i][j-1]>0)  {temp = temp +matrix[i][j-1]; } 
        if ( (temp + matrix[i][j]) > matrix[i][j] ) { matrix[i][j]=temp+matrix[i][j]; }
        if (matrix[i][j] > bigger) { bigger = matrix[i][j]; }
      }
    }
    cout << bigger << endl; 
    print_matrix(0,n);
  }
}
