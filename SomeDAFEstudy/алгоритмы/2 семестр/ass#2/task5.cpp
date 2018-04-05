#include <iostream>
#include <queue>
#include <vector>
#include <limits>
#include <set>

using namespace std;

const short S=4;

class Pole {
public:
    short size = S;
    short arr[S][S];
    int distance=0;
    Pole () {};
    Pole (Pole& p) {
        for (int i(0);i<size;++i) {
            for (int j(0);j<size;++j) {
                arr[i][j]=p.arr[i][j];
            }
        }
    }
    Pole (short a[S][S]) {
        for (int i(0);i<size;++i) {
            for (int j(0);j<size;++j) {
                arr[i][j]=a[i][j];
            }
        }
    }
    pair <short,short> rp (short val) {
        if (S==4) {
            switch (val) {
                case 0:
                    return make_pair(3,3);
                    break;
                case 1:
                    return make_pair(0,0);
                    break;
                case 2:
                    return make_pair(0,1);
                    break;
                case 3:
                    return make_pair(0,2);
                    break;
                case 4:
                    return make_pair(0,3);
                    break;
                case 5:
                    return make_pair(1,0);
                    break;
                case 6:
                    return make_pair(1,1);
                    break;
                case 7:
                    return make_pair(1,2);
                    break;
                case 8:
                    return make_pair(1,3);
                    break;
                case 9:
                    return make_pair(2,0);
                    break;
                case 10:
                    return make_pair(2,1);
                    break;
                case 11:
                    return make_pair(2,2);
                    break;
                case 12:
                    return make_pair(2,3);
                    break;
                case 13:
                    return make_pair(3,0);
                    break;
                case 14:
                    return make_pair(3,1);
                    break;
                case 15:
                    return make_pair(3,2);
                    break;
                    
                default:
                    break;
            }
        } else {
            switch (val) {
                case 0:
                    return make_pair(2,2);
                    break;
                case 1:
                    return make_pair(0,0);
                    break;
                case 2:
                    return make_pair(0,1);
                    break;
                case 3:
                    return make_pair(0,2);
                    break;
                case 4:
                    return make_pair(1,0);
                    break;
                case 5:
                    return make_pair(1,1);
                    break;
                case 6:
                    return make_pair(1,2);
                    break;
                case 7:
                    return make_pair(2,0);
                    break;
                case 8:
                    return make_pair(2,1);
                    break;
                default:
                    break;
            }
        }
        return make_pair(-1, -1);
    }
    int d () {
        for (int i(0);i<size;++i) {
            for (int j(0);j<size;++j) {
                int tmp = abs(rp(arr[i][j]).first-i)+abs(rp(arr[i][j]).second-j);
                distance+=tmp;
                cout << tmp << endl;
            }
        }
        return distance;
    }
    Pole* L () {
        short tmparr[S][S];
        pair <short,short> inz; //index zero 
        for (int i(0);i<size;++i) {
            for (int j(0);j<size;++j) {
                if (!arr[i][j]) inz=make_pair(i,j);
                tmparr[i][j]=arr[i][j];
            }
        }
        for (int j(inz.second);j<size-1;++j) {
            tmparr[i][j]=tmparr[i][j+1];
        }
        return Pole(tmparr);

    }
    Pole* R () {
        short tmparr[S][S];
        pair <short,short> inz; //index zero 
        for (int i(0);i<size;++i) {
            for (int j(0);j<size;++j) {
                if (!arr[i][j]) inz=make_pair(i,j);
                tmparr[i][j]=arr[i][j];
            }
        }
        for (int j(inz.second);j>0;--j) {
            tmparr[i][j]=tmparr[i][j-1];
        }
        return Pole(tmparr);
    }
    Pole* U () {
        short tmparr[S][S];
        pair <short,short> inz; //index zero 
        for (int i(0);i<size;++i) {
            for (int j(0);j<size;++j) {
                if (!arr[i][j]) inz=make_pair(i,j);
                tmparr[i][j]=arr[i][j];
            }
        }
        for (int i(inz.first);i<size-1;++i) {
            tmparr[i][j]=tmparr[i+1][j];
        }
        return Pole(tmparr);
    }
    Pole* D () {
        short tmparr[S][S];
        pair <short,short> inz; //index zero 
        for (int i(0);i<size;++i) {
            for (int j(0);j<size;++j) {
                if (!arr[i][j]) inz=make_pair(i,j);
                tmparr[i][j]=arr[i][j];
            }
        }
        for (int i(inz.first);i>0;--i) {
            tmparr[i][j]=tmparr[i-1][j];
        }
        return Pole(tmparr);
    }
    
};

ostream& operator << (ostream& os, Pole& p) {
    for (int i(0);i<S;++i) {
        os << endl;
        for (int j(0);j<S;++i) {
            os << p.arr[i][j]<<" ";
        }
    }
    return os;
}

int main () {
    short arr[S][S];
    for (int i(0);i<S;++i) {
        for (int j(0);j<S;++j) {
            cin >> arr[i][j];
        }
    }
    Pole p(arr);
    cout << p.d();
}










