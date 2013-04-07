#include <stdio.h>
#include <iostream>



using namespace std;

void intecambiar(int *uno, int *otro) {

int aux;

aux=*uno;
*uno=*otro;
*otro=aux;
}

int main() {

int a,b;
 a=2;
 b=5;

 printf("el valor de a es %d\n"
       "el valor de b es %d\n",a,b);

intecambiar(&a,&b);

 printf("el valor de a es %d\n"
       "el valor de b es %d\n",a,b);


}

