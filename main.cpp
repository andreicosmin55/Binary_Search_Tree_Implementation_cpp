#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Arbore.h"
using namespace std;

ifstream fin1("date1.in");
ifstream fin2("date2.in");
ifstream fin3("date3.in");
ifstream fin4("date4.in");
ifstream fin5("date5.in");
ifstream fin6("date6.in");
ofstream fout("date.out");


int main()
{
    ArboreBinarCautare a;
    short nr;
    cout<<"Ce fisier rulam? (1->6) : ";
    cin>>nr;
    long long int x;
    switch(nr){
        case 1:{
            fout<<"Input din fisierul date1.in"<<endl;
            while(fin1>>x)
                a.insereaza(x);
            break;
            }

        case 2:{
            fout<<"Input din fisierul date2.in"<<endl;
            while(fin2>>x)
                a.insereaza(x);
            break;
            }

        case 3:{
            fout<<"Input din fisierul date3.in"<<endl;
            while(fin3>>x)
                a.insereaza(x);
            break;
            }

        case 4:{
            fout<<"Input din fisierul date4.in"<<endl;
            while(fin4>>x)
                a.insereaza(x);
            break;
            }

        case 5:{
            fout<<"Input din fisierul date5.in"<<endl;
            while(fin5>>x)
                a.insereaza(x);
            break;
        }
        case 6:{
            fout<<"Input din fisierul date6.in"<<endl;
            while(fin6>>x)
                a.insereaza(x);
            break;
        }

        default:{
            while(fin1>>x)
                a.insereaza(x);
            break;
        }
    }


    fin1.close();
    fin2.close();
    fin3.close();
    fin4.close();
    fin5.close();
    fin6.close();

    for(int i=0;i<30;i++)
        fout<<'~';
    fout<<endl<<endl;


    fout<<"Arborele are radacina: "<<a.getRadacina()->info<<endl<<endl;

    fout<<"Minimul multimii este: "<<a.min()<<endl;
    fout<<"Maximul multimii este: "<<a.max()<<endl<<endl;

    fout<<"Cardinalul multimii este: "<<a.cardinal()<<endl<<endl;

    for(int i=0;i<10;i++){
        fout<<"Succesorul lui ";
        long long int aux1=rand()%a.cardinal()+1;
        long long int aux2=a.k_element(aux1);
        long long int succes=a.succesor(aux2),predec=a.predecesor(aux2);
        fout<<aux2<<" este ";
        if(succes)
            fout<<succes;
        else
            fout<<" numarul este maximul din multime ";
        fout<<" iar predecesorul lui este: ";
        if(predec)
            fout<<predec;
        else
            fout<<" numarul este minimul din multime ";
        fout<<endl;


    }
    fout<<endl;

    for(int i=0;i<10;i++){
        fout<<"Am sters elementul ";
        long long int aux1=rand()%a.cardinal()+1;
        long long int aux2=a.k_element(aux1);
        a.sterge(aux2);
        fout<<aux2<<"\t\t Noul cardinal este: "<<a.cardinal()<<endl;

    }


    fout.close();

}
