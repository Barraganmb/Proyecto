#include <iostream>
#include "ClassVendedor.h"
#include "ArchivoVendedor.h"
#include "ArchivoCliente.h"
#include "DeclaracionDeFunciones.h"
#include "ArchivoAutos.h"

using namespace std;


//MENUS
void menu(){
int opcion;
ArchivoVendedor obj;
while(true){

cout<<"1)Iniciar secion"<<endl;
cout<<"2)Olvide mi clave"<<endl;
cout<<"3)Dar alta a un vendedor"<<endl;
cout<<"4)"<<endl;
cout<<"0)Salir"<<endl;
cin>>opcion;

switch(opcion){

case 1:
    system("cls");
    obj.iniciarSecion();
    break;

case 2:
    system("cls");

    break;

case 3:
    system("cls");

    break;

case 4:
    system("cls");

    break;

case 5:
    system("cls");

    break;

case 0:
    system("cls");
    return ;
    break;
}
}


}


void menuVendedores(){
cout<<"hola";
}

//FUNCIONES PARA LOS MENUS
