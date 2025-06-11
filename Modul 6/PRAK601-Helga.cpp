#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int random(int bil) {
    int jumlah = rand() % bil;
    return jumlah;
}

void randomize() {
    srand(time(NULL));
}

void clrscr() {
    system("cls"); 
}

void sequentialSearching() {
    clrscr();
    int data[100];
    int cari = 20;
    int counter = 0;
    int flag = 0;
    int save;
    randomize();
    cout << "Generating 100 number . . .\n";
    for (int i = 0; i < 100; i++) {
        data[i] = random(100) + 1;
        cout << data[i] << " ";
    }
    cout << "\nDone.\n";

    for (int i = 0; i < 100; i++) {
        if (data[i] == cari) {
            counter++;
            flag = 1;
            save = i;
        }
    }

    if (flag == 1) {
        cout << "Data ada, sebanyak " << counter << " kali!\n";
        cout << "Pada indeks ke-" << save << endl;
    } else {
        cout << "Data tidak ada!\n";
    }
}

void binarySearch() {
    int n, kiri, kanan, tengah, temp, key;
    bool ketemu = false;

    cout << "Masukan jumlah data: ";
    cin >> n;
    int angka[n];
    for (int i = 0; i < n; i++) {
        cout << "Angka ke - [" << i << "] : ";
        cin >> angka[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++){
            if (angka[j] > angka[j + 1]){
                temp = angka[j];
                angka[j] = angka[j + 1];
                angka[j + 1] = temp;
            }
        }
    }

    cout << "================================================================================\n";
    cout << "Data yang telah diurutkan adalah:\n";
    for (int i = 0; i < n; i++) {
        cout << angka[i] << " ";
    }

    cout << "\n================================================================================\n";
    cout << "Masukan angka yang dicari: ";
    cin >> key;

    kiri = 0;
    kanan = n - 1;
    while (kiri <= kanan) {
        tengah = (kiri + kanan) / 2;
        if (key == angka[tengah]) {
            ketemu = true;
            break;
        } else if (key < angka[tengah]) {
            kanan = tengah - 1;
        } else {
            kiri = tengah + 1;
        }
    }

    if (ketemu == true) {
        cout << "Angka ditemukan!\n";
    } else {
        cout << "Angka tidak ditemukan!\n";
    }
}

void perbedaan() {
    cout << "\nPerbedaan Sequential Search dan Binary Search:\n";
    cout << "1. Sequential Search:\n";
    cout << "- Mencari data satu per satu dari awal hingga akhir.\n";
    cout << "- Data tidak harus berurutan.\n";
    cout << "- Cocok untuk dataset kecil.\n";
    cout << "- Lambat jika datanya besar.\n\n";

    cout << "2. Binary Search:\n";
    cout << "- Mencari data dengan membagi dua bagian secara terus-menerus.\n";
    cout << "- Data harus sudah berurutan (ascending).\n";
    cout << "- Lebih cepat dari sequential untuk data kompleks.\n";
    cout << "- Perlu proses sorting dulu.\n";
}

int main() {
    int pilihan;

    do {
        cout << "\nPilih menu\n";
        cout << "1. Sequential Searching\n";
        cout << "2. Binary Searching\n";
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!\n";
        cout << "4. Exit\n";
        cout << "Pilih : ";
        cin >> pilihan;

        if (pilihan == 1) {
            sequentialSearching();
        } else if (pilihan == 2) {
            binarySearch();
        } else if (pilihan == 3) {
            perbedaan();
        } else if (pilihan != 4) {
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }

    } while (pilihan != 4);

    cout << "\nTerima kasih telah menggunakan program ini!\n";
    return 0;
}