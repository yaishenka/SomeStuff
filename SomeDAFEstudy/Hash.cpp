#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

#define INITIAL_SIZE 8

class HashAtom {
public:
    string key;
    HashAtom() = default;
    HashAtom (string k) {key=k;};
};

unsigned char HashFunc (HashAtom* el) {
    const int consp = 46;
    int n = el->key.size();
    int p[n];
    p[0] = 1;
    for (int i(1); i < n; ++i) {
        p[i] = p[i-1] * consp;
    }
    char hs[n];
    hs[0] = el->key[0];
    unsigned char hash = hs[0];
    for (int i(1); i < n; ++i) {
        hs[i] = hs[i-1] + p[i] * el->key[i];
        hash += hs[i];
    }
    return hash;
}

class HashTable {
    bool * atoms = nullptr;
    int capacity = INITIAL_SIZE, size = 0;
    HashAtom ** arr = nullptr;
public:
  HashTable() {
      capacity = INITIAL_SIZE;
      atoms = new bool[capacity];
      for (int i(0); i < capacity; ++i) atoms[i] = 0;
        arr = new HashAtom*[capacity];
      for (int i(0); i < capacity; ++i)
        arr[i] = nullptr;
    }
    void grow() {
        capacity *= 2;
        bool * newAtoms = new bool[capacity];
        HashAtom ** newArr = new HashAtom*[capacity];
        for (int i(0); i < capacity; ++i)
          newArr[i] = nullptr;
        for (int i(0); i < capacity; ++i) newAtoms[i] = 0;
        for(int i=0; i<capacity/2; i++) {
            int newHash = HashFunc(arr[i])%capacity;
            newArr[newHash] = arr[i];
            newAtoms[newHash] = atoms[i];
        }
        delete atoms;
        delete arr;
        atoms = newAtoms;
        arr = newArr;
    }

    bool contains(HashAtom * x) {
        int hash = HashFunc(x) % capacity;
        int move(1);
        std::cout << "?0 " << x->key << ' ' << hash << " " << (arr[hash] == nullptr) << std::endl;
        if (arr[hash] == nullptr) return false;
        std::cout << "?1 " << x->key << ' ' << hash << " " << (arr[hash]->key == x->key && atoms[hash]) << std::endl;
        if (arr[hash]->key == x->key && atoms[hash]) return true;
        while (arr[(hash + move) % capacity] != nullptr && !(arr[(hash + move) % capacity]->key == x->key && atoms[(hash + move) % capacity]))
        //while(arr[(hash + move) % capacity] != nullptr && arr[(hash + move) % capacity]->key != x->key && !atoms[(hash + move) % capacity])
            move *= 2;
        std::cout << "?2" << x->key << ' ' << hash << " " << (arr[(hash + move) % capacity] != nullptr) << std::endl;
        return (arr[(hash + move) % capacity] != nullptr);
    }

    void insert(HashAtom * x) {
        if (size >= 3 * capacity / 4) grow();
        size++;
        int hash = HashFunc(x) % capacity;
        if (!atoms[hash]) {
            arr[hash] = x;
            atoms[hash] = 1;
            std::cout << "+ " << x->key << ' ' << (hash) << std::endl;
            return;
        }
        int move(1);
        while (atoms[(hash + move) % capacity])
            move *= 2;
        std::cout << "+ " << x->key << ' ' << ((hash + move) % capacity) << std::endl;
        arr[(hash + move) % capacity] = x;
        atoms[(hash + move) % capacity] = 1;
    }

    void erase(HashAtom * x) {
        size--;
        int hash = HashFunc(x) % capacity;
        if (arr[hash]->key == x->key) {
            atoms[hash] = 0;
            std::cout << "- " << x->key << ' ' << hash << std::endl;
        }
        else {
            int move(1);
            while(arr[(hash + move) % capacity]->key != x->key)
                move *= 2;
            atoms[(hash + move) % capacity] = 0;
            std::cout << "- " << x->key << ' ' << ((hash + move) % capacity) << std::endl;
        }
    }
};

HashTable table;

int main () {
    string el;
    char command;
    while (cin >> command >> el) {
        //cin >> command >> el;
        HashAtom* atom = new HashAtom (el);
        switch (command) {
            case '+': {
              if (table.contains(atom))
                cout << "FAIL\n";
              else {
                table.insert(atom);
                cout << "OK\n";
              }
                break;
            }
            case '-': {
              if (!table.contains(atom))
                cout << "FAIL\n";
              else {
                table.erase(atom);
                cout << "OK\n";
              }
                break;
            }
            case '?': {
                if (table.contains(atom))
                  cout << "OK\n";
                else
                  cout << "FAIL\n";
                break;
            }
            default : break;
        }
    }

/*
+ hello
+ bye
? bye
+ bye
- bye
? bye
? hello
*/
/*
OK
OK
OK
FAIL
OK
FAIL
OK */
}
/*
+ a
+ friend
+ friend
+ in
- im
+ need
? frend
+ is
+ a
+ friend
- friend
? friend
+ indeed




OK
OK
FAIL
OK
FAIL
OK
FAIL
OK
FAIL
FAIL
OK
FAIL
OK
*/

/*
?0 a 1 1
+ a 1
OK
?0 friend 0 1
+ friend 0
OK
?0 friend 0 0
?1 friend 0 1
FAIL
?0 in 6 1
+ in 6
OK
?0 im 0 0
?1 im 0 0
?2im 0 0
FAIL
?0 need 2 1
+ need 2
OK
?0 frend 2 0
?1 frend 2 0
?2frend 2 0
FAIL
?0 is 4 1
+ is 4
OK
?0 a 1 0
?1 a 1 1
FAIL
?0 friend 0 0
?1 friend 0 1
FAIL
?0 friend 0 0
?1 friend 0 1
- friend 0
OK
?0 friend 0 0
?1 friend 0 0
*/
