#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std ;
int main ()
{
    int n;
    int i=2;
    cin >> n;
    while (i<=n) {
        if (n%i==0){
            n=n/i;
            cout << i;
            if (n>1) {
                cout<<"*";
            };
            
        }
        else {
            i+=1;
        };
    }
    cout << '\n';
    return 0;
}