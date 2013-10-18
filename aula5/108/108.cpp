#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int matrix[105][105];

void print_matrix(int begin, int end) {
  for (int i=begin;i<=end;++i) {
      printf("%2d|",i);
  }
  printf("\n");
  for (int i=begin;i<=end;++i) {
      printf("---");
  }
  printf("\n");
  for (int j=begin;j<=end;++j) {
    for (int i=begin;i<=end;++i) {
      printf("%2d|",matrix[j][i]);
    }
    printf("\n");
  }
  printf("\n");
}

int main() {

  int n,bigger;
	bigger=-127*100*100;

  memset(matrix,0,sizeof(matrix));
  
  while (cin >> n) {
		//
    for (int i=1;i<=n;++i) {
      for (int j=1;j<=n;++j) {
        cin >> matrix[i][j];
      }
    }
    //print_matrix(0,n);
		// sum matrix from 0,0 to i,j
    for (int i=1;i<=n;++i) {
      for (int j=1;j<=n;++j) {
        matrix[i][j] += matrix[i-1][j];
        matrix[i][j] += matrix[i][j-1]; 
        if (i>1 && j>1) matrix[i][j] -= matrix[i-1][j-1]; //elimina redundancia
      }
    }
    //print_matrix(0,n);
		// bigger cell from i,j to p,q
		int temp;
		//int ie,je,pe,qe;
    for (int i=1;i<=n;++i) {
      for (int j=1;j<=n;++j) {
    		for (int p=n;p>i;--p) {
    		  for (int q=n;q>j;--q) {
						temp = matrix[p][q] - matrix[p][j-1] - matrix [i-1][q] + matrix[i-1][j-1];
						if (temp>bigger) { bigger=temp; }
						//if (temp>bigger) { bigger=temp; ie=i;je=j;pe=p;qe=q; }
					}
				}
      }
    }
	  //printf("%d %d %d %d\n",ie,je,pe,qe);
    //print_matrix(0,n);
		cout << bigger << endl;
  }
}
