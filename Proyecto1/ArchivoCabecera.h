#ifndef ARCHIVOCABECERA_H_INCLUDED
#define ARCHIVOCABECERA_H_INCLUDED
#include "ClassCliente.h"
#include "ClassVendedor.h"
#include "ClassCabecera.h"
class ArchivoCabecera{
public:
void cabeceraVenta();
int idVenta();
void listarCabeceras();
void buscarCabecera(int id);
};


void ArchivoCabecera::cabeceraVenta(){
FILE *cabeceraV, *vendedor, *cliente;
cabeceraV=fopen("Cabecera.dat","ab");
if(cabeceraV==NULL){
cout<<"No se logro abrir este archivo"<<endl;
return ;
}

vendedor=fopen("vendedor.dat","rb");
if(vendedor==NULL){
cout<<"No se logro abrir este archivo"<<endl;
return ;
}

cliente=fopen("cliente.dat","rb");
if(cliente==NULL){
cout<<"No se logro abrir este archivo"<<endl;
return ;
}
ArchivoCabecera obj1;
Cabecera obj;
Cliente objC;
Vendedor objV;
int id,idC,d,m,a, contador=0;
char telc[15];
char telV[15];
char nomV[30];
char nomC[30];
char correoV[30];
char correoC[30];

cout<<"Cabecera de la venta"<<endl;
cout<<"Ingrese la fecha"<<endl;
cout<<"Dia: ";
cin>>d;
cout<<"Mes: ";
cin>>m;
cout<<"Anio: ";
cin>>a;
cout<<"Ingrese el id del vendedor que realizo la venta: ";
cin>>id;
while(fread(&objV,sizeof(Vendedor),1,vendedor)!=0){
if(objV.getId()==id){
cout<<"Nombre: "<<objV.getNombre()<<endl;
strcpy(nomV,objV.getNombre());
obj.setNombreV(nomV);
cout<<"Correo: "<<objV.getCorreo()<<endl;
strcpy(correoV, objV.getCorreo());
obj.setCorreoV(correoV);
cout<<"Telefono: "<<objV.getTelefono()<<endl;
strcpy(telV,objV.getTelefono());
obj.setTelV(telV);
obj.setIdVendedor(id);
}
}
cout<<"Ingrese el id del cliente que realizo la compra: ";
cin>>idC;
while(fread(&objC,sizeof(Cliente),1,cliente)!=0){
if(objC.getIdCliente()==idC){
cout<<"Nombre: "<<objC.getNombreCliente()<<endl;
strcpy(nomC,objC.getNombreCliente());
obj.setNombreC(nomC);
cout<<"Correo: "<<objC.getCorreoCliente()<<endl;
strcpy(correoC,objC.getCorreoCliente());
obj.setCorreoC(correoC);
cout<<"Telefono: "<<objC.getTelefonoCliente()<<endl;
strcpy(telc,objC.getTelefonoCliente());
obj.setTelC(telc);
obj.setIdCliente(idC);
}
}
obj.setIdVenta(obj1.idVenta());
cout<<"EL id de esta venta es: "<<obj.getIdVenta()<<endl;
obj.setDia(d);
obj.setMes(m);
obj.setAnio(a);
fwrite(&obj,sizeof(Cabecera),1,cabeceraV);
contador+=1;
obj.setContador(contador);
fclose(cabeceraV);
fclose(cliente);
fclose(vendedor);
}


int ArchivoCabecera::idVenta(){
FILE* idC;
idC=fopen("Cabecera.dat","rb+");
if(idC==NULL){
cout<<"No se logro abrir este archivo"<<endl;
return 0;
}
int idVenta=0;
Cabecera obj;
while(fread(&obj,sizeof(Cabecera),1,idC)!=0){
idVenta++;
}
fclose(idC);
return idVenta+1;
}

void ArchivoCabecera::listarCabeceras(){
FILE* listar;
listar=fopen("Cabecera.dat","rb");
if(listar==NULL){
cout<<"No se logro abrir este archivo"<<endl;
return;
}
Cabecera obj;
while(fread(&obj,sizeof(Cabecera),1,listar)!=0){
cout<<"Id de la venta: "<<obj.getIdVenta()<<endl;
cout<<"Fecha: "<<obj.getDia()<<"/"<<obj.getMes()<<"/"<<obj.getAnio()<<endl;
cout<<endl;
cout<<"Datos del vendedor"<<endl;
cout<<endl;
cout<<"Id: "<<obj.getIdVendedor()<<endl;
cout<<"Nombre: "<<obj.getNombreV()<<endl;
cout<<"Correo: "<<obj.getCorreoV()<<endl;
cout<<"Telefono: "<<obj.getTelV()<<endl;
cout<<endl;
cout<<"Datos del cliente"<<endl;
cout<<endl;
cout<<"Id: "<<obj.getIdCliente()<<endl;
cout<<"Nombre: "<<obj.getNombreC()<<endl;
cout<<"Correo: "<<obj.getCorreoC()<<endl;
cout<<"Telefono: "<<obj.getTelC()<<endl;
}
fclose(listar);
}

void ArchivoCabecera::buscarCabecera(int id){
FILE* cabecera;
cabecera=fopen("Cabecera.dat","rb");
if(cabecera==NULL){
cout<<"No se ha logrado abrir este archivo"<<endl;
return;
}
Cabecera obj;
while(fread(&obj,sizeof(Cabecera),1,cabecera)!=0){
if(obj.getIdVenta()==id){
cout<<"Fecha: "<<obj.getDia()<<"/"<<obj.getMes()<<"/"<<obj.getAnio()<<endl;
cout<<endl;
cout<<"Datos del vendedor"<<endl;
cout<<endl;
cout<<"Id: "<<obj.getIdVendedor()<<endl;
cout<<"Nombre: "<<obj.getNombreV()<<endl;
cout<<"Correo: "<<obj.getCorreoV()<<endl;
cout<<"Telefono: "<<obj.getTelV()<<endl;
cout<<endl;
cout<<"Datos del cliente"<<endl;
cout<<endl;
cout<<"Id: "<<obj.getIdCliente()<<endl;
cout<<"Nombre: "<<obj.getNombreC()<<endl;
cout<<"Correo: "<<obj.getCorreoC()<<endl;
cout<<"Telefono: "<<obj.getTelC()<<endl;
}
}
fclose(cabecera);
system("pause");
system("cls");
}
#endif // ARCHIVOCABECERA_H_INCLUDED
