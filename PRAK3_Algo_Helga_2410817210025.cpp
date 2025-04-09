#include <iostream>
#include <string>
using namespace std;

struct random{
    string huruf, kata;
    int angka;
};
int main(){
    random ea;

    cout << "Masukkan sebuah huruf = ";
    cin >> ea.huruf;
    cout << "Masukkan Sebuah kata = ";
    cin >> ea.kata;
    cout << "Masukkan angka = ";
    cin >> ea.angka;
    

    cout << "\nHuruf yang anda masukkan adalah " << ea.huruf << endl;
    cout << "Kata yang anda masukkan adalah " << ea.kata << endl;
    cout << "Angka yang anda masukkkan adalah " << ea.angka << endl;
}