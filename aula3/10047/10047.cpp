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

int look_to_north (int i, int j) {
    int ret=BLOCKED;
    if (i-1>=0) {
        if (matrix[i-1][j][SOUTH] == 1) {
            ret=matrix[i-1][j][COST] + 1;
        }
        else if (matrix[i-1][j][EAST] + matrix[i-1][j][WEST] > 0) {
            ret=matrix[i-1][j][COST] + 2;
        }
        else if (matrix[i-1][j][NORTH] == 1) {
            ret= matrix[i-1][j][COST] + 3;
        }
        else {} //BLOCKED
    }
    return ret;
}

int look_to_south (int i, int j) {
    int ret=BLOCKED;
    if (i+1<m) {
        if (matrix[i+1][j][SOUTH] == 1) {
            ret=matrix[i+1][j][COST] + 3;
        }
        else if (matrix[i+1][j][EAST] + matrix[i+1][j][WEST] > 0) {
            ret=matrix[i+1][j][COST] + 2;
        }
        else if (matrix[i+1][j][NORTH] == 1) {
            ret= matrix[i+1][j][COST] + 1;
        }
        else {} //BLOCKED
    }
    return ret;
}

int look_to_east (int i, int j) {
    int ret=BLOCKED;
    if (j+1<n) {
        if (matrix[i][j+1][WEST] == 1) {
            ret=matrix[i][j+1][COST] + 1;
        }
        else if (matrix[i][j+1][NORTH] + matrix[i][j+1][SOUTH] > 0) {
            ret=matrix[i][j+1][COST] + 2;
        }
        else if (matrix[i][j+1][NORTH] == 1) {
            ret= matrix[i][j+1][COST] + 3;
        }
        else {} //BLOCKED
    }
    return ret;
}

int look_to_west (int i, int j) {
    int ret=BLOCKED;
    if (j-1>=0) {
        if (matrix[i][j-1][WEST] == 1) {
            ret=matrix[i][j-1][COST] + 3;
        }
        else if (matrix[i][j-1][NORTH] + matrix[i][j-1][SOUTH] > 0) {
            ret=matrix[i][j-1][COST] + 2;
        }
        else if (matrix[i][j-1][EAST] == 1) {
            ret= matrix[i][j-1][COST] + 1;
        }
        else {} //BLOCKED
    }
    return ret;
}

int main() {

    int nr=0,sr=0,er=0,wr=0;

    while (cin >> m) {
        cin >> n;
 
        matrix = new int **[m];
        for (int i=0; i < m; i++) {
            matrix[i] = new int *[n];
            for (int j=0; j<n; j++) {
                matrix[i][j] = new int[5];
                for (int k=1; k<5; k++) {
                    matrix[i][j][k] = 0; //possible facings n,s,e,w
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
                    if (matrix[i][j][COST] >=-1 || matrix[i][j][COST]==TARGET) {
                        nr = look_to_north(i,j);         
                        sr = look_to_south(i,j);         
                        er = look_to_east(i,j);         
                        wr = look_to_west(i,j);         
                        cout << "i,j="<<i<<","<<j<<": "<<nr<<" "<<sr<<" "<<er<<" "<<wr<<endl;

                        priority_queue<int> best;
                        if (nr>0) { best.push(nr*-1);}
                        if (sr>0) { best.push(sr*-1);}
                        if (er>0) { best.push(er*-1);}
                        if (wr>0) { best.push(wr*-1);}

                        if (!best.empty()) {
                            int b = best.top() * -1;
                            if (b <= matrix[i][j][COST] || matrix[i][j][COST] < 0) {
                                int best_f[5];
                                best_f[0]=0;
                                best_f[1]=0;
                                best_f[2]=0;
                                best_f[3]=0;
                                best_f[4]=0;
                                if (b == nr) { best_f[SOUTH]=1; }
                                if (b == sr) { best_f[NORTH]=1; }
                                if (b == er) { best_f[WEST]=1; }
                                if (b == wr) { best_f[EAST]=1; }

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


