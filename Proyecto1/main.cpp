#include <iostream>
#include "ClassVendedor.h"
#include "ArchivoVendedor.h"
#include "ArchivoCliente.h"
using namespace std;

int main()
{
ArchivoCliente obj1;
ArchivoVendedor obj;
obj1.darAltaCliente();
obj.listarVendedores();
obj.darAlta();
    return 0;
}
