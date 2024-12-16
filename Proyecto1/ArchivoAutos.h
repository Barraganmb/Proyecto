#ifndef ARCHIVOAUTOS_H_INCLUDED
#define ARCHIVOAUTOS_H_INCLUDED
#include "ClassAuto.h"
class ArchivoAuto{
public:
void darAltaAuto();
void listarAutos();
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

#endif // ARCHIVOAUTOS_H_INCLUDED
