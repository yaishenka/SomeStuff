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
    int a,b,c,d;
    int m,n;
    int x;
    cin >>a>>b>>c>>d;
    m=(a*d+c*b);
    n=b*d;
    x=nod(m,n);
    m=m/x;
    n=n/x;
    cout <<m<<" "<<n<<'\n';
    return 0;
    
}126 121
