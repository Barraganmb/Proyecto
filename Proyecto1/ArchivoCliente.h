#ifndef ARCHIVOCLIENTE_H_INCLUDED
#define ARCHIVOCLIENTE_H_INCLUDED
#include "ClassCliente.h"
#include <cstdio>
#include <cstring>
using namespace std;

class ArchivoCliente{
public:
void darAltaCliente();

};

void ArchivoCliente::darAltaCliente(){
FILE* altaCliente;
altaCliente=fopen("cliente.dat","ab");
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

fwrite(&obj,sizeof(Cliente),1,altaCliente);
fclose(altaCliente);
}

#endif // ARCHIVOCLIENTE_H_INCLUDED
