#ifndef ARCHIVOCLIENTE_H_INCLUDED
#define ARCHIVOCLIENTE_H_INCLUDED
#include "ClassCliente.h"
#include <cstdio>
#include <cstring>
using namespace std;

class ArchivoCliente{
public:
void darAltaCliente();
void listarClientes();
int idCliente();

};

void ArchivoCliente::darAltaCliente(){
FILE *altaCliente;
altaCliente=fopen("cliente.dat","ab+");
if(altaCliente==NULL){
cout<<"No se logro crea un nuevo archivo"<<endl;
return;
}

Cliente obj;
char nombre[35];
int dni, id;
char telefono[15];
char correo[35];

cout<<"Cliente"<<endl;
cout<<"Nombre completo: ";
cin.ignore();
cin.getline(nombre,35,'\n');
obj.setNombreCliente(nombre);

cout<<"D.N.I: ";
cin>>dni;
obj.setDniCliente(dni);

cout<<"Telefono: ";
cin.ignore();
cin.getline(telefono,15,'\n');
obj.setTelefono(telefono);

cout<<"Correo: ";
cin.ignore();
cin.getline(correo,35,'\n');
obj.setCorreoCliente(correo);

id=idCliente();
cout<<"Id asignado: "<<id<<endl;
obj.setIdCliente(id);

fwrite(&obj,sizeof(Cliente),1,altaCliente);
fclose(altaCliente);
}

void ArchivoCliente::listarClientes(){
FILE* listar;
listar=fopen("cliente.dat","rb");
if(listar==NULL){
cout<<"NO se logro abrir este archivo"<<endl;
return;
}
Cliente obj;
while(fread(&obj,sizeof(Cliente),1,listar)!=0){
cout<<"Nombre: "<<obj.getNombreCliente()<<endl;
cout<<"D.N.I: "<<obj.getDniCliente()<<endl;
cout<<"Telefono: "<<obj.getTelefonoCliente()<<endl;
cout<<"Correo: "<<obj.getCorreoCliente()<<endl;
cout<<"Id: "<<obj.getIdCliente()<<endl;
}
fclose(listar);
cout<<endl;
system("pause");
system("cls");
}

int ArchivoCliente::idCliente(){
FILE* idC;
idC=fopen("cliente.dat","rb+");
if(idC==NULL){
cout<<"No se logro abrir este archivo"<<endl;
return 0;
}
int idCliente=0;
Cliente obj;
while(fread(&obj,sizeof(Cliente),1,idC)!=0){
idCliente++;
}
fclose(idC);
return idCliente+1;
}

#endif // ARCHIVOCLIENTE_H_INCLUDED
