#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std ;
struct Stack {
private:
    int* buffer;
    int capacity,end,count;
    void resize () {
        int* new_buffer = new int[capacity*2];
        for (int i(0);i<end;++i) {
            new_buffer[i]=buffer[i];
        }
        buffer=new_buffer;
        capacity*=2;
    }
public:
    Stack () {
        count=0;
        capacity=2;
        buffer=new int [capacity];
        end=0;
    }
    void push (int number) {
        if (count==capacity) {
            resize();
        }
        buffer[end]=number;
        end+=1;
        count+=1;
    }
    int pop () {
        if (count==0) {
            return -1;
        } else {
            end-=1;
            count-=1;
            return buffer[end];
        }
    }
    void debag () {
        cout<<"\n"<<"****************"<<"\n";
        for (int i=0;i<=count;++i){
            cout<<buffer[i]<<" ";
        }
        cout<<"\n"<<"****************"<<"\n";
    }
    int get_count () {
        return count;
    }
};
int main () {
    int n(0),comand(0),a(0),tmp;
    bool ans(true);
    cin>>n;
    Stack stack;
    Stack stackRev;
    for (int i(0);i<n;++i) {
        cin>>comand>>a;
        if (comand==3) {
            stack.push(a);
        } else if (comand==2) {
            if (stackRev.get_count()==0) {
                while (stack.get_count()!=0) {
                    stackRev.push(stack.pop());
                }
                
            }
            tmp=stackRev.pop();
            if (tmp!=a) {
                ans=false;
                break;
            }
            
        }
    }
    if (ans==true) {
        cout<<"YES"<<endl;
    } else cout<<"NO"<<endl;
    return 0;
}








