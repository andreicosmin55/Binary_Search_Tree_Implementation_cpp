#ifndef ARBORE_H
#define ARBORE_H
#include <iostream>
using namespace std;

class ArboreBinarCautare
{
    private:
        struct nod{
            long long int info;
            nod* stanga=NULL;
            nod* dreapta=NULL;
        };
        nod* radacina=NULL;
        int contor;

    public:

        friend ostream& operator<<(ostream& out, nod n);

        ArboreBinarCautare();
        ~ArboreBinarCautare();

        void insereaza(long long int x);
        void sterge(long long int x);
        long long int min();
        long long int max();
        long long int succesor(long long int x);
        long long int predecesor(long long int x);
        long long int k_element(long long int k);
        int cardinal();
        bool este_in(long long int x);

        long long int SRD(nod* n, long long int* counter, long long int k); //un SRD adaptat pt cerinta k_element
        nod* getRadacina();
};

#endif // ARBORE_H
