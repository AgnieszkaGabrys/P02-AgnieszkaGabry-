#include <fstream>
#include <iostream>
using namespace std;
//Tworzymy tablicê dynamiczna do której wprowadzane beda liczby calkowite do posortowania
void ujemne_na_koniec(int* tab_in, int tab_in_len)
{
    int j = 0, k = 0;
    //Tworzymy 2 pomocnicze tablice
    int* tab1= new int[tab_in_len];
    int* tab2= new int[tab_in_len];
// Warunek dla którego liczby wieksze i równe 0 maja zoatac przeniesione do tab1
    for(int i=0; i<tab_in_len; i++)
    {
        if(tab_in[i]>=0)
        {
            tab1[j]=tab_in[i];
            j++;
        }
//Ujemne liczby zosta przeniesione do tab2
        else
        {
            tab2[k]=tab_in[i];
            k++;
        }
    }
//Liczby z pomocniczych tablic zoataj¹ z powrotem przeniesione do tab_in , w odpowiedniej kolejnoœci

    for(int i=0; i<j; i++)
        tab_in[i]=tab1[i];
    for(int i=0; i<k; i++)
        tab_in[i+j]=tab2[i];

//Dla pewności usuwamy tab1 i tab2 żeby nie zajmowały niepotrzebnego miejsca
    delete[] tab1;
    delete[] tab2;
// Zapisujemy wyniki do pliku zapis liczb.txt
     for(int i=0; i<tab_in_len; i++)
    {
        fstream plik;
        plik.open("zapis liczb.txt",ios::out|ios::app);
        plik<<tab_in[i]<<" ,";
        plik.close();
    }

}
int main()
{
    int n, j = 0, k = 0;
    cout << "ile liczb wypisujemy\n";
    cin >> n;
    int* tab=new int[n];
    for(int i=0; i<n; i++)
    {
        cout << "Podaj liczbe " << i+1 << ": ";
        cin >> tab[i];
    }
    cout << endl << endl;
    ujemne_na_koniec(tab,n);
    cout << "Wpisane liczby po sortowaniu:" << endl;

    for(int i=0; i<n; i++)
    {
        cout << tab[i] << ' ';
    }

    cout << endl;

    cout<< "Liczby podane w przykladzie:"<<endl;
    int tab2[]= {-10,5,8,-4,1,3,0,-7};
    for(int i=0; i<8; i++)
    {
        cout << tab2[i] << ' ';
    }
    cout<<endl<<endl;
    ujemne_na_koniec(tab2, 8);

    for(int i=0; i<8; i++)
    {
        cout << tab2[i] << ' ';

    }

    return 0;

}
