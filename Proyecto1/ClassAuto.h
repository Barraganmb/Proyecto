#ifndef CLASSAUTO_H_INCLUDED
#define CLASSAUTO_H_INCLUDED

class Auto{
private:
char nombreAuto[30];
char marcaAuto[30];
char modeloAuto[30];
float precioAuto;
int idAuto;
bool estadoAuto;

public:
Auto(const char* nA="XXX",const char* mA="XXX",const char* modelo="XXX",float pA=0.0,int iA=0,bool e=false){
strcpy(this->nombreAuto,nA);
strcpy(this->marcaAuto,mA);
strcpy(this->modeloAuto,modelo);
this->precioAuto=pA;
this->idAuto=iA;
this->estadoAuto=e;
}

void setNombre(const char* n){
strcpy(this->nombreAuto,n);
}

void setMarca(const char* m){
strcpy(this->marcaAuto,m);
}

void setModelo(const char* mA){
strcpy(this->modeloAuto,mA);
}

void setPrecio(float p){
this->precioAuto=p;
}

void setId(int i){
this->idAuto=i;
}

void setEstadoA(bool e){
this->estadoAuto=e;
}

const char* getNombre(){
return nombreAuto;
}

const char* getMarca(){
return marcaAuto;
}

const char* getModelo(){
return modeloAuto;
}

float getPrecio(){
return precioAuto;
}

int getIdAuto(){
return idAuto;
}

bool getEstado(){
return estadoAuto;
}

};

#endif // CLASSAUTO_H_INCLUDED
