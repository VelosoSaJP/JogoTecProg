#include "Lista.h"
#include <iostream>
using namespace std;

int main(){ 
    Lista::Lista<int> numeros;
    int* num = new int (0);


    numeros.incluir(num);

    printf("%d\n",**(numeros.getInicio()));



    return 0;
}