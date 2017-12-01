#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std ;
struct Deque {
private:
    int *buffer, begin,end,size, capacity;
    void resize (int length) {
        int *new_buffer = new int[length];
        if (begin<end) {
            for (int i=begin; i<end;++i) {
                new_buffer[i]=buffer[i];
            }
        } else {
            for (int i=begin; i<capacity;++i) {
                new_buffer[i]=buffer[i];
            }
            for (int i=0; i<end;++i) {
                new_buffer[i+capacity]=buffer[i];
            }
            end+=capacity;
            
            
        }
        buffer=new_buffer;
        //delete[] new_buffer;
        capacity*=2;
        
    }
public:
    Deque () {
        buffer=new int(2);
        begin=0;
        end=0;
        size=0;
        capacity=2;
    }
    ~Deque() {
        //delete[] buffer;
    }
    int pop_front() {
        int result(0);
        if (!size) {
            result=-1;
        } else {
            result=buffer[begin];
            
            if (begin==capacity-1) {
                begin=0;
            } else begin+=1;
            size-=1;
        }
        return result;
    }
    int pop_back () {
        int result;
        if (!size) {
            result=-1;
        } else {
            if (!end) end=capacity-1;
            else end--;
            result=buffer[end];
        }
        size--;
        return result;
    }
    void push_front (int number){
        if (size==capacity) {
            resize(capacity*2);
        }
        if (begin==0){
            buffer[capacity-1]=number;
            begin=capacity-1;
            
        } else {
            buffer[begin-1]=number;
            begin--;
        }
        size++;
        
    }
    void push_back (int number){
        if (size==capacity) {
            resize(capacity*2);
        }
        if (end==capacity-1) {
            buffer[capacity-1]=number;
            end=0;
        } else {
            buffer[end]=number;
            end++;
        }
        size++;
    }
    void debugger(){
        cout<<"*****************"<<endl;
        cout<<"Begin: "<<begin<<" End: "<<end<<" Size: "<<size<<" Capacity: "<<capacity<<endl;
        cout<<"Buffer: ";
        for(int i=0; i<capacity; i++){
            cout<<buffer[i]<<" ";
        }
        cout<<endl<<"*****************"<<endl;
    }
    
    
};
int main(){
    int a,b,n;
    bool ans(true);
    cin>>n;
    Deque deque;
    //deque.debugger();
    for (int i(0);i<n;++i) {
        cin>>a>>b;
         if (a==2) {
            if (deque.pop_front()!=b) {
                ans=false;
            }
        } else if (a==3) {
            deque.push_back(b);
        } 
        //deque.debugger();
    }
    if (ans) {
        cout<<"YES"<<endl;
    } else cout<<"NO"<<endl;
    
    
    
    return 0;
}




