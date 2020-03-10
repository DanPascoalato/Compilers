//
// Created by alumni on 3/9/20.
//

#ifndef COMPILERS_101_USUARIO_H
#define COMPILERS_101_USUARIO_H

typedef  struct tUsuario *pUsuario;

pUsuario CriarUsuario(int, char *);
void Imprimir(pUsuario);
void DestruirUsuario(pUsuario *);

#endif //COMPILERS_101_USUARIO_H
