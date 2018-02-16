#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std ;

int nod (int a1,int a2) {
    int p;
    p=1;
    while ((a1!=0) and (a2!=0)) {
        if (a1>a2) {
            a1=a1-a2;
        };
        if (a2>=a1) {
            a2=a2-a1;
        };
    }
    p=a1;
    return p;
}

int main ()

{
    
    int a,b;
    int n;
    cin>>n;
    a=1;
    b=n-1;
    for (int i=2;i<sqrt(n);++i) {
        if (n%i==0) {
            a=i;
            goto vivod;
        }
    }
    
    
vivod:
    if (a==1) {
        cout <<"1"<<" "<<n-1<<'\n';
    } else{
        cout <<n/a<<" "<<n-n/a<<'\n';
    }
    
    return 0;
    
}

