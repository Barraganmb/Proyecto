#ifndef ARCHIVOVENDEDOR_H_INCLUDED
#define ARCHIVOVENDEDOR_H_INCLUDED
#include "ClassVendedor.h"
#include <cstdio>
#include <cstring>
using namespace std;

class ArchivoVendedor{

public:
void darAlta();
void listarVendedores();
void iniciarSecion();
int idUnico();
void buscarVendedor(int idV);

};


void ArchivoVendedor::darAlta(){
FILE* alta;
alta=fopen("vendedor.dat", "ab");
if(alta==NULL){
cout<<"No se logro crear un nuevo archivo"<<endl;
return;
}
Vendedor obj;
char nombre[35];
int dni, id;
char telefono[15];
char correo[35];
char clave[20];
bool estado=false;

cout<<"Nombre completo: ";
cin.ignore();
cin.getline(nombre,35,'\n');
obj.setNombre(nombre);

cout<<"D.N.I: ";
cin>>dni;
obj.setDni(dni);

cout<<"Telefono: ";
cin.ignore();
cin.getline(telefono,15,'\n');
obj.setTelefono(telefono);

cout<<"Correo: ";
cin.ignore();
cin.getline(correo,35,'\n');
obj.setCorreo(correo);

cout<<"Clave: ";
cin.ignore();
cin.getline(clave,20,'\n');
obj.setClave(clave);

estado=true;
obj.setEstado(estado);

id=idUnico();
cout<<"Su id asignado es: "<<id<<endl;
obj.setId(id);
fwrite(&obj,sizeof(Vendedor),1,alta);
fclose(alta);

}

void ArchivoVendedor::listarVendedores(){
FILE* listar;
listar=fopen("vendedor.dat","rb");
if(listar==NULL){
cout<<"No se logro abrir este archivo"<<endl;
return;
}
Vendedor obj;
while(fread(&obj,sizeof(Vendedor),1,listar)!=0){
if(obj.getEstadoVendedor()==true){
cout<<"Nombre: "<<obj.getNombre()<<endl;
cout<<"D.N.I: "<<obj.getDni()<<endl;
cout<<"Telefono; "<<obj.getTelefono()<<endl;
cout<<"Correo: "<<obj.getCorreo()<<endl;
cout<<"Id: "<<obj.getId()<<endl;
}
fclose(listar);
cout<<endl;
system("pause");
system("cls");
}
}


void ArchivoVendedor::iniciarSecion(){
FILE* iniciar;
iniciar=fopen("vendedor.dat","rb");
if(iniciar==NULL){
cout<<"NO se logro abrir este archivo"<<endl;
return;
}
Vendedor obj;
char correo[35];
char clave[20];

cout<<"Ingrese su correo: ";
cin.ignore();
cin.getline(correo,35,'\n');

cout<<"Ingrese su clave: ";
cin.ignore();
cin.getline(clave,20,'\n');

while(fread(&obj,sizeof (Vendedor),1,iniciar)!=0){
if(obj.getCorreo()==correo&&obj.getClave()==clave){
cout<<"inicio exitoso"<<endl;
fclose(iniciar);
}
else{
cout<<"No se encontraron los datos"<<endl;
}
}

}


int ArchivoVendedor::idUnico(){
FILE* idV;
idV=fopen("vendedor.dat","rb+");
if(idV==NULL){
cout<<"No se logro abrir este archivo"<<endl;
return 0;
}
int idVendedor=0;
Vendedor obj;
while(fread(&obj,sizeof(Vendedor),1,idV)!=0){
idVendedor++;
}
fclose(idV);
return idVendedor+1;
}

void ArchivoVendedor::buscarVendedor(int idV){
FILE* buscarV;
buscarV=fopen("vendedor.dat","rb");
if(buscarV==NULL){
cout<<"No se logro abrir este archivo"<<endl;
return;
}
Vendedor obj;
bool encontrado=false;
while(fread(&obj,sizeof(Vendedor),1,buscarV)!=0){
if(obj.getId()==idV&&obj.getEstadoVendedor()==true){
cout<<"Nombre: "<<obj.getNombre()<<endl;
cout<<"D.N.I: "<<obj.getDni()<<endl;
cout<<"Correo: "<<obj.getCorreo()<<endl;
cout<<"Telefono: "<<obj.getTelefono()<<endl;
cout<<"Id: "<<obj.getId()<<endl;
encontrado=true;
}
}
if(!encontrado){
cout<<"El id ingresado no ha sido encontrado"<<endl;
return;
}
fclose(buscarV);
}
#endif // ARCHIVOVENDEDOR_H_INCLUDED
