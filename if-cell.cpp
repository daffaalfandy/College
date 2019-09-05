#include <iostream>
#include <windows.h>
#include <string.h>
#include <fstream>
#include <conio.h>
using namespace std;
int a=0;
void menu(), input(),  searching(), output(), outputsorting(), tekan();
void seqsearchmerk(), seqsearchbatre(), seqsearchharga();
void allsortmerk(),allsortbatre(), allsortharga(),  binmerk(), binbatre(), binharga(), outputbin();
struct data_hp
{
	char tipehp[100];
	int ram;
	int hdd;
	int camdepan;
	int cambelakang;
	int hargahp;
	int batre;
};
data_hp datahp[100];
data_hp temp;
data_hp temp_datahp[100];
int main()
{  menu(); }
void menu()
{
	int pilih;
	string username, password;
	cout<<"============================="<<endl;
	cout<<"=======DATABASE IF-CELL======"<<endl;
	cout<<"============================="<<endl;
	cout<<"MENU: "<<endl;
	cout<<"1. Input Data (Admin)"<<endl;
	cout<<"2. List HP"<<endl;
	cout<<"3. Searching"<<endl;
	cout<<"4. Exit"<<endl;
	cout<<"PILIH: "; cin>>pilih;
	switch(pilih)
	{
		case 1:
		cout<<"\n\t=====ADMIN====="<<endl;
		cout<<"\t\tMasukkan Username: "; cin>>username;
		cout<<"\t\tMasukkan Password: "; cin>>password;
		if((username=="admin") & (password=="admin123"))
		{ system("CLS"); input(); }
		else
		{ cout<<"\t=====MAAF ANDA TIDAK MEMILIKI OTORITAS UNTUK MENGAKSES MENU INI====="<<endl;menu(); }
		break;
		case 2:
		system("CLS"); output();
		break;
		case 3:
		system("CLS"); searching();
		break;
	}
}
void tekan()
{
	cout<<"-----Tekan Enter Untuk Melanjutkan-----"<<endl;
	getch(); system("CLS"); menu();
}
void input()
{
	int pilfile;
	system("CLS");
	ofstream myfile;
	string namafile;
	cout<<"1. Tambah File"<<endl;
	cout<<"2. Buat File Baru (RESET FILE YANG SUDAH ADA)"<<endl;
	cout<<"PILIH: "; cin>>pilfile;
	cout<<"Silahkan masukkan nama FILE(.txt): "; cin>>namafile;
	if(pilfile==1)
	{ myfile.open(namafile.c_str(), ios::app | ios::in);}
	if(pilfile==2)
	{ myfile.open(namafile.c_str(), ios::trunc | ios::in);}
	cout<<"\n=====INPUT BARANG====="<<endl;
	cout<<"Berapa merk HP yang akan diinput? "; cin>>a; cin.ignore();
	for(int i=0; i<a; i++)
	{

			cout<<"\t\t==============="<<endl;
			cout<<"\t\tNama HP  ke-"<<i+1<<"\t\t\t: ";cin.getline(datahp[i].tipehp, 100);
			cout<<"\t\tRAM HP (MB) ke-"<<i+1<<"\t\t: "; cin>>datahp[i].ram;
			cout<<"\t\tMemori Internal HP(GB) ke-"<<i+1<<"\t: "; cin>>datahp[i].hdd;
			cout<<"\t\tKamera Depan HP(MP) ke-"<<i+1<<"\t: "; cin>>datahp[i].camdepan;
			cout<<"\t\tKamera Belakang HP(MP) ke-"<<i+1<<"\t: "; cin>>datahp[i].cambelakang;			
			cout<<"\t\tKapasitas Battery HP(mAH) ke-"<<i+1<<"\t: "; cin>>datahp[i].batre;
			cout<<"\t\tHarga HP(IDR)  ke-"<<i+1<<"\t\t: "; cin>>datahp[i].hargahp; cin.ignore();
			myfile << datahp[i].tipehp <<endl;
			myfile << datahp[i].ram <<endl;
			myfile << datahp[i].hdd <<endl;
			myfile << datahp[i].camdepan <<endl;
			myfile << datahp[i].cambelakang <<endl;
			myfile << datahp[i].batre <<endl;
			myfile << datahp[i].hargahp <<endl;
	}
	myfile.close();
	tekan();
}
void output()
{
	ifstream myfilee;
	string namafile;
	awal:
	cout<<"Silahkan masukkan nama FILE(.txt): "; cin>>namafile;
	myfilee.open(namafile.c_str(), ios::out);
	if (!myfilee.good())
		{
			cout<< namafile << " tidak ada di dalam direktori" << endl;
			myfilee.close();
			goto awal;
		}
	a=0;
	while(!myfilee.eof() )
	{
		myfilee.get(datahp[a].tipehp, 100);
		myfilee >> datahp[a].ram;
		myfilee >> datahp[a].hdd;
		myfilee >> datahp[a].camdepan;
		myfilee >> datahp[a].cambelakang;
		myfilee >> datahp[a].batre;
		myfilee >> datahp[a].hargahp; myfilee.ignore(); 
		a++;
	}
	system("CLS");
	cout<<"\t\t==========LIST HP=========="<<endl;
	for(int i=0; i<a-1; i++)
	{
			cout<<"\t\t==========================="<<endl;
			cout<<"\n\t\tNama HP\t\t\t\t: "<<datahp[i].tipehp<<endl;
			cout<<"\t\tRAM HP(MB)\t\t\t: "<<datahp[i].ram<<endl; 
			cout<<"\t\tMemori Internal HP(GB)\t\t: "<<datahp[i].hdd<<endl; 
			cout<<"\t\tKamera Depan HP(MP)\t\t: "<<datahp[i].camdepan<<endl; 
			cout<<"\t\tKamera Belakangl HP(MP)\t\t: "<<datahp[i].cambelakang<<endl; 		
			cout<<"\t\tKapasitas Battery HP(MP)\t: "<<datahp[i].batre<<endl; 
			cout<<"\t\tHarga HP(IDR)\t\t\t: "<<datahp[i].hargahp<<endl; 
	}
	myfilee.close();
	tekan();
}	
void outputsorting()
{
	cout<<"==========HASIL SORTING=========="<<endl;
	for(int i=0; i<a; i++)
	{
			cout<<"\t\t=========================="<<endl;
			cout<<"\n\t\tNama HP\t\t\t\t: "<<temp_datahp[i].tipehp<<endl;
			cout<<"\t\tRAM HP(MB)\t\t\t: "<<temp_datahp[i].ram<<endl; 
			cout<<"\t\tMemori Internal HP(GB)\t\t: "<<temp_datahp[i].hdd<<endl; 
			cout<<"\t\tKamera Depan HP(MP)\t\t: "<<temp_datahp[i].camdepan<<endl; 
			cout<<"\t\tKamera Belakangl HP(MP)\t\t: "<<temp_datahp[i].cambelakang<<endl; 		
			cout<<"\t\tKapasitas Battery HP(MP)\t: "<<temp_datahp[i].batre<<endl; 
			cout<<"\t\tHarga HP(IDR)\t\t\t: "<<temp_datahp[i].hargahp<<endl; 
	}tekan();
}			
void searching()
{
	int pilih, pil;
	ifstream myfilee;
	string namafile;
	awal:
	cout<<"Silahkan masukkan nama FILE(.txt): "; cin>>namafile;
	myfilee.open(namafile.c_str(), ios::out);
	if (!myfilee.good())
		{
			cout<< namafile << " tidak ada di dalam direktori" << endl;
			myfilee.close();
			goto awal;
		}
	a=0;
	while(!myfilee.eof())
	{
		myfilee.get(temp_datahp[a].tipehp, 100);
		myfilee >> temp_datahp[a].ram;
		myfilee >> temp_datahp[a].hdd;
		myfilee >> temp_datahp[a].camdepan;
		myfilee >> temp_datahp[a].cambelakang;
		myfilee >> temp_datahp[a].batre;
		myfilee >> temp_datahp[a].hargahp; myfilee.ignore();
		a++;
	}
	system("CLS");
	cout<<"=====CARI BARANG====="<<endl;
	cout<<"Cari Berdasarkan: "<<endl;
	cout<<"1. Merk HP"<<endl;
	cout<<"2. Kapasitas Battery(mAH)"<<endl;
	cout<<"3. Harga HP(IDR)"<<endl;
	cout<<"PILIH: ";cin>>pilih; cin.ignore();
	switch(pilih)
	{
		case 1:
		cout<<"\t1. Seq Search"<<endl;
		cout<<"\t2. Binary Search"<<endl;
		cout<<"\t3. Kembali Ke Menu Utama"<<endl;
		cout<<"\tPilih Metode: ";cin>>pil; cin.ignore();
		switch(pil)
		{
			case 1:
			system("CLS");seqsearchmerk();
			break;
			case 2:
			system("CLS");allsortmerk();
			break;
			case 3:
			system("CLS"); menu();
			break;
		}
		case 2:
		cout<<"\t1. Seq Search"<<endl;
		cout<<"\t2. Binary Search"<<endl;
		cout<<"\t3. Kembali Ke Menu Utama"<<endl;
		cout<<"\tPilih Metode: ";cin>>pil;
		switch(pil)
		{
			case 1:
			system("CLS");seqsearchbatre();
			break;
			case 2:
			system("CLS"); allsortbatre();
			break;
			case 3:
			system("CLS"); menu();
		}
		break;
		case 3:
		cout<<"\t1. Seq Search"<<endl;
		cout<<"\t2. Binary Search"<<endl;
		cout<<"\t3. Kembali Ke Menu Utama"<<endl;
		cout<<"\tPilih Metode: ";cin>>pil; cin.ignore();
		switch(pil)
		{
			case 1:
			system("CLS");seqsearchharga();
			break;
			case 2:
			system("CLS"); allsortharga();
			break;
			case 3:
			system("CLS"); menu();
		}
		break;
	}
	myfilee.close();
}
void seqsearchmerk()
{
	//belum jadi
	int i=0, b=0;
	a--;
	char merk[100];
	cout<<"\tMasukkan merk HP yang ingin anda cari: "; cin.get(merk, 100);
	while(i<a) 
	{
		if(strcmp(merk, temp_datahp[i].tipehp)==1)
		{
				cout<<"\t\t=========================="<<endl;
				cout<<"\n\t\tNama HP\t\t\t\t: "<<temp_datahp[i+1].tipehp<<endl;
				cout<<"\t\tRAM HP(MB)\t\t\t: "<<temp_datahp[i+1].ram<<endl; 
				cout<<"\t\tMemori Internal HP(GB)\t\t: "<<temp_datahp[i+1].hdd<<endl; 
				cout<<"\t\tKamera Depan HP(MP)\t\t: "<<temp_datahp[i+1].camdepan<<endl; 
				cout<<"\t\tKamera Belakangl HP(MP)\t\t: "<<temp_datahp[i+1].cambelakang<<endl; 		
				cout<<"\t\tKapasitas Battery HP(MP)\t: "<<temp_datahp[i+1].batre<<endl; 
				cout<<"\t\tHarga HP(IDR)\t\t\t: "<<temp_datahp[i+1].hargahp<<endl; 
				i++;b++; 	
		}
		else
		i++;
	}
	if(b==0)
	{ cout<<merk<<" tidak ditemukan dalam daftar HP yang tersesdia"<<endl; tekan();}
	else
	tekan(); 
}
void seqsearchbatre()
{
	int i=0, b=0, atas, bawah;
	cout<<"\tMasukkan batas atas  kapasitas battery HP yang ingin anda cari: "; cin>>atas;
	cout<<"\tMasukkan batas bawah  kapasitas battery HP yang ingin anda cari: "; cin>>bawah;
	while(i<99) 
	{
				if((temp_datahp[i].batre >= atas)&&(temp_datahp[i].batre <= bawah))
				{
					cout<<"\t\t=========================="<<endl;
					cout<<"\n\t\tNama HP\t\t\t\t: "<<temp_datahp[i].tipehp<<endl;
					cout<<"\t\tRAM HP(MB)\t\t\t: "<<temp_datahp[i].ram<<endl; 
					cout<<"\t\tMemori Internal HP(GB)\t\t: "<<temp_datahp[i].hdd<<endl; 
					cout<<"\t\tKamera Depan HP(MP)\t\t: "<<temp_datahp[i].camdepan<<endl; 
					cout<<"\t\tKamera Belakangl HP(MP)\t\t: "<<temp_datahp[i].cambelakang<<endl; 		
					cout<<"\t\tKapasitas Battery HP(MP)\t: "<<temp_datahp[i].batre<<endl; 
					cout<<"\t\tHarga HP(IDR)\t\t\t: "<<temp_datahp[i].hargahp<<endl; 
					b++; 
			}
			i++;
	}
	if(b==0)
	{ cout<<"Kapasitas batre "<<atas<<"-"<<bawah<<" tidak ditemukan dalam daftar HP yang tersedia"<<endl;tekan();}
	else
	tekan();
}
void seqsearchharga()
{
	int i=0, b=0, atas, bawah;
	cout<<"\tMasukkan batas atas  harga HP yang ingin anda cari: "; cin>>atas;
	cout<<"\tMasukkan batas bawah  harga HP yang ingin anda cari: "; cin>>bawah;
	while(i<99) 
	{
				if((temp_datahp[i].hargahp >= atas)&&(temp_datahp[i].hargahp <= bawah))
				{
					cout<<"\t\t=========================="<<endl;
					cout<<"\n\t\tNama HP\t\t\t\t: "<<temp_datahp[i].tipehp<<endl;
					cout<<"\t\tRAM HP(MB)\t\t\t: "<<temp_datahp[i].ram<<endl; 
					cout<<"\t\tMemori Internal HP(GB)\t\t: "<<temp_datahp[i].hdd<<endl; 
					cout<<"\t\tKamera Depan HP(MP)\t\t: "<<temp_datahp[i].camdepan<<endl; 
					cout<<"\t\tKamera Belakangl HP(MP)\t\t: "<<temp_datahp[i].cambelakang<<endl; 		
					cout<<"\t\tKapasitas Battery HP(MP)\t: "<<temp_datahp[i].batre<<endl; 
					cout<<"\t\tHarga HP(IDR)\t\t\t: "<<temp_datahp[i].hargahp<<endl; 
					b++; 
			}
			i++;
	}
	if(b==0)
	{ cout<<"Range harga "<<atas<<"-"<<bawah<<" tidak ditemukan dalam daftar HP yang tersedia"<<endl;tekan();}
	else
	tekan(); 
}
void allsortmerk()
{
	int sort, k=0,i=0,j=0;
	cout<<"=====METODE SORTING====="<<endl;
	cout<<"1. Bubble Sort"<<endl;
	cout<<"2. Straight Insertion Sort"<<endl;
	cout<<"3. Selection Sort"<<endl;
	cout<<"4. Shell Sort"<<endl;
	cout<<"PILIH: "; cin>>sort;
	if(sort==1)
	{
		int  i,j;
		for(i=0; i<a-1; i++)
		{
			for(j=0; j<a-1-i; j++)
			{
				if(strcmp(temp_datahp[j].tipehp, temp_datahp[j+1].tipehp)==1)
				{
					swap(temp_datahp[j], temp_datahp[j+1]);
				}
			}
		}	
	}
	if(sort==2)
	{
		for(i=1; i<a; i++)
		{
			temp=temp_datahp[i];
			j=i-1;
			while((strcmp(temp.tipehp, temp_datahp[j].tipehp)==1) && (j>=0))
			{
				temp_datahp[j+1]=temp_datahp[j];
				j--;
				temp_datahp[j+1]=temp;
			}
		}
	}
	if(sort==3)
	{
		for(i=0; i<a; i++)
		{
			for(j=i+1; j<a; j++)
			{
				if(strcmp(temp_datahp[i].tipehp, temp_datahp[j].tipehp)==1)
				{
					swap(temp_datahp[j], temp_datahp[i]);
				}
			}
		}
	}
	if(sort==4)
	{
		
		for(j=k; j<a; j++)
		{
			for(i=j-k; i>=0; i-=k)
			{
				if(strcmp(temp_datahp[i+k].tipehp, temp_datahp[i].tipehp)==1)
				break;
				else
				{
					swap(temp_datahp[i+k], temp_datahp[i]);
				}
			}
		}
	}
	cin.ignore(); system("CLS"); binmerk();
	
}
void allsortbatre()
{
	int sort, k=0,i=0,j=0;
	cout<<"=====METODE SORTING====="<<endl;
	cout<<"1. Bubble Sort"<<endl;
	cout<<"2. Straight Insertion Sort"<<endl;
	cout<<"3. Selection Sort"<<endl;
	cout<<"4. Shell Sort"<<endl;
	cout<<"PILIH: "; cin>>sort;
	if(sort==1)
	{
		int  i,j;
		for(i=0; i<a-1; i++)
		{
			for(j=0; j<a-1-i; j++)
			{
				if(temp_datahp[j].batre> temp_datahp[j+1].batre)
				{
					swap(temp_datahp[j], temp_datahp[j+1]);
				}
			}
		}	
	}
	if(sort==2)
	{
		for(i=1; i<a; i++)
		{
			temp=temp_datahp[i];
			j=i-1;
			while((temp.batre<temp_datahp[j].batre)&& (j>=0))
			{
				temp_datahp[j+1]=temp_datahp[j];
				j--;
				temp_datahp[j+1]=temp;
			}
		}
	}
	if(sort==3)
	{
		for(i=0; i<a; i++)
		{
			for(j=i+1; j<a; j++)
			{
				if(temp_datahp[i].batre> temp_datahp[j].batre)
				{
					swap(temp_datahp[j], temp_datahp[i]);
				}
			}
		}
	}
	if(sort==4)
	{
		
		for(j=k; j<a; j++)
		{
			for(i=j-k; i>=0; i-=k)
			{
				if(temp_datahp[i+k].batre>= temp_datahp[i].batre)
				break;
				else
				{
					swap(temp_datahp[i+k], temp_datahp[i]);
				}
			}
		}
	}
	cin.ignore(); system("CLS"); binbatre();
	
}
void allsortharga()
{
	int sort, k=0,i=0,j=0;
	cout<<"=====METODE SORTING====="<<endl;
	cout<<"1. Bubble Sort"<<endl;
	cout<<"2. Straight Insertion Sort"<<endl;
	cout<<"3. Selection Sort"<<endl;
	cout<<"4. Shell Sort"<<endl;
	cout<<"PILIH: "; cin>>sort;
	if(sort==1)
	{
		int  i,j;
		for(i=0; i<a-1; i++)
		{
			for(j=0; j<a-1-i; j++)
			{
				if(temp_datahp[j].hargahp> temp_datahp[j+1].hargahp)
				{
					swap(temp_datahp[j], temp_datahp[j+1]);
				}
			}
		}	
	}
	if(sort==2)
	{
		for(i=1; i<a; i++)
		{
			temp=temp_datahp[i];
			j=i-1;
			while((temp.hargahp<temp_datahp[j].hargahp)&& (j>=0))
			{
				temp_datahp[j+1]=temp_datahp[j];
				j--;
				temp_datahp[j+1]=temp;
			}
		}
	}
	if(sort==3)
	{
		for(i=0; i<a; i++)
		{
			for(j=i+1; j<a; j++)
			{
				if(temp_datahp[i].hargahp> temp_datahp[j].hargahp)
				{
					swap(temp_datahp[j], temp_datahp[i]);
				}
			}
		}
	}
	if(sort==4)
	{
		
		for(j=k; j<a; j++)
		{
			for(i=j-k; i>=0; i-=k)
			{
				if(temp_datahp[i+k].hargahp>= temp_datahp[i].hargahp)
				break;
				else
				{
					swap(temp_datahp[i+k], temp_datahp[i]);
				}
			}
		}
	}
	cin.ignore(); system("CLS"); binharga();
	
}
void binmerk()
{
	char cari[100];
	int i, j, k;
	bool found;
	cout<<"\tMasukkan merk HP yang ingin anda cari: "; cin.getline(cari, 100);
	found = false;
	i=0; j=a;
	while((!found)&(i<=j))
	{
		k=(i+j)/2;
		if(strcmp(cari, temp_datahp[k].tipehp)==1)
		found=true;
		else
		{
			if(strcmp(cari, temp_datahp[k].tipehp)==0)
			j=k-1; 
			else
			i=k+1;
		}
	}
	if(found)
	{
		cout<<"\t\t=========================="<<endl;
		cout<<"\n\t\tNama HP\t\t\t\t: "<<temp_datahp[k].tipehp<<endl;
		cout<<"\t\tRAM HP(MB)\t\t\t: "<<temp_datahp[k].ram<<endl; 
		cout<<"\t\tMemori Internal HP(GB)\t\t: "<<temp_datahp[k].hdd<<endl; 
		cout<<"\t\tKamera Depan HP(MP)\t\t: "<<temp_datahp[k].camdepan<<endl; 
		cout<<"\t\tKamera Belakangl HP(MP)\t\t: "<<temp_datahp[k].cambelakang<<endl; 		
		cout<<"\t\tKapasitas Battery HP(MP)\t: "<<temp_datahp[k].batre<<endl; 
		cout<<"\t\tHarga HP(IDR)\t\t\t: "<<temp_datahp[k].hargahp<<endl;
		tekan();
	} 
	else
	{
		cout<<"Merk yang dimasukan tidak ada dalam list"<<endl;
		tekan();
	}
}
void binbatre()
{
	int i, j, k, cari;
	bool found;
	cout<<"\tMasukkan kapasitas batre yang ingin anda cari: "; cin>>cari;
	found = false;
	i=0; j=a;
	while((!found)&(i<=j))
	{
		k=(i+j)/2;
		if(cari==temp_datahp[k].batre)
		found=true;
		else
		{
			if(cari<temp_datahp[k].batre)
			j=k-1; 
			else
			i=k+1;
		}
	}
	if(found)
	{
		cout<<"\t\t=========================="<<endl;
		cout<<"\n\t\tNama HP\t\t\t\t: "<<temp_datahp[k].tipehp<<endl;
		cout<<"\t\tRAM HP(MB)\t\t\t: "<<temp_datahp[k].ram<<endl; 
		cout<<"\t\tMemori Internal HP(GB)\t\t: "<<temp_datahp[k].hdd<<endl; 
		cout<<"\t\tKamera Depan HP(MP)\t\t: "<<temp_datahp[k].camdepan<<endl; 
		cout<<"\t\tKamera Belakangl HP(MP)\t\t: "<<temp_datahp[k].cambelakang<<endl; 		
		cout<<"\t\tKapasitas Battery HP(MP)\t: "<<temp_datahp[k].batre<<endl; 
		cout<<"\t\tHarga HP(IDR)\t\t\t: "<<temp_datahp[k].hargahp<<endl;
		tekan();
	} 
	else
	{
		cout<<"Kapasitas batre  yang dimasukan tidak ada dalam list"<<endl;
		tekan();
	}
}
void binharga()
{
	int i, j, k, cari;
	bool found;
	cout<<"\tMasukkan harga yang ingin anda cari: "; cin>>cari;
	found = false;
	i=0; j=a;
	while((!found)&(i<=j))
	{
		k=(i+j)/2;
		if(cari==temp_datahp[k].hargahp)
		found=true;
		else
		{
			if(cari<temp_datahp[k].hargahp)
			j=k-1; 
			else
			i=k+1;
		}
	}
	if(found)
	{
		cout<<"\t\t=========================="<<endl;
		cout<<"\n\t\tNama HP\t\t\t\t: "<<temp_datahp[k].tipehp<<endl;
		cout<<"\t\tRAM HP(MB)\t\t\t: "<<temp_datahp[k].ram<<endl; 
		cout<<"\t\tMemori Internal HP(GB)\t\t: "<<temp_datahp[k].hdd<<endl; 
		cout<<"\t\tKamera Depan HP(MP)\t\t: "<<temp_datahp[k].camdepan<<endl; 
		cout<<"\t\tKamera Belakangl HP(MP)\t\t: "<<temp_datahp[k].cambelakang<<endl; 		
		cout<<"\t\tKapasitas Battery HP(MP)\t: "<<temp_datahp[k].batre<<endl; 
		cout<<"\t\tHarga HP(IDR)\t\t\t: "<<temp_datahp[k].hargahp<<endl;
		tekan();
	} 
	else
	{
		cout<<"Harga yang dimasukan tidak ada dalam list"<<endl;
		tekan();
	}
}
		
