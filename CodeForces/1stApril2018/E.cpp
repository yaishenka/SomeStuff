//yaishenka prod
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void cl (int* a) {
	for (int i(0);i<255;++i) {
		a[i]=0;
	}
}

int main () {
    int fort [256];
    int n;
    int ans(1000000);
    int tmp;
    string s1,s2;
    for (int i(0);i<n;++i) {
    	cin >> s1 >> s2;
    	tmp=0;
    	for (int j(0);j<s1.size();++j) {
    		if (!fort[s1[i]]) {
    			tmp++;
    			fort[s1[i]]=1;
    		}
    	}
    	if (ans>tmp) ans=tmp;
    }
    cout << tmp;
}