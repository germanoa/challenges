// uva 10954

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int howmuch;

std::priority_queue<int> numbers;


int main() {
    while(1)
    {
        cin >> howmuch;

        if(howmuch==0)
            break;

        for (int i = 0; i < howmuch; i++) {
            int number;
            cin >> number;
            numbers.push(number*-1);
        }

        int cost=0;
        while (numbers.size()>1)
        {
            //imprime_vetor();
            int a=0;
            a+=numbers.top();
            numbers.pop();
            a+=numbers.top();
            numbers.pop();
            numbers.push(a);
            cost+=a;
        }
        cout << cost*-1 << endl;
        numbers.pop();

    }

    return 0;
}
