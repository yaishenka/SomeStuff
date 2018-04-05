//yaishenka prod
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string read () {
    string s1="";
    string tmp;
    while (cin>>tmp) {
        s1+=" "+tmp;
        tmp="";
    }
    return s1;
}

int main () {
    string ans = "normal";
    int tmp(0);
    string s1;
    for (int i(0);i<9;++i) {
        cout << i << endl;
        flush(cout);
        getline ( std::cin, s1 );
        if (s1=="no") tmp++;
    }
    if (tmp == 3 ) ans = "grumpy";
    cout << ans << endl;
}