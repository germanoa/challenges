#include <iostream>
#include <stdio.h>

using namespace std;

int n, b, h, w, p, a;
int custo; 


int main()
{
    while (cin >> n >> b >> h >> w)
    {
        //printf("aqui - %d %d %d %d\n",n,b,h,w);
        custo=b+1;
        for (int i = 0; i < h; ++i)
        {
            cin >> p;
           for (int j = 0; j < w; ++j) { //para cada findi
               cin >> a;
               if (a >= n && n*p<custo) { //se o custo for o menor existente
                   if (b>=p*n) { //se hotel eh barato suficiente
                       custo = n*p; 
                   }         
               }
           }
        }
        
        if (custo > b) {
            //printf("b= %d, custo: %d - ",b,custo);
            cout << "stay home" << endl;
        }
        else {
            cout << custo << endl;
        }
    }
}

