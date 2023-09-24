#include <iostream>
using namespace std;

// 1- Declare las estructuras de datos necesarias para implementar la matriz dispersa con un vector de listas


struct Nodo{

   int pos;
    int valor;
    Nodo*sgte;
};


void inicializar(Nodo*v[],int t);
Nodo*insertar(int fila ,int columna,int valor, Nodo*v[]);
void mostrarUnaFila(Nodo*v[] ,int n);




int main(){

    Nodo*v[3];

    inicializar(v,3);
    int colum;
    int fila;
    int valor;
    int i=0;

    cout<<"Cantidad De Columnas a Cargar"<<endl;
    cin>>cColum;
    cout<<"Cantidad de Filas a Cargar"<<endl,
    cin>>cFil

    for(int j=0;j<cColum ; j++)
    {
        cout<<"Ingresando Columna :"<<j+1<<endl;


        for(int i=0;i<cColum ; i++)
        {
             cout<<"Ingrese fila: "<<i+1<<endl;

        }

    }
        Nodo *p;
        cout<<"Ingrese comlumna"<<endl;
        cin>>colum;
        cout<<"Ingrese Fila"<<endl;
        cin>>fila;
        cout<<"Ingrese Valor"<<endl;
        cin>>valor;

        p=insertar(fila,colum,valor,v);
        i++;
    }

    mostrarUnaFila(v , 1);

    caragrMatriz(Nodo*v[])

    return 0;
}

// 2 Declare y defina la funcion Nodo*Insertar(int FIla ,int Columna,int Valor, Nodo*v[])
// la cual inserte un Nodo en la matriz esparcida;

Nodo*insertar(int fila ,int columna,int valor, Nodo*v[]){


        Nodo*b,*ant,*p,*fil=v[fila-1];
        b=fil;
        p=new Nodo;
        p->pos=columna-1;
        p->valor=valor;

        while(b!=NULL && b->pos < p->pos )
        {
            ant=b;
            b=b->sgte;

        }

        p->sgte =b;
        if(b!=fil)
            ant->sgte=p;
        else
            v[fila-1]=p;






}



void inicializar(Nodo*v[],int t)
{
    for(int i=0;i<t;i++)
        v[i]=NULL;
}

void mostrarUnaFila(Nodo*v[] ,int n) {

    Nodo*fila = v[n-1];
    while(fila!=NULL)
    {
        cout<<fila->pos<< " ";
        fila=fila->sgte;

    }
}


// 4

