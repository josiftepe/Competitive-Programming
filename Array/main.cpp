#include <iostream>
#include <string.h>

using namespace std;
class Array{
private:
    int at;
    int sz;
    int *arr;
public:
    Array(int golemina = 5){
        sz = golemina;
        at = 0;
        arr = new int[golemina];
    }
    ~Array(){
        delete [] arr;
    }
    Array(const Array &other) {
        sz = other.sz;
        at = other.at;
        arr = new int[sz];
        for(int i = 0; i < at; i++){
            arr[i] = other.arr[i];
        }
    }

    void add(int broj){
        if(at == sz){
            int *new_arr = new int[2 * sz];
            sz *= 2;
            for(int i = 0; i < at; i++){
                new_arr[i] = arr[i];
            }
            arr = new_arr;
        }
        arr[at] = broj;
        ++at;
    }
    void change(int a, int b){
        for(int i = 0; i < at; i++){
            if(arr[i] == a){
                arr[i] = b;
            }
        }
    }
    void deleteAll(int broj){
        int *new_arr = new int[sz];
        int brojac = 0;
        for(int i = 0; i < at; i++){
            if(arr[i] != broj){
                new_arr[brojac] = arr[i];
                brojac++;
            }
        }
        at = brojac;
        arr = new_arr;
    }
    void print(){
        for(int i  =0; i < at; i++){
            cout << arr[i] << " ";
        }
        for(int i = at; i < sz; i++){
            cout << "-";
        }
        cout << endl;
    }
};

int main(){
    Array a;
    a.add(6);
    a.add(4);
    a.add(3);
    a.add(2);
    a.add(1);
    Array b(a);
    Array c;
    c = a;
    b.add(2);


    b.change(2, 6);
    c.deleteAll(6);
    cout << " a: ";
    a.print();
    cout << " b: ";
    b.print();
    cout << " c: ";
    c.print();

    return 0;
}
/*
 a: 6 4 3 2 1
 b: 6 4 3 6 1 6 ----
 c: 4 3 2 1 -
 */
