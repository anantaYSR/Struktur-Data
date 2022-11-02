#include <iostream>
#include <string>
using namespace std;


// struct untuk menyimpan data
struct Catering {
    string nama_pt;
    string site;
    int bungkusan;
    int year;
    string month;
};

Catering catering;
Catering* ptrCatering = &catering;
// pendeklarasian variabel total dan catering, caterings
int total = 3;
Catering caterings[100];

void pembuat(){
    cout<<"________________________________________________"<<endl;
    cout<<"=                   POSTTEST 3                 ="<<endl;
    cout<<"________________________________________________"<<endl;
    cout<<"\nNama \t\t: Ananta yusra Putra Akmal"<<endl;
    cout<<"NIM \t\t: 2109106024"<<endl;
    cout<<"Kelas \t\t: Informatika A 2021"<<endl;
    cout<<"Praktikum \t: Struktur Data "<<endl;
    cout<<"________________________________________________\n\n"<<endl;
}

// fungsi global melihat/menampilkan data
void readData(){
    system("cls");
    cout<< "\n\n\n\n\n\t\tSELURUH DATA CATERING" << endl
        << "===================================================" << endl;
    if(total == 0) {
        cout << "Data kosong...\n";
    }else {
        for (int indexs = 0; indexs < total; indexs++){
        Catering catering = caterings[indexs];
        Catering* ptrCatering = &catering;
        cout<< "Data Ke-" << indexs + 1 << endl
            << "\nNama PT\t\t: " << ptrCatering->nama_pt << endl
            << "Site\t\t: " << ptrCatering->site << endl
            << "Jumlah Bungkusan: " << ptrCatering->bungkusan << endl
            << "Tahun\t\t: " << ptrCatering->year << endl
            << "Bulan\t\t: " << ptrCatering->month << endl
            << "=============================\n\n" << endl;
        }
    }
}

// fungsi global input data 
void inputData(){
    system("cls");
    cout<< "\n\t\tTAMBAH DATA CATERING" << endl
        << "===================================================" << endl;
    // MENGAMBIL INPUTAN USER
    cout << "Masukkan Nama PT\t: "; cin >> ptrCatering->nama_pt;fflush(stdin);
    cout << "Masukkan site\t\t: "; cin >> ptrCatering->site;fflush(stdin);
    cout << "Masukkan bungkusan\t: "; cin >> ptrCatering->bungkusan;fflush(stdin);
    cout << "Masukkan Tahun\t\t: "; cin >> ptrCatering->year;fflush(stdin);
    cout << "Masukkan bulan\t\t: "; cin >> ptrCatering->month;fflush(stdin);
    // APPEND DATA KE ARRAY
    caterings[total] = catering;
    cout << "\nData Berhasil Di Tambahkan" << endl;
    total++;
    system("cls");
}

// fungsi global memperbaharui data 
void updateData(){
    system("cls");
    int indexs;
    // MENGAMBIL INPUTAN USER
    cout<< "\n\t\t\t UBAH DATA CATERING" << endl
        << "===================================================" << endl;
    cout<< "Masukkan urutan data (" << total << ") : "; cin >> indexs;

    cout<< "Masukkan Nama PT\t: "; cin >> ptrCatering->nama_pt;
    cout<< "Masukkan site\t\t: "; cin >> ptrCatering->site;
    cout<< "Masukkan bungkusan\t: "; cin >> ptrCatering->bungkusan;
    cout<< "Masukkan Tahun\t\t: "; cin >> ptrCatering->year;
    cout<< "Masukkan bulan\t\t: "; cin >> ptrCatering->month;

    // UPDATE DATA
    caterings[indexs - 1] = catering;
    system("cls");
}

void deleteData(){
    system("cls");
    int indexs;

    cout<< "\n\t\tHAPUS DATA PESANAN CATERING" << endl
    << "===================================================" << endl;
    cout << "Masukkan urutan data (1-" << total << ") : "; cin >> indexs;

    if(indexs != 0 && indexs <= total) {

    // MENGHAPUS DATA DENGAN MENINDIH DATA YANG DIHAPUS DENGAN DATA SESUDAHNYA
    for (int i = indexs - 1; i < total; ++i) {
        caterings[i] = caterings[i + 1];
    }
    cout << "\nBerhasil menghapus !";

    // MENGURANGI TOTAL DATA
    total--;
    } else {
    cout << "\nData tidak ada!";
    }system("cls");
}


int main(){
    caterings[0] = {
        "MHU",
        "Samarinda",
        237,
        2020,
        "Agustus"
    };

    caterings[1] = {
        "CK",
        "Batuah",
        154,
        2020,
        "Mei"
    };

    caterings[2] = {
        "PPA",
        "Tenggarong",
        387,
        2020,
        "September"
    };

    string pilih;
    pembuat();
    menu :
    cout <<  "======================" << endl
        << 	 "        CATERING      " << endl
        <<   "======================" << endl
        <<   "[1] Lihat  		" << endl
        <<   "[2] Tambah 		" << endl
        <<   "[3] Ubah  		" << endl
        <<   "[4] Hapus  		" << endl
        <<   "[5] Keluar Program 	" << endl;
    cout << "\nMasukkan pilihan :"; cin >> pilih;


    // pilihan 1 sebagai input data 
    if (pilih == "1"){
        readData();
        goto menu;
    }
    // pilihan 2 sebagai melihat/menampilkan data 
    else if ( pilih=="2"){
        inputData();
        goto menu;
    }
    // pilihan 3 sebagai update data 
    else if (pilih == "3"){
        updateData();
        goto menu;
    }
    // pilihan 4 sebagai hapus data 
    else if (pilih== "4") {
        deleteData();
        system("cls");
        cout << "Penghapusan Data Sukses" << endl;
        goto menu;
    }
    // pilihan 5 sebagai exit program
    else if (pilih == "5") {
        system("cls");
        atexit;
    }
    // pilihan selain 1-5
    else {
        system ("cls");
        cout << "\nInput Tidak Valid !!! \n" << endl;
        goto menu;
    } 
	return 0;
}


