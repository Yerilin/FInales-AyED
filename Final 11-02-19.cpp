#include <iostream>
using namespace std;


struct Venta{
    int efectivo;
    Cobrados TD;
    Cobrados TC;
    Cobrados ticket;
    
};

struct Cobrados{
    int cantidad;
    int total ;
};

struct Cliente {
    int NroCarrito;
    Cliente*sgte;
};

struct Registro{
    int nroCaja;
    int efectivoI;
};

struct Caja {
    int dInicial;
    Venta v;
    Cola c;
};
struct Cola {
    Cliente*pri;
    Cliente *ult;
};

void cajasHabilitadas(FILE*Cajas,Caja*CajasSuper[] );
void inicializarColas(Caja*cajasSuper[], int f);

int main(){

    Caja *cajasSuper[40];
    Cola colaClientes;
    FILE*archCajas=fopen("Cajas.dat","r");
    if(archCajas==NULL)
    {
        cout<<"No se a podido abrir el archivo "<<endl;
    }
    else 
    {
        
        cajasHabilitadas(archCajas,cajasSuper,40 );
    }

    return 0;
}


void cajasHabilitadas(FILE*archCajas,Caja*cajasSuper[], int f  ){
    Registro r;
    
    fread(&r,sizeof(Registro),1,archCajas);
    while(!feof(archCajas)){

        cajasSuper[r.nroCaja-1]->dInicial=r.efectivoI;
        
    }
    inicializarColas(cajasSuper,f) ;

}

void nuevoCliente(int carrito,Cola &colaClientes ){

    Cliente *c;
    c = new Cliente;
    c->NroCarrito= carrito ;
    c->sgte=NULL;
    if (colaClientes.pri!=NULL && colaClientes.ult!=NULL){
         Cliente* ultimo;
         ultimo=colaClientes.ult;
         ultimo->sgte=c;
    }
    else {
        colaClientes.pri= c;
        colaClientes.ult=c;

    }
}

void inicializarColas(Caja*cajasSuper[],int f){

    for(int i=0; i<f; i++){
        
        cajasSuper[i]->c.pri=NULL;
        cajasSuper[i]->c.ult=NULL;
    }
    
}
void atenderCliente(int nCaja,Caja*cajasSuper[] ){
    Cliente *primero;
    Caja *caja;
    caja=cajasSuper[nCaja-1];
    primero = cajasSuper[nCaja-1]->c.pri;

    if (primero!= NULL){
        Venta venta;
        int carrito = primero->NroCarrito;
        venta=calcularImportes(carrito);

        if ( venta.TC.cantidad== 1 || venta.TD.cantidad==0 ){
            caja->v.efectivo+=venta.efectivo;
            caja->v.TC.cantidad+=venta.TC.cantidad;
            caja->v.TC.total+= venta.TC.total; 
            if(venta.TC.cantidad== 1|| venta.TD.cantidad==0)
            {
                caja->v.TD.cantidad+=venta.TD.cantidad;
                caja->v.TD.total+=venta.TD.total;
                caja->v.ticket.cantidad += venta.ticket.cantidad;
                caja->v.ticket.total+=venta.ticket.total;

            }
            
        }

        primero=primero->sgte;
    }
    else 
    {
        cout<<"No hay clientes en esta fila"<<endl;
    }

        
    }
    //calcularImporte()


void reasignarCaja(int cajaActual,int CajaDestino,Caja*cajasSuper[]){
    Cliente *c1,*c2;
    Cola *cola,*cola2;
    cola = &cajasSuper[cajaActual-1]->c;
    c1= cola->pri;
    cola->pri= cola->pri->sgte;
    c1->sgte=NULL;
    cola2=&cajasSuper[CajaDestino-1]->c;
    cola2->ult = c1; 

  
 

}


Venta calcularImportes(int carrito){


}
