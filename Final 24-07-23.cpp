#include <iostream>
#include <string.h>
using namespace std;

struct Nodo{
    char nombre[40];
    Nodo*sgte;
};

struct ColaP{

    int prioridad; 
    Nodo*pri;
    Nodo*ult;
    ColaP*sgte;
};


int main(){

    ColaP*listaDeColas=NULL;
    crearColaPrioridad(listaDeColas,5);
    char x ;

    while(x!='x'){
        cout<<"Bienvenido a Gestion de Colas"<<endl; 
        cout<<""<<endl;
        cout<<"Cuales de las siguientes acciones quiere realizar "<<endl;
        cout<<" (Ingrese 'x' si quiere salir )"<<endl;
        cout<<" a - Insertar paciente segun prioridad"<<endl;
        cout<<" b - Visualizar paciente con mayor prioridad "<<endl;
        cout<<" c - Atender paciente con mayor prioridad  "<<endl;
        cout<<" d - Ver si todas las colas estan vacias "<<endl;

        cin>>x;

        switch (x){
        
        case 'a':
            
            char nom[40];
            int prioridad;
            cout<<"Ingrese nombre del paciente "<<endl;
            cin.getline(nom,40);
            do
            {
                cout<<"Ingrese la prioridad del paciente "<<endl;
                cin>>prioridad;
            } while (prioridad<0 && prioridad >4);
            
            insertarEnPrioridad(listaDeColas,nom,prioridad);
            break;
        
        case 'b':
            Nodo*b;
            int j;
            b= elementoMinimo(listaDeColas,j);
            if(b!=NULL){
                cout<<"Nombre del Paciente : "<< b->nombre<<endl;
                cout<<"Prioridad : "<<j<<endl;
            }

            break;
        
        case 'c':
            int j;
            ColaP*cPrio;
            Nodo*b;
            b= elementoMinimo(listaDeColas,j);
            if(b!=NULL ){

                cPrio=BuscarCola(listaDeColas,j);
                
                
            }


            break;
        
        case 'd':
            


            break;

        
    
        default:
            break;
        }


    }
    
    

   return 0;

}


/*Ejercicio 1 */ 

void crearColaPrioridad(ColaP *&listaDeColas, int cantPrioridades ){}
/*-La función no tendra valor de retorno , por que ya antes se definio la cola la función solo la inicializa 
precondición : la función debe tener una listaDeColas que inicializar , a su vez debe saber la cantidad de
prioridades que se usara para crear la cantidad de nodos que tendra la la lista  de prioridades.

postcondición : la función debe retornar un puntero a la lista de las colas por prioridad.  */


void insertarEnPrioridad(ColaP*&listaDeColas, char paciente[], int prioridad){}

/* 
- La función no tiene valor de retorno, los parametros son la lista de prioridades , el nombre del paciente,
y la prioridad que tiene esse paciente.

precondición : la función debe recibir todos los parametros antes ya mencionados , los cuales a la hora de 
de la invocación deben estar ya inicializados.

poscondición : la función debe haber ingresado un nuevo nodo dependiendo de la prioridad que tenga y 
actualizar la cola de esa prioridad (haciendo un push ).

*/

Nodo* elementoMinimo (ColaP*listaDeColas , int &i){}
/* - la función tiene como valor retorno un puntero del tipo ColaP si la prioridad mas alta no tiene elemeentos en la cola , lo hara con el 
siguiente más alto y asi hasta la prioridad mas baja ),y tiene como parametro a la colaPrioriadad sin el & 
por que no modifica nada, y ademas una variable que le pasamos para saber en que prioridad se la encontro.


precondición : todos lo parametros antes mencionados , y que la colaDePrioridades ya se haya inicializado.

poscondición : la función debe retornar un puntero del tipo Nodo , si la cola de priordad 0 no tiene elementos
devolvera NULL.
*/

void quitarMinimo(ColaP*& listaDeColas ){}
/* - la función hace uso de una función elementoMinimo en donde podra obtener en que cola se encuentra segun 
la prioridad en el cual se le encontro. y cual es ese elemento ,y despues procede a eleminarlo y cambiar 
cual es el primero de la cola ahora. 

precondición : la función dbe recibir como parametro la cola de prioridades y que ya debe estar inicializado.

postcondición : la función dbe haber quitado al cliente con mayor prioridad de la cola.
*/

bool colaVacia(ColaP*listaDeColas , int n){}
/* 
precondición : los parametros listadeColas y n.

poscondición : la función devulve true si la cola de prioridad n esta vacia.
*/

bool prioridadVacia(ColaP*listaDeColas){}
/* 
precondición : el parametro listadeColas.

poscondición : la función devulve true si la cada una de las colas de la lista esta vacia.
*/



//Funciones auxiliares

ColaP*BuscarCola(ColaP*lista , int k){

    ColaP*p=lista;
    
    while(p!=NULL && k!=p->prioridad){
        p=p->sgte;
    }
    
    return p;
}