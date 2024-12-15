#ifndef ARCHIVOVENDEDOR_H_INCLUDED
#define ARCHIVOVENDEDOR_H_INCLUDED
#include "ClassVendedor.h"

#include <cstdio>
#include <cstring>
using namespace std;

class ArchivoVendedor{

public:
void darAlta();
void buscarId(int idV);
void listarVendedores();

};

void ArchivoVendedor::buscarId(int idV){
FILE* buscar;
buscar=fopen("vendedor.dat","rb");
if(buscar==NULL){
cout<<"No se pudo abrir este archivo"<<endl;
return;
}
Vendedor obj;
bool encontrado=false;

while(fread(&obj,sizeof(Vendedor),1,buscar)!=0){
if(obj.getId()==idV){
cout<<"Id encontrado"<<endl;
fclose(buscar);
encontrado=true;
}
if(!encontrado){
cout<<"No se encontro este id"<<endl;
}
fclose(buscar);
}

}


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
cout<<"Nombre: "<<obj.getNombre()<<endl;
cout<<"D.N.I: "<<obj.getDni()<<endl;
cout<<"Telefono; "<<obj.getTelefono()<<endl;
cout<<"Correo: "<<obj.getCorreo()<<endl;
fclose(listar);
}

}
#endif // ARCHIVOVENDEDOR_H_INCLUDED
