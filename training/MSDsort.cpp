//yaishenka prod : (
//stringMSDsort

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std ;

char check (string s, int t) {
    if (t < s.size()) {
        return s[t];
    } else return 0;
}

void MSDsort (string* arr, int size,int t, long long maxlen) {
    if (size==0 || size==1 || t>maxlen) {
        return;
    }
    int c[256];
    string ans[size];
    for (int i(0);i<256;++i) {
        c[i]=0;
    }
    for (int i(0);i<size;++i) {
        c[check(arr[i],t)]+=1;
    }
    int sum(0);
    int tmp(0);
    for (int i(0);i<256;++i) {
        tmp = c[i];
        c[i]=sum;
        sum+=tmp;
    }
    for (int i(0);i<size;++i) {
        ans[c[check(arr[i], t)]]=arr[i];
        c[check(arr[i], t)]++;
    }
    for (int i(0);i<size;++i) {
        arr[i]=ans[i];
    }
    int tmp_size=0;
    for (int i(0);i<256;++i) {
        MSDsort(arr+tmp_size, c[i]-tmp_size, t+1, maxlen);
        tmp_size=c[i];
    }
}
int main () {
    string arr [1000];
    long long int maxlen(0);
    int count (-1);
    while (cin) {
        count++;
        cin>>arr[count];
        if (arr[count].size()>maxlen) {
            maxlen=arr[count].size();
        }
    }
    MSDsort(arr, count, 0, maxlen);
    for (int i(0);i<count;++i) {
        cout<<arr[i]<<endl;
    }
}
