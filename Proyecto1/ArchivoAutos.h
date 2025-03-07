#ifndef ARCHIVOAUTOS_H_INCLUDED
#define ARCHIVOAUTOS_H_INCLUDED
#include "ClassAuto.h"
class ArchivoAuto{
public:
void darAltaAuto();
void listarAutos();
int idAuto();
void buscarAuto();
void bajaAuto();
void modificarAuto();
void modificarNombre();
void modificarMarca();
void modificarModelo();
void modificarPrecio();
};

void ArchivoAuto::darAltaAuto(){
FILE* altaAuto;
altaAuto=fopen("autos.dat","ab");
if(altaAuto==NULL){
cout<<"No se pudo abrir este archivo"<<endl;
return;
}
Auto obj;
char nombre[30];
char modelo[30];
char marca[30];
float precio;
int id;
bool estado=false;
cout<<"Nombre: ";
cin.ignore();
cin.getline(nombre,30, '\n');
obj.setNombre(nombre);

cout<<"Marca: ";
//cin.ignore();
cin.getline(marca,30,'\n');
obj.setMarca(marca);

cout<<"Modelo: ";
//cin.ignore();
cin.getline(modelo,30,'\n');
obj.setModelo(modelo);

cout<<"Precio: ";
cin>>precio;
obj.setPrecio(precio);

estado=true;
obj.setEstadoA(estado);

id=idAuto();
cout<<"El id asignado es: "<<id<<endl;
obj.setId(id);

fwrite(&obj,sizeof(Auto),1,altaAuto);
fclose(altaAuto);
system("pause");
system("cls");
}


void ArchivoAuto::listarAutos(){
FILE* listarA;
listarA=fopen("autos.dat","rb");
if(listarA==NULL){
cout<<"No se logro abrir este archivo"<<endl;
return;
}
Auto objA;

while(fread(&objA,sizeof(Auto),1,listarA)!=0){
if(objA.getEstado()==true){
cout<<"Nombre: "<<objA.getNombre()<<endl;
cout<<"Marca: "<<objA.getMarca()<<endl;
cout<<"Modelo: "<<objA.getModelo()<<endl;
cout<<"Precio: "<<objA.getPrecio()<<endl;
cout<<"Id: "<<objA.getIdAuto()<<endl;
}
}
fclose(listarA);
system("pause");
system("cls");
}


int ArchivoAuto::idAuto(){
FILE* idA;
idA=fopen("autos.dat","rb+");
if(idA==NULL){
cout<<"No se logro abrir este archivo"<<endl;
return 0;
}
int idAuto=0;
Auto obj;
while(fread(&obj,sizeof(Auto),1,idA)!=0){
idAuto++;
}
fclose(idA);
return idAuto+1;
}

void ArchivoAuto::buscarAuto(){
FILE* buscarAuto;
buscarAuto=fopen("autos.dat","rb");
if(buscarAuto==NULL){
cout<<"No se logro abrir este archivo"<<endl;
return;
}
Auto obj;
int idA;
cout<<"Ingrese el id del vehiculo que quiere buscar: ";
cin>>idA;
bool encontrado=false;
while(fread(&obj,sizeof(Auto),1,buscarAuto)!=0){
if(obj.getIdAuto()==idA&&obj.getEstado()==true){
cout<<"Nombre: "<<obj.getNombre()<<endl;
cout<<"Marca: "<<obj.getMarca()<<endl;
cout<<"Modelo: "<<obj.getModelo()<<endl;
cout<<"Precio: "<<obj.getPrecio()<<endl;
cout<<"Id: "<<obj.getIdAuto()<<endl;
encontrado=true;
}
}
if(!encontrado){
cout<<"No se encontro el id ingresado"<<endl;
return;
}
system("pause");
system("cls");
fclose(buscarAuto);
}

void ArchivoAuto::bajaAuto(){
FILE* bajaA;
bajaA=fopen("autos.dat","rb+");
if(bajaA==NULL){
cout<<"No se logro abrir este archivo"<<endl;
return;
}
Auto obj;
int id;
bool encontrado=false;
cout<<"Ingrese el id del auto a dar de baja: ";
cin>>id;
while(fread(&obj,sizeof(Auto),1,bajaA)!=0){
if(obj.getIdAuto()&&obj.getEstado()==true){
cout<<"Nombre: "<<obj.getNombre()<<endl;
cout<<"Marca: "<<obj.getMarca()<<endl;
cout<<"Modelo; "<<obj.getModelo()<<endl;
cout<<"Precio: "<<obj.getPrecio()<<endl;
obj.setEstadoA(false);
encontrado=true;
long posicion=ftell(bajaA)- sizeof(Auto);
fseek(bajaA, posicion, SEEK_SET);
fwrite(&obj, sizeof(Auto), 1, bajaA);
cout<<"Auto dado de baja correctamente"<<endl;
fclose(bajaA);
return;
}
}
if(!encontrado){
cout<<"No se logro dar de baja el id del auto ingresado"<<endl;
return;
}
}


void ArchivoAuto::modificarAuto(){
FILE* modificarA;
modificarA=fopen("autos.dat","rb+");
if(modificarA==NULL){
cout<<"No se ha logrado abrir este archivo"<<endl;
return;
}
Auto obj;
int id;
float precio;
char nomA[30];
char marca[30];
char modelo[30];
bool modificado=false;
cout<<"Ingrese el id del auto a modificar: ";
cin.ignore();
cin>>id;
while(fread(&obj,sizeof(Auto),1,modificarA)!=0){
if(obj.getIdAuto()==id&&obj.getEstado()==true){
cout<<"Nombre actual: "<<obj.getNombre()<<endl;
cout<<"Nombre: ";
cin.ignore();
cin.getline(nomA,30,'\n');
obj.setNombre(nomA);
cout<<"Marca Actual: "<<obj.getMarca()<<endl;
cout<<"Marca: ";
cin.ignore();
cin.getline(marca,30,'\n');
obj.setMarca(marca);
cout<<"Modelo actual: "<<obj.getModelo()<<endl;
cout<<"Modelo: ";
cin.ignore();
cin.getline(modelo,30,'\n');
obj.setModelo(modelo);
cout<<"Precio actual: "<<obj.getPrecio()<<endl;
cout<<"Precio: ";
cin.ignore();
cin>>precio;
obj.setPrecio(precio);
modificado=true;
long posicion=ftell(modificarA)- sizeof(Auto);
fseek(modificarA, posicion, SEEK_SET);
fwrite(&obj, sizeof(Auto), 1, modificarA);
cout<<"Se modificaron los datos correctamente"<<endl;
fclose(modificarA);
return;
}
}
if(!modificado){
cout<<"Los datos no fueron modificados correctamente"<<endl;
return;
}
}

void ArchivoAuto::modificarNombre(){
FILE* nombreAuto;
nombreAuto=fopen("autos.dat","rb+");
if(nombreAuto==NULL){
cout<<"No se pudo abrir este archivo"<<endl;
return;
}
Auto obj;
char nombre[30];
int id;
bool modificado=false;
cout<<"Ingrese el id del auto a modificar: ";
cin.ignore();
cin>>id;
while(fread(&obj,sizeof(Auto),1,nombreAuto)!=0){
if(obj.getIdAuto()==id){
cout<<"Nombre actual: "<<obj.getNombre()<<endl;
cout<<"Nombre: ";
cin.ignore();
cin.getline(nombre,30,'\n');
obj.setNombre(nombre);
modificado=true;
long posicion=ftell(nombreAuto)- sizeof(Auto);
fseek(nombreAuto, posicion, SEEK_SET);
fwrite(&obj, sizeof(Auto), 1, nombreAuto);
cout<<"Nombre modificado correctamente"<<endl;
fclose(nombreAuto);
return;
}
}
if(!modificado){
cout<<"No se ha logrado modificar el nombre de este auto"<<endl;
return;
}
}


void ArchivoAuto::modificarMarca(){
FILE* marca;
marca=fopen("autos.dat","rb+");
if(marca==NULL){
cout<<"No se pudo abrir este archivo"<<endl;
return;
}
Auto obj;
char marcaA[30];
int id;
bool modificado=false;
cout<<"Ingrese el id del auto a modificar: ";
cin.ignore();
cin>>id;
while(fread(&obj,sizeof(Auto),1,marca)!=0){
if(obj.getIdAuto()==id){
cout<<"Marca actual: "<<obj.getMarca()<<endl;
cout<<"marca: ";
cin.ignore();
cin.getline(marcaA,30,'\n');
obj.setMarca(marcaA);
modificado=true;
long posicion=ftell(marca)- sizeof(Auto);
fseek(marca, posicion, SEEK_SET);
fwrite(&obj, sizeof(Auto), 1, marca);
cout<<"Marca modificada correctamente"<<endl;
fclose(marca);
return;
}
}
if(!modificado){
cout<<"No se ha logrado modificar la marca de este auto"<<endl;
return;
}
}


void ArchivoAuto::modificarModelo(){
FILE* modelo;
modelo=fopen("autos.dat","rb+");
if(modelo==NULL){
cout<<"No se pudo abrir este archivo"<<endl;
return;
}
Auto obj;
char mod[30];
int id;
bool modificado=false;
cout<<"Ingrese el id del auto a modificar: ";
cin.ignore();
cin>>id;
while(fread(&obj,sizeof(Auto),1,modelo)!=0){
if(obj.getIdAuto()==id){
cout<<"Modelo actual: "<<obj.getModelo()<<endl;
cout<<"Modelo: ";
cin.ignore();
cin.getline(mod,30,'\n');
obj.setModelo(mod);
modificado=true;
long posicion=ftell(modelo)- sizeof(Auto);
fseek(modelo, posicion, SEEK_SET);
fwrite(&obj, sizeof(Auto), 1, modelo);
cout<<"Modelo modificado correctamente"<<endl;
fclose(modelo);
return;
}
}
if(!modificado){
cout<<"No se ha logrado modificar el modelo de este auto"<<endl;
return;
}
}


void ArchivoAuto::modificarPrecio(){
FILE* precio;
precio=fopen("autos.dat","rb+");
if(precio==NULL){
cout<<"No se pudo abrir este archivo"<<endl;
return;
}
Auto obj;
float pr;
int id;
bool modificado=false;
cout<<"Ingrese el id del auto a modificar: ";
cin.ignore();
cin>>id;
while(fread(&obj,sizeof(Auto),1,precio)!=0){
if(obj.getIdAuto()==id){
cout<<"Precio actual: "<<obj.getPrecio()<<endl;
cout<<"Precio: ";
cin.ignore();
cin>>pr;
obj.setPrecio(pr);
modificado=true;
long posicion=ftell(precio)- sizeof(Auto);
fseek(precio, posicion, SEEK_SET);
fwrite(&obj, sizeof(Auto), 1, precio);
cout<<"Precio modificado correctamente"<<endl;
fclose(precio);
return;
}
}
if(!modificado){
cout<<"No se ha logrado modificar el precio de este auto"<<endl;
return;
}
}
#endif // ARCHIVOAUTOS_H_INCLUDED
