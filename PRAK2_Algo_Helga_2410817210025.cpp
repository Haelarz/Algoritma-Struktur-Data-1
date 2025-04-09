#include <iostream>
#include <string>
using namespace std;

struct kendaraan{
    string plat, jenis, nama, alamat, kota;
};
int main(){
    kendaraan ninja;

    ninja.plat = "DA1234MK";
    ninja.jenis = "RUSH";
    ninja.nama = "Andika Hartanto";
    ninja.alamat = "Jl. Kayu Tangi 1";
    ninja.kota = "Banjarmasin";

    cout << "Plat Nomor Kendaraan : " << ninja.plat << endl;
    cout << "Jenis Kendaraan : " << ninja.jenis << endl;
    cout << "Nama Pemilik : " << ninja.nama << endl;
    cout << "Alamat : " << ninja.alamat << endl;
    cout << "Kota : " << ninja.kota << endl;
}
