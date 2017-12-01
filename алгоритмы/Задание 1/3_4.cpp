#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std ;

int main(){
    cin.tie(0);
    cout.tie (0);
    int size1st,size2nd;
    int k=0,left(0),right(0);
    int absolute;
    cin>>size1st;
    
    int arr1[size1st];
    for (int i(0);i<size1st;++i){
        cin>>arr1[i];
        
    };
    cin>>size2nd;
    int arr2[size2nd];
    for (int i(0);i<size2nd;++i){
        
        cin>>arr2[i];
    };
    
    
    
    for (int i(0);i<size2nd;++i) {
        k=1;
        
        absolute=abs(arr2[i]-arr1[0]);
        
        while (arr1[k]<arr2[i] and k<size1st){
            
            
            k*=2;
        }
        left=k/2;
        if (k>=size1st) {
            k=size1st-1;
        }
        right=k;
        // cout<<"number: "<<i<<" "<<left<<" "<<right<<"\n";
        if (left>right) {
            int param=right;
            right=left;
            left=param;
        }
        
        
        //cout<<absolute<<"\n";
        while (left<right) {
            absolute=abs(arr1[((left+right)/2)-1]-arr2[i]);
            if (right-left<=1) {
                if (abs(arr1[left]-arr2[i])<=abs(arr1[right]-arr2[i])) {
                    right=left;
                }
                break;
            }
            if (abs(arr1[(left+right)/2]-arr2[i])<absolute){
                
                left=(left+right)/2;
            } else {
                
                right=(left+right)/2;
                
            }
            
            
        }
        
        
        cout<<right<<" ";
        
    }
    return 0;
    
}
