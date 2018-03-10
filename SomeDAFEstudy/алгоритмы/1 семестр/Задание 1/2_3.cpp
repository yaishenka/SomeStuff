#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std ;

int main(){
    int size1st,size2nd;
    int tek1=0,gran2=0,k=0,ans=0;
    cin>>size1st;
    int arr1[100000];
    for (int i(0);i<=size1st-1;++i){
        cin>>arr1[i];
    };
    cin>>size2nd;
    int arr2[100000];
    for (int i(0);i<=size2nd-1;++i){
        
        cin>>arr2[i];
        //cout<<arr2[i]<<" ";
    };
    
    cin>>k;
    
    gran2=size2nd-1;
    while ((tek1<=size1st-1) and (gran2>=0)) {
        for (int i(0);i<=gran2;++i) {
            if (arr1[tek1]+arr2[i]==k) {
                
                ans+=1;
                gran2-=1;
            }
            if (arr1[tek1]+arr2[i]>k) {
                
                gran2=i-1;
                break;
            }
        }
        tek1+=1;
    }
    cout<<ans<<'\n';
    
}
