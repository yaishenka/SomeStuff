//yaishenka prod : (
//templateQuickSort

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std ;

template <class t>
int Partition (t* arr, int size) {
    t a = arr[0];
    t b = arr[size/2];
    t c = arr[size-1];
    t base;
    int basei;
    if ((a<=b && b <= c)||(c<=b && b <= a) ) basei=size/2;
    else if ((a<=c && c <= b)||(b<=c && c <= a) ) basei=size-1;
    else basei = 0;
    swap (arr[basei],arr[size-1]);
    base = arr [size-1];
    int i(0),j(0);
    while (j<size-1) {
        if (arr[j]>base) {
            j++;
        } else {
            swap(arr[j], arr[i]);
            j++;i++;
        }
    }
    swap (arr[i],arr[size-1]);
    return i;
}

template <class t>
void quicksort (t* arr, int n) {
    if (n<=2) {
        if (n==2) {
            if (arr[0]>arr[1]) {
                swap(arr[0], arr[1]);
            }
        }
        return;
    }
    int i = Partition(arr, n);
    quicksort(arr+i, n-i);
    quicksort(arr, i);
}

int main () {
    int arr[5]={0,10,4,5,2};
    //cout << Partition(arr, 5);
    //cout << endl;
    quicksort(arr, 5);
    for (int i(0);i<5;++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
}



