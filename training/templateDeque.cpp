#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std ;

template <typename t> //строим шаблонный дек
struct Deque {
private:
    int size,capacity,begin,end; //size-кол-во элементов в деке
//capacity - вместимость
//begin,end - указатели на начало и конец
    t* buffer; // динамический массив в котором лежат наши элементы
    void resize() { //удваиваем размер
        t* newbuf = new t [capacity*2];
        if (begin < end) {
            for (int i(begin); i < end; ++i) {
                newbuf[i] = buffer[i];
            }
        } else {
            for (int i(begin); i<capacity; ++i) {
                 newbuf[i] = buffer[i];
            }
            for (int i(0); i<end; ++i) {
                newbuf[i + capacity] = buffer[i];
            }
            end+=capacity;
        }
        capacity *= 2;
        buffer = newbuf;
    }
public:
    Deque () {
        buffer = new t [2];
        capacity = 2;
        size = 0;
        begin = 0;
        end = 0;
    }
    t pop_front () {
        t result(-1); //-1 если пусто
        if (size) {
            result = buffer [begin];
            if (begin == capacity-1) {
                begin=0;
            } else begin++;
            size--;
        }
        return result;
    }
    t pop_back () {
        t result(-1);
        if (size) {
            if (!end) {
                end = capacity - 1;
            } else end-- ;
            result = buffer [end];
            size--;
        }
        return result;
    }
    void push_front (t a) {
        if (size==capacity) resize();
        if (!begin) {
            begin = capacity-1;
        } else begin--;
        buffer[begin] = a;
        size++;
        
    }
    void push_back (t a) {
        if (size==capacity) resize();
        buffer[end]=a;
        if (end==capacity-1) {
            end = 0;
        } else end++;
        size++;
    }
};

int main() {
    Deque<double> deque;
    int a,n;
    double b;
    cin >> n;
    for (int i(0); i < n; ++i) {
        cin >> a >> b;
        switch (a) {
            case 1:
                deque.push_front(b);
                break;
            case 2:
                if(b!=deque.pop_front()) {
                    cout << "NO" << endl;
                    return 0;
                }
                break;
            case 3:
                deque.push_back(b);
                break;
            case 4:
                if(b!=deque.pop_back()) {
                    cout << "NO" << endl;
                    return 0;
                }
                break;
            default:
                break;
        }
    }
    cout << "YES" << endl;
}














