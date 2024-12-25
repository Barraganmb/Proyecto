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
ArchivoCliente obj1;
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
  menuVendedores();
    break;

case 2:
    system("cls");
obj1.listarClientes();

    break;

case 3:
    system("cls");
obj.darAlta();
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

int opcion;
ArchivoVendedor obj;
while(true){
cout<<"1)Listar vendedores"<<endl;
cout<<"2)Buscar vendedor "<<endl;
cout<<"3)Modificar Datos"<<endl;
cout<<"0)Salir"<<endl;
cin>>opcion;
switch(opcion){
case 1:
    system("cls");
    obj.listarVendedores();
    break;

case 2:
    system("cls");
    obj.buscarVendedor();

    break;

case 0:
    system("cls");
    menu();
    break;

}

}
}


//FUNCIONES PARA LOS MENUS
