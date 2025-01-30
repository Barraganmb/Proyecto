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
void buscarCliente();
void modificarCliente();
void modificarNombreCliente();
void modificarDNICliente();
void modificarTelefonoCliente();
void modificarCorreoCliente();

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
//cin.ignore();
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

void ArchivoCliente::buscarCliente(){
FILE* buscarCliente;
buscarCliente=fopen("cliente.dat","rb");
if(buscarCliente==NULL){
cout<<"No se logro abrir este archivo"<<endl;
return;
}
Cliente obj;
bool encontrado=false;
int idC;
cout<<"Ingrese el id que quiere buscar: ";
cin>>idC;
while(fread(&obj,sizeof(Cliente),1,buscarCliente)!=0){
if(obj.getIdCliente()==idC){
cout<<"Nombre: "<<obj.getNombreCliente()<<endl;
cout<<"D.N.I: "<<obj.getDniCliente()<<endl;
cout<<"Correo: "<<obj.getCorreoCliente()<<endl;
cout<<"Telefono: "<<obj.getTelefonoCliente()<<endl;
cout<<"Id: "<<obj.getIdCliente()<<endl;
encontrado=true;
}
}
if(!encontrado){
cout<<"No se encontro el id ingresado"<<endl;
return;
}
fclose(buscarCliente);
}

void ArchivoCliente::modificarCliente(){
FILE* modificarC;
modificarC=fopen("cliente.dat","rb+");
if(modificarC==NULL){
cout<<"No se ha logrado abrir este archivo"<<endl;
return;
}
Cliente obj;
int id,dni;
char nombre[35];
char correo[35];
char telefono[15];
bool encontrado=false;
cout<<"Ingrese el id del cliente a modificar: ";
cin>>id;
while(fread(&obj,sizeof(Cliente),1,modificarC)!=0){
if(obj.getIdCliente()==id){
cout<<"Ingrese los nuevos datos"<<endl;
cout<<"Nombre: ";
cin.ignore();
cin.getline(nombre,35,'\n');
obj.setNombreCliente(nombre);
cout<<"D.N.I: ";
cin>>dni;
obj.setDniCliente(dni);
cout<<"Correo: ";
cin.ignore();
cin.getline(correo,35,'\n');
obj.setCorreoCliente(correo);
cout<<"Telefono: ";
cin.ignore();
cin.getline(telefono,15,'\n');
obj.setTelefono(telefono);

long posicion=ftell(modificarC)- sizeof(Cliente);
fseek(modificarC, posicion, SEEK_SET);
fwrite(&obj, sizeof(Cliente), 1, modificarC);
cout<<"Los datos fueron modificados correctamente"<<endl;
encontrado=true;
fclose(modificarC);
return;
}
if(!encontrado){
cout<<"No se ha logrado modificar los datos del cliente"<<endl;
return;
}
}
}

void ArchivoCliente::modificarNombreCliente(){
FILE* nombreC;
nombreC=fopen("cliente.dat","rb+");
if( nombreC==NULL){
cout<<"No se logro abrir este archivo"<<endl;
return;
}
Cliente obj;
char nom[35];
int id;
bool encontrado=false;
cout<<"Ingrese el id del cliente a modificar: ";
cin>>id;
while(fread(&obj,sizeof(Cliente),1,nombreC)!=0){
if(obj.getIdCliente()==id){
cout<<"Nombre actual: "<<obj.getNombreCliente()<<endl;
cout<<"Nombre: ";
cin.ignore();
cin.getline(nom,35,'\n');
obj.setNombreCliente(nom);
long posicion=ftell(nombreC)- sizeof(Cliente);
fseek(nombreC, posicion, SEEK_SET);
fwrite(&obj, sizeof(Cliente), 1, nombreC);
cout<<"Se modifico el nombre correctamente"<<endl;
encontrado=true;
fclose(nombreC);
return;
}
}
if(!encontrado){
cout<<"No se ha logrado modificar el nombre"<<endl;
return;
}
}

void ArchivoCliente::modificarDNICliente(){
FILE* dni;
dni=fopen("cliente.dat","rb+");
if(dni==NULL){
cout<<"No se logro abrir este archivo"<<endl;
return;
}
Cliente obj;
int d;
int id;
bool encontrado=false;
cout<<"Ingrese el id del cliente a modificar: ";
cin>>id;
while(fread(&obj,sizeof(Cliente),1,dni)!=0){
if(obj.getIdCliente()==id){
cout<<"D.N.I actual: "<<obj.getDniCliente();
cout<<"D.N.I: ";
cin.ignore();
cin>>d;
obj.setDniCliente(d);
long posicion=ftell(dni)- sizeof(Cliente);
fseek(dni, posicion, SEEK_SET);
fwrite(&obj, sizeof(Cliente), 1, dni);
cout<<"Se modifico el dni correctamente"<<endl;
encontrado=true;
fclose(dni);
return;
}
}
if(!encontrado){
cout<<"No se ha logrado modificar el dni"<<endl;
return;
}
}

void ArchivoCliente::modificarCorreoCliente(){
FILE* correo;
correo=fopen("cliente.dat","rb+");
if(correo==NULL){
cout<<"No se logro abrir este archivo"<<endl;
return;
}
Cliente obj;
char co[35];
int id;
bool encontrado=false;
cout<<"Ingrese el id del cliente a modificar: ";
cin>>id;
while(fread(&obj,sizeof(Cliente),1,correo)!=0){
if(obj.getIdCliente()==id){
cout<<"Correo actual: "<<obj.getCorreoCliente();
cout<<"Correo: ";
cin.ignore();
cin.getline(co,35,'\n');
obj.setCorreoCliente(co);
long posicion=ftell(correo)- sizeof(Cliente);
fseek(correo, posicion, SEEK_SET);
fwrite(&obj, sizeof(Cliente), 1, correo);
cout<<"Se modifico el correo correctamente"<<endl;
encontrado=true;
fclose(correo);
return;
}
}
if(!encontrado){
cout<<"No se ha logrado modificar el correo"<<endl;
return;
}
}

void ArchivoCliente::modificarTelefonoCliente(){
FILE* telefono;
telefono=fopen("cliente.dat","rb+");
if(telefono==NULL){
cout<<"No se logro abrir este archivo"<<endl;
return;
}
Cliente obj;
char tel[15];
int id;
bool encontrado=false;
cout<<"Ingrese el id del Cliente a modificar: ";
cin>>id;
while(fread(&obj,sizeof(Cliente),1,telefono)!=0){
if(obj.getIdCliente()==id){
cout<<"Telefono actual: "<<obj.getTelefonoCliente();
cout<<"Telefono: ";
cin.ignore();
cin.getline(tel,15,'\n');
obj.setTelefono(tel);
long posicion=ftell(telefono)- sizeof(Cliente);
fseek(telefono, posicion, SEEK_SET);
fwrite(&obj, sizeof(Cliente), 1, telefono);
cout<<"Se modifico el telefono correctamente"<<endl;
encontrado=true;
fclose(telefono);
return;
}
}
if(!encontrado){
cout<<"No se ha logrado modificar el telefono"<<endl;
return;
}
}

#endif // ARCHIVOCLIENTE_H_INCLUDED
