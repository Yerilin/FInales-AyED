#include <iostream>
#include <string.h>
using namespace std;
/*
typedef char[41] str40;
typedef char[31] str30;
typedef char[7] str06;
*/
struct Pasajero 
{
    char nombreYApellido[41];
    char destino[31];
    char vuelo[7];
    int   asiento;
    int   salida;
    int  llegada;
};

struct Nodo
{
    Pasajero info;
    Nodo *sgte;
};



int main(){

    Nodo*listaC=NULL;
    int i;

    while(i!=0){
        cout<<"Menu de acciones : Presione una de las opciones (1,2,3,4,5,o 0)"<<endl;
        cout<<" 1 - Ingresar Pasajero"<<endl;
        cout<<" 2 - Visualizar datos de un Pasajero"<<endl;
        cout<<" 3 - Visualizar todos los pasajeros "<<endl;
        cout<<" 4 - Visualizar los pasajeros de un destino especifico"<<endl;
        cout<<" 5 - Eliminar pasajero "<<endl;
        cout<<" 6 - Modificar datos de un pasajero"<<endl;
        cout<<" 0 - Salir "<<endl;
        cin>> i;
        switch (i)
        {
        case 1:
            Pasajero per;
            cout<<"Ingrese datos del pasajero :"<<endl;
            cout<<"Ingrese nombre y apellido ( que no esceda los 41 caracteres)"<<endl;
            cin.getline(per.nombreYApellido,41);
            cout<<" -Destino: "<<endl;
            cin.getline(per.destino,31);
            cout<<" -Vuelo: "<<endl;
            cin.getline(per.vuelo,7);
            cout<<" -Salida: "<<endl;
            cin>>per.salida;
            cout<<" -LLegada: "<<endl;
            cin>>per.llegada;
            cout<<" Asiento: "<<endl;
            cin>> per.asiento;

            ingresarPasajeros(per,listaC);

            break;
        case 2 :
            char nombr[41];
            cout<<"Ingrese nombre y apellido ( que no esceda los 41 caracteres)"<<endl;
            cin.getline(nombr,41);
            visualizarPasajero(nombr,listaC);

            break;
        case 3 :
            visualizarListaTotal(listaC);
        case 4 : 
            char des[31];
            cout<<"Ingrese destino para ver pasajeros "<<endl;
            cin.getline(des,31);
            visualizarListaDestino(des,listaC);
            break;
        case 5 :
            char nombr[41];
            cout<<"Ingrese nombre y apellido que quiere eliminar"<<endl;
            cin.getline(nombr,41);
            eliminarPasajero(nombr,listaC);

            break;
        
        case 6:
            char nombr[41];
            Pasajero pas;
            cout<<"Ingrese nombre y apellido del pasajero que quiere modificar "<<endl;
            cin.getline(nombr,41);
            cout<<"Nombre y apellido del pasajero "<<endl;
            cin.getline(pas.nombreYApellido,41);
            cout<<" -Destino: "<<endl;
            cin.getline(pas.destino,31);
            cout<<" -Vuelo: "<<endl;
            cin.getline(pas.vuelo,7);
            cout<<" -Salida: "<<endl;
            cin>>pas.salida;
            cout<<" -LLegada: "<<endl;
            cin>>pas.llegada;
            cout<<" Asiento: "<<endl;
            cin>> pas.asiento;

            modificarDatosPas(listaC,pas,nombr);
            
            break;

        default:
            cout<<"La opcin selecionada no existe "<<endl;
            break;
        }
    }
    cout<<"Fin del progrma "<<endl;
    return 0;
}


void modificarDatosPas(Nodo *listaCircular, Pasajero datosNuevos, char nombreDePasajeroABuscar[])
{
    Nodo *aux = buscarNodo(listaCircular, nombreDePasajeroABuscar);
    
    if(aux != NULL)
        aux -> info = datosNuevos;
}

Nodo *buscarNodo(Nodo *listaCircular, char nombreYApellido[])
{
    Nodo *aux = listaCircular;
    bool encontrado=false;
    if (aux !=  NULL)
    {  
       
     do
        {
            if (strcmp(aux->info.nombreYApellido, nombreYApellido) == 0)
                encontrado=true;
            
            else
                 aux = aux->sgte;
        
        } while (aux != listaCircular && encontrado!=true );
        
        if(encontrado)
            return aux;
    }
    
    return NULL;
}

void ingresarPasajeros(Pasajero nuevo,Nodo*listaCircular){

    Nodo*pas=new Nodo;
    pas->info=nuevo;
    
    if(listaCircular==NULL){

        listaCircular=pas;
        pas->sgte=pas;
    }
    else 
    {   
        Nodo *p=listaCircular->sgte,*ant=listaCircular;
        if( strcmp(p->info.destino,pas->info.destino)<0){
            do
            {
                ant=p;
                p=p->sgte;

            } while (p!=listaCircular && strcmp(p->info.destino,pas->info.destino)<0);
            
        }
        pas->sgte=p;
        ant->sgte=pas;
        if( strcmp(pas->info.destino,listaCircular->info.destino)<0);
            listaCircular=pas;
    }
}

void visualizarPasajero(char nombre[],Nodo*listaCircular){

    Nodo*b;
    b=buscarNodo(listaCircular,nombre);
    if(b==NULL){
        cout<<"No se encontro al pasajero "<<endl;
    }
    else {

        mostrarDatosPasajero(b);

    }

}
void visualizarListaTotal(Nodo*listaCircular){
    Nodo*p,*b;
    p=listaCircular;

    if(p!=NULL){
        visualizarPasajero(p->info.nombreYApellido,listaCircular);
        p=p->sgte;

        while(p!=listaCircular){

           visualizarPasajero(p->info.nombreYApellido,listaCircular);
           p=p->sgte;
         }
    }
    else
        cout<<"La lista circular esta vacia"<<endl;
}

void visualizarListaDestino(char destino[],Nodo*listaCircular){

    Nodo*p;
    p=listaCircular;
    if(p!=NULL ){

        cout<<"Lista de Pasajeros para el Destino: "<<destino<<endl;
        if(strcmp(p->info.destino,destino)==0)
            cout<<" - "<<p->info.nombreYApellido<<endl;
        p=p->sgte;
       while(p!=listaCircular){

            if(strcmp(p->info.destino,destino)==0)
                cout<<" - "<<p->info.nombreYApellido<<endl;
            p=p->sgte;
       }
    }
    

    
}

void eliminarPasajero(char nya[],Nodo*listaCircular){

    Nodo*b,*ant,*p=listaCircular;
    ant=listaCircular;
    b=buscarNodo(listaCircular,nya);
    if(p!=NULL && b!=NULL){
        
        if(p==p->sgte && b==p){

            delete p;
            listaCircular=NULL;
        }

        Nodo* p = listaCircular;
          while (p->sgte != b) {
            if (p->sgte == listaCircular) {
                cout<<"No se encontro al Pasajero"<<endl;
            }
            p = p->sgte;
         }

          p->sgte = b->sgte;

          if (listaCircular == b) {
           listaCircular = listaCircular->sgte;
          }

          delete b;
         }
       
}


void mostrarDatosPasajero(Nodo*b){

    if (b!=NULL){
        cout<<"Datos del pasajero : "<<b->info.nombreYApellido<<endl;
        cout<<" -Destino: "<<b->info.destino<<endl;
        cout<<" -Vuelo: "<<b->info.vuelo<<endl;
        cout<<" -Salida: "<<b->info.salida<<endl;
        cout<<" -LLegada: "<<b->info.llegada<<endl;
        cout<<" Asiento: "<<b->info.asiento<<endl;
    }
}