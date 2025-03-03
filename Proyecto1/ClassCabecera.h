#ifndef CLASSCABECERA_H_INCLUDED
#define CLASSCABECERA_H_INCLUDED
#include <cstdio>
#include <cstring>

using namespace std;
class Cabecera{
private:
int idVenta;
char nombreV[35];
char nombreC[35];
char correoV[35];
char correoC[35];
char telV[15];
char telC[15];
int idVendedor;
int idCliente;
int dia;
int mes;
int anio;
int contador;

public:
Cabecera(int id=0,const char* nV="XXX", const char* nC="XXX", const char* cV="XXX", const char* cC="XXX", const char* tV="111", const char* tC="111", int iV=0, int iC=0, int d=0, int m=0, int a=0, int c=0){
this->idVenta=id;
strcpy(this->nombreV, nV);
strcpy(this->nombreC, nC);
strcpy(this->correoV, cV);
strcpy(this->correoC, cC);
strcpy(this->telV, tV);
strcpy(this->telC, tC);
this->idVendedor=iV;
this->idCliente=iC;
this->dia=d;
this->mes=m;
this->anio=a;
this->contador=c;
}
void setIdVenta(int id){
idVenta=id;
}

int getIdVenta(){
return idVenta;
}

void setNombreV(const char* nV){
strcpy(this->nombreV, nV);
}

void setNombreC(const char* nC){
strcpy(this->nombreC, nC);
}

void setCorreoV(const char* cV){
strcpy(this->correoV,cV);
}

void setCorreoC(const char* cC){
strcpy(this->correoC,cC);
}

void setTelV(const char* tV){
strcpy(this->telV,tV);
}

void setTelC(const char* tC){
strcpy(this->telC,tC);
}

void setIdVendedor(int iV){
idVendedor=iV;
}

void setIdCliente(int iC){
idCliente=iC;
}

void setDia(int d){
dia=d;
}

void setMes(int m){
mes=m;
}

void setAnio(int a){
anio=a;
}

void setContador(int c){
contador=c;
}

const char* getNombreV(){
return nombreV;
}

const char* getNombreC(){
return nombreC;
}

const char* getCorreoV(){
return correoV;
}

const char* getCorreoC(){
return correoC;
}

const char* getTelV(){
return telV;
}

const char* getTelC(){
return telC;
}

int getIdVendedor(){
return idVendedor;
}

int getIdCliente(){
return idCliente;
}

int getDia(){
return dia;
}

int getMes(){
return mes;
}

int getAnio(){
return anio;
}

int getContador(){
return contador;
}

};


#endif // CLASSCABECERA_H_INCLUDED
