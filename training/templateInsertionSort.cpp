//yaishenka prod :(
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std ;

class Box {
    friend ostream & operator << (ostream &os, const Box& b); //friend означает что данная функция имеет доступ к приватным полям
    friend bool operator < (Box b1, Box b2);
    friend bool operator > (Box b1, Box b2);
    friend bool operator == (Box b1, Box b2);
    int h,l,w,n;
    int maxsize;
public:
    Box () {
        h=l=w=maxsize=0;
    }
    Box (int height,int length,int width, int number) {
        h=height;
        l=length;
        w=width;
        n=number;
        maxsize = std::max(h, l);
        maxsize = std::max(w,maxsize);
    }
};
//определим операторы сравнения и вывода для нашей структуры
bool operator < (Box b1, Box b2) {
    return b1.maxsize < b2.maxsize;
}
bool operator > (Box b1, Box b2) {
    return b1.maxsize > b2.maxsize;
}
bool operator == (Box b1, Box b2) {
    return b1.maxsize == b2.maxsize;
}
ostream & operator << (ostream &os, const Box& b) {
    os << b.n;
    return os;
}
template <class t> //означает что наша функция может работать с пользовательскими типами данных
void insertion_sort (t* arr, size_t size) {
    int i,j;
    for (i = 1 ; i < size; ++i) {
        j = i-1;
        t tmp = arr[i];
        while (tmp < arr[j] && j>=0 ) {
            arr[j+1]=arr[j]; //сдвигаем элементы как бы расчищая место под тот, который двигаем
            j--;
        }
        arr[j+1]=tmp; //ставим элемент на место
    }
}

int main () {
    int n,l,w,h;
    cin >> n;
    Box arr[n];
    for (int i(0);i<n;++i) {
        cin >> l >> w >> h;
        arr[i] = Box(h,l,w,i); //вызываем конструктор
    }
    insertion_sort(arr, n);
    for (int i(0);i<n;++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}









