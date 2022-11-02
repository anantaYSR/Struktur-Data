// struktur pembuatan dan syntax di ambil dari kodingan kelas terbuka :)
#include <iostream>
#include <string>
using namespace std;
// struktur pembuatan dan syntax di ambil dari kodingan kelas terbuka :)


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

// struct untuk menyimpan data
struct Catering {
    string nama_pt;
    string site;
    int bungkusan;
    int year;
    string month;
};

Catering catering;

//Struct Node
struct Node{
  Catering data;
  Node *next = NULL;
};

//fungsi pengecekan dan deklarasi jika value di node kosong atau tidak
bool isEmpty(Node *head)
{
  if (head == NULL)
  {
    return true;
  }
  return false;
}

//jumlah dari banyak nya data didalam Node
int lenght(Node *head)
{
  int jumlah = 0;
  while (head != NULL)
  {
    jumlah++;
    head = head->next;
  }
  return jumlah;
}


// fungsi pembuat node jika user ingin menggunakan fungsi add data
Node *newNode()
{
  // Membuat node baru
  Node *nodeBaru = new Node;
    cout<< "Masukkan Nama PT\t: "; cin >> nodeBaru->data.nama_pt;fflush(stdin);
    cout<< "Masukkan site\t\t: "; cin >> nodeBaru->data.site;fflush(stdin);
    cout<< "Masukkan bungkusan\t: "; cin >> nodeBaru->data.bungkusan;
    cout<< "Masukkan Tahun\t\t: "; cin >> nodeBaru->data.year;
    cout<< "Masukkan bulan\t\t: "; cin >> nodeBaru->data.month;
  return nodeBaru;
}


// add data dari depan
void addFirst(Node **head)
{
  cout<< "\n\t\tADD FIRST" << endl
      << "=======================================" << endl;
  Node *nodeBaru = newNode();
  nodeBaru->next = *head;
  *head = nodeBaru;
}

//add data di antara value lenght
void addMiddle(Node **head) {
    // Jika linked list kosong
    if (isEmpty(*head)) {
        cout<< "\n\t    TIDAK DAPAT MENAMBAHKAN DATA" << endl
            << "\n\t\tDATA MASIH KOSONG" << endl
            << "===================================================" << endl;
        return;
    }

    Node *nodeBaru = *head;

    int i=0;
    while (nodeBaru != NULL) {
    cout << "\n===================================================" << endl
         << "Data Ke-" << i + 1 << endl
         << "Nama PT\t\t: " << nodeBaru->data.nama_pt << endl
         << "Site\t\t: " << nodeBaru->data.site << endl
         << "Jumlah Bungkusan: " << nodeBaru->data.bungkusan << endl
         << "Tahun\t\t: " << nodeBaru->data.year << endl
         << "Bulan\t\t: " << nodeBaru->data.month << endl
         << "===================================================" << endl;
        nodeBaru = nodeBaru->next;
    }

    int index;
    cout<< "\n\t\tADD MIDDLE" << endl
        << "=======================================" << endl;
    cout << "\n- Masukkan Data Pada Nomor : ";
    cin >> index;

    if (index > 0 && index <= lenght(*head)){        
        Node *nodeBaru = newNode();

        int nomor = 1;
        Node *temp = (*head);
        while(nomor < index-1){
            temp = temp->next;
            nomor++;
        }

        nodeBaru->next = temp->next;
        temp->next = nodeBaru;
    }
    else{
        cout<< "\n\t\tDATA TIDAK TERSEDIA" << endl
            << "===================================================" << endl;
    }
}

//add data di akhir Node
void addLast(Node **head)
{
  cout<< "\n\t\tADD LAST" << endl
      << "=======================================" << endl;
  Node *nodeBaru = newNode();
  // Jika linked kosong
  if (isEmpty(*head))
  {
    *head = nodeBaru;
  }
  else
  {
    // Traversal ke node terakhir
    Node *temp = *head;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    // Menghubungkan node terakhir dengan node baru
    temp->next = nodeBaru;
  }
}

// fungsi global menghapus node pertama
void deleteFirst(Node **head)
{
  if (isEmpty(*head))
  {
    cout << "\n\t\tLinked List Kosong" << endl
         << "===================================================" << endl;
    return;
  }
  *head = (*head)->next;
  cout << "\n\t\tDelete Node Berhasil" << endl
       << "===================================================" << endl;
}

// fungsi global menghapus node di antara value akhir dan awal Node
void deleteMiddle(Node **head){

    // Jika linked list kosong
    if (isEmpty(*head)) {
        cout << "\n\t\tLinked List Kosong" << endl
             << "===================================================" << endl;
        return;
    }

    int nomor = 1;
    Node *nodeBaru, *del;
    int hapus;
    cout << "\nNomor Berapa Yang Ingin Dihapus? :  ";
    cin >> hapus;

    if (hapus > 0 && hapus <= lenght(*head)){

        if (hapus == 1 or hapus == lenght(*head)){

        cout<< "\n\t\tTIDAK DAPAT MENGHAPUS DATA" << endl
            << "\n\t\tDATA TIDAK ADA DI ANTARA NODE" << endl
            << "===================================================" << endl;

        }
        else{

            Node *temp = (*head);

            while( nomor <= hapus ){
            if( nomor == hapus-1 ){
                nodeBaru = temp;
            }
            if( nomor == hapus ){
                del = temp;
            }
            temp = temp->next;
            nomor++;
            }
            nodeBaru->next = temp;
            delete del;
        }
    }
    else{
        cout << "\n\t\tDATA TIDAK TERSEDIA " << endl
             << "===================================================" << endl;
    }
}

// fungsi global menghapus node terakhir
void deleteLast(Node **head)
{
  if (isEmpty(*head))
  {
    cout << "\n\t\tLinked List Kosong" << endl
         << "===================================================" << endl;
    return;
  }
  if ((*head)->next == NULL)
  {
    *head = NULL;
    cout << "\n\t\tDelete Node Berhasil" << endl
         << "===================================================" << endl;
    return;
  }
  Node *temp = *head;
  while (temp->next->next != NULL)
  {
    temp = temp->next;
  }
  Node *varDelete = temp->next;
  temp->next = NULL;
  delete varDelete;
  cout << "\n\t\tDelete Node Berhasil" << endl
       << "===================================================" << endl;
}

// menampilkan data/value dari Node
void display(Node *head)
{
  // Jika linked list kosong
    if (isEmpty(head))
    {
        cout << "\n\t\tLinked List Kosong" << endl
             << "===================================================" << endl;
    return;
    }
  // Traversal ke node terakhir
        cout<< "\n\t\tSELURUH DATA CATERING" << endl
            << "===================================================" << endl;
        Node *temp = head;

        int i=0;
        while (temp != NULL)
    {
       cout << "Data Ke-" << i + 1 << endl
            << "Nama PT\t\t: " << temp->data.nama_pt << endl
            << "Site\t\t: " << temp->data.site << endl
            << "Jumlah Bungkusan: " << temp->data.bungkusan << endl
            << "Tahun\t\t: " << temp->data.year << endl
            << "Bulan\t\t: " << temp->data.month << endl
            << "=============================\n\n" << endl;
        i += 1;
        temp = temp->next;
    }
  cout << endl;
}


// fungsi mengubah nilai/value dari Node 
void update(Node **head)
{
  // Jika linked list kosong
  if (isEmpty(*head))
  {
    cout << "\n\t\tLinked List Kosong" << endl
         << "===================================================" << endl;
    return;
  }
  cout<< "\n\t\tUPDATE NODE" << endl
            << "===================================================" << endl;
  int pilihan = 0;
  cout << "\nBanyak node ada : " << lenght(*head) << endl;
  cout << "Pilih node yang ingin diupdate : ";
  cin >> pilihan;
  Node *temp = *head;
  if (pilihan > 0 && pilihan <= lenght(*head))
  {
    for (int i = 1; i < pilihan; i++)
    {
      temp = temp->next;
    }
    cout<< "\nMasukkan Nama PT\t: "; cin >> temp->data.nama_pt;fflush(stdin);
    cout<< "Masukkan site\t\t: "; cin >> temp->data.site;fflush(stdin);
    cout<< "Masukkan bungkusan\t: "; cin >> temp->data.bungkusan;
    cout<< "Masukkan Tahun\t\t: "; cin >> temp->data.year;
    cout<< "Masukkan bulan\t\t: "; cin >> temp->data.month;
  }
  else
  {
    cout << "Inputan melebihi jumlah node" << endl;
  }
}


int main()
{
  Node *HEAD = NULL;
  int pilihan = 0;
  pembuat();
  while (pilihan != 9)
  {
    cout <<  "==========================" << endl
         <<  "    Program linked list   " << endl
         <<  "==========================" << endl
         << "1.  Add First" << endl
         << "2.  Add Middle" << endl
         << "3.  Add Last" << endl
         << "4.  Delete First" << endl
         << "5.  Delete Middle" << endl
         << "6.  Delete Last" << endl
         << "7.  Update" << endl
         << "8.  Display" << endl
         << "9.  Exit Program" << endl
         << "\nMasukan pilihan : ";
    cin >> pilihan;
    switch (pilihan)
    {
    case 1:
      addFirst(&HEAD);
      break;
    case 2:
      addMiddle(&HEAD);
      break;
    case 3:
      addLast(&HEAD);
      break;
    case 4:
      deleteFirst(&HEAD);
      break;
    case 5:
      deleteMiddle(&HEAD);
      break;
    case 6:
      deleteLast(&HEAD);  
      break;
    case 7:
      update(&HEAD);  
    break;
    case 8: 
      display(HEAD);
      break;
    case 9:
      break;
    default:
      break;
    }
  }
  return 0;
}

    