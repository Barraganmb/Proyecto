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
void buscarVendedor();
void darBaja();
void modificarVendedor();
void modificarNombre();
void modificarDni();
void modificarCorreo();
void modificarTelefono();
void modificarClave();
void recuperarClave();
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
//cin.ignore();
cin.getline(correo,35,'\n');
obj.setCorreo(correo);

cout<<"Clave: ";
cin.ignore();
cin.getline(clave,20,'\n');
obj.setClave(clave);
obj.setEstado(true);

id=idUnico();
cout<<"Su id asignado es: "<<id<<endl;
obj.setId(id);
fwrite(&obj,sizeof(Vendedor),1,alta);
fclose(alta);
system("pause");
system("cls");
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
}
fclose(listar);
system("pause");
system("cls");
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
bool encontrado=false;
cout<<"Ingrese su correo: ";
cin.ignore();
cin.getline(correo,35,'\n');

cout<<"Ingrese su clave: ";
cin.ignore();
cin.getline(clave,20,'\n');

while(fread(&obj,sizeof (Vendedor),1,iniciar)!=0){
if(strcmp(obj.getCorreo(),correo)==0&&strcmp(obj.getClave(),clave)==0){
cout<<"inicio exitoso"<<endl;
encontrado=true;
fclose(iniciar);
}
}
if(!encontrado){
cout<<"No se encontraron los datos"<<endl;
}
system("pause");
system("cls");
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

void ArchivoVendedor::buscarVendedor(){
FILE* buscarV;
buscarV=fopen("vendedor.dat","rb");
if(buscarV==NULL){
cout<<"No se logro abrir este archivo"<<endl;
return;
}
Vendedor obj;
int id;
bool encontrado=false;
cout<<"Ingrese el id que queire buscar: ";
cin>>id;
while(fread(&obj,sizeof(Vendedor),1,buscarV)!=0){
if(obj.getId()==id&&obj.getEstadoVendedor()==true){
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
system("pause");
system("cls");
}



void ArchivoVendedor::darBaja(){
FILE* baja;
baja=fopen("vendedor.dat","rb+");
if(baja==NULL){
cout<<"No se pudo abrir el archivo"<<endl;
return;
}
Vendedor obj;
int id;
bool encontrado=false;
cout<<"Ingrese el id a dar de baja: ";
cin>>id;
while(fread(&obj,sizeof(Vendedor),1,baja)!=0){
if(obj.getId()==id&&obj.getEstadoVendedor()==true){
cout<<"Nombre: "<<obj.getNombre()<<endl;
cout<<"D.N.I: "<<obj.getDni()<<endl;
cout<<"Correo: "<<obj.getCorreo()<<endl;
cout<<"Telefono: "<<obj.getTelefono()<<endl;
obj.setEstado(false);
encontrado=true;
long posicion=ftell(baja)- sizeof(Vendedor);
fseek(baja, posicion, SEEK_SET);
fwrite(&obj, sizeof(Vendedor), 1, baja);
cout<<"Vendedor dado de baja correctamente"<<endl;
}
}
if(!encontrado){
cout<<"No se ha logrado dar de baja el id ingresado"<<endl;
}
fclose(baja);
system("pause");
system("cls");
}

void ArchivoVendedor::modificarVendedor(){
FILE* modificar;
modificar=fopen("vendedor.dat","rb+");
if(modificar==NULL){
cout<<"No se ha logrado abrir este archivo"<<endl;
return;
}
Vendedor obj;
int id,dni;
char nombre[35];
char correo[35];
char telefono[15];
char clave[20];
cout<<"Ingrese el id del vendedor a modificar: ";
cin>>id;
while(fread(&obj,sizeof(Vendedor),1,modificar)!=0){
if(obj.getId()==id&&obj.getEstadoVendedor()==true){
cout<<"Ingrese los nuevos datos"<<endl;
cout<<"Nombre: ";
cin.ignore();
cin.getline(nombre,35,'\n');
obj.setNombre(nombre);
cout<<"D.N.I: ";
cin>>dni;
obj.setDni(dni);
cout<<"Correo: ";
cin.ignore();
cin.getline(correo,35,'\n');
obj.setCorreo(correo);
cout<<"Telefono: ";
cin.ignore();
cin.getline(telefono,15,'\n');
obj.setTelefono(telefono);
cout<<"Clave: ";
cin.ignore();
cin.getline(clave,20,'\n');
obj.setClave(clave);

long posicion=ftell(modificar)- sizeof(Vendedor);
fseek(modificar, posicion, SEEK_SET);
fwrite(&obj, sizeof(Vendedor), 1, modificar);
cout<<"Los datos fueron modificados correctamente"<<endl;
}
}
fclose(modificar);
system("pause");
system("cls");
}

void ArchivoVendedor::modificarNombre(){
FILE* nombre;
nombre=fopen("vendedor.dat","rb+");
if(nombre==NULL){
cout<<"No se logro abrir este archivo"<<endl;
return;
}
Vendedor obj;
char nom[35];
int id;
bool encontrado=false;
cout<<"Ingrese el id del vendedor a modificar: ";
cin>>id;
while(fread(&obj,sizeof(Vendedor),1,nombre)!=0){
if(obj.getId()==id&&obj.getEstadoVendedor()==true){
cout<<"Nombre actual: "<<obj.getNombre()<<endl;
cout<<"Nombre: ";
cin.ignore();
cin.getline(nom,35,'\n');
obj.setNombre(nom);
long posicion=ftell(nombre)- sizeof(Vendedor);
fseek(nombre, posicion, SEEK_SET);
fwrite(&obj, sizeof(Vendedor), 1, nombre);
cout<<"Se modifico el nombre correctamente"<<endl;
encontrado=true;
fclose(nombre);
return;
}
}
if(!encontrado){
cout<<"No se ha logrado modificar el nombre"<<endl;
}
system("pause");
system("cls");
}

void ArchivoVendedor::modificarDni(){
FILE* dni;
dni=fopen("vendedor.dat","rb+");
if(dni==NULL){
cout<<"No se logro abrir este archivo"<<endl;
return;
}
Vendedor obj;
int d;
int id;
bool encontrado=false;
cout<<"Ingrese el id del vendedor a modificar: ";
cin>>id;
while(fread(&obj,sizeof(Vendedor),1,dni)!=0){
if(obj.getId()==id&&obj.getEstadoVendedor()==true){
cout<<"D.N.I actual: "<<obj.getDni();
cout<<"D.N.I: ";
cin.ignore();
cin>>d;
obj.setDni(d);
long posicion=ftell(dni)- sizeof(Vendedor);
fseek(dni, posicion, SEEK_SET);
fwrite(&obj, sizeof(Vendedor), 1, dni);
cout<<"Se modifico el dni correctamente"<<endl;
encontrado=true;
return;
}
}
if(!encontrado){
cout<<"No se ha logrado modificar el dni"<<endl;
return;
}
fclose(dni);
system("pause");
system("cls");
}


void ArchivoVendedor::modificarCorreo(){
FILE* correo;
correo=fopen("vendedor.dat","rb+");
if(correo==NULL){
cout<<"No se logro abrir este archivo"<<endl;
return;
}
Vendedor obj;
char co[35];
int id;
bool encontrado=false;
cout<<"Ingrese el id del vendedor a modificar: ";
cin>>id;
while(fread(&obj,sizeof(Vendedor),1,correo)!=0){
if(obj.getId()==id&&obj.getEstadoVendedor()==true){
cout<<"Correo actual: "<<obj.getCorreo();
cout<<"Correo: ";
cin.ignore();
cin.getline(co,35,'\n');
obj.setCorreo(co);
long posicion=ftell(correo)- sizeof(Vendedor);
fseek(correo, posicion, SEEK_SET);
fwrite(&obj, sizeof(Vendedor), 1, correo);
cout<<"Se modifico el correo correctamente"<<endl;
encontrado=true;
return;
}
}
if(!encontrado){
cout<<"No se ha logrado modificar el correo"<<endl;
return;
}
fclose(correo);
system("pause");
system("cls");
}


void ArchivoVendedor::modificarTelefono(){
FILE* telefono;
telefono=fopen("vendedor.dat","rb+");
if(telefono==NULL){
cout<<"No se logro abrir este archivo"<<endl;
return;
}
Vendedor obj;
char tel[15];
int id;
bool encontrado=false;
cout<<"Ingrese el id del vendedor a modificar: ";
cin>>id;
while(fread(&obj,sizeof(Vendedor),1,telefono)!=0){
if(obj.getId()==id&&obj.getEstadoVendedor()==true){
cout<<"Telefono actual: "<<obj.getTelefono();
cout<<"Telefono: ";
cin.ignore();
cin.getline(tel,15,'\n');
obj.setTelefono(tel);
long posicion=ftell(telefono)- sizeof(Vendedor);
fseek(telefono, posicion, SEEK_SET);
fwrite(&obj, sizeof(Vendedor), 1, telefono);
cout<<"Se modifico el telefono correctamente"<<endl;
encontrado=true;
return;
}
}
if(!encontrado){
cout<<"No se ha logrado modificar el telefono"<<endl;
return;
}
fclose(telefono);
system("pause");
system("cls");
}


void ArchivoVendedor::modificarClave(){
FILE* clave;
clave=fopen("vendedor.dat","rb+");
if(clave==NULL){
cout<<"No se logro abrir este archivo"<<endl;
return;
}
Vendedor obj;
char cl[20];
int id;
bool encontrado=false;
cout<<"Ingrese el id del vendedor a modificar: ";
cin>>id;
while(fread(&obj,sizeof(Vendedor),1,clave)!=0){
if(obj.getId()==id&&obj.getEstadoVendedor()==true){
cout<<"Ingrese clave actual: ";
cin.ignore();
cin.getline(cl,20,'\n');
if(strcmp(obj.getClave(),cl)==0){
cout<<"Ingrese su nueva clave: ";
cin.ignore();
cin.getline(cl,20,'\n');
obj.setClave(cl);
long posicion=ftell(clave)- sizeof(Vendedor);
fseek(clave, posicion, SEEK_SET);
fwrite(&obj, sizeof(Vendedor), 1, clave);
cout<<"Se modifico la clave correctamente"<<endl;
encontrado=true;
return;
}
}
}
if(!encontrado){
cout<<"No se ha logrado modificar la clave"<<endl;
return;
}
fclose(clave);
system("pause");
system("cls");
}

void ArchivoVendedor::recuperarClave(){
FILE* recuperar;
recuperar=fopen("vendedor.dat","rb+");
if(recuperar==NULL){
cout<<"No se ha logrado abrir est archivo"<<endl;
return;
}
Vendedor obj;
char clave[20];
char correo[35];
int dni,id;
bool encontrado=false;
cout<<"RECUPERAR CLAVE"<<endl;
cout<<"Ingrese su id: ";
cin.ignore();
cin>>id;
while(fread(&obj,sizeof(Vendedor),1,recuperar)!=0){
if(obj.getId()==id&&obj.getEstadoVendedor()==true){
cout<<"Nombre: "<<obj.getNombre()<<endl;
cout<<"Ingrese su dni: ";
cin.ignore();
cin>>dni;
cout<<"Ingrese su correo: ";
cin.ignore();
cin.getline(correo,35,'\n');
if(obj.getDni()==dni&&strcmp(obj.getCorreo(),correo)==0){
cout<<"Ingrese su nueva clave: ";
cin.ignore();
cin.getline(clave,20,'\n');
obj.setClave(clave);
long posicion=ftell(recuperar)- sizeof(Vendedor);
fseek(recuperar, posicion, SEEK_SET);
fwrite(&obj, sizeof(Vendedor), 1, recuperar);
cout<<"La nueva clave fue modificada correctamente"<<endl;
encontrado=true;
}
}
}
if(!encontrado){
cout<<"No se ha logrado modificar la clave correctamente"<<endl;
}
fclose(recuperar);
system("pause");
system("cls");
}
#endif // ARCHIVOVENDEDOR_H_INCLUDED
