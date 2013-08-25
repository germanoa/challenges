#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <map>

using namespace std;

set<int> courses;
map< set<int>, int > courses_list;
int null,froshs,v;
bool already_in_the_set;

int main() {

    while(1) {
        cin >> froshs;
        if (froshs == 0) {
            break;
        }
        else if (froshs == 1) {
            cin >> null >> null >> null >> null >> null;
            printf("1\n");
        }
        else {
            int most_pop_v=1;
            int most_pop_t=1;
            for (int i = 0; i < froshs; i++) {
                courses.clear();
                for (int k = 0; k <5; k++) {
                    cin >> v;
                    courses.insert(v);
                }
                courses_list[courses]++;
                if (courses_list[courses] == most_pop_v) {
                    most_pop_t++;
                }
                if (courses_list[courses] > most_pop_v) {
                    most_pop_v = courses_list[courses];
                    most_pop_t=1;
                }
            }
            if (most_pop_v==1) {
                most_pop_t=froshs;
            }
            printf("%d\n",most_pop_v*most_pop_t);
            courses_list.clear();
        }
    }
}
