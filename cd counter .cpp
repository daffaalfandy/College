#include <iostream>
using namespace std;
char judul[50][50], nama[50], alamat[100], member, btm;
int keping[50], hari, nik, hp, tot, disc, total, kemb, pay, pilih, kep;
void memb1();
void memb2();
void memb3();
void nonmember1();
void nonmember2();
void nonmember3();

int main()
{
	
	do
	{
		cout<<"===============WELCOME TO DAREDEVIL CD==============="<<endl;
		cout<<"Menu :"<<endl;
		cout<<"1. Software	\n2. Film	\n3. Game"<<endl;
		cout<<"Pilih	: ";cin>>pilih;
		
		switch (pilih)
		{
			
			case 1:
				int i;
				char nambah;
				do
				{
					cout<<"====================================================="<<endl;
					cout<<"Judul			: "; cin.ignore(); cin.getline(judul[i], 50);
					cout<<"Keping CD		: "; cin>>keping[i];
					cout<<"Ingin menambah? (y/n)"; cin>>nambah;
					i++;
				}while(nambah=='y' || nambah=='Y');
					cout<<"Lama penyewaan(Hari)	: "; cin>>hari;
					cout<<"\nIdentitas Penyewa"<<endl;
					cout<<"Nama 		: "; cin.ignore(); cin.getline(nama,50);
					cout<<"NIK		: "; cin>>nik;
					cout<<"Alamat		: "; cin.ignore(); cin.getline(alamat,100);
					cout<<"Nomor HP	: "; cin>>hp;
					cout<<"\nMember? (y/n)		:"; cin>>member;
		
					if(member=='y' || member=='Y')
						{
							memb1();
						}
					else
						{
							nonmember1();
						}
					cout<<"Uang yang dibayarkan 	: "; cin>>pay;
					kemb=pay-total;
					cout<<"Kembalian		: "<<kemb<<endl;
					cout<<"=================TERIMA KASIH================="<<endl;
					break;
			case 2:
				
					cout<<"====================================================="<<endl;
					cout<<"Judul			: "; cin.ignore(); cin.getline(judul[i], 50);
					cout<<"Keping CD		: "; cin>>keping[i];
					cout<<"Lama penyewaan(Hari)	: "; cin>>hari;
					cout<<"\nIdentitas penyewa"<<endl;
					cout<<"Nama 		: "; cin.ignore(); cin.getline(nama,50);
					cout<<"NIK		: "; cin>>nik;
					cout<<"Alamat		: "; cin.ignore(); cin.getline(alamat,100);
					cout<<"Nomor HP	: "; cin>>hp;
					cout<<"\nMember? (y/n)		:"; cin>>member;
		
					if(member=='y' || member=='Y')
						{
							memb2();
						}
					else
						{
							nonmember2();
						}
					cout<<"Uang yang dibayarkan 	: "; cin>>pay;
					kemb=pay-total;
					cout<<"Kembalian		: "<<kemb<<endl;
					cout<<"=================TERIMA KASIH================="<<endl;
					break;
			case 3:
			
					cout<<"====================================================="<<endl;
					cout<<"Judul			: "; cin.ignore(); cin.getline(judul[i], 50);
					cout<<"Keping CD		: "; cin>>keping[i];
					cout<<"Lama penyewaan(Hari)	: "; cin>>hari;
					cout<<"\nIdentitas penyewa"<<endl;
					cout<<"Nama 		: "; cin.ignore(); cin.getline(nama,50);
					cout<<"NIK		: "; cin>>nik;
					cout<<"Alamat		: "; cin.ignore(); cin.getline(alamat,100);
					cout<<"Nomor HP	: "; cin>>hp;
					cout<<"\nMember? (y/n)		:"; cin>>member;
		
					if(member=='y' || member=='Y')
						{
							memb3();
						}
					else
						{
							nonmember3();
						}
					cout<<"Uang yang dibayarkan 	: "; cin>>pay;
					kemb=pay-total;
					cout<<"Kembalian		: "<<kemb<<endl;
					cout<<"=================TERIMA KASIH================="<<endl;
					break;
		}
		cout<<endl;
		cout<<"Apakah anda ingin membuat struk baru lagi? (y/n) : ";cin>>btm;
	}
	while (btm=='y'||'Y');
}
	
void memb1()
	{
		tot=(3000*kep*hari);
		disc=tot*0.20;
		total=tot-disc;
		cout<<"===============Struk Penyewaan==============="<<endl;
		cout<<"Nama 			: "<<nama<<endl;
		cout<<"NIK 			: "<<nik<<endl;
		cout<<"Alamat			: "<<alamat<<endl;
		cout<<"Nomor HP		: "<<hp<<endl;
		cout<<"Judul			: "<<judul<<endl;
		cout<<"Jumlah keping cd 	: "<<kep<<endl;
		cout<<"Lama penyewaan		: "<<hari<<endl;
		cout<<"============================================="<<endl;
		cout<<"Total Pembayaran 	: "<<total<<endl;

	}
	
void memb2()
	{
		tot=(2000*kep*hari);
		disc=tot*0.25;
		total=tot-disc;
		cout<<"===============Struk Penyewaan==============="<<endl;
		cout<<"Nama 			: "<<nama<<endl;
		cout<<"NIK 			: "<<nik<<endl;
		cout<<"Alamat			: "<<alamat<<endl;
		cout<<"Nomor HP		: "<<hp<<endl;
		cout<<"Judul			: "<<judul<<endl;
		cout<<"Jumlah keping cd 	: "<<kep<<endl;
		cout<<"Lama penyewaan		: "<<hari<<endl;
		cout<<"============================================="<<endl;
		cout<<"Total Pembayaran 	: "<<total<<endl;

	}

void memb3()
	{
		tot=(5000*kep*hari);
		disc=tot*0.10;
		total=tot-disc;
		cout<<"===============Struk Penyewaan==============="<<endl;
		cout<<"Nama 			: "<<nama<<endl;
		cout<<"NIK 			: "<<nik<<endl;
		cout<<"Alamat			: "<<alamat<<endl;
		cout<<"Nomor HP		: "<<hp<<endl;
		cout<<"Judul			: "<<judul<<endl;
		cout<<"Jumlah keping cd 	: "<<kep<<endl;
		cout<<"Lama penyewaan		: "<<hari<<endl;
		cout<<"============================================="<<endl;
		cout<<"Total Pembayaran 	: "<<total<<endl;

	}
void nonmember1()
	{
		total=(3000*kep*hari);
		cout<<"===============Struk Penyewaan==============="<<endl;
		cout<<"Nama 			: " <<nama<<endl;
		cout<<"NIK 			: "<<nik<<endl;
		cout<<"Alamat			: "<<alamat<<endl;
		cout<<"Nomor HP		: "<<hp<<endl;
		cout<<"Judul			: "<<judul<<endl;
		cout<<"Jumlah keping cd 	: "<<kep<<endl;
		cout<<"Lama penyewaan		: "<<hari<<endl;
		cout<<"======================================="<<endl;
		cout<<"Total Pembayaran 	: "<<total<<endl;
	}
void nonmember2()
	{
		total=(2000*kep*hari);
		cout<<"===============Struk Penyewaan==============="<<endl;
		cout<<"Nama 			: " <<nama<<endl;
		cout<<"NIK 			: "<<nik<<endl;
		cout<<"Alamat			: "<<alamat<<endl;
		cout<<"Nomor HP		: "<<hp<<endl;
		cout<<"Judul			: "<<judul<<endl;
		cout<<"Jumlah keping cd 	: "<<kep<<endl;
		cout<<"Lama penyewaan		: "<<hari<<endl;
		cout<<"======================================="<<endl;
		cout<<"Total Pembayaran 	: "<<total<<endl;
	}
void nonmember3()
	{
		total=(5000*kep*hari);
		cout<<"===============Struk Penyewaan==============="<<endl;
		cout<<"Nama 			: " <<nama<<endl;
		cout<<"NIK 			: "<<nik<<endl;
			cout<<"Alamat			: "<<alamat<<endl;
			cout<<"Nomor HP		: "<<hp<<endl;
			cout<<"Judul			: "<<judul<<endl;
			cout<<"Jumlah keping cd 	: "<<kep<<endl;
			cout<<"Lama penyewaan		: "<<hari<<endl;
			cout<<"======================================="<<endl;
			cout<<"Total Pembayaran 	: "<<total<<endl;
		}	
