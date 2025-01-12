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
cout<<"0)Salir"<<endl;
cin>>opcion;

switch(opcion){

case 1:
    system("cls");
    obj.iniciarSecion();
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

case 0:
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

case 3:
    system("cls");
    menuModificar();

case 0:
    system("cls");
    menu();
    break;

}
}
}


void menuModificar(){
int opcion;
ArchivoVendedor obj;
while(true){
cout<<"1)Modificar todos los datos"<<endl;
cout<<"2)Modificar nombre"<<endl;
cout<<"3)Modificar dni"<<endl;
cout<<"4)Modificar correo"<<endl;
cout<<"5)Modificar telefono"<<endl;
cout<<"0)Salir"<<endl;
cin>>opcion;
switch(opcion){
case 1:
    system("cls");
    obj.modificarVendedor();
    break;

case 2:
    system("cls");
    obj.modificarNombre();
    break;

case 3:
    system("cls");
    obj.modificarDni();
    break;

case 4:
    system("cls");
    obj.modificarCorreo();
    break;

case 5:
    system("cls");
    obj.modificarTelefono();
    break;

case 0:
    return;
    break;
}
}
}


void menuCliente(){
ArchivoCliente obj;
int opcion;
while(true){
cout<<"1)Dar alta cliente"<<endl;
cout<<"2)Listar clientes"<<endl;
cout<<"3)Buscar cliente"<<endl;
cout<<"4)Modificar clientes"<<endl;
cout<<"0)Salir"<<endl;
cin>>opcion;
switch(opcion){

case 1:
    system("cls");
    obj.darAltaCliente();
    break;

case 2:
    system("cls");
    obj.listarClientes();
    break;

case 3:
    system("cls");
    obj.buscarCliente(0);
    break;

case 4:
    system("cls");
    menuModificarCliente();
    break;

case 0:
    return;
    break;
}
}
}


void menuModificarCliente(){
int opcion;
ArchivoCliente obj;
while(true){
cout<<"1)Modificar todos los datos"<<endl;
cout<<"2)Modificar nombre"<<endl;
cout<<"3)Modificar dni"<<endl;
cout<<"4)Modificar correo"<<endl;
cout<<"5)Modificar telefono"<<endl;
cout<<"0)Salir"<<endl;
cin>>opcion;
switch(opcion){
case 1:
     system("cls");
     obj.modificarCliente();
     break;

case 2:
     system("cls");
     obj.modificarNombreCliente();
     break;

case 3:
     system("cls");
     obj.modificarDNICliente();
     break;

case 4:
     system("cls");
     obj.modificarCorreoCliente();
     break;

case 5:
    system("cls");
    obj.modificarTelefonoCliente();
    break;

case 0:
    return;
    break;

}
}
}
//FUNCIONES PARA LOS MENUS
