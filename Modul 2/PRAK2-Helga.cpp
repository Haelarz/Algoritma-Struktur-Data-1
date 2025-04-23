#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define n 10
using namespace std;

char Q[n];
int F = -1, R = -1;

void Inisialisasi(){
    F = R = -1;
}

void RESET(){
    F = R = -1;
}

int isFull(){
    if (R == n - 1){
        return 1; 
    }
    else{
        return 0;  
    }
}

int isEmpty(){
    if(F == -1 || F > R){
        return 1;  
    } else{
        return 0;  
    }

}

void INSERT(){
    char huruf;
    if(isFull()){
        cout << "Queue penuh!" << endl;
    }
    else{
        cout << "Masukkan huruf: ";
        cin >> huruf;
        if (F == -1) F = 0;
        R++;
        Q[R] = huruf;
        cout << "Data '" << huruf << "' dimasukkan ke queue." << endl;
    }
}

void DELETE(){
    if (isEmpty()) {
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Data '" << Q[F] << "' dihapus dari queue." << endl;
        F++;
        if (F > R) RESET(); 
    }
}

void CETAKLAYAR(){
    if (isEmpty()){
        cout << "Queue kosong!" << endl;
    } 
    else{
        cout << "Isi queue: ";
        for (int i = F; i <= R; i++){
            cout << Q[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    char PILIHAN[2];
    int PIL;
    Inisialisasi();

    do{
        cout << "QUEUE" << endl;
        cout << "======================" << endl;
        cout << "1. INSERT" << endl;
        cout << "2. DELETE" << endl;
        cout << "3. CETAK QUEUE" << endl;
        cout << "4. QUIT" << endl;
        cout << "PILIHAN : ";
        cin >> PILIHAN;
        PIL = atoi(PILIHAN);

        switch (PIL){
            case 1:
                INSERT();
                break;
            case 2:
                DELETE();
                break;
            case 3:
                CETAKLAYAR();
                break;
            default:
                cout << "TERIMA KASIH" << endl;
                break;
        }

        cout << "Press any key to continue" << endl;
        getch();
        system("cls");

    } 
    while (PIL < 4);

    return 0;
}