#include <iostream>
#include <stdio.h>

using namespace std;

#define MURO -1

int b, w;
typedef enum { north, south, east, west } orientation; 

int main()
{
    int robot_x,robot_y;
    
    do {
        cin >> b >> w;
        int maze[b][w];
        int v_zero=0,v_one=0,v_twice=0,v_thrice=0,v_fourtimes=0;
        orientation o = east;
        if (b == 0 && w == 0) { 
            break;
        }
        else { 
            robot_y=b-1;
            robot_x=0;
            for ( int i=0; i<b; i++) {
                for (int j=0; j<w; j++) {
                    char v;
                    cin >> v;
                    if (v == '0') { maze[i][j] = 0; }
                    else if (v == '1') {maze[i][j] = -1; }
                    //else { printf("ops\n"); }
                }    
            }
            do {
                //continuar: switch, cuidar orientation, inc maze[b][w] and inc v_x and dec v_x-1. 
                switch(o) {
                    case east:
                        if ( (robot_y < b-1) && (maze[robot_y+1][robot_x] != MURO) ) { //tem curva
                            o=south;
                            robot_y++;
                            maze[robot_y][robot_x]++;
                        }
                        else if ( (robot_x == w-1) || (maze[robot_y][robot_x+1] == MURO) ) { //se estah junto a borda direita ou se ha muro
                            o=north;
                        }
                        else {
                            robot_x++;
                            maze[robot_y][robot_x]++;
                        }
                        break;
                    case west:
                        if ( (robot_y > 0) && (maze[robot_y-1][robot_x] != MURO) ) { //tem curva
                            o=north;
                            robot_y--;
                            maze[robot_y][robot_x]++;
                        }
                        else if ( (robot_x == 0) || (maze[robot_y][robot_x-1] == MURO) ) { //se estah junto a borda esquerda ou se ha muro
                            o=south;
                        }
                        else {
                            robot_x--;
                            maze[robot_y][robot_x]++;
                        }
                        break;
                    case north:
                        if ( (robot_x < w-1) && (maze[robot_y][robot_x+1] != MURO) ) { //tem curva
                            o=east;
                            robot_x++;
                            maze[robot_y][robot_x]++;
                        }
                        else if ( (robot_y == 0) || (maze[robot_y-1][robot_x] == MURO) ) { //se estah junto a borda superior ou se ha muro
                            o=west;
                        }
                        else {
                            robot_y--;
                            maze[robot_y][robot_x]++;
                        }
                        break;
                    case south:
                        if ( (robot_x > 0) && (maze[robot_y][robot_x-1] != MURO) ) { //tem curva
                            o=west;
                            robot_x--;
                            maze[robot_y][robot_x]++;
                        }
                        else if ( (robot_y == b-1) || (maze[robot_y+1][robot_x] == MURO) ) { //se estah junto a borda superior ou se ha muro
                            o=east;
                        }
                        else {
                            robot_y++;
                            maze[robot_y][robot_x]++;
                        }
                        break;
                }
            //printf ("x:%d y:%d\n",robot_x,robot_y);
            } while (!(robot_x == 0 && robot_y == b-1)); 
        }
        for ( int i=0; i<b; i++) {
            for (int j=0; j<w; j++) {
                switch(maze[i][j]) {
                    case 0:
                        v_zero++;
                        break;
                    case 1:
                        v_one++;
                        break;
                    case 2:
                        v_twice++;
                        break;
                    case 3:
                        v_thrice++;
                        break;
                    case 4:
                        v_fourtimes++;
                        break;
                    case -1:
                        break;
                    default:
                        //printf("%d:%d = %d\n",i,j,maze[i][j]);
                        break;
                }
            }    
        }
        printf ("%3d%3d%3d%3d%3d\n",v_zero,v_one,v_twice,v_thrice,v_fourtimes);    
    } while (1);
}

