#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std ;


int main () {
    int m,n,v,c;
    int min1,max1;
    int k(1);
    cin>>m>>n;
    int arrsort[m-1];
    for (int i(0);i<=m-1;++i) {
        cin>>arrsort[i];
    }
    int arrnotsort[n-1];
    for (int i(0);i<=n-1;++i) {
        cin>>arrnotsort[i];
    }
    for (int i(0);i<n;++i) {
        k=1;
        while (arrsort[k]<=arrnotsort[i] && k<m) {
            k*=2;
        }
        
        min1=k/2;
        if (k>=m) {
            k=m-1;
        }
        max1=k;
        c=0;
        while (min1<max1) {
            c=1;
            if (arrsort[(max1+min1)/2]<arrnotsort[i]) {
                min1=(max1+min1)/2;
            }
            else {
                max1=(max1+min1)/2 ;
            }
            if (arrsort[(max1+min1)/2]==arrnotsort[i]) {
                break;
            }
        }
        v=(max1+min1)/2;
        while (v>0 and arrsort[v-1]==arrsort[v]){
            v--;
        }
        if (c==0) {
            cout<<m-1<<" ";
        } else {
            cout<<v<<" ";
        }
        
        
        
        
        
        
    }
    return 0;
    
    
    
    
    
    
    
}
