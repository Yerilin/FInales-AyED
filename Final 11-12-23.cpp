#include <iostream>
#include <string.h>
using namespace std;

/*Declaración - Ejercicio 1 */
struct Nodo{

    int i;
    Nodo*sgte;
};

/*Declaración - Ejercicio 2*/
struct Nodo2{
    int codHotel;
    int diasReservados;
    Nodo2*sgte;
};

struct Hotel {

    int codH;
    int cantReservas;
    int disponible;

};

/*Declaración - Ejercicio 3 */

struct Producto{
    int cod;
    int peso;
    char c;
    int bultos;
};

struct NodoP{
    Producto c;
    NodoP*sgte;
};


void insertarOrdenado(Nodo*lista, int i);
void pop(Nodo*&pila);
void desencolar(Nodo*&lista);
Nodo* buscarNodo(Nodo*p,int i);
void insertar(Nodo*p,int i);
int buscarPosición(Hotel v[],int cod);
void insertarOrdenadoA(NodoP*&lista,Producto d);
void listar (NodoP*lista);

int main(){

    /*Definiciones Ej 2 */
    Hotel v[50];
    Nodo2*ListaOrdenada;

    actualizarReservas(v,ListaOrdenada);

    /*Definiciones Ej 3*/
    NodoP *listaProductos=NULL;
    FILE*productos=fopen("Stock.dat","r+");
    if(!feof(productos)){

        ordenarArchivo(productos,listaProductos);

    }

    NodoP*sinStock,*BebidasyPesados;
    sinStock=ClasificarSinStock(listaProductos);
    if(sinStock!=NULL)
        listar(sinStock);
    BebidasyPesados=ClasificarPesadosYbebidas(listaProductos);
    if(BebidasyPesados!=NULL)
        listar(BebidasyPesados);

}



/*Ejercicio 1 - SubProgramas*/

    /*A - Una función que retorne una lista ordenada a partir de la union de 
    una pila y una cola */

    Nodo* listaUnion(Nodo*pila, Nodo *pri,Nodo*ult){

        Nodo*p,*d,*listaOrd=NULL;
        p=pila;
        d=pri;
        while(p!=NULL){
            insertarOrdenado(listaOrd,p->i);
                pop(p);
        }
        if( ult!=NULL){

            while(d!=NULL){
                insertarOrdenado(listaOrd,p->i);
                desencolar(d);

            }
        }
        return listaOrd;
    }




    /*B - Una función que retorne una lista son orden a partir de la INTERSECCIÓN  de 2 listas */

    Nodo*listaIntersección(Nodo*lista1, Nodo*lista2){

        Nodo*p,*d,*b,*listaInt=NULL;
        p=lista1;
        d=lista2;

        while(p!=NULL){

            b=buscarNodo(d,p->i);
            if(b!=NULL){
                
                insertar(listaInt,p->i);
                
            }
            p=p->sgte;
        }
        return listaInt;
    }


/*Ejercicio 2 - Actualizar Reservas */


void actualizarReservas(Hotel v[],Nodo2*listaOrd){
     
    Nodo2*p;
    int b;
    p=listaOrd;
    while(p!=NULL){

        b=buscarPosición(v,p->codHotel);
        if(b!=-1 && v[b-1].disponible>p->diasReservados){
            
            v[b-1].disponible-=p->diasReservados;
            v[b-1].cantReservas+=p->diasReservados;
    
        }
        p=p->sgte;

    }
}

/*Sin actualizar la lista */

/*Ejercicio 3 - Archivo y listas  */

    /*A- Ordenar Archivo */

    void ordenarArchivo(FILE*productos, NodoP *&listaProductos){

        Producto p,d,f;
        fread(&p,sizeof(Producto),1,productos);
        while(!feof(productos)){
            d.cod=p.cod;
            d.bultos=p.bultos;
            d.c=p.c;
            d.peso=p.peso;

            insertarOrdenadoA(listaProductos,d);
            fread(&p,sizeof(Producto),1,productos);
        }

        NodoP*c;
        c=listaProductos;
        while(c!=NULL){

            f.bultos=c->c.bultos;
            f.c=c->c.c;
            f.cod=c->c.cod;
            f.peso=c->c.peso;
            fwrite(&f,sizeof(Producto),1,productos);
            c=c->sgte;
        }
    }


    /*B <a> - lista con los productos sin stock*/

    NodoP*ClasificarSinStock(NodoP*productos){

        NodoP*p,*sinStock=NULL;
        p=productos;
        while(p!=NULL){

            if(p->c.bultos ==0){

                insertarOrdenadoA(sinStock,p->c); // Podria no ser ordenado 
            }
            p=p->sgte;

        }
        return sinStock;
    }

    /*B <b> - lista con los productos que son bebidas o pesados */

    NodoP*ClasificarPesadosYbebidas(NodoP*productos){
        NodoP*p,*byP=NULL;
        p=productos;
        while(p!=NULL){

            if(p->c.peso > 100 || p->c.c=='B'){

                insertarOrdenadoA(byP,p->c); // Podria no ser ordenado 
            }
            p=p->sgte;

        }
        return byP;
    }


/*Funciones Auxiliares */

void insertarOrdenado(Nodo*lista, int i){}
void pop(Nodo*&pila){}
void desencolar(Nodo*&lista){}
Nodo* buscarNodo(Nodo*p,int i){}
void insertar(Nodo*p,int i){}
int buscarPosición(Hotel v[],int cod){}
void insertarOrdenadoA(NodoP*&lista,Producto d){}
void listar (NodoP*lista){}