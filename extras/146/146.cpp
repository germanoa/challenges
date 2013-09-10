#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

string line;
typedef string::reverse_iterator sri;
sri it;

void minor_of_range_at_head(sri present_head, sri range_rbegin) {
    sri temp1,temp2;
    temp1 = present_head;
    temp2 = present_head;
    char x;
    x = 'z'; //the greatest item
    for (;range_rbegin != present_head-1/*it*/;range_rbegin++) {
        if (*range_rbegin < x ) { 
            printf (" changing %c < %c: %c\n",*range_rbegin,x,*temp2);
            printf (" end: %X %X\n",temp2,range_rbegin);
            temp2 = range_rbegin;
            printf (" end: %X %X\n",temp2,range_rbegin);
            x = *range_rbegin;
        }           
    }
        printf("%c %c %c\n",*present_head,*temp2,*temp1);
    *present_head = *temp2;
    *temp2 = *temp1;
}


int main()  {
    getline(cin,line);
    while (line != "#") {
        for (it = line.rbegin(); it != line.rend()-1; it++) {
            if (*it > *(it+1)) {
                cout << line;
                minor_of_range_at_head(it+1,line.rbegin());
                cout << line;
                //range_sorted(
                //printf("%c > %c\n",*it,*(it+1));
                break;
            }
        }
        line.clear();
        getline(cin,line);
    }
} 
