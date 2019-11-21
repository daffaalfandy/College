#include <iostream>
#include <string.h>
#include <fstream>
#include <windows.h>
#define true 1
#define false 0
#define max 100
using namespace std;
void input(), archive(), del();
int jumlah, cek, ceks;
// PTB
typedef int typeinfo;
typedef struct typenode *typeptr;
struct typenode{
                typeinfo info;
				typeptr kiri, kanan;
			};
typeptr akar,p,b;
int  NH;
void buat_ptb();
int ptb_kosong();
void sisipnode(typeinfo IB);
void cetak();
void preorder(typeptr akar);
void inorder(typeptr akar);
void postorder(typeptr akar);
void hapusnode(typeinfo IH);
void hapus();

// Data Mahasiswa
struct data {
    int nim;
    string nama;
    float uts, uas, akhir;
};
data mhs[100], temp[100];
// End
int main() {
    int pilih;
    buat_ptb();
    menu:
    cout<<"========================================"<<endl;
    cout<<"\tSimpan Data Mahasiswa Dengan PTB"<<endl;
    cout<<"========================================"<<endl;
    cout<<"Menu : "<<endl;
    cout<<"[1] Input Data Mahasiswa"<<endl;
    cout<<"[2] Tampilkan Data"<<endl;
    cout<<"[3] Hapus Data"<<endl;
    cout<<"[4] Archive"<<endl;
    cout<<"[5] Exit"<<endl;
    cout<<"PILIH: "; cin>>pilih;
    switch(pilih) {
        case 1:
        input();
        system("pause");
        system("CLS");
        goto menu;
        case 2:
        cetak();
        system("pause");
        system("CLS");
        goto menu;
        case 3:
        del();
        system("pause");
        goto menu;
        case 4: 
        archive();
        system("pause");
        system("cls");
        goto menu;
        default: 
        return 0;
        break;
        
    }
}
void input(){

    cout<<"=====INPUT DATA MAHASISWA====="<<endl;
    cout<<"Masukkan jumlah data yang ingin diinput: "; cin>>jumlah; cin.ignore();
    for(int i=0; i<jumlah; i++){
        cout<<"\t=====Mahasiswa ke-"<<i+1<<"====="<<endl;
        cout<<"\tNIM Mahasiswa  : "; cin>>mhs[i].nim; cin.ignore();
        cout<<"\tNama Mahasiswa : "; getline(cin, mhs[i].nama);
        cout<<"\tNilai UTS      : "; cin>>mhs[i].uts; cin.ignore();
        cout<<"\tNilai UAS      : "; cin>>mhs[i].uas; cin.ignore();
        mhs[i].akhir = (mhs[i].uts + mhs[i].uas) / 2;  
        sisipnode(mhs[i].nim); 
    }
}
void del(){
  int nim;
  cout<<"Masukkan NIM yang ingin dihapus: "; cin>>nim;
  for(int i = 0; i<jumlah; i++){
    if(mhs[i].nim == nim){
      ceks++;
      temp[i] = mhs[i];
      hapusnode(nim);
      cout<<"Berhasil menghapus "<<endl;
      break;
    } else {
      cek++;
      break;
    }
    if(cek > 0){
      cout<<"NIM tidak terdapat dalam data"<<endl;
    }
  }
}
void archive(){
    cout<<"=====History Hapus Data====="<<endl;
    for(int i = 0; i<ceks; i++){
      cout<<"NIM Mahasiswa  : "<<temp[i].nim<<endl;
      cout<<"Nama Mahasiswa : "<<temp[i].nama<<endl;
      cout<<"Hasil UTS      : "<<temp[i].uts<<endl;
      cout<<"Hasil UAS      : "<<temp[i].uas<<endl;
      cout<<"Hasil AKHIR    : "<<temp[i].akhir<<endl;
    }
}
void buat_ptb()
{ typeptr ptb;
  ptb=NULL;
  akar=ptb; }

int ptb_kosong()
{ if(akar==NULL)
	 return(true);
  else
	 return(false); }
void sisipnode(typeinfo IB)
{ typeptr NB;
  NB=(typenode *) malloc(sizeof(typenode));
  NB->info=IB;
  NB->kiri=NULL;
  NB->kanan=NULL;
  if (ptb_kosong())
	 akar=NB;
  else
	 { b=akar;
		p=akar;
		// mencari tempat untuk menyisipkan node
		while(p!=NULL && IB!=p->info)
		  { b=p;
			 if (IB<p->info)
				p=b->kiri;
			 else
				p=b->kanan; }
		if (IB==b->info)
		  cout << "\n\nNode " << IB << " sudah ada !\n\n";
		else
		  { if (IB<b->info)
				b->kiri=NB;
			 else
				b->kanan=NB; }
	 }
}
void cetak()
{
  cout << "\n\tPre-order :  "<<endl;
  cout<<"---------------------------------------------------------------------------------"<<endl;
    cout<<"\t|\tNIM\t|\tNama\t|\tUTS\t|\tUAS\t|\tAKHIR\t|"<<endl;
    cout<<"---------------------------------------------------------------------------------"<<endl;
  preorder(akar);
  cout << "\n\tIn-order  :  "<<endl;
  cout<<"---------------------------------------------------------------------------------"<<endl;
    cout<<"\t|\tNIM\t|\tNama\t|\tUTS\t|\tUAS\t|\tAKHIR\t|"<<endl;
    cout<<"---------------------------------------------------------------------------------"<<endl;
  inorder(akar);
  cout << "\n\tPost-order:  "<<endl;
  cout<<"---------------------------------------------------------------------------------"<<endl;
    cout<<"\t|\tNIM\t|\tNama\t|\tUTS\t|\tUAS\t|\tAKHIR\t|"<<endl;
    cout<<"---------------------------------------------------------------------------------"<<endl;
  postorder(akar);
  return;
}
void preorder(typeptr akar)
{   
    if (akar!=NULL){ 
        for(int i=0; i<jumlah; i++){
            if(mhs[i].nim == akar->info){
                cout<<"\t|\t"<<mhs[i].nim<<"\t|";
                cout<<"\t"<<mhs[i].nama<<"\t|";
                cout<<"\t"<<mhs[i].uts<<"\t|";
                cout<<"\t"<<mhs[i].uas<<"\t|";
                cout<<"\t"<<mhs[i].akhir<<"\t|"<<endl;
            }
        }
		preorder(akar->kiri);
		preorder(akar->kanan); }
}
void inorder(typeptr akar)
{ 
    if (akar!=NULL)
	 { inorder(akar->kiri);
		for(int i=0; i<jumlah; i++){
            if(mhs[i].nim == akar->info){
                cout<<"\t|\t"<<mhs[i].nim<<"\t|";
                cout<<"\t"<<mhs[i].nama<<"\t|";
                cout<<"\t"<<mhs[i].uts<<"\t|";
                cout<<"\t"<<mhs[i].uas<<"\t|";
                cout<<"\t"<<mhs[i].akhir<<"\t|"<<endl;
            }
        }
		inorder(akar->kanan); }
}
void postorder(typeptr akar)
{ 
    if (akar!=NULL)
	 { postorder(akar->kiri);
		postorder(akar->kanan);
		for(int i=0; i<jumlah; i++){
            if(mhs[i].nim == akar->info){
                cout<<"\t|\t"<<mhs[i].nim<<"\t|";
                cout<<"\t"<<mhs[i].nama<<"\t|";
                cout<<"\t"<<mhs[i].uts<<"\t|";
                cout<<"\t"<<mhs[i].uas<<"\t|";
                cout<<"\t"<<mhs[i].akhir<<"\t|"<<endl;
            }
        }
     }
}
void hapusnode(typeinfo IH)
{
  if (ptb_kosong())
	  cout << "PTB Kosong !\n\n";
  else
	 { b=akar;
		p=akar;

		// mencari tempat hapus node
		while(p!=NULL && IH!=p->info)
		  { b=p;
			 if (IH<p->info)
				p=b->kiri;
			 else
				p=b->kanan; }
	 }
  hapus();
}
void hapus()
{ typeptr temp;
// Bila PTB terdiri dari akar saja atau akar dengan 1 anak kiri/kanan
  if (p->kiri==NULL && p->kanan==NULL)
	  {
		 if (b==akar && p==akar)
			 akar=NULL;
		 else
			 {
				if (p==b->kiri)
					b->kiri=NULL;
				else
					b->kanan=NULL;
			 }
		free(p);
	  }


// Bila PTB memiliki anak kiri dan anak kanan dgn banyak anak cabang
  else if (p->kiri!=NULL && p->kanan!=NULL)
	  {
		 temp=p->kiri;
		 b=p;
		 while (temp->kanan != NULL)
			{ b=temp;
			  temp=temp->kanan; }
		 p->info=temp->info;
		 if (b==p)
			 b->kiri = temp->kiri;
		 else
			 b->kanan = temp->kiri;
		 free(temp);
	  }
// Bila PTB memiliki anak kiri saja dgn banyak anak cabang
  else if (p->kiri!=NULL && p->kanan==NULL)
	  {
		 if (b==p)
			 akar=p->kiri;
		 else
			{ if (p==b->kiri)
				  b->kiri=p->kiri;
			  else
				  b->kanan=p->kiri;
			}
		 free(p);
	  }

// Bila PTB memiliki anak kanan saja dgn banyak anak cabang
  else if (p->kiri==NULL && p->kanan!=NULL)
	  {
		 if (b==p)
			 akar=p->kanan;
		 else
			{ if (p==b->kanan)
				  b->kanan=p->kanan;
			  else
				  b->kiri=p->kanan;
			}
		 free(p);
	  }
}

