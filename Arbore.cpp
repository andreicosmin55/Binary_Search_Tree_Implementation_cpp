#include "Arbore.h"
#include<iostream>
#include <stdlib.h>
using namespace std;
ArboreBinarCautare::ArboreBinarCautare():contor(0)
{
}

ArboreBinarCautare::~ArboreBinarCautare()
{
}

ostream& operator<<(ostream& out, ArboreBinarCautare::nod n)
{
    out<<n.info;
    return out;
}

long long int ArboreBinarCautare::min()
{
    if(radacina == NULL)
        return 0;

    nod* pointerAux = radacina;
    while(pointerAux->stanga != NULL)
        pointerAux = pointerAux->stanga;

    return pointerAux->info;
}

long long int ArboreBinarCautare::max()
{
    if(radacina == NULL)
        return 0;

    nod* pointerAux = radacina;
    while(pointerAux->dreapta != NULL)
        pointerAux = pointerAux->dreapta;

    return pointerAux->info;

}

long long int ArboreBinarCautare::succesor(long long int x)
{
    if(radacina == NULL || este_in(x) == 0)
    {
        cout << x << " nu exista in arbore" << endl;
        return 0;
    }
    if(max() == x)
    {
        return 0;
    }
    if(este_in(x))
    {
        nod* p = radacina;
        nod* aux;       //aux o sa fie pointer pentru ultimul nod din care plec in stanga
        while(p != NULL && p->info != x)
        {
            if(p->info < x)
                p = p->dreapta;
            else
            {
                aux = p;
                p = p->stanga;
            }
        }
        if(p->dreapta != NULL)
        {
            p = p->dreapta;
            while(p->stanga != NULL)
                p = p->stanga;
            return p->info;
        }
        else
        {
            return aux->info;
        }
    }
}

long long int ArboreBinarCautare::predecesor(long long int x)
{
    if(radacina == NULL || este_in(x) == 0)
    {
        cout << x << " nu exista in arbore" << endl;
        return 0;
    }
    if(min() == x)
    {
        return 0;
    }
    if(este_in(x))
    {
        nod* p = radacina;
        nod* aux;   //aux o sa fie pointer pentru ultimul nod din care plec in dreapta
        while(p != NULL && p->info != x)
        {
            if(p->info < x)
            {
                aux = p;
                p = p->dreapta;
            }
            else
                p = p->stanga;
        }
        if(p->stanga != NULL)
        {
            p = p->stanga;
            while(p->dreapta != NULL)
                p = p->dreapta;
            return p->info;
        }
        else
        {
            return aux->info;
        }
    }
}


int ArboreBinarCautare::cardinal()
{
    return contor;
}

bool ArboreBinarCautare::este_in(long long int x)
{
    if(radacina == NULL)
    {
        return false;
    }

    nod* pointerAux = radacina;

    while(pointerAux != NULL && pointerAux->info != x)
    {
        if(pointerAux->info < x)
            pointerAux = pointerAux->dreapta;
        else
            pointerAux = pointerAux->stanga;
    }

    if(pointerAux == NULL)
        return false;

    return true;

}

void ArboreBinarCautare::insereaza(long long int x)
{
    contor++ ;
    if(radacina == NULL)
    {
        radacina = new nod;
        radacina->info = x;
    }
    else
    {
        nod* p = radacina;
        nod* aux;

        while(p != NULL)
        {
            aux = p;
            if(p->info < x)
                p = p->dreapta;
            else
                p = p->stanga;
        }

        nod* nodNou = new nod;
        if(aux->info < x)
            aux->dreapta = nodNou;
        else
            aux->stanga = nodNou;

        nodNou->info = x;
    }
}

void ArboreBinarCautare::sterge(long long int x)
{

    if(radacina == NULL)
    {
        cout << x << " nu exista in arbore";
        return;
    }

    nod* p = radacina;
    nod* aux;   //aux o sa fie pointer catre nodul imediat deasupra lui p

    while(p != NULL && p->info != x)
    {
        aux = p;
        if(p->info < x)
            p = p->dreapta;
        else
            p = p->stanga;
    }

    if(p == NULL)
    {
        cout << x << " nu exista in arbore";
        return;
    }

    if(p->dreapta == NULL && p->stanga == NULL)
    {
        if(p == radacina)
        {
            delete p;
            radacina = NULL;
            return;
        }
        if(aux->dreapta != NULL && aux->dreapta->info == x)
            aux->dreapta = NULL;
        else
            aux->stanga = NULL;
        contor-- ;
        delete p;
        return;
    }

    if(p->dreapta == NULL && p->stanga != NULL)
    {

        if(p == radacina)
        {
            radacina = p->stanga;
            delete p;
            return;
        }

        if(aux->dreapta != NULL && aux->dreapta->info == x)
            aux->dreapta = p->stanga;
        else
            aux->stanga = p->stanga;
        contor-- ;
        delete p;
        return;
    }


    if(p->dreapta != NULL && p->stanga == NULL)
    {
        if(p == radacina)
        {
            radacina = p->dreapta;
            delete p;
            return;
        }

        if(aux->dreapta != NULL && aux->dreapta->info == x)
            aux->dreapta = p->dreapta;
        else
            aux->stanga = p->dreapta;
        contor-- ;
        delete p;
        return;
    }

    nod* cauta = p->stanga;
    while(cauta->dreapta != NULL)
        cauta = cauta->dreapta;
    long long int memoreaza = cauta->info;
    sterge(memoreaza);
    p->info = memoreaza;
}



long long int ArboreBinarCautare::k_element(long long int k)
{
    if(k == 0)
    {
        cout << "k trebuie sa fie un intreg >0!";
        return -1;
    }
    long long int card = cardinal();
    if(k > card)
    {
        cout << "Nu exista atatea elemente in arbore!";
        return -1;
    }

    if(k == 1)
        return ArboreBinarCautare::min();
    if(k == card)
        return ArboreBinarCautare::max();

    long long int i = 0;
    return SRD(radacina,&i, k);
}


long long int ArboreBinarCautare::SRD(nod* n, long long int* counter, long long int k)
{
    if(n == NULL)
        return 9223372036854775807;     //valoarea maxima pe care o poate lua un long long

    long long int stanga = SRD(n->stanga, counter, k);
    if(stanga != 9223372036854775807 )
        return stanga;

    if( ++*counter == k)
        return n->info;

    return SRD(n->dreapta, counter, k);


}

ArboreBinarCautare::nod* ArboreBinarCautare::getRadacina()
{
    return radacina;
}
