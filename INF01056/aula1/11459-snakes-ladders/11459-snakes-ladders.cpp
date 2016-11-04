#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int test_cases;
int num_players,snakes_ladders,die_rolls;
int src,dst;
int die_value;

vector<int> player;
vector<int> sl_src;
vector<int> sl_dst;
bool gameover;

int main()
{
    cin >> test_cases;
    for (int i = 0; i < test_cases; i++) {
        player.clear();
        sl_src.clear();
        sl_dst.clear();
        gameover = false;
        cin >> num_players >> snakes_ladders >> die_rolls;
        for (int j = 0; j < num_players; j++) {
            player.push_back(1);
        }
        for (int j = 0; j < snakes_ladders; j++) {
            cin >> src >> dst;
            sl_src.push_back(src);
            sl_dst.push_back(dst);
        }
        for (int j = 0; j < die_rolls; j++) {
            int p=j%num_players;
            cin >> die_value;
            if (!gameover) {
                player[p]= player[p] + die_value;
                for (int k = 0; k < snakes_ladders; k++) {
                    if (player[p] == sl_src[k]) {
                        player[p] = sl_dst[k];
                    }
                }
                if (player[p] >= 100 ) {
                    player[p]=100;
                    gameover = true;
                }
            }
        }
        for (int j = 0; j < num_players; j++) {
            printf("Position of player %d is %d.\n",j+1,player[j]);
        }
    }
}

