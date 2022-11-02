// struktur pembuatan dan syntax di ambil dari kodingan kelas terbuka :)
#include <iostream>
#include <string>
#include <unistd.h>
#include <bits/stdc++.h>
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
int panjang = 0;

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

int jumlah = 0;



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
  panjang++;
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
    panjang = 0;
    cout << "\n===================================================" << endl
         << "Data Ke-" << i + 1 << endl
         << "Nama PT\t\t: " << nodeBaru->data.nama_pt << endl
         << "Site\t\t: " << nodeBaru->data.site << endl
         << "Jumlah Bungkusan: " << nodeBaru->data.bungkusan << endl
         << "Tahun\t\t: " << nodeBaru->data.year << endl
         << "Bulan\t\t: " << nodeBaru->data.month << endl
         << "===================================================" << endl;
         i++;
        nodeBaru = nodeBaru->next;
        panjang++;
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
        panjang++;
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
    panjang++;
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
    panjang = 0;
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
        while (temp != NULL){
       cout << "Data Ke-" << i + 1 << endl
            << "Nama PT\t\t: " << temp->data.nama_pt << endl
            << "Site\t\t: " << temp->data.site << endl
            << "Jumlah Bungkusan: " << temp->data.bungkusan << endl
            << "Tahun\t\t: " << temp->data.year << endl
            << "Bulan\t\t: " << temp->data.month << endl
            << "=============================\n\n" << endl;
        i += 1;
        temp = temp->next;
        panjang++;
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

Node *SortedMerge(Node *a, Node *b, int kategori, int tipe);
Node *SortedMerge_namaPT(Node *a, Node *b);
void FrontBackSplit(Node *source, Node **frontRef, Node **backRef);

void MergeSort(Node **headRef, int kategori, int tipe)
{
    Node *head = *headRef;
    Node *a;
    Node *b;
    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }
    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(head, &a, &b);
    /* Recursively sort the sublists */
    MergeSort(&a, kategori, tipe);
    MergeSort(&b, kategori, tipe);
    /* answer = merge the two sorted lists together */
    *headRef = SortedMerge(a, b, kategori, tipe);
}


Node *SortedMerge(Node *a, Node *b, int kategori, int tipe)
{
    bool Ascending = tipe == 1;
    bool condition = false;
    Node *result = NULL;
    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    /* Pick either a or b, and recur */
    if(kategori == 1) {
        condition = Ascending ? a->data.nama_pt <= b->data.nama_pt : a->data.nama_pt >= b->data.nama_pt;
    } else if(kategori == 2) {
        condition = Ascending ? a->data.year <= b->data.year : a->data.year >= b->data.year;
    }

    if (condition) {
        result = a;
        result->next = SortedMerge(a->next, b, kategori, tipe);
    } else {
        result = b; 
        result->next = SortedMerge(a, b->next, kategori, tipe);
    }
    return (result);
}
/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves,
and return the two lists using the reference parameters.
If the length is odd, the extra node should go in the front list.
Uses the fast/slow pointer strategy. */
void FrontBackSplit(Node *source, Node **frontRef, Node **backRef)
{
    Node *fast;
    Node *slow;
    slow = source;
    fast = source->next;
    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    /* 'slow' is before the midpoint in the list, so split it in two
    at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

void sort(Node **head)
{
    int kategori = 1;
    int tipe = 1;

    cout
        << "\n\n\tPENGURUTAN SORTING" << endl
        << "==================================" << endl
        << "1. Ascending" << endl
        << "2. Descending\n" << endl
        << "Pilih : ";
    cin >> tipe;

    cout
        << "\n\n\tKATEGORI SORTING" << endl
        << "==================================" << endl
        << "1. Nama_PT" << endl
        << "2. Tahun\n" << endl
        << "Pilih : ";
    cin >> kategori;

    MergeSort(head, kategori, tipe);

    cout << "\n\tData Berhasil Disorting" << endl;
}



// ----------------------------------------------------------------
// SEARCHING
// ----------------------------------------------------------------
void split(Node *source, Node **frontRef, Node **backRef) {
    Node *fast;
    Node *slow;
    slow = source;
    fast = source->next;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}
// Urutkan Data

Node *SortedMerge(Node *a, Node *b){
    Node *result = NULL;
    if (a == NULL) return (b);
    else if (b == NULL) return (a);
    
    if (a->data.nama_pt <= b->data.nama_pt){
        result = a;
        result->next = SortedMerge(a->next, b);
    }else{
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}
 
void MergeSort(Node **headRef){
    Node *head = *headRef;
    Node *a;
    Node *b;
    if ((head == NULL) || (head->next == NULL)) return;
    split(head, &a, &b);
    MergeSort(&a);
    MergeSort(&b);
    *headRef = SortedMerge(a, b);
}
 
// ----------------------------------------------------------------
// FIBONACCI
// ----------------------------------------------------------------

// Prosedur Fibonacci Searching
int fibonacciSearch(Node *node, string x, int n){
    int F0 = 0; 
    int F1 = 1; 
    int F = F0 + F1; 
    while (F < n){
        F0 = F1;
        F1 = F;
        F = F0 + F1;
    }
    int offset = -1;
    int trv = 0;
    
    while (F > 1){
        Node *temp = node;
        int i = min(offset + F0, n - 1);

        while (temp->next != NULL && trv < i){
            temp = temp->next;
            trv++;
        }

        if (temp->data.nama_pt < x){
            F = F1;
            F1 = F0;
            F0 = F - F1;
            offset = i;
        }

        else if (temp->data.nama_pt > x){
            F = F0;
            F1 = F1 - F0;
            F0 = F - F1;
        }

        else return i;
        trv = 0;

    }

    Node  *temp2 = node;
    while (temp2->next != NULL && trv < offset +1){
        temp2 = temp2->next;
        trv++;
    }
    if (F1 && temp2->data.nama_pt == x) return offset + 1;
    return -1;
}

// Prosedur mencari
void search(Node **head){
    
    if (isEmpty(*head)) {
        cout << "\n============= TIDAK ADA DATA YANG DITEMUKAN =============== " << endl;
        return;
    }

    string key;
    int data;

    Node *temp = *head;

    int jumlah = lenght(*head);
    int index = 0;

    cout << "\nMasukkan Nama PT yang dicari : ";
    fflush(stdin);
    getline(cin, key); 

    int idx = fibonacciSearch(*head, key, jumlah);

    int nomor = idx + 1;
    if (idx >= 0) {
        while (temp != NULL){

            if (index == idx){
                cout << "\n=========== "<< nomor <<" =========== " << endl
                     << "Nama PT\t\t: " << temp->data.nama_pt << endl
                     << "Site\t\t: " << temp->data.site << endl
                     << "Jumlah Bungkusan: " << temp->data.bungkusan << endl
                     << "Tahun\t\t: " << temp->data.year << endl
                     << "Bulan\t\t: " << temp->data.month << endl
                     << "\n"<< endl;
                break;
            }
            index++;
            temp = temp->next;
        }
    }else{
        cout << "\n TIDAK ADA DATA" << endl;
    }

}





int main()
{
  Node *HEAD = NULL;
  int pilihan = 0;
  pembuat();
  while (pilihan != 11)
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
         << "9.  Sorting" << endl
         << "10. Searching" << endl
         << "11. Exit Program"
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
      sort(&HEAD);
      break;
    case 10:
      search(&HEAD);
    case 11:
      break;
    default:
      break;
    }
  }
  return 0;
}

    