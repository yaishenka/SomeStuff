//yaishenka prod
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string pal (string s) {
    string ans="";
    for (int i(s.size()-1);i>=0;--i) {
        ans+=s[i];
    }
    //cout << ans << endl;
    return ans;
}
bool isitpal (string s) {
    string comp = pal(s);
    return comp==s;
}
string strcop (string s, int i, int j) {
    //cout << s << " " << i << " " << j << endl;
    string ans="";
    for (int t(i);t<=j;++t) {
        ans+=s[t];
    }
    //cout << ans << endl;
    return ans;
}
int main () {
    string s;
    string ans="-1";
    cin >> s;
    for (int i(0); i<s.size();++i) {
        for (int j(i+1);j<s.size();j++){
            if (isitpal(strcop(s, i, j))) {
                if (ans!="-1") {
                    if (pal(strcop(s, i, j)) < ans) {
                        ans = pal(strcop(s, i, j));
                    }
                } else ans = pal(strcop(s, i, j));
            }
        }
    }
    cout << ans << endl;
    
}