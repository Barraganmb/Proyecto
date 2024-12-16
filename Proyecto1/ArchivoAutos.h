#ifndef ARCHIVOAUTOS_H_INCLUDED
#define ARCHIVOAUTOS_H_INCLUDED
#include "ClassAuto.h"
class ArchivoAuto{
public:
void darAltaAuto();

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

fwrite(&obj,sizeof(Auto),1,altaAuto);
fclose(altaAuto);

}

#endif // ARCHIVOAUTOS_H_INCLUDED
