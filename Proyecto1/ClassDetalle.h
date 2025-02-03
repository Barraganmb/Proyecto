#ifndef CLASSDETALLE_H_INCLUDED
#define CLASSDETALLE_H_INCLUDED

class DetalleVenta{
private:
char nombreA[30];
char modelo[30];
char marca[30];
int idAuto;
float precio;
int idDetalle;

public:
DetalleVenta(const char* nA="XXX", const char* m="XXX", const char* Mo="XXX",int iA=0, float p=0.0, int iD=0){
strcpy(this->nombreA,nA);
strcpy(this->modelo,Mo);
strcpy(this->marca,m);
this->idAuto=iA;
this->precio=p;
this->idDetalle=iD;
}

void setNombreA(const char* n){
strcpy(this->nombreA,n);
}

void setMarca(const char* m){
strcpy(this->marca,m);
}

void setModelo(const char*mo){
strcpy(this->modelo, mo);
}

void setIdAuto(int i){
this->idAuto=i;
}

void setPrecio(float p){
this->precio=p;
}

void setIdDetalle(int i){
this->idDetalle=i;
}

const char* getNombre(){
return nombreA;
}

const char* getMarca(){
return marca;
}

const char* getModelo(){
return modelo;
}

int getIdAuto(){
return idAuto;
}

float getPrecio(){
return precio;
}

int getIdDetalle(){
return idDetalle;
}
};

#endif // CLASSDETALLE_H_INCLUDED
