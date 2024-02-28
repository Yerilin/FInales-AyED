#include <iostream>
using namespace std;

struct Nodo1{

    int i;
    Nodo1*sgte;
};

struct Notas {

    int legajo;
    int nota1;
    int nota2;
};

struct Nodo2{

    int leg;
    int rec2;
    Nodo2*sgte;
};


int main(){

    //Definiciones Ejercicio 2 
    Notas v[1500];
    Nodo2*lista2rec;
    actualizarVectorNotas(v,1500,lista2rec);

    

}


/*Ejercicio 1 - Crear una función que retorne una lista ordenada de la unión de una pila y una cola */

Nodo1* listaUnion(Nodo1*pila, Nodo1 *pri,Nodo1*ult){

        Nodo1*p,*d,*listaOrd=NULL;
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

/*Ëjercicio 2 -Se tiene un Vector de Notas con el siguiente formato: Legajo - Noto 1° Parcial - Nota 2° Parcial
y se tiene una lista ordenada que contiene las notas del recuperatorio del 2° Parcial con el siguiente formato:
legajo - Nora Recuperatorio 2° Parcial , se pide actualizar las notas,si la nota esta aprobada}(6>=) debe
cambiarse en el vector,de lo contrario debe permanecer igual , se sabe que como maximo se tiene 
1500 alumnos.  */

void actualizarVectorNotas(Notas v[],int i,Nodo2* lista){

    Nodo2*p;
    p=lista;
    if(p!=NULL){

        while(p!=NULL){
            int b;
            b=busquedaSecuencial(v,i,p->leg);
            if(b!=-1 && p->rec2>=6){

                v[b-1].nota2=p->rec2;
            }
            p=p->sgte;
        }
    }
    else 
        cout<<"No se pudo actualizar la lista esta vacia "<<endl;
}


/*Ejercicio 3- Indique que sale por pantalla en los siguiente segmentos de codigo o justique si no compila*/
 // A- 
    struct Nodo{
        int info;
        Nodo*sgte;
    };

    int main (){

        Nodo*p;
        p=new Nodo();
        p->info=1;             
        p->sgte=new Nodo();
        p->sgte->info=2;
        p->sgte->sgte=new Nodo();
        p->sgte->sgte->info= 3;
        p->sgte->sgte->sgte=NULL;
        Nodo*aux;
        aux=p;
        p=p->sgte;
        p->sgte->sgte=aux;
        aux->sgte=NULL;
        aux=p;

        
        while(aux){

            cout<<aux->info<< " ;"<<endl;
            aux=aux->sgte;

        }

        return 0;
    }
        // respuesta : 2; 3; 1;
        /*Explicación : visitar siguiente link: https://jamboard.google.com/d/1R0vCRckkVK-tg4ymOwAr3NHpjYmOsKk2u3D5RDaURFc/edit?usp=sharing*/
    //B

    int main(){

        int x=30;
        x++;
        int *p;

        dothat(p,&x);
        cout<<*p;
        delete p;

        return 0;

    }
    void dothat(int*&p,int*q){
        p= new int();
        *p=*q;
        return;
    }

    // respuesta: 31

    /* Explicación : Ahora, la función dothat toma un puntero por referencia (int*& p).
    Esto significa que cualquier cambio realizado en p dentro de la función se reflejará fuera de la función. 
    En este caso, se asigna dinámicamente memoria para un entero y se copia el valor de *q en esa ubicación 
    de memoria.
    Después de llamar a dothat(p, &x); en main, el puntero p ahora apunta a un entero dinámicamente asignado
    con el valor de x (31 en este caso). Luego, se imprime el valor al que apunta p con cout << *p;, 
    y finalmente, se libera la memoria asignada dinámicamente con delete p;.
    En resumen, este código modificado evita el problema de acceso a memoria indefinida al utilizar un puntero
    por referencia en la función dothat, lo que permite la asignación dinámica de memoria y el acceso
    a la misma fuera de la función.*/

//Ejercicio 4 - V o F

    /* -- En el apareo, el conjunto resultante contendrá todos los elementos únicos presentes en ambos 
          conjuntos originales, sin ninguna pérdida de información.
          -- Verdadera, el apareo toma a los elementos
          que se encuentran en ambas lista, de no ser el mismp elemento se avanza hasta encontrar el mismp o finalizar
          la operación. 

       -- El corte de control en archivos solo puede aplicarse si el archivo esta ordenado y no tiene clave repetida
          -- Falso, si bien el archivo debe estar ordenado,la clave si es repetida por que el cc implica agrupar 
             elementos de un mismo tipo.
    */

// Funciones Auxiliares 
void insertarOrdenado(Nodo1*lista,int i){}
int pop(Nodo1*pila){}
int desencolar(Nodo1*pri){}
int busquedaSecuencial(Notas v[],int j,int buscar){}
