#ifndef ARCHIVODETALLE_H_INCLUDED
#define ARCHIVODETALLE_H_INCLUDED
#include "ClassDetalle.h"
#include "ArchivoAutos.h"
class ArchivoDetalle{
public:
void detalle();
int idDetalle();
void listarDetalle();
};

void ArchivoDetalle::detalle(){
FILE* detalle, *vehiculo;
detalle=fopen("Detalle.dat","ab");
if(detalle==NULL){
cout<<"No se ha logrado abrir este archivo"<<endl;
return;
}
vehiculo=fopen("autos.dat","rb");
if(vehiculo==NULL){
cout<<"No se ha logrado abrir este archivo"<<endl;
return;
}

DetalleVenta obj;
Auto obj1;
ArchivoDetalle obj2;
char nom[30];
char marca[30];
char modelo[30];
int idA, idD;
float precio;

cout<<"Detalle de la venta"<<endl;
cout<<endl;
cout<<"Ingrese el id del vehiculo: ";
cin>>idA;
while(fread(&obj1,sizeof(Auto),1,vehiculo)!=0){
if(obj1.getIdAuto()==idA){
cout<<"Datos del vehiculo"<<endl;
cout<<"Nombre: "<<obj1.getNombre()<<endl;
strcpy(nom,obj1.getNombre());
obj.setNombreA(nom);
cout<<"Marca: "<<obj1.getMarca()<<endl;
strcpy(marca,obj1.getMarca());
obj.setMarca(marca);
cout<<"Modelo: "<<obj1.getModelo()<<endl;
strcpy(modelo, obj1.getModelo());
obj.setModelo(modelo);
cout<<"Precio: "<<obj1.getPrecio();
precio=obj1.getPrecio();
obj.setPrecio(precio);
}
}
idD=obj2.idDetalle();
cout<<"EL DETALLE DE LA VENTA ES: "<<idD<<endl;
obj.setIdDetalle(idD);
obj.setIdAuto(idA);
system("pause");
fwrite(&obj,sizeof(DetalleVenta),1,detalle);
fclose(detalle);
fclose(vehiculo);
}


int ArchivoDetalle::idDetalle(){
FILE* idDetalle;
idDetalle=fopen("Detalle.dat","rb+");
if(idDetalle==NULL){
cout<<"No se logro abrir este archivo"<<endl;
return 0;
}
int idD=0;
DetalleVenta obj;
while(fread(&obj,sizeof(DetalleVenta),1,idDetalle)!=0){
idD++;
}
fclose(idDetalle);
return idD+1;
}

void ArchivoDetalle::listarDetalle(){
FILE *listar;
listar=fopen("Detalle.dat","rb");
if(listar==NULL){
cout<<"No se ha logrado abrir este archivo"<<endl;
return;
}
DetalleVenta obj;
cout<<"Detalle de la venta "<<endl;
while(fread(&obj,sizeof(DetalleVenta),1,listar)!=0){
cout<<"Datos del vehiculo"<<endl;
cout<<"Id: "<<obj.getIdAuto()<<endl;
cout<<"Nombre: "<<obj.getNombre()<<endl;
cout<<"Marca: "<<obj.getMarca()<<endl;
cout<<"Modelo: "<<obj.getModelo()<<endl;
cout<<"Precio: "<<obj.getPrecio()<<endl;
}
fclose(listar);
}

#endif // ARCHIVODETALLE_H_INCLUDED
