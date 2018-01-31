//yaishenka prod : (
//templateMergeSort

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std ;

template <class t>
void Merge (t* arr1, t* arr2, int n1, int n2, t* ans) {
    int i(0), j(0);
    while (i<n1 && j<n2) {
        if (arr1[i]<=arr2[j]) {
            ans[i+j]=arr1[i];
            ++i;
        } else
        {
            ans[i+j]=arr2[j];
            ++j;
        }
    }
    if (i==n1) {
        for (;j<n2;++j) {
            ans[i+j]=arr2[j];
        }
    }
    if (j==n2) {
        for (;i<n1;++i) {
            ans[i+j]=arr1[i];
        }
    }
}
template <class t>
void MergeSort (t* arr, int n) {
    if (n<=1) {
        return;
    }
    int l,r;
    l=n/2;
    r=n-n/2;
    MergeSort(arr,l);
    MergeSort(arr+l,r);
    t* ans = new t [n];
    Merge(arr,arr+l,l,r,ans);
    for (int i(0);i<n;++i) {
        arr[i]=ans[i];
    }
    delete[] ans;
}

int main () {
    int arr[5]={0,10,4,5,2};
    MergeSort(arr, 5);
    for (int i(0);i<5;++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
}








