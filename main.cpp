#include <iostream>
#include <string.h>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct qebul_siyahi{
	string ad, soyad;
	double kg, qiymeti, meblegi;
	bool mehsul;
} test1;

typedef struct satis_siyahi{
	string ad, soyad;
	double kg, qiymeti, meblegi;
	bool mehsul;
} test;
class anbar{	
	double arpa_kg, bugda_kg, arpa_qiymet, bugda_qiymet, kassa, kassa_evvel;
	int sat_say, qeb_say;
	string ad, soyad;
	public:
	test1 qeb_siy[50];
	test sat_siy[50]; 
		anbar(double ar_kg, double bug_kg, double ar_qiy, double bug_qiy, double kas);
		void menu();
		void mehsul_qebulu();
		void mehsul_satisi();
		void anbardaki_mehsul();
		void qebul_siyahisi();
		void satis_siyahisi();
		void mehsul_qiymetleri();
		void umumi_gelir();
		void bagla();		
};

anbar :: anbar(double ar_kg, double bug_kg, double ar_qiy, double bug_qiy, double kas)
		{
			system("cls");
			arpa_kg = ar_kg; bugda_kg = bug_kg, kassa = kas; kassa_evvel = kas;
			arpa_qiymet = ar_qiy; bugda_qiymet = bug_qiy; sat_say = 0; qeb_say = 0;
			menu();
		}
void anbar :: mehsul_qebulu()
		{
			string a, s;
			int sec;
			double kg, qiy, meb;
			system("cls");
			cout<<"Mehsulu qebul olan sexsin adi: ";
			cin>>a;
			qeb_siy[qeb_say].ad = a;
			cout<<"Mehsulu qebul olan sexsin soyadi: ";
			cin>>s;
			qeb_siy[qeb_say].soyad = s;	
			v:		
			cout<<endl<<"Mehsulun miqdari (kg): ";
			cin>>kg;
			qeb_siy[qeb_say].kg = kg;
			t:
			cout<<endl<<"Mehsulun novu - Arpa (0 - daxil edin) / Bugda (1 - daxil edin): ";
			cin>>sec;
			if(sec == 1) 
			{
				qiy = bugda_qiymet;
				meb = qiy * kg;
				if(kassa < meb) 
				{
					cout<<endl<<"Bu qeder BUGDA almaq ucun KASSA-da kifayet qeder mebleg yoxdur!"<<endl;
					cout<<"Siz KASSA daki vesaitle Max: "<<kassa/bugda_qiymet<<" kg BUGDA ala bilersiz!"<<endl;
					goto v;
				}
				qeb_siy[qeb_say].mehsul = true;				
				bugda_kg += kg;
			}
			else if(sec == 0) 
			{
				qiy = arpa_qiymet;
				meb = qiy * kg;
				if(kassa < meb) 
				{
					cout<<endl<<"Bu qeder ARPA almaq ucun KASSA-da kifayet qeder mebleg yoxdur!"<<endl;
					cout<<"Siz KASSA daki vesaitle Max: "<<kassa/arpa_qiymet<<" kg ARPA ala bilersiz!"<<endl;
					goto v;
				}
				qeb_siy[qeb_say].mehsul = false;
				arpa_kg += kg;				
			}
			else
			{
				cout<<"Sehv daxil etme: "<<endl;
				goto t;
			}			
			qeb_siy[qeb_say].qiymeti = qiy;
			qeb_siy[qeb_say].meblegi = meb;
			cout<<endl<<"Mehsul ucun odenilecek mebleg => "<<qiy<<" x "<<kg<<" = "<<meb<<" AZN"<<endl;
			kassa = kassa - meb;
			qeb_say++;
			system("pause");
			system("cls");
			menu();
		}
void anbar :: mehsul_satisi()
		{
			string a, s;
			int sec;
			double kg, qiy, meb;
			system("cls");
			cout<<"Mehsulu alan sexsin adi: ";
			cin>>a;
			sat_siy[sat_say].ad = a;
			cout<<"Mehsulu alan sexsin soyadi: ";
			cin>>s;
			sat_siy[sat_say].soyad = s; 
			y:
			cout<<endl<<"Mehsulun miqdari (kg): ";
			cin>>kg;
			sat_siy[sat_say].kg = kg;
			t:
			cout<<endl<<"Mehsulun novu - Arpa (0 - daxil edin) / Bugda (1 - daxil edin): ";
			cin>>sec;
			if(sec == 1) 
			{
				if(bugda_kg < kg)
				{
					cout<<endl<<"Anbarda bu qeder BUGDA yoxdur! Daha az kutle daxil edin! MAX:"<<bugda_kg<<endl;
					goto y;
				}
				sat_siy[sat_say].mehsul = true;
				qiy = bugda_qiymet + (bugda_qiymet * 0.1);
				bugda_kg -= kg;
			}
			else if(sec == 0) 
			{
				if(arpa_kg < kg)
				{
					cout<<endl<<"Anbarda bu qeder ARPA yoxdur! Daha az kutle daxil edin! MAX:"<<arpa_kg<<endl;
					goto y;
				}
				sat_siy[sat_say].mehsul = false;
				qiy = arpa_qiymet + (arpa_qiymet * 0.1);
				arpa_kg -= kg;
			}
			else
			{
				cout<<"Sehv daxil etme: "<<endl;
				goto t;
			}
			sat_siy[sat_say].qiymeti = qiy;
			meb = qiy * kg;
			sat_siy[sat_say].meblegi = meb;
			cout<<endl<<"Mehsul ucun odenilecek mebleg => "<<qiy<<" x "<<kg<<" = "<<meb<<" AZN"<<endl;
			kassa = kassa + meb;
			sat_say++;
			system("pause");
			system("cls");
			menu();
		}
void anbar :: anbardaki_mehsul()
		{
			system("cls");
			cout<<"HAL-HAZIRDA ANBARDA: "<<endl<<"ARPA: "<<arpa_kg<<" kg"<<endl<<"BUGDA: "<<bugda_kg<<" kg"<<endl;
			cout<<"CEMI: "<<arpa_kg + bugda_kg<<" kg";
			cout<<endl<<endl;
			system("pause");
			menu();
		}
void anbar :: qebul_siyahisi()
		{
			system("cls");
			string a;
			cout<<"\tANBARA QEBUL OLUNAN MEHSULLARIN SIYAHISI: "<<endl;
			cout<<"\n-----------------------\n\n";
			for(int i = 0; i < qeb_say; i++)
			{				
				if(qeb_siy[i].mehsul == true) a = " BUGDA";
				else a = " ARPA ";
				cout<<"FROM: "<<qeb_siy[i].ad<<" "<<qeb_siy[i].soyad<<endl;
				cout<<qeb_siy[i].kg<<" kg,"<<a<<endl;
				cout<<qeb_siy[i].qiymeti<<" AZN qiymetle, "<<qeb_siy[i].meblegi<<" AZN\n\n"<<"-----------------------\n\n";
			}
			cout<<endl<<endl<<endl<<endl;
			system("pause");
			menu();
		}
void anbar :: satis_siyahisi()
		{
			string a;
			system("cls");
			cout<<"\tANBARDAN SATILAN MEHSULLARIN SIYAHISI: "<<endl;
			cout<<"\n-----------------------\n\n";
			for(int i = 0; i < sat_say; i++)
			{				
				if(sat_siy[i].mehsul == true) a = " BUGDA";
				else a = " ARPA ";
				cout<<"TO: "<<sat_siy[i].ad<<" "<<sat_siy[i].soyad<<endl;
				cout<<sat_siy[i].kg<<" kg,"<<a<<endl;
				cout<<sat_siy[i].qiymeti<<" AZN qiymetle, "<<sat_siy[i].meblegi<<" AZN\n\n"<<"-----------------------\n\n";
			}
			cout<<endl<<endl<<endl<<endl;
			system("pause");
			menu();
		}
void anbar :: mehsul_qiymetleri()
		{
			int secim;
			double ayeni, byeni;
			system("cls");
			cout<<"\tANBARDA MEHSULLARIN CARI QIYMETLERI: "<<endl;
			cout<<"mehsullar alis qiymetlerinin 10% artiqi ile satilir! "<<endl<<endl;
			cout<<"1. ARPA (alis qiymeti) => "<<arpa_qiymet<<" AZN"<<endl;
			cout<<"2. BUGDA (alis qiymeti) => "<<bugda_qiymet<<" AZN"<<"\n\n--------------------------------------\n"<<endl;
			cout<<"ARPA-nin qiymetini deyismek ucun: (1)"<<endl;
			cout<<"BUGDA-nin qiymetini deyismek ucun: (2)"<<endl<<"sizin seciminiz: ";
			g:
			cin>>secim;
			switch(secim)
			{
				case 1: 
					cout<<"ARPA-nin yeni qiymetini daxil edin: ";
					cin>>ayeni;
					arpa_qiymet = ayeni;
					break;
				case 2:
					cout<<"BUGDA-nin yeni qiymetini daxil edin: ";
					cin>>byeni;
					bugda_qiymet = byeni;
					break;
				default:
					cout<<"secim yanlisdir, yeniden: ";
					goto g;			
			}
			cout<<endl<<endl<<"1. ARPA (yeni alis qiymeti) => "<<arpa_qiymet<<" AZN"<<endl;
			cout<<"2. BUGDA (yeni alis qiymeti) => "<<bugda_qiymet<<" AZN"<<endl<<"\n---------------------\n\n"<<endl<<endl;
			system("pause");
			menu();
		}
void anbar :: umumi_gelir()
		{
			double bugsatgel = 0, arsatgel = 0, bugalcix = 0, aralcix = 0;
			cout<<"\tPROGRAM ISE SALINDIQDAN INIYEDEK OLAN DEYISIKLIK"<<endl;
			cout<<"KASSADA OLAN ONCEKI MEBLEG: "<<kassa_evvel<<endl<<"--------------------------------------------\n";
			for(int i = 0; i < sat_say; i++)
			{
				if(sat_siy[i].mehsul == true) 
				{
					bugsatgel += sat_siy[i].meblegi;
				}
				else arsatgel += sat_siy[i].meblegi;
			}
			cout<<"BUGDA SATISINDAN ELDE EDILEN GELIR: "<<bugsatgel<<endl;
			cout<<"ARPA SATISINDAN GELEN GELIR: "<<arsatgel<<endl;
			cout<<"SATISLARDAN GELEN UMUMI GELIR: "<<arsatgel + bugsatgel<<"\n---------------------------------------\n";
			for(int i = 0; i < qeb_say; i++)
			{
				if(qeb_siy[i].mehsul == true) 
				{
					bugalcix += qeb_siy[i].meblegi;
				}
				else aralcix += qeb_siy[i].meblegi;
			}
			cout<<"BUGDA ALISINA CEKILEN XERC: "<<bugalcix<<" AZN"<<endl;
			cout<<"ARPA ALISINA CEKILEN XERC: "<<aralcix<<" AZN"<<endl;
			cout<<"ALISLARA CEKILEN UMUMI XERC: "<<aralcix + bugalcix<<" AZN"<<"\n---------------------------------------\n";
			cout<<"KASSADA OLAN INDIKI MEBLEG: "<<kassa<<" AZN"<<endl<<"\n-------------------------------------\n";			
			cout<<"ANBARIN DEYERI (anbardaki mehsulun satis qiymeti ile hesablanmasi): ";
			cout<<(arpa_kg * (arpa_qiymet + (arpa_qiymet * 0.1)) + bugda_kg * (bugda_qiymet + (bugda_qiymet * 0.1)))<<" AZN";
			cout<<endl<<endl;
			system("pause");
			menu();
		}
void anbar :: menu()
		{
			system("cls");
			int secim;
			cout<<"--------------- TAXIL ANBARI -----------------"<<endl;
			cout<<"\t\t1. Mehsul qebulu"<<endl;
			cout<<"\t\t2. Mehsul satisi"<<endl;
			cout<<"\t\t3. Anbardaki cari mehsul"<<endl;
			cout<<"\t\t4. Qebul siyahilari"<<endl;
			cout<<"\t\t5. Satis siyahilari"<<endl;
			cout<<"\t\t6. Mehsul qiymetleri"<<endl;
			cout<<"\t\t7. Muhasibat"<<endl;
			cout<<"\t\t8. Bagla"<<endl<<endl;
			cout<<"\tBir secim daxil edin: "; 
			f:
			cin>>secim;
			if(secim == 8) exit(0);
			else
			{
				switch(secim)
				{
					case 1:
						mehsul_qebulu();
						break;
					case 2:
						mehsul_satisi();
						break;
					case 3:
						anbardaki_mehsul();
						break;
					case 4:
						qebul_siyahisi();
						break;
					case 5:
						satis_siyahisi();
						break;
					case 6:
						mehsul_qiymetleri();
						break;
					case 7:
						umumi_gelir();
						break;
					default: 
						cout<<endl<<"Lutfen duzgun secim ediniz: ";
						goto f;						
				}
			}			
		}		
int main(int argc, char** argv) {
	double ar_kg, bug_kg, ar_qiy, bug_qiy, kas;
	cout<<"-------------- Proqrama ilkin verilenleri daxil edin ---------------"<<endl;
	cout<<"\t\tKASSADAKI ILKIN MEBLEGI: "; cin>>kas;
	cout<<"\t\tANBARDAKI ARPA MIQDARINI DAXIL ET: "; cin>>ar_kg;
	cout<<"\t\tARPANIN GUNLUK ALIS QIYMETI (1 kg): "; cin>>ar_qiy;
	cout<<"\t\tARPANIN GUNLUK SATIS QIYMETI (10% qazanc ile): "<<ar_qiy + (ar_qiy * 0.1)<<endl;
	cout<<"\t\tANBARDAKI BUGDA MIQDARINI DAXIL ET: "; cin>>bug_kg;
	cout<<"\t\tBUGDANIN GUNLUK ALIS QIYMETI (1 kg): "; cin>>bug_qiy;
	cout<<"\t\tBUGDANIN GUNLUK SATIS QIYMETI (10% qazanc ile): "<<bug_qiy + (bug_qiy * 0.1)<<endl;
	system("pause");
	anbar test(ar_kg, bug_kg, ar_qiy, bug_qiy, kas);
	return 0;
}
