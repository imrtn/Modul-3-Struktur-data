# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT)</h1>

<p align="center">Imroatun Sholikha - 109082500111</p>

## Dasar Teori

Abstract Data Type (ADT) merupakan tipe data yang terdiri dari definisi tipe dan sekumpulan operasi dasar yang digunakan untuk mengolah tipe data tersebut. Dalam pemrograman C++, ADT dapat diterapkan menggunakan `struct`, fungsi, dan prosedur untuk mengelola data secara terstruktur. [1]

ADT memiliki beberapa operasi dasar, seperti konstruktor untuk membentuk nilai tipe data, selector untuk mengakses komponen, prosedur pengubah untuk mengubah nilai komponen, serta validator untuk memeriksa kesesuaian data dengan ketentuan tertentu. Operasi tersebut membantu pengelolaan data agar lebih terorganisasi. [1]

Penerapan ADT dalam C++ dilakukan dengan memisahkan deklarasi tipe data dan fungsi ke dalam file header berekstensi `.h`, implementasi fungsi ke dalam file `.cpp`, serta program utama pada `main.cpp`. Pemisahan ini bertujuan agar program lebih terstruktur dan mudah dikembangkan. [1]

**A. Abstract Data Type (ADT)**

ADT merupakan tipe data yang dilengkapi dengan operasi untuk mengolah data tersebut. Dalam C++, tipe data dapat didefinisikan menggunakan `struct`, sedangkan operasi pengolahannya dibuat dalam bentuk fungsi atau prosedur.

**B. Header File dan Implementasi**

File `.h` digunakan untuk mendeklarasikan tipe data dan fungsi yang tersedia. File `.cpp` berisi implementasi fungsi atau prosedur tersebut, sedangkan `main.cpp` digunakan sebagai program utama untuk menjalankan dan menguji ADT.

**C. Fungsi, Prosedur, dan Struct**

`struct` digunakan untuk mengelompokkan beberapa komponen data dalam satu tipe. Fungsi digunakan untuk menjalankan proses dan dapat mengembalikan nilai, sedangkan prosedur digunakan untuk menjalankan proses tertentu. Ketiganya membantu pengelolaan data dalam penerapan ADT.


## Guided

### 1. 

```C++
#ifndef BUKU_H
#define BUKU_H
#include <iostream>

using namespace std;

struct buku{
    string judul;
    int halaman;
    string penulis;
};

void editIsi(string judul, int halaman, string penulis, buku &buku);
void tampilkanisiBuku(buku buku);
bool checkPenulis(buku buku);


#endif
```

Program ini digunakan untuk mendeklarasikan ADT buku yang memiliki tiga atribut, yaitu judul, jumlah halaman, dan penulis. File ini juga mendeklarasikan tiga fungsi, yaitu editIsi() untuk mengubah data buku, tampilkanisiBuku() untuk menampilkan data buku, dan checkPenulis() untuk memeriksa apakah nama penulis kosong.

### 2. 

```C++
#include "buku.h"

void editIsi(string judul, int halaman, string penulis, buku &buku)
{
    buku.judul = judul;
    buku.halaman = halaman;
    buku.penulis = penulis;
}

void tampilkanisiBuku(buku buku)
{
    cout << "Judul Buku : " << buku.judul << endl;
    cout << "Halaman Buku : " << buku.halaman << endl;
    cout << "Penulis Buku : " << buku.penulis << endl;
}

bool checkPenulis(buku buku)
{
    return buku.penulis == "";
}
```

Kode ini merupakan implementasi dari fungsi-fungsi yang telah dideklarasikan pada file buku.h. Fungsi editIsi() digunakan untuk mengisi atau mengubah data buku, tampilkanisiBuku() digunakan untuk menampilkan judul, jumlah halaman, dan penulis buku, sedangkan checkPenulis() digunakan untuk memeriksa apakah atribut penulis berisi string kosong.

### 3. 

```C++
#include <iostream>
#include "buku.h"

using namespace std;
int main()
{
    buku novel;
    string judul, penulis;
    int halaman;

    cout << "Masukkan Judul Buku : ";
    cin >> judul;
    cout << "Masukkan Halaman Buku : ";
    cin >> halaman;
    cout << "Masukkan Penulis Buku : ";
    cin >> penulis;

    editIsi(judul, halaman, penulis, novel);
    tampilkanisiBuku(novel);

    cout << checkPenulis(novel);

    return 0;
}
```

Program utama ini digunakan untuk menerima input berupa judul buku, jumlah halaman, dan nama penulis dari pengguna. Data tersebut kemudian disimpan ke dalam variabel bertipe buku menggunakan fungsi editIsi(), ditampilkan menggunakan fungsi tampilkanisiBuku(), dan diperiksa menggunakan fungsi checkPenulis().

## Unguided

### 1. Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```C++

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas, nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    Mahasiswa mhs[10];
    int n;

    cout << "Jumlah mahasiswa (maksimal 10): ";
    cin >> n;

    if (n < 1 || n > 10) {
        cout << "Jumlah mahasiswa tidak valid!";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;

        cout << "Nama: ";
        getline(cin >> ws, mhs[i].nama);

        cout << "NIM: ";
        cin >> mhs[i].nim;

        cout << "Nilai UTS: ";
        cin >> mhs[i].uts;

        cout << "Nilai UAS: ";
        cin >> mhs[i].uas;

        cout << "Nilai Tugas: ";
        cin >> mhs[i].tugas;

        mhs[i].nilaiAkhir = hitungNilaiAkhir(
            mhs[i].uts, mhs[i].uas, mhs[i].tugas
        );
    }

    cout << "\n=== DATA MAHASISWA ===\n";

    for (int i = 0; i < n; i++) {
        cout << "\nNama: " << mhs[i].nama << endl;
        cout << "NIM: " << mhs[i].nim << endl;
        cout << "Nilai UTS: " << mhs[i].uts << endl;
        cout << "Nilai UAS: " << mhs[i].uas << endl;
        cout << "Nilai Tugas: " << mhs[i].tugas << endl;
        cout << fixed << setprecision(2);
        cout << "Nilai Akhir: " << mhs[i].nilaiAkhir << endl;
    }

    return 0;
}

```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1]()

Program ini dibuat untuk menyimpan dan menampilkan data maksimal 10 mahasiswa dalam sebuah array. Data yang disimpan meliputi nama, NIM, nilai UTS, UAS, tugas, dan nilai akhir. Nilai akhir dihitung menggunakan fungsi dengan rumus 0,3 × UTS + 0,4 × UAS + 0,3 × tugas.

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100

```C++
//pelajaran.h

#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif

//pelajaran.cpp
#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran pel;
    pel.namaMapel = namapel;
    pel.kodeMapel = kodepel;
    return pel;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}

//main.cpp
#include <iostream>
#include <string>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}


```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2_1]()

Program ini dibuat untuk menerapkan konsep Abstract Data Type (ADT) pada data pelajaran. Data terdiri dari nama mata pelajaran dan kode mata pelajaran. Program dibagi menjadi tiga file, yaitu pelajaran.h sebagai deklarasi tipe dan fungsi, pelajaran.cpp sebagai implementasi fungsi, serta main.cpp untuk menjalankan dan menguji program.

### 3. Buatlah program yang dapat memberikan input dan output sbb.

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    
    cout << "Input: ";
    cin >> n;
    
    cout << "Output:\n";

    for (int i = n; i >= 0; --i) {

        for (int j = 0; j < n - i; ++j)
            cout << "  ";

        for (int j = i; j > 0; --j)
            cout << j << " ";

        cout << "*";

        for (int j = 1; j <= i; ++j)
            cout << " " << j;

        cout << endl;
    }

    return 0;
}
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3_1]()

Program ini dibuat untuk mengolah dua buah array integer dua dimensi berukuran 3 × 3 dan dua buah pointer integer. Program memiliki fungsi untuk menampilkan isi array, menukar elemen pada posisi tertentu dari kedua array, serta menukar nilai variabel yang ditunjuk oleh dua pointer.

## Kesimpulan

Berdasarkan latihan yang dikerjakan, konsep dasar C++ dapat digunakan untuk mengolah data menggunakan struktur data, fungsi, array, dan pointer. Latihan pertama menerapkan `struct`, array, dan fungsi untuk menyimpan data maksimal 10 mahasiswa serta menghitung nilai akhir. Latihan kedua menerapkan konsep Abstract Data Type (ADT) dengan memisahkan deklarasi tipe data, implementasi fungsi, dan program utama ke dalam tiga file. Latihan ketiga menerapkan array dua dimensi berukuran 3×3, fungsi untuk menampilkan dan menukar elemen array, serta pointer untuk menukar nilai variabel yang ditunjuk.

## Referensi

[1] Triase. (2020). *Diktat Edisi Revisi: Struktur Data*. Medan: Universitas Islam Negeri Sumatera Utara Medan.

[2] Indahyati, Uce, dan Rahmawati Yunianita. (2020). *Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++*. Sidoarjo: Umsida Press. https://doi.org/10.21070/2020/978-623-6833-67-4