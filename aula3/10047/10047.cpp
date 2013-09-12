#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <queue>

using namespace std;


#define SOURCE 0
#define VIRGIN -1
#define BLOCKED -2
#define TARGET -3

#define NORTH 1
#define SOUTH 2
#define EAST 3
#define WEST 4

#define COST 0

#define ROTATE_NORTH 5
#define ROTATE_SOUTH 6
#define ROTATE_EAST 7
#define ROTATE_WEST 8

int ***matrix; //1D:row 2D:col 3D:possible facings
int m,n,si,sj,ti,tj;
char c;

void print_matrix() {
    for (int i=0; i < m; i++) {
        for (int j=0; j<n; j++) {
            printf("%d;",matrix[i][j][COST]);
        }
        cout << endl;
    }
}

pair<int,int> look_to_north (int i, int j) {
    pair<int,int> cost_rotates;
    cost_rotates.first=BLOCKED;
    cost_rotates.second=0;
    int x,y;
    x=i-1;
    y=j;
    if (x>=0) {
        if (matrix[x][y][SOUTH] == 1) {
            cost_rotates.first=matrix[x][y][COST] + 1;
            cost_rotates.second=matrix[x][y][ROTATE_SOUTH];
        }
        else if (matrix[x][y][EAST] == 1) {
            cost_rotates.first=matrix[x][y][COST] + 2;
            if (matrix[x][y][WEST] == 1) {
                if (matrix[x][y][ROTATE_WEST] < matrix[x][y][ROTATE_EAST]) {
                    cost_rotates.second=matrix[x][y][ROTATE_WEST]+1;
                }    
            }
            else { cost_rotates.second=matrix[x][y][ROTATE_EAST]+1; }
        }
        else if (matrix[x][y][WEST] == 1) {
            cost_rotates.first=matrix[x][y][COST] + 2;
            cost_rotates.second=matrix[x][y][ROTATE_WEST]+1;
        }
        else if (matrix[x][y][NORTH] == 1) {
            cost_rotates.first= matrix[x][y][COST] + 3;
            cost_rotates.second=matrix[x][y][ROTATE_NORTH]+2;
        }
        else {} //BLOCKED
    }
    return cost_rotates;
}

pair<int,int> look_to_south (int i, int j) {
    pair<int,int> cost_rotates;
    cost_rotates.first=BLOCKED;
    cost_rotates.second=0;
    int x,y;
    x=i+1;
    y=j;
    if (x<m) {
        if (matrix[x][y][SOUTH] == 1) {
            cost_rotates.first=matrix[x][y][COST] + 3;
            cost_rotates.second=matrix[x][y][ROTATE_SOUTH]+2;
        }
        else if (matrix[x][y][EAST] == 1) {
            cost_rotates.first=matrix[x][y][COST] + 2;
            if (matrix[x][y][WEST] == 1) {
                if (matrix[x][y][ROTATE_WEST] < matrix[x][y][ROTATE_EAST]) {
                    cost_rotates.second=matrix[x][y][ROTATE_WEST]+1;
                }    
            }
            else { cost_rotates.second=matrix[x][y][ROTATE_EAST]+1; }
        }
        else if (matrix[x][y][WEST] == 1) {
            cost_rotates.first=matrix[x][y][COST] + 2;
            cost_rotates.second=matrix[x][y][ROTATE_WEST]+1;
        }
        else if (matrix[x][y][NORTH] == 1) {
            cost_rotates.first= matrix[x][y][COST] + 1;
            cost_rotates.second=matrix[x][y][ROTATE_NORTH];
        }
        else {} //BLOCKED
    }
    return cost_rotates;
}

pair<int,int> look_to_east (int i, int j) {
    pair<int,int> cost_rotates;
    cost_rotates.first=BLOCKED;
    cost_rotates.second=0;
    int x,y;
    x=i;
    y=j+1;
    if (y<n) {
        if (matrix[x][y][WEST] == 1) {
            cost_rotates.first=matrix[x][y][COST] + 1;
            cost_rotates.second=matrix[x][y][ROTATE_WEST];
        }
        else if (matrix[x][y][NORTH] == 1) {
            cost_rotates.first=matrix[x][y][COST] + 2;
            if (matrix[x][y][SOUTH] == 1) {
                if (matrix[x][y][ROTATE_SOUTH] < matrix[x][y][ROTATE_NORTH]) {
                    cost_rotates.second=matrix[x][y][ROTATE_SOUTH]+1;
                }    
            }
            else { cost_rotates.second=matrix[x][y][ROTATE_NORTH]+1; }
        }
        else if (matrix[x][y][SOUTH] == 1) {
            cost_rotates.first=matrix[x][y][COST] + 2;
            cost_rotates.second=matrix[x][y][ROTATE_SOUTH]+1;
        }
        else if (matrix[x][y][EAST] == 1) {
            cost_rotates.first= matrix[x][y][COST] + 3;
            cost_rotates.second=matrix[x][y][ROTATE_EAST]+2;
        }
        else {} //BLOCKED
    }
    return cost_rotates;
}

pair<int,int> look_to_west (int i, int j) {
    pair<int,int> cost_rotates;
    cost_rotates.first=BLOCKED;
    cost_rotates.second=0;
    int x,y;
    x=i;
    y=j-1;
    if (y>=0) {
        if (matrix[x][y][WEST] == 1) {
            cost_rotates.first=matrix[x][y][COST] + 3;
            cost_rotates.second=matrix[x][y][ROTATE_WEST]+2;
        }

        else if (matrix[x][y][NORTH] == 1) {
            cost_rotates.first=matrix[x][y][COST] + 2;
            if (matrix[x][y][SOUTH] == 1) {
                if (matrix[x][y][ROTATE_SOUTH] < matrix[x][y][ROTATE_NORTH]) {
                    cost_rotates.second=matrix[x][y][ROTATE_SOUTH]+1;
                }    
            }
            else { cost_rotates.second=matrix[x][y][ROTATE_NORTH]+1; }
        }
        else if (matrix[x][y][SOUTH] == 1) {
            cost_rotates.first=matrix[x][y][COST] + 2;
            cost_rotates.second=matrix[x][y][ROTATE_SOUTH]+1;
        }
        else if (matrix[x][y][EAST] == 1) {
            cost_rotates.first= matrix[x][y][COST] + 1;
            cost_rotates.second=matrix[x][y][ROTATE_EAST];
        }
        else {} //BLOCKED
    }
    return cost_rotates;
}

int main() {


    while (cin >> m) {
        cin >> n;
        if (m == 0 && n == 0) { break; } 

        matrix = new int **[m];
        for (int i=0; i < m; i++) {
            matrix[i] = new int *[n];
            for (int j=0; j<n; j++) {
                matrix[i][j] = new int[9];
                for (int k=1; k<9; k++) {
                    matrix[i][j][k] = 0; //possible facings and rotates n,s,e,w
                }
                cin >> c;
                if (c == '#') { matrix[i][j][COST]=BLOCKED; }
                else if (c == '.') { matrix[i][j][COST]=VIRGIN; }
                else if (c == 'S') {si=i; sj=j; \
                                    matrix[i][j][COST]=SOURCE; \
                                    matrix[i][j][NORTH]=1; } //S face to north
                else if (c == 'T') {ti=i; tj=j; \
                                    matrix[i][j][COST]=TARGET;}
                //else { cout << "invalid input\n"; exit(1); }
            }
        }
        bool state_change;
        state_change=true;
        while ((matrix[ti][tj][COST] == TARGET) && (state_change==true) ) {
            state_change=false;
            for (int i=0; i < m; i++) {
                for (int j=0; j<n; j++) {
                    pair<int,int> nr,sr,er,wr;
                    if (matrix[i][j][COST] >=-1 || matrix[i][j][COST]==TARGET) {
                        nr = look_to_north(i,j);         
                        sr = look_to_south(i,j);         
                        er = look_to_east(i,j);         
                        wr = look_to_west(i,j);         
                        //cout << "i,j="<<i<<","<<j<<": "<<nr<<" "<<sr<<" "<<er<<" "<<wr<<endl;

                        priority_queue<int> best;
                        if (nr.first>0) { best.push(nr.first*-1);}
                        if (sr.first>0) { best.push(sr.first*-1);}
                        if (er.first>0) { best.push(er.first*-1);}
                        if (wr.first>0) { best.push(wr.first*-1);}

                        if (!best.empty()) {
                            int b = best.top() * -1;
                            if (b <= matrix[i][j][COST] || matrix[i][j][COST] < 0) {
                                int best_f[9];
                                best_f[0]=0;
                                best_f[1]=0;
                                best_f[2]=0;
                                best_f[3]=0;
                                best_f[4]=0;
                                if (b == nr.first) { best_f[SOUTH]=1; matrix[i][j][ROTATE_SOUTH]=nr.second;}
                                if (b == sr.first) { best_f[NORTH]=1; matrix[i][j][ROTATE_NORTH]=sr.second;}
                                if (b == er.first) { best_f[WEST]=1; matrix[i][j][ROTATE_WEST]=er.second;}
                                if (b == wr.first) { best_f[EAST]=1; matrix[i][j][ROTATE_EAST]=wr.second;}

                                matrix[i][j][COST]=b;
                                state_change=true;
                                printf("#################################\n");
                                print_matrix();
                                printf("#################################\n");
                                for (int z=1; z<5;z++) {
                                    matrix[i][j][z]=best_f[z];
                                }
                            }
                        }
                    }
                }
            }
        }
        if (state_change==false) {
            cout << "destination not reacheable" << endl;
        }

        print_matrix();
        printf ("rotates tgt(n,s,e,w): %d:  %d %d %d %d\n",matrix[ti][tj][COST], matrix[ti][tj][ROTATE_NORTH], matrix[ti][tj][ROTATE_SOUTH], matrix[ti][tj][ROTATE_EAST], matrix[ti][tj][ROTATE_WEST]);

        cout << endl;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                delete [] matrix[i][j];
            }
            delete [] matrix[i];
        }
        delete [] matrix;


    }



}


