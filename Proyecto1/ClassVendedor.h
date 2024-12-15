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

public:
Vendedor(const char* n="XXX",int d=0,const char* t="1100000000",const char* c="vendedor@gmail.com"){
strcpy(this->nombre, n);
this->dni = d;
strcpy(this->telefono, t);
strcpy(this->correo, c);
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

const char* getNombre(char n[35]){
return nombre;
}

int getDni(int d){
return dni;
}

const char* getTelefono(char t[35]){
return telefono;
}

};

#endif // CLASSVENDEDOR_H_INCLUDED
