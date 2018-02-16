#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std ;
struct Deque {
private:
    char *buffer;
    int end,size, capacity;
    void resize (int length) {
        char *new_buffer = new char[length];
        
        for (int i=0; i<end;++i) {
            new_buffer[i]=buffer[i];
            
            
        }
        delete[] buffer;
        buffer=new_buffer;
        //delete[] new_buffer;
        capacity*=2;
        
    }
public:
    Deque () {
        buffer=new char(2);
        end=0;
        size=0;
        capacity=2;
    }
    ~Deque() {
        //delete[] buffer;
    }
    
    char pop_front() {
        char result;
        if (!size) {
            result=' ';
        } else {
            result=buffer[end-1];
            end--;
        }
        return result;
    }
    
    void push_front (char number){
        if (size==capacity) {
            resize(capacity*2);
        }
        buffer[end]=number;
        end++;
        size++;
        
    }
    int givesize () {
        return size;
    }
    char what_up () {
        char result;
        if (!size) {
            result=' ';
        } else {
            result=buffer[end-1];
        }
        //cout<<"what up: "<<result<<"\n";
        return result;
    }
};
int main () {
    string str1,str2,ans;
    int position(0);
    int position2(0);
    cin>>str1>>str2;
    Deque stack;
    bool canwego(true);
    while (canwego==true and position2<str2.size()){
        if (position<=str1.size()) {
            if (str1[position]==str2[position2]) {
                ans+=str1[position];
                position2++;
                position++;
            } else {
                if (stack.what_up()==str2[position2]) {
                    ans+=stack.pop_front();
                    position2 += 1;
                } else {
                    stack.push_front(str1[position]);
                    position +=1 ;
                }
            }
        } else {
            if (stack.givesize()==0 || stack.what_up()!=str2[position2]) {
                canwego=false;
            } else {
                ans+=stack.pop_front();
                position2+=1;
            }
        }
    }
    
    
    
    if (ans==str2) {
        cout<<"YES";
    } else cout<<"NO";
    
    
    
}






