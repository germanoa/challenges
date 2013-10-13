#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <pthread.h>

using namespace std;

#define SOURCE 0
#define VIRGIN -1
#define BLOCKED -2
#define TARGET -3
#define VISITED -4

#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3

typedef struct {
  int i;
  int j;
  int o;
  int c;
  int r;
  int color;
} ijocr;

int **matrix;
int m,n,si,sj,ti,tj,timeout;
char c;
priority_queue<int> results;
bool first_time,has_path;

void print_matrix() {
    for (int i=0; i < m; i++) {
        for (int j=0; j<n; j++) {
            printf("%d;",matrix[i][j]);
        }
        cout << endl;
    }
}

int i;

void* f(void* arg) {
// o: orientation
// c: cost
// r: rotations
  ijocr *z;
  z = new ijocr;
  z = (ijocr*) arg;
  if ((matrix[z->i][z->j] == BLOCKED) || (matrix[z->i][z->j] == VISITED)) {
  }
  else if(z->c >= timeout) {
  //
  }
  else if ((matrix[z->i][z->j] == TARGET) && (z->color==0)) {
    results.push((z->c+z->r)*-1); //-1 = inverse priority queue
    //cout <<"green! " << z->c+z->r << endl;
    has_path=true;
    //printf("TARGET! %d: %p -> i=%d j=%d o:%d r:%d c:%d color:%d\n",i++, &z, z->i, z->j, z->o, z->r, z->c, z->color);
  }
  else {
    //matrix[z->i][z->j] = VISITED;
    //printf("%d: %p -> i=%d j=%d o:%d r:%d c:%d color:%d\n",i++, &z, z->i, z->j, z->o, z->r, z->c, z->color);
    ijocr zz[4];
    pthread_t t[4];
    
    bool go_north=true;
    bool go_south=true;
    bool go_east=true;
    bool go_west=true;

    if (z->o == NORTH) {
        zz[NORTH].r=z->r;
        zz[NORTH].color=(z->color+1)%5;
        zz[SOUTH].r=z->r;
        zz[SOUTH].color=(z->color-1)%5;
        zz[EAST].r=z->r+1;
        zz[EAST].color=(z->color+1)%5;
        zz[WEST].r=z->r+1;
        zz[WEST].color=(z->color+1)%5;
        if (!first_time) {
          go_south=false;
        }
    }
    else if(z->o == SOUTH) {
        zz[NORTH].r=z->r;
        zz[NORTH].color=(z->color-1)%5;
        zz[SOUTH].r=z->r;
        zz[SOUTH].color=(z->color+1)%5;
        zz[EAST].r=z->r+1;
        zz[EAST].color=(z->color+1)%5;
        zz[WEST].r=z->r+1;
        zz[WEST].color=(z->color+1)%5;
        if (!first_time) {
          go_north=false;
        }
    }
    else if(z->o == EAST) {
        zz[NORTH].r=z->r+1;
        zz[NORTH].color=(z->color+1)%5;
        zz[SOUTH].r=z->r+1;
        zz[SOUTH].color=(z->color+1)%5;
        zz[EAST].r=z->r;
        zz[EAST].color=(z->color+1)%5;
        zz[WEST].r=z->r;
        zz[WEST].color=(z->color-1)%5;
        if (!first_time) {
          go_west=false;
        }
    }
    else if(z->o == WEST) {
        zz[NORTH].r=z->r+1;
        zz[NORTH].color=(z->color+1)%5;
        zz[SOUTH].r=z->r+1;
        zz[SOUTH].color=(z->color+1)%5;
        zz[EAST].r=z->r;
        zz[EAST].color=(z->color-1)%5;
        zz[WEST].r=z->r;
        zz[WEST].color=(z->color+1)%5;
        if (!first_time) {
          go_east=false;
        }
    }

    if ((z->i != 0) && (go_north==true)) {
      zz[NORTH].i=z->i-1;
      zz[NORTH].j=z->j;
      zz[NORTH].o=NORTH;
      zz[NORTH].c=z->c+1;
      pthread_create(&t[NORTH], NULL,&f,&zz[NORTH]); 
      pthread_join(t[NORTH], NULL);
    }
    if ((z->i != m-1) && (go_south==true)) {
      zz[SOUTH].i=z->i+1;
      zz[SOUTH].j=z->j;
      zz[SOUTH].o=SOUTH;
      zz[SOUTH].c=z->c+1;
      pthread_create(&t[SOUTH], NULL,&f,&zz[SOUTH]); 
      pthread_join(t[SOUTH], NULL);
    }
    if ((z->j != n-1) && (go_east==true)) {
      zz[EAST].i=z->i;
      zz[EAST].j=z->j+1;
      zz[EAST].o=EAST;
      zz[EAST].c=z->c+1;
      pthread_create(&t[EAST], NULL,&f,&zz[EAST]); 
      pthread_join(t[EAST], NULL);
    }
    if ((z->j != 0) && (go_west==true)) {
      zz[WEST].i=z->i;
      zz[WEST].j=z->j-1;
      zz[WEST].o=WEST;
      zz[WEST].c=z->c+1;
      pthread_create(&t[WEST], NULL,&f,&zz[WEST]); 
      pthread_join(t[WEST], NULL);
    }
  }
  first_time=false;
  return NULL;
}


int main() {
    i=0;
    while (cin >> m) {
        cin >> n;
        if (m == 0 && n == 0) { break; } 
        timeout=m*n/2;
        first_time=true;
        has_path=false;
        matrix = new int *[m];
        for (int i=0; i < m; i++) {
            matrix[i] = new int [n];
            for (int j=0; j<n; j++) {
                cin >> c;
                if (c == '#') { matrix[i][j]=BLOCKED; }
                else if (c == '.') { matrix[i][j]=VIRGIN; }
                else if (c == 'S') {si=i; sj=j; \
                                    matrix[i][j]=SOURCE; }
                else if (c == 'T') {ti=i; tj=j; \
                                    matrix[i][j]=TARGET; }
                //else { cout << "invalid input\n"; exit(1); }
            }
        }
        ijocr *z;
        z = new ijocr;
        z->i=si;
        z->j=sj;
        z->o=NORTH;
        z->c=0;
        z->r=0;
        z->color=0;
        f((void*)z);
        if (has_path) {
          cout << (results.top() *-1) << endl;
        }
        else {
          cout << "destination not reacheable\n"; 
        }
    }
}
