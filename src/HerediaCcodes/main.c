#include <stdio.h>
#include <stdlib.h>

#include "usuario.h"

int main(void){
    pUsuario u1 = CriarUsuario(1, NULL);
    //pUsuario u2 = CriarUsuario(2, "Daniel Ruiz");

    Imprimir(u1);
    //Imprimir(u2);
    for(int i = 0;i<1000;i++) {
        DestruirUsuario(&u1);
    }
    //DestruirUsuario(u2);
    exit(0);
}
