#include <iostream>
using namespace std;

// 1- Declare las estructuras de datos necesarias para implementar la matriz dispersa con un vector de listas
  
  

struct Nodo{

   int pos;
    int valor;
    Nodo*sgte;
};


void inicializar(Nodo*v[],int t);
void insertar(int columna,int valor, Nodo*&lista);
void mostrarUnaFila(Nodo*v[] ,int n);
Nodo*Buscar(Nodo*v[],int t,int valor );



int main() {

   // Nodo*v[3];

   // inicializar(v,3);
    int colum;
    int fila;
    int valor;
  //  int i=0;
    int cColum;
    int cFil=0;



    cout<<"Cantidad De Columnas a Cargar"<<endl;
    cin>>cColum;
    cout<<"Cantidad de Filas a Cargar"<<endl,
    cin>>cFil;

    Nodo*v[cFil];
    inicializar(v,cFil);


    for(int j=0;j<cColum ; j++)
    {
        cout<<"Ingresando Columna :"<<j+1<<endl;
        cout<<""<<endl;
        for(int i=0;i<cFil ; i++)
        {
            int unValor =0;
            do
            {

                cout<<"Ingresando fila: "<<i+1<<endl;
                cout<<"Ingrese un Valor"<<endl;
                cin>>unValor;
                // punto 5 implementaria la restricci�n que un valor tiene que ser mayor a 0
            }while(unValor<=0);
                insertar(j,unValor, v[i]);


        }

    }

    mostrarUnaFila(v , 1);
    cout<<""<<endl;
    mostrarUnaFila(v , 2);
    cout<<""<<endl;
    //mostrarUnaFila(v , 3);


    int asignar=0;
    cout<<"Buscar valor :"<<endl;
    cin>>asignar;
    Nodo*c;
    c=Buscar(v,cFil,asignar);
    cout<<"Posicion del valor :"<<endl;

    if(c!=NULL)
        cout<<c->pos<<endl;
    else
        cout<<"No se encontro ese valor"<<endl;


    /*
        Nodo *p;
        cout<<"Ingrese comlumna"<<endl;
        cin>>colum;
        cout<<"Ingrese Fila"<<endl;
        cin>>fila;
        cout<<"Ingrese Valor"<<endl;
        cin>>valor;

        p=insertar(fila,colum,valor,v);
        i++;


  //  mostrarUnaFila(v , 1);

   // caragarMatriz(Nodo*v[])
  */
    return 0;
}

// 2 Declare y defina la funcion Nodo*Insertar(int FIla ,int Columna,int Valor, Nodo*v[])
// la cual inserte un Nodo en la matriz esparcida;

void insertar(int columna,int valor, Nodo *&lista){


        Nodo*ant,*p,*b=lista;
        p=new Nodo;
        p->pos=columna;
        p->valor=valor;

        while(b!=NULL && b->pos < p->pos )
        {
            ant=b;
            b=b->sgte;

        }

        p->sgte=b;
        if(b!=lista)
            ant->sgte=p;
        else
             lista=p;


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
        cout<<fila->valor<< " ";
        fila=fila->sgte;

    }
}


// 3

Nodo*Buscar(Nodo*v[],int t,int unValor )
{

    Nodo*p=NULL;
    int i=0;
    for(i;i<t ;i++)
    {
        while( v[i]!=NULL && v[i]->valor !=unValor){

              v[i]=v[i]->sgte;
        }

        if(v[i]!=NULL)
            p=v[i];


    }
    return p ;
}



