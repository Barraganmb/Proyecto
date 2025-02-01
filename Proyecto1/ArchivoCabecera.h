#ifndef ARCHIVOCABECERA_H_INCLUDED
#define ARCHIVOCABECERA_H_INCLUDED
#include "ClassCliente.h"
#include "ClassVendedor.h"
#include "ClassCabecera.h"
class ArchivoCabecera{
public:
void cabeceraVenta();
int idVenta();
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
int id,idC;
char telc[15];
char telV[15];
char nomV[30];
char nomC[30];
char correoV[30];
char correoC[30];
cout<<"Cabecera de la venta"<<endl;
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
obj.setTelC(telV);
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

fwrite(&obj,sizeof(Cabecera),1,cabeceraV);

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
