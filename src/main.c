#include <stdio.h>
#include <stdlib.h>

typedef enum TokenType{
    TEXTO=1,
    INTEIRO=2,
    REAL=3,
}TokenType;

//você so pode definir apenas 1 valor por vez já que utilizam a mesma memoria
typedef union Value{
    int i;
    double r;
    char *t;
}Value;

typedef struct Token{
    TokenType tokenType;
    Value value;
} Token;

int main() {
    Token token;
    token.tokenType = INTEIRO;

    token.value.i = 10;
    //ken.value.r = 3.14;

    printf("%i\n", token.value.i);
    printf("%f\n", token.value.r);
    printf("%zu\n", sizeof(Token));
}