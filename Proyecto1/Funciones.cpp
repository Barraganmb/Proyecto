#include <iostream>
#include "ClassVendedor.h"
#include "ArchivoVendedor.h"
#include "ArchivoCliente.h"
#include "DeclaracionDeFunciones.h"
using namespace std;

void menu(){
int opcion;
ArchivoVendedor objV;
ArchivoCliente objC;
while(true){

cout<<"1)Alta vendedor"<<endl;
cout<<"2)Alta cliente"<<endl;
cout<<"3)Listar vendedores"<<endl;
cout<<"4)Listar clientes"<<endl;
cin>>opcion;

switch(opcion){

case 1:
    system("cls");
    objV.darAlta();
    break;

case 2:
    system("cls");
    objC.darAltaCliente();
    break;

case 3:
    system("cls");
    objV.listarVendedores();
    break;

case 4:
    system("cls");
    objC.listarClientes();
    break;

case 0:
    system("cls");
    return ;
    break;
}
}


}
