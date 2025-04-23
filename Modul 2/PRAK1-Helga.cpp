#include <iostream>
#define max 10
using namespace std;

int data[max];
int atas = -1;

int kosong(){
    if(atas == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int penuh(){
    if(atas == max-1){
        return 1;
    }
    else{
        return 0;
    }
}

void input(int nilai){
    if(kosong()){
        atas++;
        data[atas] = nilai;
        cout << "Data " << data[atas] << " Masuk Ke Stack\n";
    }
    else if(!penuh()){
        atas++;
        data[atas] = nilai;
        cout << "Data " << data[atas] << " Masuk Ke Stack\n";
    }
    else{
        cout << "Tumpukan Penuh\n";
    }
}

void hapus(){
    if(!kosong()){
        cout << "Data Teratas " << data[atas] << " Sudah Terambil\n";
        atas--;
    }
    else{
        cout << "Data Kosong\n";
    }
}

void tampil(){
    if(!kosong()){
        for(int i = atas; i >= 0; i--){
            cout << "Tumpukan Ke " << i << " = " << data[i] << endl;
        }
    }
    else{
        cout << "Tumpukan Kosong\n";
    }
}

void bersih(){
    atas = -1;
    cout << "Tumpukan Kosong!\n";
}

int main(){
    input(2);
    input(6);
    input(11);

    tampil();

    hapus();
    tampil();

    bersih();
    tampil();

    return 0;
}