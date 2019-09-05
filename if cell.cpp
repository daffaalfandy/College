#include <iostream>
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <conio.h>
using namespace std;
void menu(), input(),  searching(), output(), outputsorting();
void seqsearchmerk(), seqsearchbatre(), seqsearchharga();
void binmerk(), binbatre(), binharga(), outputbin();
int a;
struct data_hp
{
	char tipehp[100];
	int ram;
	int hdd;
	int camdepan;
	int cambelakang;
	int stockhp;
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
	cout<<"==SELAMAT DATANG DI IF-CELL=="<<endl;
	cout<<"============================="<<endl;
	cout<<"MENU: "<<endl;
	cout<<"1. Input Data (Admin)"<<endl;
	cout<<"2. List HP"<<endl;
	cout<<"3. Searching"<<endl;
	cout<<"4. Transaksi"<<endl;
	cout<<"5. Exit"<<endl;
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
		case 4:
		system("CLS");
		break;
	}
}
void input()
{
	system("CLS");
	ofstream myfile;
	//string namafile;
	//cout<<"Silahkan masukkan nama FILE(.txt): "; cin>>namafile;
	myfile.open("dataHP.txt", ios::app | ios::in);
	cout<<"\n=====INPUT BARANG====="<<endl;
	cout<<"Berapa merk HP yang akan diinput? "; cin>>a;
	for(int i=0; i<a; i++)
	{

			cout<<"\t\t==============="<<endl;
			cout<<"\t\tNama HP  ke-"<<i+1<<"\t\t\t: ";cin.ignore();cin.get(datahp[i].tipehp,100);
			cout<<"\t\tRAM HP (MB) ke-"<<i+1<<"\t\t: "; cin>>datahp[i].ram;
			cout<<"\t\tMemori Internal HP(GB) ke-"<<i+1<<"\t: "; cin>>datahp[i].hdd;
			cout<<"\t\tKamera Depan HP(MP) ke-"<<i+1<<"\t: "; cin>>datahp[i].camdepan;
			cout<<"\t\tKamera Belakang HP(MP) ke-"<<i+1<<"\t: "; cin>>datahp[i].cambelakang;			
			cout<<"\t\tKapasitas Battery HP(mAH) ke-"<<i+1<<"\t: "; cin>>datahp[i].batre;
			cout<<"\t\tHarga HP(IDR)  ke-"<<i+1<<"\t\t: "; cin>>datahp[i].hargahp;
			cout<<"\t\tStock Barang\t\t\t: ";cin>>datahp[i].stockhp;
			myfile <<" "<< datahp[i].tipehp <<endl;
			myfile << datahp[i].ram <<endl;
			myfile << datahp[i].hdd <<endl;
			myfile << datahp[i].camdepan <<endl;
			myfile << datahp[i].cambelakang <<endl;
			myfile << datahp[i].batre <<endl;
			myfile << datahp[i].hargahp <<endl;
			myfile << datahp[i].stockhp <<endl;
	
	}
	myfile.close();
	 menu();
}	
void output()
{
	ifstream myfilee;
	myfilee.open("dataHP.txt", ios::app);
	a=0;
	while(!myfilee.eof())
	{
		myfilee.ignore(); myfilee.get(datahp[a].tipehp, 100);
		myfilee >> datahp[a].ram;
		myfilee >> datahp[a].hdd;
		myfilee >> datahp[a].camdepan;
		myfilee >> datahp[a].cambelakang;
		myfilee >> datahp[a].batre;
		myfilee >> datahp[a].hargahp;
		myfilee >> datahp[a].stockhp;
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
			cout<<"\t\tStock Barang\t\t\t: "<<datahp[i].stockhp<<endl;
	}
	myfilee.close();
	menu();
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
			cout<<"\t\tStock Barang\t\t\t: "<<temp_datahp[i].stockhp<<endl;
	}menu();;
}			
void searching()
{
	int pilih, pil;
	ifstream myfilee;
	myfilee.open("dataHP.txt", ios::app);
	a=0;
	while(!myfilee.eof())
	{
		myfilee.ignore(); myfilee.get(temp_datahp[a].tipehp, 100);
		myfilee >> temp_datahp[a].ram;
		myfilee >> temp_datahp[a].hdd;
		myfilee >> temp_datahp[a].camdepan;
		myfilee >> temp_datahp[a].cambelakang;
		myfilee >> temp_datahp[a].batre;
		myfilee >> temp_datahp[a].hargahp;
		myfilee >> temp_datahp[a].stockhp;
		a++;
	}
	system("CLS");
	cout<<"=====CARI BARANG====="<<endl;
	cout<<"Cari Berdasarkan: "<<endl;
	cout<<"1. Merk HP"<<endl;
	cout<<"2. Kapasitas Battery(mAH)"<<endl;
	cout<<"3. Harga HP(IDR)"<<endl;
	cout<<"PILIH: ";cin>>pilih;
	switch(pilih)
	{
		case 1:
		cout<<"\t1. Seq Search"<<endl;
		cout<<"\t2. Binary Search"<<endl;
		cout<<"\t3. Kembali Ke Menu Utama"<<endl;
		cout<<"\tPilih Metode: ";cin>>pil;
		switch(pil)
		{
			case 1:
			system("CLS");seqsearchmerk();
			break;
			case 2:
			system("CLS");binmerk();
			break;
			case 3:
			system("CLS"); menu();
		}
		break;
		case 2:
		cout<<"\t1. Seq Search"<<endl;
		cout<<"\t2. Binary Search"<<endl;
		cout<<"\t3. Kembali Ke Menu Utama"<<endl;
		cout<<"\tPilih Metode: ";cin>>a;
		switch(a)
		{
			case 1:
			system("CLS");seqsearchbatre();
			break;
			case 2:
			system("CLS");
			break;
			case 3:
			system("CLS"); menu();
		}
		break;
		case 3:
		cout<<"\t1. Seq Search"<<endl;
		cout<<"\t2. Binary Search"<<endl;
		cout<<"\t3. Kembali Ke Menu Utama"<<endl;
		cout<<"\tPilih Metode: ";cin>>a;
		switch(a)
		{
			case 1:
			system("CLS");seqsearchharga();
			break;
			case 2:
			system("CLS");
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
	char merk[100];
	cout<<"\tMasukkan merk HP yang ingin anda cari: "; cin.ignore(); cin.get(merk, 100);
	while(i<a) 
	{
		if(strcmp(temp_datahp[i].tipehp, merk)==1)
		{
				cout<<"\t\t=========================="<<endl;
				cout<<"\n\t\tNama HP\t\t\t\t: "<<temp_datahp[i+1].tipehp<<endl;
				cout<<"\t\tRAM HP(MB)\t\t\t: "<<temp_datahp[i+1].ram<<endl; 
				cout<<"\t\tMemori Internal HP(GB)\t\t: "<<temp_datahp[i+1].hdd<<endl; 
				cout<<"\t\tKamera Depan HP(MP)\t\t: "<<temp_datahp[i+1].camdepan<<endl; 
				cout<<"\t\tKamera Belakangl HP(MP)\t\t: "<<temp_datahp[i+1].cambelakang<<endl; 		
				cout<<"\t\tKapasitas Battery HP(MP)\t: "<<temp_datahp[i+1].batre<<endl; 
				cout<<"\t\tHarga HP(IDR)\t\t\t: "<<temp_datahp[i+1].hargahp<<endl; 
				cout<<"\t\tStock Barang\t\t\t: "<<temp_datahp[i+1].stockhp<<endl;
				i++;b++; 	
		}
		else
		i++;
	}
	if(b==0)
	{ cout<<merk<<" tidak ditemukan dalam daftar HP yang tersesdia"<<endl; menu();}
	else
	menu(); 
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
					cout<<"\t\tStock Barang\t\t\t: "<<temp_datahp[i].stockhp<<endl;
					b++; 
			}
			i++;
	}
	if(b==0)
	{ cout<<"Kapasitas batre "<<atas<<"-"<<bawah<<" tidak ditemukan dalam daftar HP yang tersedia"<<endl;menu();}
	else
	menu(); 
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
					cout<<"\t\tStock Barang\t\t\t: "<<temp_datahp[i].stockhp<<endl;
					b++; 
			}
			i++;
	}
	if(b==0)
	{ cout<<"Range harga "<<atas<<"-"<<bawah<<" tidak ditemukan dalam daftar HP yang tersedia"<<endl;menu();}
	else
	menu(); 
}
void binmerk()
{
	int pilih;
	char merk[100];
	cout<<"Silahkan masukkan merk HP: "; cin.ignore(); cin.get(merk, 100);
	{cout<<"=====METODE SORTING====="<<endl;
	cout<<"1. Bubble Sort"<<endl;
	cout<<"2. Straight Insertion Sort"<<endl;
	cout<<"3. Selection Sort"<<endl;
	cout<<"4. Shell Sort"<<endl;
	cout<<"5. Quick Sort"<<endl;
	cout<<"PILIH: "; cin>>pilih;system("CLS");}
	switch(pilih)
	{
		case 1: 
		int  i,j;
		for(i=0; i<a-1; i++)
		{
			for(j=0; j<a-1-i; j++)
			{
				if(strcmp(temp_datahp[j].tipehp, temp_datahp[j+1].tipehp)==1)
				{
					temp=temp_datahp[j];
					temp_datahp[j]=temp_datahp[j+1];
					temp_datahp[j+1]=temp;
				}
			}
		}outputsorting();
		break;
		case 2:
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
		}outputsorting();
		break;
		case 3:
		for(i=0; i<a; i++)
		{
			for(j=i+1; j<a; j++)
			{
				if(strcmp(temp_datahp[i].tipehp, temp_datahp[j].tipehp)==1)
				{
					temp=temp_datahp[i];
					temp_datahp[i]=temp_datahp[j];
					temp_datahp[j]=temp;
				}
			}
		}outputsorting();
		break;
		case 4:
		int k=0;i=0;j=0;
		for(j=k; j<a; j++)
		{
			for(i=j-k; i>=0; i-=k)
			{
				if(strcmp(temp_datahp[i+k].tipehp, temp_datahp[i].tipehp)==1)
				break;
				else
				{
					temp=temp_datahp[i];
					temp_datahp[i]=temp_datahp[i+k];
					temp_datahp[i+k]=temp;
				}
			}
		}outputsorting();
		break;
	}
}
		
