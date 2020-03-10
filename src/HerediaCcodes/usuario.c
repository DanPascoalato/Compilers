#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "usuario.h"
//#define LEN_MAX 80

struct tUsuario{
    int id;
    //char nome[LEN_MAX+1];
    char *nome;
};

pUsuario CriarUsuario(int id, char *nome){
    pUsuario p = malloc(sizeof(struct tUsuario));
    p->id = id;
    if(nome != NULL){
        p->nome = malloc(strlen(nome)* sizeof(char)+1);
        strcpy(p->nome, nome);
    } else {
        p->nome = malloc(sizeof(char));
        p->nome[0] = '\0';
    }
    return p;
}

void DestruirUsuario(pUsuario *u){
    if(*u != NULL){
        free((*u)->nome);
        free(*u);
    }
    *u = NULL;
}

void Imprimir(pUsuario u){
    printf("%s\n", u->nome);
}
