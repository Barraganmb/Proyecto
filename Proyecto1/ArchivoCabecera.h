#ifndef ARCHIVOCABECERA_H_INCLUDED
#define ARCHIVOCABECERA_H_INCLUDED
#include "ClassCliente.h"
#include "ClassVendedor.h"
class ArchivoCabecera{
public:
void cabeceraVenta();
int idVenta();
};


void ArchivoCabecera::cabeceraVenta(){
FILE *cabeceraV, vendedor, cliente;
cabeceraV=fopen("Cabecera.dat","rb");
if(cabeceraV==NULL){
cout<<"No se logro abrir este archivo"<<endl;
return 0;
}

vendedor=fopen("vendedor.dat","rb");
if(vendedor==NULL){
cout<<"No se logro abrir este archivo"<<endl;
return 0;
}

cliente=fopen("cliente.dat","rb");
if(cliente==NULL){
cout<<"No se logro abrir este archivo"<<endl;
return 0;
}
ArchivoCabecera obj1;
Cabecera obj;
Cliente objC;
Vendedor objV;
int id,idC, telV, telc;
char nomV[30];
char nomC[30];
char correoV[30];
char correoC[30];
cout<<"Cabecera de la venta"<<endl;
cout<<"Ingrese el id del vendedor que realizo la venta: ";
cin>>id;
while(fread(&objV,sizeof(Vendedor),1,id)!=0){
if(objV.idUnico()==id){
cout<<"Nombre: "<<objV.getNombre()<<endl;
cout<<"Correo: "<<objV.getCorreo()<<endl;
cout<<"Telefono: "<<objV.getTelefono()<<endl;
}
}
cout<<"Ingrese el id del cliente que realizo la compra: ";
cin>>idC;
while(fread(&objC,sizeof(Cliente),1,idC)!=0){
if(objC.getIdCliente()==idC){
cout<<"Nombre: "<<objC.getNombreCliente()<<endl;
cout<<"Correo: "<<objC.getCorreoCliente()<<endl;
cout<<"Telefono: "<<objC.getTelefonoCliente()<<endl;
}
}
obj.setIdVenta(obj1.idVenta());
cout<<"EL id de esta venta es: "<<obj.getIdVenta()<<endl;
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


#endif // ARCHIVOCABECERA_H_INCLUDED
