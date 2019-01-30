#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cmath>
#include<time.h>
#include<windows.h>
#include<cstring>
#include<ctime>


using namespace std;

// Definiujemy struktury, które póŸniej u¿yjemy podczas rozgrywki do zapisywania roznych danych.

struct CenaBazowa
{
	float pieprz;
	float gozdzik;
	float cynamon;
	float szafran;
	
};


struct Gracz
{	
	char nazwa[15];
	bool malyplecak;
	bool duzyplecak;
	bool samochod;
	bool bilet;
	int pieprz;
	int gozdzik;
	int cynamon;
	int szafran;
	float coins;
	char lokalizacja[15];
	int lokal;
	int tura;
	
};


struct Miasto
{
	char nazwa[15];
	float pieprz;
	float gozdzik;
	float cynamon;
	float szafran;
	int ilosc_miast;
};


// Funkcja inicjalizujaca ceny towarow w miastach oraz poczatkowe ceny bazowe.

void Inicjalizator(Miasto TM[],CenaBazowa &CB)
{
	strcpy(TM[0].nazwa,"Winterfell");
	TM[0].pieprz=CB.pieprz*0.2;
	TM[0].gozdzik=CB.gozdzik*0.15;
	TM[0].cynamon=CB.cynamon*0.05;
	TM[0].szafran=CB.szafran*0.15;
	TM[0].ilosc_miast=6;
	
	strcpy(TM[1].nazwa,"Bravos");
	TM[1].pieprz=CB.pieprz*0.05;
	TM[1].gozdzik=CB.gozdzik*0.2;
	TM[1].cynamon=CB.cynamon*0.15;
	TM[1].szafran=CB.szafran*0.1;
	TM[1].ilosc_miast=6;
	
	strcpy(TM[2].nazwa,"Lannisport");
	TM[2].pieprz=CB.pieprz*0.15;
	TM[2].gozdzik=CB.gozdzik*0.05;
	TM[2].cynamon=CB.cynamon*0.1;
	TM[2].szafran=CB.szafran*0.1;
	TM[2].ilosc_miast=6;
	
	strcpy(TM[3].nazwa,"Dragonstone");
	TM[3].pieprz=CB.pieprz*0.2;
	TM[3].gozdzik=CB.gozdzik*0.2;
	TM[3].cynamon=CB.cynamon*0.1;
	TM[3].szafran=CB.szafran*0.15;
	TM[3].ilosc_miast=6;
	
	strcpy(TM[4].nazwa,"Volantis");
	TM[4].pieprz=CB.pieprz*0.05;
	TM[4].gozdzik=CB.gozdzik*0.15;
	TM[4].cynamon=CB.cynamon*0.05;
	TM[4].szafran=CB.szafran*0.30;
	TM[4].ilosc_miast=6;
	
	strcpy(TM[5].nazwa,"Valyria");
	TM[5].pieprz=CB.pieprz*0.1;
	TM[5].gozdzik=CB.gozdzik*0.2;
	TM[5].cynamon=CB.cynamon*0.05;
	TM[5].szafran=CB.szafran*0.15;
	TM[5].ilosc_miast=6;

}


// Inicjalizator pocz¹tkowego stanu gracza.

void InicjalizatorGracza(Gracz &player, Miasto TM[])
{
	player.coins=100;
	player.cynamon=0;
	player.pieprz=0;
	player.szafran=0;
	player.gozdzik=0;
	player.malyplecak=true;
	player.duzyplecak=false;
	player.samochod=false;
	player.bilet=false;
	strcpy(player.lokalizacja,TM[0].nazwa);
	player.lokal=0;
	player.tura=1;
}



void mainMENU(Gracz &player, Miasto TM[]);


//Spontaniczna animacja...

void MW()
{
	system("cls");
	for(int i=0;i<1;i++)
	{
		cout<<"MMMMMMMMMMMMMMMM"<<endl;
		cout<<"~~~~~~~~~~~~~~~~"<<endl;
		cout<<"WWWWWWWWWWWWWWWW"<<endl<<endl;
		Sleep(50);
		cout<<"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout<<"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"<<endl<<endl;
		Sleep(50);
		cout<<"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout<<"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"<<endl<<endl;
		Sleep(50);
		cout<<"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout<<"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"<<endl<<endl;
		Sleep(50);
		cout<<"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout<<"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"<<endl<<endl;
		Sleep(50);
		cout<<"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout<<"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"<<endl<<endl;
		Sleep(50);
		cout<<"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout<<"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"<<endl<<endl;
		Sleep(50);
		cout<<"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout<<"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"<<endl<<endl;
		Sleep(50);
		cout<<"MMMMMMMMMMMMMMMM"<<endl;
		cout<<"~~~~~~~~~~~~~~~~"<<endl;
		cout<<"WWWWWWWWWWWWWWWW"<<endl<<endl;
		
	}
	system("cls");
}

// Rysowanie tabeli cen w miastach.

void piszStanMiasta(Miasto TM[])
{
	cout<<"     Miasto    |  pieprz  |  gozdziki  |  cynamon  |  szafran  | "<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;
	for(int i=0;i<(TM[0].ilosc_miast);i++)
	{
	
		cout<<setw(15)<<TM[i].nazwa<<"|"
			<<setw(10)<<TM[i].pieprz<<"|"
			<<setw(12)<<TM[i].gozdzik<<"|"
			<<setw(11)<<TM[i].cynamon<<"|"
			<<setw(11)<<TM[i].szafran<<"|"<<endl;
			cout<<"-----------------------------------------------------------------"<<endl;
	}
	cout<<"W tabeli podano cene za jednostke."<<endl;
}


// Funkcja zwracaj¹ca pojemnoœæ ekwipunku gracza.

int MaxPoj(Gracz player)
{
	if(player.malyplecak && player.duzyplecak && player.samochod) return 140;
	if(player.malyplecak && player.duzyplecak) return 40;
	if(player.malyplecak && player.samochod) return 110;
	if(player.malyplecak) return 10;
}


//Funkcja zwracaj¹ca czesc zajetego ekwipunku.

int SumaEkwipunku(Gracz player)
{
return (player.pieprz + player.gozdzik + player.cynamon + player.szafran);
}


//Funkcja wypisujaca aktualny stan gracza

void piszStanGracza(Gracz player)
{	
	cout<<endl;
	cout<<"Dzien "<<player.tura<<endl;
	cout<<player.nazwa<<endl;
	cout<<"Wartosc portfela: "<<player.coins<<" sztuk srebra."<<endl;
	cout<<"Lokalizacja: "<<player.lokalizacja<<endl<<endl;
	cout<<"Posiadane przyprawy: "<<endl;
	cout<<"pieprz: "<<player.pieprz<<" szt."<<endl;
	cout<<"gozdziki: "<<player.gozdzik<<" szt."<<endl;
	cout<<"cynamon: "<<player.cynamon<<" szt."<<endl;
	cout<<"szafran: "<<player.szafran<<" szt."<<endl;
	cout<<"Razem: "<<SumaEkwipunku(player)<<"/"<<MaxPoj(player)<<" szt."<<endl<<endl;
	cout<<"Wyposazenie: "<<endl;
	if(player.duzyplecak)cout<<"Duzy plecak"<<endl;
	if(player.samochod)cout<<"Samochod"<<endl;
	if(player.malyplecak)cout<<"Maly plecak"<<endl;
	if(player.bilet)cout<<"Bilet miesieczny"<<endl;
	cout<<endl<<endl;
	
}

// Funkcja wypisujaca ogolne zasady gry, ktore opcjonalnie wyswietla sie przed pocz¹tkiem rozgrywki.

void Zasady()
{
	cout<<"Celem gry jest uzbieranie 10 000 srebrnych monet w jak najmniejszej liczbie tur handlujac roznego rodzaju przyprawami.\n"
	<<"W kazdym miescie obowiazuja inne ceny przypraw.\n"
	<<"Podroz do innego miasta oznacza koniec tury oraz kosztuje 4 srebrne monety.\n"
	<<"Istnieje mozliwosc kupienia dodatkowego wyposazenia minimalizujacego koszty podrozy. \n"
	<<"Na poczatku gracz dysponuje 10 miejscami w ekwipunku, ktory mozna rozszerzyc kupujac dodatkowe wyposazenie.\n"
	<<"Istnieje szansa na zjawisko losowe miedzy turami: Wzrost lub spadek ceny towarow w danym miescie o 50% \n"
	<<"Mozesz takze zagrac w loterii, zasady w trakcie rozgrywki wyjasni Ci Hazardowiec.\n";
	
	cout<<endl<<endl;
	system("pause");
	
}

// Funkcja do kupowania przypraw

void sklepKup(Gracz &player, Miasto TM[])
{
	int w, ile;
	cout<<"Jaka przyprawe chcesz kupic?"<<endl;
	cout<<"1. Pieprz"<<endl;
	cout<<"2. Gozdziki"<<endl;
	cout<<"3. Cynamon"<<endl;
	cout<<"4. Szafran"<<endl;
	cout<<"5. Cofnij"<<endl;
	cin>>w;
	cout<<endl;
	if(w<5)
	{
		cout<<"Ile sztuk? ";cin>>ile;
	}
	
	switch	(w)
	{
		case 1:
			if((SumaEkwipunku(player)+ile)>MaxPoj(player))     // Sprawdzenie czy mamy miejsce w ekwipunku
			{
				cout<<"Przekroczono maksymalna pojemnosc ekwipunku. Cofam do wyboru przyprawy"<<endl;
				Sleep(3000);
				MW();
				piszStanMiasta(TM);
				piszStanGracza(player);
				sklepKup(player, TM);
			}
				else if((player.coins) < ile*TM[player.lokal].pieprz)   //Sprawdzanie czy mamy dosc srebrnych monet
					 {
					 	cout<<"Za malo sztuk srebra. Cofam do wyboru przyprawy"<<endl;
					 	Sleep(3000);
						MW();
						piszStanMiasta(TM);
						piszStanGracza(player);
						sklepKup(player, TM);
					 }
						else 
						{
							player.pieprz+=ile;
							player.coins=player.coins-(ile*TM[player.lokal].pieprz);
							cout<<"Zakonczono sukcesem!"<<endl;
							Sleep(2000);
							
						}	
			MW();
			break;
			   	
		case 2: 
			if((SumaEkwipunku(player)+ile)>MaxPoj(player))
			{
				cout<<"Przekroczono maksymalna pojemnosc ekwipunku. Cofam do wyboru przyprawy"<<endl;
				Sleep(3000);
				MW();
				piszStanMiasta(TM);
				piszStanGracza(player);
				sklepKup(player, TM);
			}
				else if((player.coins) < ile*TM[player.lokal].gozdzik)
					 {
					 	cout<<"Za malo sztuk srebra. Cofam do wyboru przyprawy"<<endl;
					 	Sleep(3000);
						MW();
						piszStanMiasta(TM);
						piszStanGracza(player);
						sklepKup(player, TM);
					 }
						else 
						{
							player.gozdzik+=ile;
							player.coins=player.coins-(ile*TM[player.lokal].gozdzik);
							cout<<"Zakonczono sukcesem!"<<endl;
							Sleep(2000);
							
						}				
			MW();
			break;
			   	
		case 3:
			if((SumaEkwipunku(player)+ile)>MaxPoj(player))
			{
				cout<<"Przekroczono maksymalna pojemnosc ekwipunku. Cofam do wyboru przyprawy"<<endl;
				Sleep(3000);
				MW();
				piszStanMiasta(TM);
				piszStanGracza(player);
				sklepKup(player, TM);
			}
				else if((player.coins) < ile*TM[player.lokal].cynamon)
					 {
					 	cout<<"Za malo sztuk srebra. Cofam do wyboru przyprawy"<<endl;
					 	Sleep(3000);
						MW();
						piszStanMiasta(TM);
						piszStanGracza(player);
						sklepKup(player, TM);
					 }
						else 
						{
							player.cynamon+=ile;
							player.coins=player.coins-(ile*TM[player.lokal].cynamon);
							cout<<"Zakonczono sukcesem!"<<endl;
							Sleep(2000);
							
						}				
		    MW();
			break;
			   	
		case 4: 
			if((SumaEkwipunku(player)+ile)>MaxPoj(player))
			{
				cout<<"Przekroczono maksymalna pojemnosc ekwipunku. Cofam do wyboru przyprawy"<<endl;
				Sleep(3000);
				MW();
				piszStanMiasta(TM);
				piszStanGracza(player);
				sklepKup(player, TM);
			}
				else if((player.coins) < ile*TM[player.lokal].szafran)
					 {
					 	cout<<"Za malo sztuk srebra. Cofam do wyboru przyprawy"<<endl;
						Sleep(3000);
						MW();
						piszStanMiasta(TM);
						piszStanGracza(player);
						sklepKup(player, TM);
					 }
						else 
						{
							player.szafran+=ile;
							player.coins=player.coins-(ile*TM[player.lokal].szafran);
							cout<<"Zakonczono sukcesem!"<<endl;
							Sleep(2000);
							
						}				
			MW();
			break;
			   	
		default: ; break;
		
		
	}

}

//Funkcja do sprzedawania przypraw.

void sklepSprzedaj(Gracz &player, Miasto TM[])
{
	int w, ile;
	cout<<"Jaka przyprawe chcesz sprzedac?"<<endl;
	cout<<"1. Pieprz"<<endl;
	cout<<"2. Gozdziki"<<endl;
	cout<<"3. Cynamon"<<endl;
	cout<<"4. Szafran"<<endl;
	cout<<"5. Cofnij"<<endl;
	cin>>w;
	cout<<endl;
	if(w<5)
	{
		cout<<"Ile sztuk? ";cin>>ile;
	}
	
	switch	(w)
	{
		case 1:
			if((player.pieprz-ile)<0)   // Sprawdzanie czy mamy tyle sztuk przeprawy, ktora chcemy sprzedaæ
			{
				cout<<"Nie masz tylu sztuk tej przyprawy. Cofam do wyboru przyprawy."<<endl;
				Sleep(3000);
				MW();
				piszStanMiasta(TM);
				piszStanGracza(player);
				sklepSprzedaj(player, TM);
			}
				else 
				{
					player.pieprz-=ile;
					player.coins=player.coins+(ile*TM[player.lokal].pieprz);
					cout<<"Zakonczono sukcesem!"<<endl;
					Sleep(2000);
					MW();
							
				}	
			break;
			   	
		case 2: 
			if((player.gozdzik-ile)<0)
			{
				cout<<"Nie masz tylu sztuk tej przyprawy. Cofam do wyboru przyprawy."<<endl;
				Sleep(3000);
				MW();
				piszStanMiasta(TM);
				piszStanGracza(player);
				sklepSprzedaj(player, TM);
			}
				else 
				{
					player.gozdzik-=ile;
					player.coins=player.coins+(ile*TM[player.lokal].gozdzik);
					cout<<"Zakonczono sukcesem!"<<endl;
					Sleep(2000);
					MW();
							
				}	
			break;
			   	
		case 3:
			if((player.cynamon-ile)<0)
			{
				cout<<"Nie masz tylu sztuk tej przyprawy. Cofam do wyboru przyprawy."<<endl;
				Sleep(3000);
				MW();
				piszStanMiasta(TM);
				piszStanGracza(player);
				sklepSprzedaj(player, TM);
			}
				else 
				{
					player.cynamon-=ile;
					player.coins=player.coins+(ile*TM[player.lokal].cynamon);
					cout<<"Zakonczono sukcesem!"<<endl;
					Sleep(2000);
					MW();
							
				}	
			break;
			   	
		case 4: 
			if((player.szafran-ile)<0)
			{
				cout<<"Nie masz tylu sztuk tej przyprawy. Cofam do wyboru przyprawy."<<endl;
				Sleep(3000);
				MW();
				piszStanMiasta(TM);
				piszStanGracza(player);
				sklepSprzedaj(player, TM);
			}
				else 
				{
					player.szafran-=ile;
					player.coins=player.coins+(ile*TM[player.lokal].szafran);
					cout<<"Zakonczono sukcesem!"<<endl;
					Sleep(2000);
					MW();
							
				}	
			break;
			   	
		default: ; break;
		
		
	}

}

// Funkcja do zjawisk losowych. Stwierdzi³em, ¿e lepiej bêdzie jeœli raz zmieniona cena bazowa nie wraca³a do normy po turze. 
// Aby wraca³a po turze powinnismy te funkcje odpowiednio przerobiæ i wrzucic w funkcje "Inicjaliztor"
// Zwiekszylem szanse na zjawisko losowe w celu urozmaicenia rozgrywki normalnie byloby losowa=rand()%10+1

void ZjawiskaLosowe(CenaBazowa &Bazowa, Miasto TM[])
{
	int losowa=rand()%6+1;    // do losowania CZY wystapi zjawisko
	int losowaprzyprawa=rand()%4; // jesli wystapi to jaka przyprawa?
	
	if(losowa==1)
	{
		system("cls");
		cout<<"-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o"<<endl<<endl;
		cout<< "UWAGA! Statek transportowy zatonal!"<<endl;
		cout<<"Statek byl po burty zaladowany ";
		if(losowaprzyprawa==0)
		  {
		   cout<<"pieprzem!";
		   Bazowa.pieprz=1.5*Bazowa.pieprz;
	      }
		else if(losowaprzyprawa==1)
				{
				 cout<<"gozdzikami!";
		   		 Bazowa.gozdzik=1.5*Bazowa.gozdzik;
				}
			 else if(losowaprzyprawa==2)
				   	 {
					  cout<<"cynammonem!";
					  Bazowa.cynamon=1.5*Bazowa.cynamon;
					 }		
				  else 
					 {
					  cout<<"szafranem!";
					  Bazowa.szafran=1.5*Bazowa.szafran;
					 }
		cout<<endl<<"Od nastepnej tury cena bazowa tej przyprawy rosnie o 50%!"<<endl<<endl;
		cout<<"-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o"<<endl;
		system("pause");
		MW();
	}
	
	if(losowa==2)
	{
		system("cls");
		cout<<"-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o"<<endl<<endl;
		cout<< "UWAGA! NADPRODUKCJA PRZYPRAWY!"<<endl;
		cout<<"Nadprodukacja wystapila na farmie z ";
		if(losowaprzyprawa==0)
		  {
		   cout<<"pieprzem!";
		   Bazowa.pieprz=0.5*Bazowa.pieprz;
	      }
		else if(losowaprzyprawa==1)
				{
				 cout<<"gozdzikami!";
		   		 Bazowa.gozdzik=0.5*Bazowa.gozdzik;
				}
			 else if(losowaprzyprawa==2)
				   	 {
					  cout<<"cynammonem!";
					  Bazowa.cynamon=0.5*Bazowa.cynamon;
					 }		
				  else 
					 {
					  cout<<"szafranem!";
					  Bazowa.szafran=0.5*Bazowa.szafran;
					 }
		cout<<endl<<"Od nastepnej tury cena bazowa tej przyprawy maleje o 50%!"<<endl<<endl;
		cout<<"-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o"<<endl;
		system("pause");
		MW();
	}
	
	Inicjalizator(TM,Bazowa);   // Inicjalizujemy nowe Ceny w miastach.
	
}

// Funkcja do zmiany miasta, w którym jesteœmy

int ZmianaMiasta(Gracz &player, Miasto TM[],CenaBazowa &Bazowa)
{
	
	if(player.coins<4&&player.bilet&&player.samochod)     // Jesli nie mamy samochodu/biletu to czy mamy 4 monety na przejazd?
	{
	cout<<"Brakuje Ci pieniedzy na przejazd. (Potrzebujesz 4 sztuk srebra)"<<endl;
	Sleep(4000);
	MW();
	return 0;	
	}
	
	int q,z;
	cout<<"Gdzie chcesz podrozowac?"<<endl;      
	for(int i=0; i<TM[0].ilosc_miast;i++)
	{
		cout<<i+1<<". "<<TM[i].nazwa<<endl;
		if(i==TM[0].ilosc_miast-1)
			cout<<i+2<<". Wroc"<<endl<<endl;
	}
	
	cin>>q;
	z=player.lokal;     // zapisujemy w zmiennej  index tablicy miasta w ktorym jestesmy. Jesli jest taki sam jak ten gdzie chcemy sie udac to wyswietla odpowiedni komunikat.
	
	switch (q)
	{
		case 1: 	
			player.lokal=0;
			if(player.lokal==z)
				{
				 cout<<"Jestes juz w tym miescie... Cofam do MENU Glownego."<<endl;
				 Sleep(4000);
				 MW();
				 break;
				 
			    }
			else
				strcpy(player.lokalizacja, TM[player.lokal].nazwa);
				player.tura++;
				if(player.samochod||player.bilet)
				{
					cout<<"Posiadasz samochod lub bilet miesieczny, wiec nie placisz za przejazd.\n Zapada zmrok... Kiedy dojedziesz bedzie juz nowy dzien"<<endl;
					Sleep(9000);
					MW();
				}
				else
				{
					cout<<" Nie posiadasz samochodu ani biletu miesiecznego, wiec placisz za przejazd 4 sztuki srebra.\n Zapada zmrok... Kiedy dojedziesz bedzie juz nowy dzien"<<endl;
					player.coins-=4;
					Sleep(9000);
					MW();
				}	
		
			break;
			
		case 2: 	
			player.lokal=1;
			if(player.lokal==z)
				{
				 cout<<"Jestes juz w tym miescie... Cofam do MENU Glownego."<<endl;
				 Sleep(4000);
				 MW();
				 break;
				 
			    }
			else
				strcpy(player.lokalizacja, TM[player.lokal].nazwa);
				player.tura++;
				if(player.samochod||player.bilet)
				{
					cout<<"Posiadasz samochod lub bilet miesieczny, wiec nie placisz za przejazd.\n Zapada zmrok... Kiedy dojedziesz bedzie juz nowy dzien"<<endl;
					Sleep(9000);
					MW();
				}
				else
				{
					cout<<" Nie posiadasz samochodu ani biletu miesiecznego, wiec placisz za przejazd 4 sztuki srebra.\n Zapada zmrok... Kiedy dojedziesz bedzie juz nowy dzien"<<endl;
					player.coins-=4;
					Sleep(9000);
					MW();
				}	
		
			break;
		
		case 3: 	
			player.lokal=2;
			if(player.lokal==z)
				{
				 cout<<"Jestes juz w tym miescie... Cofam do MENU Glownego."<<endl;
				 Sleep(4000);
				 MW();
				 break;
				 
			    }
			else
				strcpy(player.lokalizacja, TM[player.lokal].nazwa);
				player.tura++;
				if(player.samochod||player.bilet)
				{
					cout<<"Posiadasz samochod lub bilet miesieczny, wiec nie placisz za przejazd.\n Zapada zmrok... Kiedy dojedziesz bedzie juz nowy dzien"<<endl;
					Sleep(9000);
					MW();
				}
				else
				{
					cout<<" Nie posiadasz samochodu ani biletu miesiecznego, wiec placisz za przejazd 4 sztuki srebra.\n Zapada zmrok... Kiedy dojedziesz bedzie juz nowy dzien"<<endl;
					player.coins-=4;
					Sleep(9000);
					MW();
				}	
		
			break;
			
		case 4: 	
			player.lokal=3;
			if(player.lokal==z)
				{
				 cout<<"Jestes juz w tym miescie... Cofam do MENU Glownego."<<endl;
				 Sleep(4000);
				 MW();
				 break;
				 
			    }
			else
				strcpy(player.lokalizacja, TM[player.lokal].nazwa);
				player.tura++;
				if(player.samochod||player.bilet)
				{
					cout<<"Posiadasz samochod lub bilet miesieczny, wiec nie placisz za przejazd.\n Zapada zmrok... Kiedy dojedziesz bedzie juz nowy dzien"<<endl;
					Sleep(9000);
					MW();
				}
				else
				{
					cout<<" Nie posiadasz samochodu ani biletu miesiecznego, wiec placisz za przejazd 4 sztuki srebra.\n Zapada zmrok... Kiedy dojedziesz bedzie juz nowy dzien"<<endl;
					player.coins-=4;
					Sleep(9000);
					MW();
				}	
		
			break;
			
		case 5: 	
			player.lokal=4;
			if(player.lokal==z)
				{
				 cout<<"Jestes juz w tym miescie... Cofam do MENU Glownego."<<endl;
				 Sleep(4000);
				 MW();
				 break;
				 
			    }
			else
				strcpy(player.lokalizacja, TM[player.lokal].nazwa);
				player.tura++;
				if(player.samochod||player.bilet)
				{
					cout<<"Posiadasz samochod lub bilet miesieczny, wiec nie placisz za przejazd.\n Zapada zmrok... Kiedy dojedziesz bedzie juz nowy dzien"<<endl;
					Sleep(9000);
					MW();
				}
				else
				{
					cout<<" Nie posiadasz samochodu ani biletu miesiecznego, wiec placisz za przejazd 4 sztuki srebra.\n Zapada zmrok... Kiedy dojedziesz bedzie juz nowy dzien"<<endl;
					player.coins-=4;
					Sleep(9000);
					MW();
				}	
		
			break;
			
		case 6: 	
			player.lokal=5;
			if(player.lokal==z)
				{
				 cout<<"Jestes juz w tym miescie... Cofam do MENU Glownego."<<endl;
				 Sleep(4000);
				 MW();
				 break;
				 
			    }
			else
				strcpy(player.lokalizacja, TM[player.lokal].nazwa);
				player.tura++;
				if(player.samochod||player.bilet)
				{
					cout<<"Posiadasz samochod lub bilet miesieczny, wiec nie placisz za przejazd.\n Zapada zmrok... Kiedy dojedziesz bedzie juz nowy dzien"<<endl;
					Sleep(9000);
					MW();
				}
				else
				{
					cout<<" Nie posiadasz samochodu ani biletu miesiecznego, wiec placisz za przejazd 4 sztuki srebra.\n Zapada zmrok... Kiedy dojedziesz bedzie juz nowy dzien"<<endl;
					player.coins-=4;
					Sleep(9000);
					MW();
				}	
		
			break;			
	}
	ZjawiskaLosowe(Bazowa,TM);
	
return 0;	
}



void Koniectury(Gracz &player, CenaBazowa &Bazowa, Miasto TM[])   // Funkcja w ktorej konczysz ture zostajac w tym samym miescie( Kiedy liczysz bardzo na Zjawisko losowe...)
{
	int q;
	cout<<"Jestes pewien, ze zostajesz tu na noc?"<<endl;
	cout<<"1. TAK"<<endl;
	cout<<"2. NIE"<<endl;
	cin>>q;
	
	if(q==1)
	{
	 cout<<"Zapada zmrok...Gdy sie obudzisz bedzie juz nowy dzien...";
	 player.tura++;
     Sleep(7000);
     ZjawiskaLosowe(Bazowa, TM);
     MW();
	}
	else MW();
}



void sklepWyposazenie(Gracz &player, Miasto TM[])  // Kupowanie dodatkowego ekwipunku.
{
	int q;
	cout<<"Dostepne przedmioty ktorych jeszcze nie masz:                            cena(sztuk srebra)"<<endl;
	if(player.bilet)cout<<"1. ZAKUPIONO"<<endl;
	else cout<<"1. Bilet miesieczny (darmowe przejazdy)                                         100 "<<endl;
	if(player.duzyplecak)cout<<"2. ZAKUPIONO"<<endl;
	else cout<<"2. Duzy plecak (dodatkowe 30 miejsc w ekwipunku)                                200 "<<endl;
	if(player.samochod)cout<<"3. ZAKUPIONO"<<endl;
	else cout<<"3. Samochod ( darmowe przejazdy + dodatkowe 100 miejsc w ekwipunku)             2000"<<endl;
	cout<<"4. Wyjscie"<<endl;
	
	cout<<endl<<endl;
	cin>>q;
	
	switch(q)
	{
		case 1: 
			if(player.bilet)cout<<"Juz masz bilet miesieczny"<<endl;
			else
				if( player.coins>=100)
				{
					player.bilet=1;
					player.coins-=100;
					cout<<"Zakupiono bilet!"<<endl;	
				}
				else cout<<"Za malo srebrnych monet!"<<endl;
			Sleep(3000);
			break;	
			
		case 2: 
			if(player.duzyplecak)cout<<"Juz masz Duzy plecak"<<endl;
			else
				if( player.coins>=200)
				{
					player.duzyplecak=1;
					player.coins-=200;
					cout<<"Zakupiono Duzy plecak!"<<endl;		
				}
				else cout<<"Za malo srebrnych monet!"<<endl;
			Sleep(3000);	
			break;	
		
		case 3: 
			if(player.samochod)cout<<"Juz masz samochod"<<endl;
			else
				if( player.coins>=2000)
				{
					player.samochod=1;
					player.coins-=2000;
					cout<<"Zakupiono samochod!"<<endl;
					
				}
				else cout<<"Za malo srebrnych monet!"<<endl;
			Sleep(3000);	
			break;	
			
		default:break;			
	}
	
}

//Funkcja loterii

void Loteria(Gracz &player)
{
	MW();
	system("cls");
	piszStanGracza(player);
	cout<<endl;
	cout<<"Stary Hazardowiec schowal kamien pod jednym z kubkow ponumerowanych od 1 do 5"<<endl;
	cout<<"Zaraz po ostatecznej decyzji Twoim zadaniem bedzie podanie ktory kubek wybierasz"<<endl;
	cout<<"Jeœli trafisz w kubek pod ktorym jest kamyk to ilosc postawionego srebra powiekszy sie PIECIOKROTNIE."<<endl;
	cout<<"W przeciwnym razie srebro przepadnie"<<endl;
	cout<<endl<<"Czy na pewno chcesz zagrac?"<<endl;
	cout<<"1. TAK!"<<endl;
	cout<<"2. Rezygnuje"<<endl;
	int q;
	cin>>q;	
	switch (q)
	{
		case 1 : 
			cout<<"Widze zes odwazny! Ile sztuk srebra chcesz postawic smialku?"<<endl<<endl<<endl; 
			int w;
			cin>>w;
			if(player.coins<w)
			{
				cout<<"Oszust! Oszust! Nie masz tyle srebra chcesz wyrolowac Staruszka!!! Precz!"<<endl<<endl<<endl;  // Jesli nie masz tylu sztuk srebra ile chcesz postawic Hazardowiec przepedzi Cie.
				Sleep(4000);
				break;	
			}	
			else
			{
				player.coins-=w;
				
				cout<<"Dobrze wiec Mlodziencze wybierz kubek."<<endl<<endl;
				cout<<"_________   _________   _________   _________   _________"<<endl;
				cout<<"|       |   |       |   |       |   |       |   |       |"<<endl;
				cout<<"|       |   |       |   |       |   |       |   |       |"<<endl;
				cout<<"|   1   |   |   2   |   |   3   |   |   4   |   |   5   |"<<endl;
				cout<<"|       |   |       |   |       |   |       |   |       |"<<endl;
				cout<<"|       |   |       |   |       |   |       |   |       |"<<endl;
				
				int q;
				cin>> q;
				if(q==rand()%5+1)   // Jesli podasz liczbe od 1 do 5 to masz 1/5 szans ze trafisz w odpowiedni kubek- odzyskasz pieciokrotnosc postawionej sumy
				{                   //Jesli nie trafisz lub podasz liczbe spoza przedzialu to postawione srebro przepada
					player.coins+=w*5;
					cout<<"Szczescie Ci sprzyja oto Twoje srebro. Zegnaj Handlarzu!"<<endl;
					cout<<"Wygrales "<<w*4<<" sztuk srebra!"<<endl;
					Sleep(4000);
				}
				else
				{
					cout<<"Haha! latwe pieniadze zarobione na nie roztropnym czlowieku!\nMoze nastepnym razem bedziesz mial wiecej szczescia! Zegnaj Handlarzu. "<<endl;
					cout<<"Straciles "<<w<<" sztuk/i srebra";
					Sleep(4000);
				}
				
			}
		
		default: break;
	}
}



void mainMENU(Gracz &player, Miasto TM[], CenaBazowa &Bazowa)
{	
	
	int w;
	cout<<"Mozliwe akcje:"<<endl;
	cout<<"1. Zakup przyprawy."<<endl;
	cout<<"2. Sprzedaj przyprawy."<<endl;
	cout<<"3. Zakup dodatkowe wyposazenie."<<endl;
	cout<<"4. Zagraj w Loterii"<<endl;
	cout<<"5. Zmien otoczenie(Nastepna ture rozpoczniesz w wybranym miescie)"<<endl;
	cout<<"6. Nocuj w miescie (Zakoncz ture bez zmiany lokalizacji)"<<endl;
	cout<<"7. Poddaj sie"<<endl;
	cin>>w;
	switch(w) 
	{
		case 1 : sklepKup(player, TM);break;
		case 2 : sklepSprzedaj(player, TM);break;
		case 3 : sklepWyposazenie(player, TM);break;
		case 4 : Loteria(player);break;
		case 5 : ZmianaMiasta(player, TM, Bazowa);break;
    	case 6 : Koniectury(player, Bazowa, TM);break;
    	case 7 : 
    		cout<<"Jestes pewien?"<<endl;
    		cout<<"1. Tak"<<endl;
    		cout<<"2. Wroc do gry"<<endl;
    		int a;
			cin>>a;
			if(a==1)exit(0);
		
	}
}


// Wyswietla menu zaraz po wlaczeniu programu. Mozemy wyswietlic zasady lub rozpocz¹c rozgrywke pomijaj¹c wyswietlanie zasad.

void poczatkoweMENU()
{
	
	int wybor;
	
	cout<<"Witaj w grze!"<<endl;
	cout<<"Prosze o gre w trybie pelnoekranowym, aby wszystkie elementy miescily sie."<<endl;
	cout<<"1. Zasady gry."<<endl;
	cout<<"2. Nowa gra."<<endl;
	cout<<">";
	
	cin>>wybor;
	system("cls");
	switch(wybor)
	{
	
	case 1 : Zasady(); break;
	case 2 : break;
	
	}
	system("cls");
	 
}

// Funkcja do okreslania poziomu trudnosci gry. Ustalamy niektore wartosci stuktury gracza przed poczatkiem rozgrywki.

void Poziom(Gracz &player)
{
	cout<<"Wybierz poziom trudnosci: "<<endl;
	cout<<"1. Latwy     (na start 200 sztuk srebra oraz duzy plecak)"<<endl;
	cout<<"2. Sredni    (na start 150 sztuk srebra)"<<endl;
	cout<<"3. Trudny    (na start 60 sztuk srebra)"<<endl;
	int q;
	cin>>q;
	
	switch (q)
	{
		case 1 : 
			player.coins=200;
			player.duzyplecak=1;
			cout<<"Wybrano Latwy!"<<endl;
			Sleep(3000);
			break;
		
		case 2 :
			player.coins=150;
			cout<<"Wybrano Sredni!"<<endl;
			Sleep(3000);
			break;
			
		case 3 :
			player.coins=60;
			cout<<"wybrano Trudny!"<<endl;
			Sleep(3000);
			break;
			
		default : 
			cout<<"Niepoprawne dane, sprobuj jeszcze raz."<<endl;
			Poziom(player);
			break;
			
			MW();		
	}

}



int main(){
	
	int ilosc_miast=6;
	Gracz player;
	Miasto TM[ilosc_miast];
	CenaBazowa Bazowa;
	char s[15];
	srand(time(NULL));	
	
	poczatkoweMENU();
	
	
	cout<<" Podaj nazwe gracza(max 14 znakow): ";cin>>s;
	strcpy(player.nazwa,s);
	MW();
	
	Bazowa.pieprz=40;      //Inicjalizacja poczatkowych cen bazowych.
	Bazowa.gozdzik=70;
	Bazowa.cynamon=90;
	Bazowa.szafran=100;
	
	Inicjalizator(TM, Bazowa);
	InicjalizatorGracza(player, TM);
	
	Poziom(player);
	
	while(player.coins<10000){   // warunek do zwyciestwa kiedy konczysz ture posiadaj¹c 10 000 srebra wychodzi z petli i wyswietla komunikat zwyciestwa,
								// oraz liczbe tur w jakich sie tego dokona³o.
	piszStanMiasta(TM);
	piszStanGracza(player);
	mainMENU(player, TM, Bazowa);
	MW();
}

cout<<endl<<"ZWYCIESTWO! Jestes krolem handlarzy przypraw!\nUdalo Ci sie zgromadzic az 10 000 sztuk srebra w zaledwie:"<<player.tura-1<<"dni.";
	Sleep(10000);
	system("pause");
	
	return 0;
}
