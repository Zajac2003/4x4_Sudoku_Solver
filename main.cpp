#include <iostream>
#include <windows.h>
using namespace std;

//4x4
int tablica[4][4]={
    {1,0,0,0},
    {0,0,0,4},
    {0,0,0,2},
    {3,0,0,0}
};
int bufor[4]={0,0,0,0};

void wypelnianie();//Mozna samemu wpisac tablice (wszystkie cyfry)
void wypisz();//Wypisuje cala tablice (sudoku)
void seekNulls();//Wyszukuje puste komorki, dziala tylko raz
int seekHorizontally(int b){//Wyszukuje nieobecne cyfry w rzedzie b
    bufor[0]=0;
    bufor[1]=0;
    bufor[2]=0;
    bufor[3]=0;
        for(int j=0;j<4;j++)//Ustala tablice brakujacych, 0=nie ma, 1=jest
        {
            if(tablica[b][j]==1){bufor[0]=1;}
            if(tablica[b][j]==2){bufor[1]=1;}
            if(tablica[b][j]==3){bufor[2]=1;}
            if(tablica[b][j]==4){bufor[3]=1;}
        }
}
int Delete(int komorka,int cyfra){//Usuwa ze wskazanego inta jedna cyfre, np z liczby 1234&3=124

string zawartosc=to_string(komorka);
string znak=to_string(cyfra);
size_t pozycja=zawartosc.find(znak);

if(komorka==cyfra)
{
    return atoi(zawartosc.c_str());
}

if(pozycja==4294967295)
{
    return atoi(zawartosc.c_str());
}
zawartosc=zawartosc.erase(pozycja,1);
return atoi(zawartosc.c_str());
}
void deleteHorizontally(int rzad){//Usuwa obecne cyfry w buforze poziomo z tablicy (obecna=1)
    for(int k=0;k<4;k++)
    {
        if(bufor[k]==1)
        {
            for(int j=0;j<4;j++)
            {
                if(tablica[rzad][j]!=bufor[k])
                {
                    tablica[rzad][j]=Delete(tablica[rzad][j],k+1);
                }
            }
        }
    }

}
void Seek_n_Delete_H(int rzad){//seekHorizontally & deleteHorizontally
seekHorizontally(rzad);
deleteHorizontally(rzad);
}
void Seek_Upright(int rzad){

    bufor[0]=0;
    bufor[1]=0;
    bufor[2]=0;
    bufor[3]=0;

    for(int i=0;i<4;i++)
    {
            if(tablica[i][rzad]==1){bufor[0]=1;}
            if(tablica[i][rzad]==2){bufor[1]=1;}
            if(tablica[i][rzad]==3){bufor[2]=1;}
            if(tablica[i][rzad]==4){bufor[3]=1;}
    }
}
int Delete_Upright(int kolumna){
    for(int i=0;i<4;i++)
    {
        if(bufor[i]==1)
            {
            for(int a=0;a<4;a++)
                {
                    tablica[a][kolumna]=Delete(tablica[a][kolumna],i+1);
                }

            }
    }

}
void Seek_n_Delete_U(int kolumna){
    Seek_Upright(kolumna);
    Delete_Upright(kolumna);
}
void Seek_Quarter(int quart){

    bufor[0]=0;
    bufor[1]=0;
    bufor[2]=0;
    bufor[3]=0;

    int i=0;int j=0;
    switch(quart)
    {
        case 2:     j+=2;
                    break;

        case 3:     i+=2;
                    break;

        case 4:     i+=2;j+=2;
                    break;
    }
        quart--;

    for(int k=0;k<4;k++)
    {
        if(tablica[i][j]==k+1)
            {
            bufor[k]=1;
            }

        if(tablica[i][j+1]==k+1)
            {
            bufor[k]=1;
            }

        if(tablica[i+1][j]==k+1)
            {
            bufor[k]=1;
            }

        if(tablica[i+1][j+1]==k+1)
            {
            bufor[k]=1;
            }

    }
}
void Delete_Quarter(int quart){
    int i=0;int j=0;
    switch(quart)
    {
        case 2:     j+=2;
                    break;

        case 3:     i+=2;
                    break;

        case 4:     i+=2;j+=2;
                    break;
    }
        quart--;


        for(int k=0;k<4;k++)
        {
            if(bufor[k]==1)
            {

                    tablica[i][j]=Delete(tablica[i][j],k+1);
                    tablica[i][j+1]=Delete(tablica[i][j+1],k+1);
                    tablica[i+1][j]=Delete(tablica[i+1][j],k+1);
                    tablica[i+1][j+1]=Delete(tablica[i+1][j+1],k+1);
            }
        }
}


int main()
{
    wypisz();
    //wypelnianie();
    cout<<endl;
    seekNulls();
    for(int a=0;a<5;a++)
    {
            for(int b=0;b<4;b++)
            {
                Seek_n_Delete_H(b);
                Seek_n_Delete_U(b);
            }
            for(int q=1;q<5;q++)
                {
                    Seek_Quarter(q);
                    Delete_Quarter(q);
                }

    }
    wypisz();
    return 0;
}




void wypelnianie()//Mozna samemu wpisac tablice (wszystkie cyfry)
{
    cout<<"Jesli jakies pole jest puste, wpisz '0'."<<endl;
    for(int i=0, j=0;i<4;i++)
    {
            for(j=0;j<4;j++)
            {
                cin>>tablica[i][j];
            }
    }
    system("cls");
}
void wypisz()//Wypisuje cala tablice (sudoku)
{

for(int i=0,j=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<tablica[i][j]<<" ";
        }
    cout<<endl;
    }

}
void seekNulls()//Wyszukuje puste komorki i podmienia na inta "1234", dziala tylko raz
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if (tablica[i][j]==0)
            {
                tablica[i][j]=1234;
            }
        }
    }
}


