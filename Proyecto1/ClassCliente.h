#ifndef CLASSCLIENTE_H_INCLUDED
#define CLASSCLIENTE_H_INCLUDED
#include <iostream>
#include <cstring>

class Cliente{

private:
char nombreCliente[35];
int dniCliente;
char telefonoCliente[15];
char correoCliente[35];
int idCliente;
bool estadoC;

public:
Cliente(const char* nC="XXX",int dC=0,const char* tC="1100000000",const char* cC="cliente@gmail.com",int iC=0){
strcpy(this->nombreCliente, nC);
this->dniCliente = dC;
strcpy(this->telefonoCliente, tC);
strcpy(this->correoCliente, cC);
this->idCliente=iC;

}

void setNombreCliente(const char* n){
strcpy(this->nombreCliente,n);
}

void setDniCliente(int d){
dniCliente=d;
}

void setTelefono(const char* t){
strcpy(this->telefonoCliente,t);
}

void setCorreoCliente(const char* c){
strcpy(this->correoCliente,c);
}

void setIdCliente(int i){
this->idCliente=i;
}


const char* getNombreCliente(){
return nombreCliente;
}

int getDniCliente(){
return dniCliente;
}

const char* getTelefonoCliente(){
return telefonoCliente;
}

const char* getCorreoCliente(){
return correoCliente;
}

int getIdCliente(){
return idCliente;
}

};

#endif // CLASSCLIENTE_H_INCLUDED
