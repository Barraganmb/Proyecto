#ifndef ARCHIVOAUTOS_H_INCLUDED
#define ARCHIVOAUTOS_H_INCLUDED
#include "ClassAuto.h"
class ArchivoAuto{
public:
void darAltaAuto();
void listarAutos();
int idAuto();
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
cin.ignore();
cin.getline(marca,30,'\n');
obj.setMarca(marca);

cout<<"Modelo: ";
cin.ignore();
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
fclose(listarA);
}
}

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
#endif // ARCHIVOAUTOS_H_INCLUDED
