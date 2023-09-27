#include <iostream>
#include <string.h>
using namespace std;

struct Nodo{

   int pos;
    int valor;
    Nodo*sgte;
};

int main(){

    char nombreyApellido[30];
    char nombreyApellid[30];
    int i=0;

    cout<<"Comparando letras en Mayusculas"<<endl;
   // cin>>nombreyApellido;
    cin.getline(nombreyApellido,30);
    cout<<"Ahora en en Minusculas"<<endl;
    cin.getline(nombreyApellid,30);

    i=strcmpi(nombreyApellido,nombreyApellid);
    cout<<i<<endl;

    generar

}
