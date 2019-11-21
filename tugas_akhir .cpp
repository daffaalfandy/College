#include <iostream>
#include <malloc.h>
#include <string.h>
#include <windows.h>
#define max 100
#define true 1
#define false 0
using namespace std;
void input(), order(), riwayat(), defaultMenu(), addMenu(), orderMenu(), deleteQueue();
int jumlah = 4, temp, y_order=0;
//linked list
typedef int typeinfo; 
typedef struct typenode *typeptr;
struct typenode
{
	typeinfo info;
	typeptr next;
};

struct data
{
	string nama;
	float harga;
};
data pesanan[100];
struct data_order{
    int order,x_pesan[100], x_jmlorder;
    float total;
    string no_meja;
};
data_order queue_order[100], arcv[100];
//orderdetail[berjalan].
typeptr kepala, ekor;
void linkedList();
void buatListBaru();
void sisipNode(typeinfo IB);
void hapusNode(typeinfo IH);
void bacaMaju();
int listKosong();

struct typequeue //Queue
{
	int data[max];
	int belakang;
};
typequeue queue;
void Queue();
void buatQueue();
void cetakQueue();
void enqueue(int IB);
void dequeue();
int queueKosong();
int queuePenuh();

int top = 0, stack[max]; //Stack
int IP;
void Stack();
void buatStack();
int stackKosong();
int stackPenuh();
void push(int IB);
void pop();
void cetakStack();
int templink = 0, tempque = 0, tempord = 0;
int main()
{
    int pilih;
    buatListBaru();
    buatStack();
    buatQueue();
    defaultMenu();
    main:
    cout<<"=====RESTORAN DANA====="<<endl;
    cout<<"[1] Menu Makanan (Linked List)"<<endl;
    cout<<"[2] Order Makanan (Queue)"<<endl;
    cout<<"[3] Riwayat Pembelian (Stack)"<<endl;
    cout<<"[4] Exit"<<endl;
    cout<<"PILIH: "; cin>>pilih; cin.ignore();
    switch(pilih){
        case 1:
        input();
        system("pause");
        system("cls");
        goto main;
        case 2:
        order();
        system("pause");
        system("cls");
        goto main;
        case 3:
        riwayat();
        system("pause");
        system("cls");
        goto main;
        default:
        return 0;
        break;
    }
}
void defaultMenu(){
    pesanan[0].nama = "Nasi Telur";
    pesanan[0].harga = 10000;
    pesanan[1].nama = "Nasi Ayam";
    pesanan[1].harga = 15000;
    pesanan[2].nama = "Nasi Rendang";
    pesanan[2].harga = 20000;
    pesanan[3].nama = "Nasi Goreng";
    pesanan[3].harga = 12000;
    sisipNode(0);
    sisipNode(1);
    sisipNode(2);
    sisipNode(3);
}

void input(){
    int pilmenu;
    cout<<"=====Daftar Menu====="<<endl;
    cout<<"[1] Lihat Menu"<<endl;
    cout<<"[2] Tambah Menu"<<endl;
    cout<<"[3] Main Menu"<<endl;
    cout<<"PILIH: "; cin>>pilmenu; cin.ignore();
    switch(pilmenu){
        case 1:
        bacaMaju();
        system("pause");
        system("cls");
        break;
        case 2:
        addMenu();
        system("pause");
        system("cls");
        break;
        default:
        break;
    }
}
void bacaMaju()
{
	typeptr bantu;
	bantu = kepala->next;
	cout <<endl<< "\tMenu : " << endl;
	while (bantu != ekor)
	{
		cout<<"\t=====Menu ke-"<<(bantu->info + 1)<<"====="<<endl;
        cout<<"\tNama Menu  : "<<pesanan[bantu->info].nama<<endl;
        cout<<"\tHarga Menu : "<<pesanan[bantu->info].harga<<endl;
		bantu = bantu->next;
	}
	cout << endl;
}
void addMenu()
{
    int tambah;
    cout<<"\tTambah Menu : "<<endl;
    cout<<"\tJumlah menu yang ingin ditambahkan: "; cin>>tambah; cin.ignore();
    temp = jumlah;
    jumlah += tambah; 
    for(int i=temp; i<jumlah; i++){
        cout<<"\t=====Menu ke-"<<i+1<<"====="<<endl;
        cout<<"\tNama Menu  : "; getline(cin, pesanan[i].nama);
        cout<<"\tHarga Menu  : "; cin>>pesanan[i].harga;
        sisipNode(i);
    }
}
void buatListBaru()
{
	kepala = (typenode *)malloc(sizeof(typenode));
	ekor = (typenode *)malloc(sizeof(typenode));
	kepala->info = -9999;
	kepala->next = ekor;
	ekor->info = 9999;
	ekor->next = NULL;
}

int listKosong()
{
	if (kepala->next == ekor)
		return (true);
	else
		return (false);
}

void sisipNode(typeinfo IB)
{
	typeptr NB, bantu;
	NB = (typenode *)malloc(sizeof(typenode));
	NB->info = IB;
	bantu = kepala;
	while (IB > bantu->next->info)
	{
		bantu = bantu->next;
	}
	NB->next = bantu->next;
	bantu->next = NB;
}

void hapusNode(typeinfo IH)
{
	typeptr hapus, bantu;
	if (listKosong())
		cout << "\nList masih kosong";

	else
	{
		bantu = kepala;
		while (bantu->next != ekor && IH != bantu->next->info)
			bantu = bantu->next;
		if (IH == bantu->next->info)
		{
			hapus = bantu->next;
			bantu->next = hapus->next;
			free(hapus);
		}
		else
			cout << "Node tidak di temukan" << endl;
	}
}
void order(){
    int pilorder;
    cout<<"=====Order Menu====="<<endl;
    cout<<"[1] Order Menu"<<endl;
    cout<<"[2] List Order"<<endl;
    cout<<"[3] Hapus Order"<<endl;
    cout<<"[4] Main Menu"<<endl;
    cout<<"PILIH: "; cin>>pilorder; cin.ignore();
    switch(pilorder){
        case 1:
        orderMenu();
        system("pause");
        system("cls");
        break;
        case 2:
        cetakQueue();
        system("pause");
        system("cls");
        break;
        case 3: 
        dequeue();
        system("pause");
        system("cls");
        break;
        default:
        break;

    }
}
void orderMenu(){
    int pilorder, x_order=0;
    string tambahorder;
    cout<<"\t=====Daftar Menu====="<<endl;
    //brapa x psn
    for(int i=0; i<jumlah; i++){
        cout<<"\t=====Menu ke-"<<i+1<<"====="<<endl;
        cout<<"\tNama Menu  : "<<pesanan[i].nama<<endl;
        cout<<"\tHarga Menu : "<<pesanan[i].harga<<endl;
    }
    cout<<"No Meja: "; getline(cin, queue_order[y_order].no_meja);
    ulang:
    cout<<"\tPilih Menu : "; cin>>pilorder;
    queue_order[y_order].total += pesanan[pilorder-1].harga;
    queue_order[y_order].x_pesan[x_order] = pilorder-1;
    queue_order[y_order].x_jmlorder += 1;
    x_order++;
    cout<<"Tambah Order (y/n) : "; cin>>tambahorder;
    if(tambahorder == "y" || tambahorder == "Y"){
        goto ulang;
    } else {
        enqueue(y_order);
        y_order+=1;
    }
}
void cetakQueue(){
    int x = 1;
	cout << "Data Orderan : " << endl;
	while (x <= queue.belakang)
	{
		cout<<"["<<x<<"]. No Meja = "<<queue_order[queue.data[x]].no_meja<<endl;
		cout<<"\tPesanan      : "<<endl;
        cout<<"\tMenu         : ";
		for(int i = 0; i<queue_order[queue.data[x]].x_jmlorder; i++ ){
            cout<<"\t"<<pesanan[queue_order[queue.data[x]].x_pesan[i]].nama<<"\t\t"<<pesanan[queue_order[queue.data[x]].x_pesan[i]].harga<<"\n\t\t";
        }
        cout<<"\t\tTotal Harga  : "<<queue_order[queue.data[x]].total<<endl;	
		x++;
	}
}
void buatQueue()
{
	queue.belakang = 0;
}
int queueKosong()
{
	if (queue.belakang == 1)
		return (true);
	else
		return (false);
}
int queuePenuh()
{
	if (queue.belakang == max - 1)
		return (true);
	else
		return (false);
}
void enqueue(int IB)
{
	if (queuePenuh())
		cout << "Queue overlflow\n";
	else
	{
		queue.belakang++;
		queue.data[queue.belakang] = IB;
	}
}
void dequeue()
{	struct data_order temp;
	int i;
	if (queueKosong())
	{
		cout << "Queue underflow\n";
	}
	else
	{
		push(queue.data[1]);
		arcv[tempord]=queue_order[queue.data[1]];
		for (i = 1; i < queue.belakang; i++){
			queue.data[i] = queue.data[i + 1];
			queue_order[queue.data[i]] = queue_order[queue.data[i+1]];
		}
        tempord += 1;
		queue.belakang--;
	}
}

void riwayat(){
    int pilriwayat;
    cout<<"=====Riwayat Order====="<<endl;
    cout<<"[1] Lihat Riwayat Order (yang sudah dihapus)"<<endl;
    cout<<"[2] Kosongkan Riwayat Order "<<endl;
    cout<<"[3] Menu Utama"<<endl;
    cout<<"PILIH: "; cin>>pilriwayat; cin.ignore();
    switch(pilriwayat){
        case 1: 
        cetakStack();
        system("pause");
        break;
        case 2:
        while(!stackKosong())pop();
        system("pause");
        break;
        default:
        break;
    }
}
void cetakStack()
{
	int i = top;
	cout << "List Order History :" << endl;
	while (i > 0)
	{
		cout<<"["<<i<<"] No Meja = "<<arcv[stack[i]].no_meja<<endl;
		cout<<"\tPesanan        :"<<endl;
        cout<<"\tMenu           : ";
        for(int x = 0; x<=tempord; x++){
            cout<<"\t"<<pesanan[arcv[stack[i]].x_pesan[x]].nama<<"\t\t"<<pesanan[arcv[stack[i]].x_pesan[x]].harga<<"\n\t\t";
        }
        cout<<"\tTotal Harga    : " << arcv[stack[i]].total<<endl;
		i--;
	}
}
void buatStack()
{
	stack[top] = 0;
}
int stackKosong()
{
	if (top == 0)
		return (true);
	else
		return (false);
}
int stackPenuh()
{
	if (top == max)
		return (true);
	else
		return (false);
}
void push(int IB)
{
	if (stackPenuh())
		cout << "stack overflow\n";
	else
	{
		top++;
		stack[top] = IB;
		stack[0] = top;
	}
}
void pop()
{ struct data temp;

	if (stackKosong())
		cout << "stack underflow\n";
	else
	{
		IP = stack[top];
		top--;
		stack[0] = top;
	}
}

