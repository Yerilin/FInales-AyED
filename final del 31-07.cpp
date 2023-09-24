#include <iostream>
using namespace std; 


struct NodoCola
{
  char nombre[41];
  NodoCola*sgte;
};

struct tipoInfoPrioridades
{
   NodoCola *frente;
   NodoCola *fin;

};


struct NodoPrioridad
{
   tipoInfoPrioridades info;
   NodoPrioridad * sgte;

};


NodoPrioridad *crearColaPrioridad();

int main()
{
   NodoPrioridad *p;

   p = crearColaPrioridad();
   return 0;
}

NodoPrioridad *crearColaPrioridad(){

   NodoPrioridad* head =NULL;
   NodoPrioridad* current =NULL;

   for (int i = 0; i < 4; ++i)
    {
        NodoPrioridad* newNode = new NodoPrioridad;
        newNode->info.frente = NULL;
        newNode->info.fin = NULL;
        newNode->sgte = NULL;

        if (head == NULL)
        {
            head = newNode;
            current = newNode;
        }
        else
        {
            current->sgte = newNode; // conectar 
            current = newNode; // Mover pointer
        }
    }

   return head;
}


/*
NodoPrioridad* crearColaPrioridad()
{
    NodoPrioridad* cabeza = nullptr;  // Puntero al primer nodo de la cola
    NodoPrioridad* actual = nullptr;  // Puntero para rastrear el nodo actual
    
    // Crear cinco nodos, uno para cada prioridad del 0 al 4
    for (int prioridad = 0; prioridad <= 4; ++prioridad)
    {
        NodoPrioridad* nuevoNodo = new NodoPrioridad;  // Crear un nuevo nodo
        nuevoNodo->info.frente = nullptr;  // Inicializar el frente de la cola en este nodo
        nuevoNodo->info.fin = nullptr;     // Inicializar el fin de la cola en este nodo
        nuevoNodo->sgte = nullptr;         // Inicializar el puntero al siguiente nodo
        
        if (cabeza == nullptr)
        {
            cabeza = nuevoNodo;  // Si es el primer nodo, establecerlo como la cabeza
            actual = nuevoNodo;  // También establecerlo como el nodo actual
        }
        else
        {
            actual->sgte = nuevoNodo;  // Conectar el nodo actual al nuevo nodo
            actual = nuevoNodo;       // Mover el puntero actual al nuevo nodo
        }
    }

    return cabeza;  // Devolver el puntero al primer nodo de la cola de prioridad
*/






void insertarEnPrioridad(NodoPrioridad *colaPrioridad, int prioridad, char paciente[]){

   NodoPrioridad*p;
   p = colaPrioridad; // la posicion seria prioridad -1 pero no se como ingresar a esa posicicon 
   for(int i=0;i<prioridad;i++){
      if(p!=NULL){
       p= p->sgte;
      }
   }

   p=p->sgte;
}
 
/*
void generar(Nodo *&lista)
{
   Alumno al;
   Examen ex;
   Nodo *p;
   cout << "DNI alumno: ";
   cin >> dniAl;
   while (dniAl != 0) // ingresa datos del examen
   {
      cout << "Nombre alumno: ";
      cin >> nomAl;
      cout << "Fecha examen: ";
      cin >> fechaEx;
      cout << "Materia rendida: ";
      cin >> codMateria;
      cout << "Nota: ";
      cin >> notaOb;

      al.dni = dniAl;
      al.nom = nomAl;
      al.listaExa = NULL;
      p = buscarInsertar(lista, al);
      ex.dia = fechaEx;
      ex.codMat = codMateria;
      ex.nota = notaOb;
      insertar(p->info.listaExa, ex);

      cout << "DNI alumno: ";
      cin >> dniAl;
   }
}
*/