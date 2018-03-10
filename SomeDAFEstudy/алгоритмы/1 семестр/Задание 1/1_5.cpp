#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <time.h>
using namespace std ;

int kvadrat (int a,int b) {
    int kvadr=b;
    if (a>1) {
        kvadr=kvadrat (a-1,b)+b;
    }
    return kvadr;
}
int main () {
    
    int n;
    cin>>n;
    for (int i=1;i<=n;++i) {
    cout<<kvadrat(i,i)<<" ";
    }
    return 0;
    
}