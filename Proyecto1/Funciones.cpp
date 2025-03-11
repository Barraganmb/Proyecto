#include <iostream>
#include "ClassVendedor.h"
#include "ArchivoVendedor.h"
#include "ArchivoCliente.h"
#include "DeclaracionDeFunciones.h"
#include "ArchivoAutos.h"
#include "ArchivoCabecera.h"
#include "ArchivoDetalle.h"
//#include <vector>
using namespace std;


//MENUS
void menu(){
int opcion;
ArchivoVendedor obj;
ArchivoCliente obj1;
ArchivoCabecera o;
ArchivoDetalle ob;
while(true){
//rlutil::setColor(rlutil::RED);
cout<<"1)Iniciar secion"<<endl;
cout<<"2)Olvide mi clave"<<endl;
cout<<"3)Dar alta a un vendedor"<<endl;
cout<<"0)Salir"<<endl;
cin>>opcion;

switch(opcion){

case 1:
    system("cls");
    obj.iniciarSecion();
    system("cls");
    menuVendedores();
    break;

case 2:
    system("cls");
    obj.recuperarClave();
    break;

case 3:
    system("cls");
    obj.darAlta();
    break;

case 0:
    return;
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
cout<<"4)Clientes"<<endl;
cout<<"5)Vehiculos"<<endl;
cout<<"6)Ventas"<<endl;
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
    break;

case 4:
    system("cls");
    menuCliente();
    break;

case 5:
    system("cls");
    menuAutos();
    break;

case 6:
    system("cls");
    menuVentas();
    break;
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
    system("cls");
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
    obj.buscarCliente();
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


void menuAutos(){
int opcion;
ArchivoAuto obj;
while(true){
cout<<"1)Dar de alta vehiculo"<<endl;
cout<<"2)Buscar vehiculo"<<endl;
cout<<"3)Listar vehiculo"<<endl;
cout<<"4)Dar de baja vehiculo"<<endl;
cout<<"5)Modificar vehiculo"<<endl;
cout<<"0)Salir"<<endl;
cin>>opcion;
switch(opcion){
case 1:
    system("cls");
    obj.darAltaAuto();
    break;

case 2:
    system("cls");
    obj.buscarAuto();
    break;

case 3:
    system("cls");
    obj.listarAutos();
    break;

case 4:
    system("cls");
    obj.bajaAuto();
    break;

case 5:
    system("cls");
    menuModificarAuto();
    break;

case 0:
    system("cls");
    return;
    break;
}
}
}



void menuModificarAuto(){
int opcion;
ArchivoAuto obj;
while(true){
cout<<"1)Modificar todos los datos"<<endl;
cout<<"2)Modificar nombre"<<endl;
cout<<"3)Modificar marca"<<endl;
cout<<"4)Modificar modelo"<<endl;
cout<<"5)Modificar precio"<<endl;
cout<<"0)Salir"<<endl;
cin>>opcion;
switch(opcion){
case 1:
    system("cls");
    obj.modificarAuto();
    break;

case 2:
    system("cls");
    obj.modificarMarca();
    break;

case 3:
    system("cls");
    obj.modificarModelo();
    break;

case 4:
    system("cls");
    obj.modificarPrecio();
    break;

case 5:
    system("cls");
    return;
    break;

case 0:
    return;
    break;
}
}
}

void menuVentas(){
int opcion;
ArchivoCabecera objC;
ArchivoDetalle objD;
while(true){
cout<<"1)Realizar una venta"<<endl;
cout<<"2)Buscar una factura"<<endl;
cout<<"3)Listar facturas"<<endl;
cout<<"0)Salir"<<endl;
cin>>opcion;
switch(opcion){
case 1:
    system("cls");
    cout<<"Factura"<<endl;
    objC.cabeceraVenta();
    objD.detalle();

case 2:
    system("cls");
    buscarFactura();
    break;

case 3:
    system("cls");
    listarFacturas();
    break;

case 0:
    system("cls");
    return;
    break;
}

}

}

void buscarFactura(){
ArchivoCabecera obj;
ArchivoDetalle obj1;
int id;
cout<<"Ingrese el id de la factura que quiere buscar: ";
cin>>id;
obj.buscarCabecera(id);
obj1.buscarDetalle(id);

}

void listarFacturas() {
FILE *cabecera, *detalle;
cabecera = fopen("Cabecera.dat", "rb+");
if (cabecera == NULL) {
cout << "No ha sido posible abrir el archivo Cabecera.dat" << endl;
return;}

detalle = fopen("Detalle.dat", "rb");
if (detalle == NULL) {
cout << "No ha sido posible abrir el archivo Detalle.dat" << endl;
return;}
Cabecera obj;
DetalleVenta obj1;
int contador = 0;
while (fread(&obj, sizeof(Cabecera), 1, cabecera) != 0) {
contador++;
}
fseek(cabecera, 0, SEEK_SET);
for (int i = 0; i < contador; i++) {
fread(&obj, sizeof(Cabecera), 1, cabecera);
fseek(detalle, 0, SEEK_SET);
while (fread(&obj1, sizeof(DetalleVenta), 1, detalle) != 0) {
if (obj.getIdVenta() == obj1.getIdDetalle()) {
cout << endl;
cout << "Cabecera" << endl;
cout << "Fecha: " << obj.getDia() << "/" << obj.getMes() << "/" << obj.getAnio() << endl;
cout << "Id de la venta: " << obj.getIdVenta() << endl;
cout << "Datos del vendedor" << endl;
cout << "Id: " << obj.getIdVendedor() << endl;
cout << "Nombre: " << obj.getNombreV() << endl;
cout << "Correo: " << obj.getCorreoV() << endl;
cout << "Telefono: " << obj.getTelV() << endl;
cout << endl;
cout << "Datos del cliente" << endl;
cout << "Id: " << obj.getIdCliente() << endl;
cout << "Nombre: " << obj.getNombreC() << endl;
cout << "Correo: " << obj.getCorreoC() << endl;
cout << "Telefono: " << obj.getTelC() << endl;
cout << endl;
cout << "Detalle" << endl;
cout << "Datos del vehiculo" << endl;
cout << "Id: " << obj1.getIdAuto() << endl;
cout << "Nombre: " << obj1.getNombre() << endl;
cout << "Marca: " << obj1.getMarca() << endl;
cout << "Modelo: " << obj1.getModelo() << endl;
cout << "Precio: " << obj1.getPrecio() << endl;
}
}
}
system("pause");
system("cls");
fclose(cabecera);
fclose(detalle);
}


