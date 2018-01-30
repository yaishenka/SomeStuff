//yaishenka prod : (
//шаблонная сортировка кучей с определенным для нее оператором вывода а саму кучу строим на классе Сегмент(отрезок) для которого тоже определеяем операторы
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std ;

class Segment {
    int x1,x2,l,n;
    friend bool operator > (Segment s1, Segment s2);
    friend bool operator < (Segment s1, Segment s2);
    friend bool operator == (Segment s1, Segment s2);
    friend ostream& operator << (ostream& os, Segment& s);
    
public:
    Segment () {
        x1=x2=l=n=0;
    }
    Segment (int x_, int x__, int number) {
        x1=x_;
        x2=x__;
        l = abs(x2-x1);
        n=number;
    }
};

bool operator > (Segment s1, Segment s2) { return s1.x1>s2.x2 && s1.x2>s2.x2; };
bool operator < (Segment s1, Segment s2) { return s1.x1<s2.x2 && s1.x2<s2.x2; };
bool operator == (Segment s1, Segment s2) { return s1.x1==s2.x2 && s1.x2==s2.x2; };
ostream& operator << (ostream& os, Segment& s) {
    cout << s.n;
    return os;
}


template <class t>
class HeapSort {
    template <class t1> friend ostream& operator << (ostream& os, HeapSort<t1>& heap);
    size_t size;
    t* arr;
    bool has_left (int index) {
        return 2*index+1<size;
    }
    bool has_right (int index) {
        return 2*index+2<size;
    }
    int parrent (int index) {
        return index/2;
    }
    int left (int index) {
        return 2*index+1;
    }
    int right (int index) {
        return 2*index+2;
    }
    void down (int i){
        if (has_left(i) && has_right(i)) {
            t maxel = arr[right(i)];
            int maxelind = right(i);
            if (arr[left(i)] > arr[right(i)] ) {
                t maxel = arr[left(i)];
                int maxelind = left(i);
            }
            if (arr[i]<maxel) {
                swap(arr[i], arr[maxelind]);
                down(maxelind);
            }
        }
        if (has_left(i)) {
            if (arr[i]<arr[left(i)]) {
                swap(arr[i], arr[left(i)]);
                down(left(i));
            }
        }
    }
    void up (int i) {
        if (arr[i]>arr[parrent(i)]) {
            swap(arr[i], arr[parrent(i)]);
            up(parrent(i));
        }
    }
public:
    HeapSort<t> () {};
    HeapSort<t> (t* a, size_t s) {
        size = s ;
        arr = a;
        for (int i=size/2 - 1 ;i>=0;--i) {
            down(i);
        }
    }
    void sort () {
        size_t tmps=size;
        while (size>1) {
            swap(arr[0], arr[size-1]);
            size--;
            down(0);
        }
        size = tmps;
    }
};

template <class t1>
ostream& operator <<  (ostream& os, HeapSort<t1>& heap) {
    for (int i(0) ; i< heap.size; ++i) {
        os << heap.arr[i] << " ";
    }
    return os;
}


int main () {
    int n,x1,x2;
    cin >> n;
    Segment arr [n];
    for (int i(0);i<n;++i) {
        cin >> x1 >> x2;
        arr[i] = Segment(x1,x2,i);
    }
    HeapSort<Segment> heap;
    heap = HeapSort<Segment> (arr,n);
    heap.sort();
    cout << heap;
}



















