#ifndef CLASSCABECERA_H_INCLUDED
#define CLASSCABECERA_H_INCLUDED
#include <cstdio>
#include <cstring>

using namespace std;
class Cabecera{
private:
int idVenta;
public:
Cabecera(int id=0){
this->idVenta=id;
}
void setIdVenta(int id){
idVenta=id;
}

int getIdVenta(){
return idVenta;
}
};


#endif // CLASSCABECERA_H_INCLUDED
