// struktur pembuatan dan syntax di ambil dari kodingan kelas terbuka :)
#include <iostream>
#include <string>
#include <unistd.h>
#include <bits/stdc++.h>
using namespace std;
// struktur pembuatan dan syntax di ambil dari kodingan kelas terbuka :)


void pembuat(){
    cout<<"________________________________________________"<<endl;
    cout<<"=                   POSTTEST 5                 ="<<endl;
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
  Node *next;
  Node *prev;
};

//fungsi pengecekan dan deklarasi jika value di node kosong atau tidak
bool isEmpty(Node *head, Node *tail)
{
  if (head == NULL)
  {
    return true;
  }
  return false;
}

//jumlah dari banyak nya data didalam Node
int lenght(Node *head,Node *tail)
{
  int jumlah = 0;
  while (head != NULL)
  {
    jumlah++;
    head = head->next;
    tail = tail->prev;
  }
  return jumlah;
}

int jumlah = 0;



// fungsi pembuat node jika user ingin menggunakan fungsi add data
Node *newNode(){
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
void addFirst(Node **head, Node **tail){
  cout<< "\n\t\tADD FIRST" << endl
      << "=======================================" << endl;
	Node *nodeBaru = newNode();
	nodeBaru->next = *head;
	nodeBaru->prev = NULL;
    if (*head == NULL && *tail == NULL){
        *head = nodeBaru;
        *tail = nodeBaru;
    } else {
        (*head)->prev = nodeBaru;
        *head = nodeBaru;
    }
  panjang++;
}

//add data di antara value lenght
void addMiddle(Node **head, Node **tail) {
    // Jika linked list kosong
    if (isEmpty(*head, *tail)) {
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

    if (index > 0 && index <= lenght(*head, *tail)){        
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
void addLast(Node **head, Node **tail){
    cout<< "\n\t\tADD FIRST" << endl
    << "=======================================" << endl;
      Node *nodeBaru = newNode();
	    nodeBaru->prev = *tail;
	    nodeBaru->next = NULL;
	
    // Jika linked kosong
    if (*head == NULL && *tail == NULL){
        *head = nodeBaru;
        *tail = nodeBaru;
    } else {
        (*tail)->next = nodeBaru;
        *tail = nodeBaru;
    }
    panjang++;
}

// fungsi global menghapus node pertama
void deleteFirst(Node **head, Node **tail){
  if (isEmpty(*head, *tail)){
	    cout << "\n\t\tLINKED LIST KOSONG" << endl
      << "===================================================" << endl;
    return;
  }else if((*head)->next == NULL){
        Node *del = *head;
        *head = NULL;
        *tail = NULL;
        delete del;
        panjang--;
        cout << "\n\t\tDelete Node Berhasil" << endl
        << "===================================================" << endl;
        system("pause");
    } else {
        Node *del;
        del = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        delete del;
        panjang--;
        cout << "\n\t\tDelete Node Berhasil" << endl
        << "===================================================" << endl;
        system("pause");
    }
}

// fungsi global menghapus node di antara value akhir dan awal Node
void deleteMiddle(Node **head, Node **tail){

    // Jika linked list kosong
    if (isEmpty(*head, *tail)) {
        cout << "\n\t\tLinked List Kosong" << endl
             << "===================================================" << endl;
        return;
    }

    int nomor = 1;
    Node *nodeBaru, *del;
    int hapus;
    cout << "\nNomor Berapa Yang Ingin Dihapus? :  ";
    cin >> hapus;

    if (hapus > 0 && hapus <= lenght(*head, *tail)){

        if (hapus == 1 or hapus == lenght(*head, *tail)){

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
void deleteLast(Node **head, Node **tail){
  if (isEmpty(*head, *tail))
  {
    cout << "\n\t\tLINKED LIST KOSONG" << endl
       << "===================================================" << endl;
    return;
  }else if((*head)->next == NULL){
        Node *del = *head;
        *head = NULL;
        *tail = NULL;
        delete del;
        panjang--;
        cout << "\n\t\tDelete Node Berhasil" << endl
       << "===================================================" << endl;
        system("pause");
    } else {
        Node *del;
        del = *tail;
        *tail = (*tail)->prev;
        (*tail)->next = NULL;
        delete del;
        panjang--;
        cout << "\n\t\tDelete Node Berhasil" << endl
        << "===================================================" << endl;
        system("pause");
    }
}

// menampilkan data/value dari Node
void display(Node *head, Node *tail){
  // Jika linked list kosong
    panjang = 0;
    if (isEmpty(head, tail))
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
void update(Node **head, Node **tail){
  // Jika linked list kosong
  if (isEmpty(*head, *tail))
  {
    cout << "\n\t\tLinked List Kosong" << endl
         << "===================================================" << endl;
    return;
  }
  cout<< "\n\t\tUPDATE NODE" << endl
            << "===================================================" << endl;
  int pilihan = 0;
  cout << "\nBanyak node ada : " << lenght(*head, *tail) << endl;
  cout << "Pilih node yang ingin diupdate : ";
  cin >> pilihan;
  Node *temp = *head;
  if (pilihan > 0 && pilihan <= lenght(*head, *tail))
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

void MergeSort(Node **headRef, int kategori, int tipe){
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


Node *SortedMerge(Node *a, Node *b, int kategori, int tipe){
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
        result->next->prev = a;
        result->prev = NULL;
    } else {
        result = b; 
        result->next = SortedMerge(a, b->next, kategori, tipe);
        result->next->prev = b;
        result->prev = NULL;
    }
    return (result);
}
/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves,
and return the two lists using the reference parameters.
If the length is odd, the extra node should go in the front list.
Uses the fast/slow pointer strategy. */
void FrontBackSplit(Node *source, Node **frontRef, Node **backRef){
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

void jadikanNilaiUjungItuTail(Node **head, Node **tail){
    Node *cur = *head;
    while (cur->next != NULL){
        cur = cur->next;
    }
    *tail = cur;
}

void sort(Node **head){
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
void search(Node **head, Node **tail){
    
    if (isEmpty(*head, *tail)) {
        cout << "\n============= TIDAK ADA DATA YANG DITEMUKAN =============== " << endl;
        return;
    }

    string key;
    int data;

    Node *temp = *head;

    int jumlah = lenght(*head, *tail);
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

void printReverse(Node *tail){
    Node *cur = tail;
    while (cur != NULL){
        cout << "\n===================================================" << endl
         << "Nama PT\t\t: " << cur->data.nama_pt << endl
         << "Site\t\t: " << cur->data.site << endl
         << "Jumlah Bungkusan: " << cur->data.bungkusan << endl
         << "Tahun\t\t: " << cur->data.year << endl
         << "Bulan\t\t: " << cur->data.month << endl
         << "===================================================" << endl;
        cur = cur->prev;
    }
}

void printfoward(Node *head){
    Node *cur = head;
    while (cur != NULL){
        cout << "\n===================================================" << endl
         << "Nama PT\t\t: " << cur->data.nama_pt << endl
         << "Site\t\t: " << cur->data.site << endl
         << "Jumlah Bungkusan: " << cur->data.bungkusan << endl
         << "Tahun\t\t: " << cur->data.year << endl
         << "Bulan\t\t: " << cur->data.month << endl
         << "===================================================" << endl;
        cur = cur->next;
    }
}

void insertSpecific(Node **head, Node **tail){
    panjang = 0;
    int position;
    cout << "\nBanyak node ada : " << lenght(*head, *tail) << endl;
    cout << "Masukkan data pada posisi: "; cin >> position;
    if (panjang != 0 && position > panjang+1 || position < 0){
        cout << "Posisi melewati batas." << endl;
        system("pause");
        return;
    }
 
    Node *newNode = new Node();
    cout<< "Masukkan Nama PT\t: "; cin >> newNode->data.nama_pt;fflush(stdin);
    cout<< "Masukkan site\t\t: "; cin >> newNode->data.site;fflush(stdin);
    cout<< "Masukkan bungkusan\t: "; cin >> newNode->data.bungkusan;
    cout<< "Masukkan Tahun\t\t: "; cin >> newNode->data.year;
    cout<< "Masukkan bulan\t\t: "; cin >> newNode->data.month;
    // Jika ingin meletakkan node baru pada awal node (Insert First)
    if (position == 1){
        newNode->prev = NULL;
        newNode->next = *head;
        // Jika linkedlist kosong:
        if (*head == NULL && *tail == NULL){
            *head = newNode;
            *tail = newNode;
        } 
        // Jika linkedlist tidak kosong:
        else {
            (*head)->prev = newNode;
            *head = newNode;
        }
    } 
    // Jika terdapat >1 elemen dan ingin meletakkan node baru pada posisi akhir (Insert Last)
    else if (position == panjang + 1){
        newNode->prev = *tail;
        newNode->next = NULL;
        (*tail)->next = newNode;
        *tail = newNode;
    } 
    // Jika ingin meletakkan node baru di tengah-tengah linkedlist
    else {
        // Jika posisi <= 1/2 panjang data
        if (position <= panjang/2){
            // Traversal ke node yang berada SEBELUM node yang ingin disisipkan:
            // Contoh [A->B->C->D->E->F->G->H->I]
            // Z ingin disisipkan pada node D, sehingga ingin node menjadi ...C->Z->D->...
            // Maka traversal ke node C
            Node *cur = *head;
            for (int trv = 0; trv < position - 1 && cur != NULL; trv++) cur = cur->next;
            newNode->next = cur->next;
            newNode->prev = cur; // atau cur->next->prev
            cur->next->prev = newNode;
            cur->next = newNode;
        }
        // Jika posisi > 1/2 panjang data
        else if (position > panjang/2){
            Node *cur = *tail;
            // Traversal ke node yang berada PADA node yang ingin disisipkan:
            // Contoh [A->B->C->D->E->F->G->H->I]
            // Z ingin disisipkan pada node F, sehingga ingin node menjadi ...E->Z->F->...
            // Maka traversal ke node F
            for (int trv = panjang; trv > position + 1 && cur != NULL; trv--) cur = cur->prev;
            newNode->next = cur; // atau cur->prev->next
            newNode->prev = cur->prev;
            cur->prev->next = newNode;
            cur->prev = newNode;
        }
    }
    panjang++;
    cout << "Data telah tersimpan." << endl;
}


void deleteSpecific(Node **head, Node **tail){
    if (*head == NULL && *tail == NULL){
        cout << "LinkedList Kosong" << endl;
        return;
    }

    int position; // index
    cout << "\nBanyak node ada : " << lenght(*head, *tail) << endl;
    cout << "Input index data yang ingin dihapus: "; cin >> position;  
      if (panjang != 0 && position > panjang || position < 0){
          cout << "Posisi terlalu jauh/tidak sesuai" << endl;
          
          return;
      }
      if (position == 0 && panjang > 1){
          Node *del = *head;
          *head = (*head)->next;
          (*head)->prev = NULL;
          delete del;
      } else if (position == 0 && panjang == 1){
          Node *del = *head;
          *head = NULL;
          *tail = NULL;
          delete del;
      } else {
          if (position < panjang/2){
              Node *cur = *head;
              for (int trv = 0; trv < position; trv++){
                  cur = cur->next;
              }
              cur->prev->next = cur->next;
              cur->next->prev = cur->prev;
              delete cur;
          } else {
              Node *cur = *tail;
              for (int trv = panjang - 1; trv > position; trv--){
                  cur = cur->prev;
              }
              cur->prev->next = cur->next;
              cur->next->prev = cur->prev;
              delete cur;
          }
      }
      panjang--;
      cout << "Data telah terhapus." << endl;
      
}

int main()
{
  Node *HEAD = NULL;
  Node *tail = NULL;
  int pilihan = 0;
  pembuat();
  while (pilihan != 15)
  {
    cout <<  "==========================" << endl
         <<  "    Program linked list   " << endl
         <<  "==========================" << endl
         << "1.  Add First" << endl
         << "2.  Add Middle" << endl
         << "3.  Add Last" << endl
         << "4.  Insert Spesific " << endl
         << "5.  Delete First" << endl
         << "6.  Delete Middle" << endl
         << "7.  Delete Last" << endl
         << "8.  Delete Spesific" << endl
         << "9.  Update" << endl
         << "10. Display" << endl
         << "11. Sorting" << endl
         << "12. Searching" << endl
         << "13. Foward" << endl
         << "14. Backward" << endl
         << "15. Exit Program"
         << "\nMasukan pilihan : ";
    cin >> pilihan;
    switch (pilihan)
    {
    case 1:
      addFirst(&HEAD, &tail);
      break;
    case 2:
      addMiddle(&HEAD, &tail);
      break;
    case 3:
      addLast(&HEAD, &tail);
      break;
    case 4:
      insertSpecific(&HEAD, &tail);
      break;
    case 5:
      deleteFirst(&HEAD, &tail);
      break;
    case 6:
      deleteMiddle(&HEAD, &tail);
      break;
    case 7:
      deleteLast(&HEAD, &tail);  
      break;
    case 8:
      deleteSpecific(&HEAD, &tail);  
    break;
    case 9:
      update(&HEAD, &tail);  
    break;
    case 10: 
      display(HEAD, tail);
      break;
    case 11: 
      sort(&HEAD);
      jadikanNilaiUjungItuTail(&HEAD, &tail);
      break;
    case 12:
      search(&HEAD, &tail);
      break;
    case 13:
      printfoward(HEAD);
      break;
    case 14:
      printReverse(tail);
      break;
    case 15:
      break;
    default:
      break;
    }
  }
  return 0;
}