//prod. yaishenka
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std ;

struct chelik {
    int m,p;
    chelik() {m=p=0;}
    chelik(int m1,int p1) {
        m=m1;
        p=p1;
    }
};

int main () {
    int om(0),ans(0);
    chelik base;
    int m,p;
    cin >> m >> p;
    base=chelik(m,p);
    ans++;
    while (cin) {
        cin>>m>>p;
        if (p>base.p) {
            if (om+base.m<=p) {
                om+=base.m;
                base=chelik(m,p);
                ans++;
            } else if (om+m<=base.p) {
                om+=m;
                ans++;
            }
        } else {
            if (om+m<=base.p) {
                om+=m;
                ans++;
            }
        }
    }
    cout << ans << endl;
    
}










