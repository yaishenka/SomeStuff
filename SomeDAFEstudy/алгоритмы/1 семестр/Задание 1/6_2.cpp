#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std ;
struct Heap {
private:
    int* buffer;
    int size;
public:
    Heap (int* arr,int size_) {
        buffer=new int [size_+1];
        size=size_;
        for (int i(1);i<=size;++i) {
            buffer[i]=arr[i-1];
        }
        //debag();
        for (int i=size;i>=1;--i) {
            if (has_left(i)){
                //cout<<"i: "<<buffer[i];
                down(i);
                //debag();
            }
        }
    }
    void debag () {
        cout<<"\n"<<"****************"<<"\n";
        for (int i=1;i<=size;++i){
            cout<<buffer[i]<<" ";
        }
        cout<<"\n"<<"****************"<<"\n";
    }
    
    int give_size (){
        return size;
    }
    bool has_left (int index) {
        return index*2<=size;
    }
    bool has_right (int index) {
        return index*2 +1<=size;
    }
    int left (int index) {
        return index*2;
    }
    int right (int index) {
        return index*2 +1;
    }
    int parent (int index) {
        return index/2;
    }
    void down (int index) {
        if (has_left(index) && has_right(index)){
            int min=(buffer[left(index)]<buffer[right(index)])? left(index) : right(index);
            if (buffer[index]>buffer[min]) {
                //cout<<"index: "<<index;
                int tmp=buffer[index];
                buffer[index]=buffer[min];
                buffer[min]=tmp;
                //debag();
                down(min);
            }
        }
        if (has_left(index)) {
            if (buffer[index]>buffer[left(index)]) {
                //cout<<"index: "<<index;
                int tmp=buffer[index];
                buffer[index]=buffer[left(index)];
                buffer[left(index)]=tmp;
                //debag();
                down(left(index));
            }
        }
    }
    void up (int index) {
        if (index >1 && buffer[index]<buffer[parent(index)]){
            int tmp=buffer[parent(index)];
            buffer[parent(index)]=buffer[index];
            buffer[index]=tmp;
            //debag();
            up(parent(index));
        }
    }
    int get_min (){
        return buffer[1];
    }
    void pop_min () {
        int tmp=buffer[1];
        buffer[1]=buffer[size];
        buffer[size]=tmp;
        size--;
        down(1);
    }
    void push (int number) {
        ++size;
        buffer[size]=number;
        up(size);
    }
    
    
};
int main () {
    int n,sum(0),ans(0);
    cin>>n;
    int arr[n];
    for (int i(0);i<n;++i)
        cin>>arr[i];
    Heap heap (arr,n);
    //heap.debag();
    while (heap.give_size()>1) {
        sum=0;
        sum+=heap.get_min();
        heap.pop_min();
        sum+=heap.get_min();
        heap.pop_min();
        ans+=sum;
        //cout<<ans<<endl;
        heap.push(sum);
        //heap.debag();
    }
    cout<<ans;
    
}
















