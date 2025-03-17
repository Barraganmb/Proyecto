#ifndef ARCHIVOVENDEDOR_H_INCLUDED
#define ARCHIVOVENDEDOR_H_INCLUDED
#include "ClassVendedor.h"
#include <cstdio>
#include <cstring>
#include "rlutil.h"
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

rlutil::locate(1,1);
cout<<"DATOS"<<endl;
rlutil::locate(1,3);
cout<<"Nombre completo: ";
cin.ignore();
cin.getline(nombre,35,'\n');
obj.setNombre(nombre);
rlutil::locate(1,5);
cout<<"D.N.I: ";
cin>>dni;
obj.setDni(dni);
rlutil::locate(1,7);
cout<<"Telefono: ";
cin.ignore();
cin.getline(telefono,15,'\n');
obj.setTelefono(telefono);
rlutil::locate(1,9);
cout<<"Correo: ";
//cin.ignore();
cin.getline(correo,35,'\n');
obj.setCorreo(correo);
rlutil::locate(1,11);
cout<<"Clave: ";
cin.ignore();
cin.getline(clave,20,'\n');
obj.setClave(clave);
obj.setEstado(true);

id=idUnico();
rlutil::locate(1,13);
cout<<"Su id asignado es: "<<id<<endl;
obj.setId(id);
rlutil::locate(1,15);
rlutil::setColor(rlutil::GREEN);
cout<<"Vendedor dado de alta correctamente"<<endl;
rlutil::setColor(rlutil::BLACK);
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
rlutil::locate(1,1);
cout<<"Nombre:"<<endl;
rlutil::locate(30,1);
cout<<"DNI: "<<endl;
rlutil::locate(50,1);
cout<<"Telefono: "<<endl;
rlutil::locate(70,1);
cout<<"Correo: "<<endl;
rlutil::locate(95,1);
cout<<"Id:"<<endl;
rlutil::locate(1,2);
cout<<"_____________________________________________________________________________________________________"<<endl;
int fila = 3;
int filas=0;
while(fread(&obj,sizeof(Vendedor),1,listar)!=0){
if(obj.getEstadoVendedor()==true){
rlutil::locate(1,fila);
cout<<obj.getNombre()<<endl;
rlutil::locate(30,fila);
cout<<obj.getDni()<<endl;
rlutil::locate(50,fila);
cout<<obj.getTelefono()<<endl;
rlutil::locate(70,fila);
cout<<obj.getCorreo()<<endl;
rlutil::locate(95,fila);
cout<<obj.getId()<<endl;
fila=fila+2;
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
int x=40, y=9, alto=7, ancho=40;
 rlutil::locate(x, y);
    std::cout << (char)201; // Esquina superior izquierda
    rlutil::locate(x + ancho, y);
    std::cout << (char)187; // Esquina superior derecha
    rlutil::locate(x, y + alto);
    std::cout << (char)200; // Esquina inferior izquierda
    rlutil::locate(x + ancho, y + alto);
    std::cout << (char)188; // Esquina inferior derec


for (int i = 1; i < ancho; i++) {
        rlutil::locate(x + i, y);
        std::cout << (char)205; // Línea superior
        rlutil::locate(x + i, y + alto);
        std::cout << (char)205; // Línea inferior
    }

    // Bordes verticales
    for (int i = 1; i < alto; i++) {
        rlutil::locate(x, y + i);
        std::cout << (char)186; // Línea izquierda
        rlutil::locate(x + ancho, y + i);
        std::cout << (char)186; // Línea derecha
    }





rlutil::locate(52,9);
cout<<"INICIAR SECCION"<<endl;
rlutil::locate(42,11);
cout<<"Ingrese su correo: ";
cin.ignore();
cin.getline(correo,35,'\n');
rlutil::locate(42,13);
cout<<"Ingrese su clave: ";
cin.ignore();
cin.getline(clave,20,'\n');

while(fread(&obj,sizeof (Vendedor),1,iniciar)!=0){
if(strcmp(obj.getCorreo(),correo)==0&&strcmp(obj.getClave(),clave)==0){
rlutil::setColor(rlutil::GREEN);
rlutil::locate(42,15);
cout<<"inicio exitoso"<<endl;
rlutil::setColor(rlutil::BLACK);
encontrado=true;
fclose(iniciar);
}
}
if(!encontrado){
rlutil::setColor(rlutil::RED);
rlutil::locate(42,15);
cout<<"No se encontraron los datos"<<endl;
rlutil::setColor(rlutil::BLACK);
}
rlutil::locate(42,25);
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
rlutil::locate(1,1);
cout<<"BUSCAR VENDEDOR"<<endl;
rlutil::locate(1,2);
cout<<"_______________________________________"<<endl;
rlutil::locate(1,3);
cout<<"Ingrese el id que queire buscar: ";
cin>>id;
while(fread(&obj,sizeof(Vendedor),1,buscarV)!=0){
if(obj.getId()==id&&obj.getEstadoVendedor()==true){
rlutil::locate(1,5);
cout<<"Nombre: "<<obj.getNombre()<<endl;
rlutil::locate(1,7);
cout<<"D.N.I: "<<obj.getDni()<<endl;
rlutil::locate(1,9);
cout<<"Correo: "<<obj.getCorreo()<<endl;
rlutil::locate(1,11);
cout<<"Telefono: "<<obj.getTelefono()<<endl;
rlutil::locate(1,13);
cout<<"Id: "<<obj.getId()<<endl;
encontrado=true;
}
}
if(!encontrado){
rlutil::setColor(rlutil::RED);
cout<<"El id ingresado no ha sido encontrado"<<endl;
return;
rlutil::setColor(rlutil::BLACK);
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
rlutil::locate(1,1);
cout<<"DAR DE BAJA VENDEDOR"<<endl;
cout<<"__________________________________"<<endl;
rlutil::locate(1,3);
cout<<"Ingrese el id a dar de baja: ";
cin>>id;
while(fread(&obj,sizeof(Vendedor),1,baja)!=0){
if(obj.getId()==id&&obj.getEstadoVendedor()==true){
rlutil::locate(1,5);
cout<<"Nombre: "<<obj.getNombre()<<endl;
rlutil::locate(1,7);
cout<<"D.N.I: "<<obj.getDni()<<endl;
rlutil::locate(1,9);
cout<<"Correo: "<<obj.getCorreo()<<endl;
rlutil::locate(1,11);
cout<<"Telefono: "<<obj.getTelefono()<<endl;
rlutil::locate(1,13);
obj.setEstado(false);
encontrado=true;
long posicion=ftell(baja)- sizeof(Vendedor);
fseek(baja, posicion, SEEK_SET);
fwrite(&obj, sizeof(Vendedor), 1, baja);
rlutil::setColor(rlutil::GREEN);
cout<<"Vendedor dado de baja correctamente"<<endl;
rlutil::setColor(rlutil::BLACK);
}
}
if(!encontrado){
rlutil::setColor(rlutil::RED);
cout<<"No se ha logrado dar de baja el id ingresado"<<endl;
rlutil::setColor(rlutil::BLACK);
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
cout<<"MODIFICAR VENDEDOR"<<endl;
cout<<"_____________________________________________"<<endl;
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
rlutil::setColor(rlutil::GREEN);
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
cout<<"MODIFICAR NOMBRE"<<endl;
cout<<"____________________________________________"<<endl;
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
rlutil::setColor(rlutil::GREEN);
cout<<"Se modifico el nombre correctamente"<<endl;
rlutil::setColor(rlutil::BLACK);
encontrado=true;
fclose(nombre);
return;
}
}
if(!encontrado){
rlutil::setColor(rlutil::RED);
cout<<"No se ha logrado modificar el nombre"<<endl;
rlutil::setColor(rlutil::BLACK);
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
cout<<"MODIFICAR DNI"<<endl;
cout<<"_______________________________________________"<<endl;
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
rlutil::setColor(rlutil::GREEN);
cout<<"Se modifico el dni correctamente"<<endl;
rlutil::setColor(rlutil::BLACK);
encontrado=true;
return;
}
}
if(!encontrado){
rlutil::setColor(rlutil::RED);
cout<<"No se ha logrado modificar el dni"<<endl;
rlutil::setColor(rlutil::BLACK);
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
cout<<"MODIFICAR CORREO"<<endl;
cout<<"___________________________________________"<<endl;
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
rlutil::setColor(rlutil::GREEN);
cout<<"Se modifico el correo correctamente"<<endl;
rlutil::setColor(rlutil::BLACK);
encontrado=true;
return;
}
}
if(!encontrado){
rlutil::setColor(rlutil::RED);
cout<<"No se ha logrado modificar el correo"<<endl;
rlutil::setColor(rlutil::BLACK);
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
cout<<"MODIFICAR TELEFONO"<<endl;
cout<<"____________________________________________"<<endl;
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
rlutil::setColor(rlutil::GREEN);
cout<<"Se modifico el telefono correctamente"<<endl;
rlutil::setColor(rlutil::BLACK);
encontrado=true;
return;
}
}
if(!encontrado){
rlutil::setColor(rlutil::RED);
cout<<"No se ha logrado modificar el telefono"<<endl;
rlutil::setColor(rlutil::BLACK);
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
