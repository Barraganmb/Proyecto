#ifndef CLASSVENDEDOR_H_INCLUDED
#define CLASSVENDEDOR_H_INCLUDED
#include <iostream>
#include <cstring>

class Vendedor{

private:
char nombre[35];
int dni;
char telefono[15];
char correo[35];
int id;
char clave[20];
bool estadoV;

public:
Vendedor(const char* n="XXX",int d=0,const char* t="1100000000",const char* c="vendedor@gmail.com",int i=0, const char* cv="12345678", bool eV=false){
strcpy(this->nombre, n);
this->dni = d;
strcpy(this->telefono, t);
strcpy(this->correo, c);
this->id=i;
strcpy(this->clave,cv);
this->estadoV=eV;
}

void setNombre(const char* n){
strcpy(this->nombre,n);
}

void setDni(int d){
dni=d;
}

void setTelefono(const char* t){
strcpy(this->telefono,t);
}

void setCorreo(const char* c){
strcpy(this->correo,c);
}

void setId(int i){
this->id=i;
}

void setClave(const char* cv){
strcpy(this->clave,cv);
}

void setEstado(bool e){
this->estadoV=e;
}

const char* getNombre(){
return nombre;
}

int getDni(){
return dni;
}

const char* getTelefono(){
return telefono;
}

int getId(){
return id;
}

const char* getClave(){
return clave;
}

const char* getCorreo(){
return correo;
}

bool getEstadoVendedor(){
return estadoV;
}

};

#endif // CLASSVENDEDOR_H_INCLUDED
