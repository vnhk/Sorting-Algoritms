#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <fstream>


using namespace std;


void fillTableRand(int *tab, int n)
{
    for(int i = 0; i < n; ++i)
    {
        tab [i] = rand()%100;
    }
}
void fillTableM(int *tab, int n)//malejaca
{
    for(int i = n-1; i >= 0 ; --i)
        tab[i] = n-i;
}
void fillTableR(int *tab, int n)//rosnaca
{
    for(int i = 0; i < n ; ++i)
        tab[i] = i;
}

void printTable(int *tab, int n)
{
    for(int i = 0; i < n; ++i)
    {
        cout<<"Tab["<<i<<"] = "<<tab[i]<<"  ";
        if(i>0&&i%5==0)
            cout<<endl;
    }

}

int ISsort(int *tab, int n, unsigned short ch)
{
    int ilosc_zamian = 0;
    int pom,j,i;

    if(ch == 1)
    {
        for(i=1; i<n; i++)
        {
            pom=tab[i];
            j=i-1;
            while((tab[j]>pom) && (j>=0))
            {
                tab[j+1]=tab[j];
                ilosc_zamian++;
                j--;
            }
            if( tab[j+1]!=pom)
            {
                tab[j+1]=pom;
                ilosc_zamian++;
            }

        }
    }
    else
    {
        for(i=1; i<n; i++)
        {
            pom=tab[i];
            j=i-1;
            while((tab[j]<pom) && (j>=0))
            {
                tab[j+1]=tab[j];
                ilosc_zamian++;
                j--;
            }
             if( tab[j+1]!=pom)
            {
                tab[j+1]=pom;
                ilosc_zamian++;
            }
        }
    }
    return ilosc_zamian;
}
int SSsort(int *tab, int n, unsigned short ch)
{
    int pom;
    int ilosc_zamian = 0;

    if(ch==1)//ros
    {
        for( int i = 0; i < n; i++ )
        {
            pom = i;
            for( int j = i + 1; j < n; j++ )
                if( tab[ j ] < tab[ pom ] )
                    pom = j;

            if(tab[pom]!=tab[i])
            {
                 swap( tab[ pom ], tab[ i ] );
                 ilosc_zamian++;
            }
        }
    }
    else
    {
        for( int i = 0; i < n; i++ )
        {
            pom = i;
            for( int j = i + 1; j < n; j++ )
                if( tab[ j ] > tab[ pom ] )
                    pom = j;


            if(tab[pom]!=tab[i])
            {
                 swap( tab[ pom ], tab[ i ] );
                 ilosc_zamian++;
            }


        }
    }

    return 3*ilosc_zamian;

}


int SSwap(int *tab,int n, unsigned short ch)
{
    int ilosc_zamian = 0;
    int i, j, temp, k=n-1;
    bool swapbool;

    if(ch == 1)
    {
        for(i=0; i<n-1; i++)
        {
            swapbool=false;
            for(j=0; j<=k-1; j++)
            {
                if(tab[j]>tab[j+1])
                {
                    swap(tab[j], tab[j+1]);
                    ilosc_zamian++;
                    swapbool=true;
                    temp=j;
                }
            }
            k=temp;
            if(!swapbool) break;
        }
    }
    else
    {
        for(i=0; i<n-1; i++)
        {
            swapbool=false;
            for(j=0; j<=k-1; j++)
            {
                if(tab[j]<tab[j+1])
                {
                    swap(tab[j], tab[j+1]);
                    ilosc_zamian++;
                    swapbool=true;
                    temp=j;
                }
            }
            k=temp;
            if(!swapbool) break;
        }
    }

    return 3*ilosc_zamian;
}

void saveToFile(int *tab, int n, unsigned short sortdirection,unsigned short ch,unsigned short chRM,float timer,unsigned long long int ilosc_zamian)
{
    std::fstream file;
    file.open("result.txt",std::ios::app);
    if(file.good())
    {
        file<<"Sortowanie dla "<<n<<" elementow"<<endl;
        if(chRM==1)
            file<<"Wstepne wypelnienie tablicy: rosnace "<<endl;
        else if(chRM==2)
            file<<"Wstepne wypelnienie tablicy: malejace "<<endl;
        else
            file<<"Wstepne wypelnienie tablicy: losowe "<<endl;
        if(sortdirection==1)
            file<<"Sortowanie rosnaco. "<<endl;
        else
            file<<"Sortowanie malejaco."<<endl;
        if(ch==1)
            file<<"Sortowanie Insertion Sort."<<endl;
        else if(ch==2)
            file<<"Sortowanie Selection Sort."<<endl;
        else
            file<<"Sortowanie Prosta Zamiana."<<endl;

        file<<"Czas sortowania: "<<timer<<"s."<<endl;
        file<<"Ilosc zamian: "<<ilosc_zamian<<endl;
        file<<endl<<endl;
    }
    file.close();
}

int main()
{
    int n;
    unsigned long long int ilosc_zamian;
    unsigned short ch,chRM;
    clock_t start, stop;
    float timer;

    do
    {
        srand(997);
        ilosc_zamian = 0;
        cout<<endl<<"Rozmiar tablicy: "<<endl<<"1. 500"<<endl<<"2. 5000"<<endl<<"3. 50000"<<endl;
        cout<<"4. 150000"<<endl<<"5. 300000"<<endl<<"6. 500000"<<endl;

        cin>>n;

        switch(n)
        {
        case 1:
            n = 500;
            break;
        case 2:
            n = 5000;
            break;
        case 3:
            n = 50000;
            break;
        case 4:
            n = 150000;
            break;
        case 5:
            n = 300000;
            break;
        case 6:
            n = 500000;
            break;
        default:
            n = 30;
        }
        cout<<"Wypelnij: 1. Rosnaco, 2.Malejaco, 3. Losowo"<<endl;
        cin>>chRM;

        int tab[n];

        switch(chRM)
        {
        case 1:
            fillTableR(tab,n);
            break;
        case 2:
            fillTableM(tab,n);
            break;
        default:
            fillTableRand(tab,n);
            break;

        }
        if(n==30) printTable(tab,n);

        unsigned short sortdirection;
        cout<<endl<<"Sortuj:"<<endl<<"1 - Rosnaco 2 - Malejaco."<<endl;
        cin>>sortdirection;

        cout<<endl<<"1 - Insertion Sort, 2 - Selection Sort, 3 - Prosta zamiana."<<endl;
        cin>>ch;

        switch(ch)
        {
        case 1:
            start = clock();
            ilosc_zamian = ISsort(tab,n,sortdirection);
            stop = clock();
            break;
        case 2:
            start = clock();
            ilosc_zamian = SSsort(tab,n,sortdirection);
            stop = clock();
            break;
        case 3:
            start = clock();
            ilosc_zamian = SSwap(tab,n,sortdirection);
            stop = clock();
            break;
        default:
            cin>>ch;
        }
        timer =(stop - start)/1000.0;
        if(timer>=0)
            cout<<"Czas wynosi = "<<timer<<endl;
        if(n==30) printTable(tab,n);
        if(timer>=0)
            saveToFile(tab,n,sortdirection,ch,chRM,timer,ilosc_zamian);
    }
    while(getchar()!='q');


    return 0;
}
