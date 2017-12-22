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

char HashFunc (HashAtom* el) {
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
    HashTable()
    {
        capacity = INITIAL_SIZE;
        atoms = new bool[capacity];
        for (int i(0); i < capacity; ++i) atoms[i] = 0;
        arr = new HashAtom*[capacity];
    }
    void grow()
    {
        capacity *= 2;
        bool * newAtoms = new bool[capacity];
        HashAtom ** newArr = new HashAtom*[capacity];
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
        if (arr[hash] != nullptr) return false;
        if (arr[hash]->key == x->key) return true; //не дойдет до этого куска
        while(arr[(hash + move) % capacity]->key != x->key && arr[(hash + move) % capacity] != nullptr)
            move *= 2;
        return (arr[(hash + move) % capacity] != nullptr);
    }
    
    void insert(HashAtom * x)
    {
        if (size >= 3 * capacity / 4) grow();
        int hash = HashFunc(x) % capacity;
        if (!atoms[hash]){
            arr[hash] = x;
            atoms[hash] = 1;
            return;
        }
        int move(1);
        while (atoms[(hash + move) % capacity])
            move *= 2;
        arr[(hash + move) % capacity] = x;
        atoms[(hash + move) % capacity] = 1;
    }
    
    void erase(HashAtom * x)
    {
        int hash = HashFunc(x) % capacity;
        atoms[hash] = 0;
    }
};
HashTable table;
int main () {
    int n;
    cin >> n;
    string el;
    char command;
    for (int i(0);i < n;++i) {
        cin >> command >> el;
        HashAtom atom (el);
        switch (command) {
            case '+': {
                table.insert(&atom);
                break;
            }
            case '-': {
                table.erase(&atom);
                break;
            }
            case '?': {
                cout << table.contains(&atom);
                break;
            }
            default : break;
        }
    }
}
