#include <stdio.h>
#include <string.h>

int percorrer_lista(char nome, int i, char lista[]){
    //letra valida 0
    //letra invalida 1
    if(lista[i] == '\0') return 1;
    else{
        if(nome == lista[i]) return 0;
        return percorrer_lista(nome, i+1, lista);
    }
}

int caracteres_validos(char nome[50], int i, char lista[]){
    //se o nome for valido, retorna 0
    //se o nome for invalido, retorna 1
    int valido;
    if(i == 50 || nome[i] == '\0') return 0;
    else{
        valido = percorrer_lista(nome[i], 0, lista);
        if(valido == 1) return 1;
        return caracteres_validos(nome, i+1, lista);
    }
}

int analisa_min(char nome, int i, char lista[]){
    //retorna 0 se a letra for minuscula
    //retorna 1 se a letra for maiuscula
    if(i == 26) return 1;
    else{
        if(nome == lista[i]) return 0;
        return analisa_min(nome, i+1, lista);
    }
}

int analisa_nome(char nome[], int i, char lista[]){
    if(i == 50 || nome[i] == '\0') return 0;
    else{
        if(nome[i] == ' '){
            if(analisa_min(nome[i+1], 0, lista) == 0) return 1;
        }else if(nome[i] != ' '){
            if(i == 0){
                if(analisa_min(nome[i], 0, lista) == 0) return 1;
            }
            else if(nome[i-1] != ' ' && analisa_min(nome[i], 0, lista) == 1) return 1;
        }
        return analisa_nome(nome, i+1, lista);
    }
}

int main(){
    char lista[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                    'A', 'B', 'C', 'D', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 
                    'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};

    char nome[50];
    scanf("%[^\n]", nome);
    int valido = caracteres_validos(nome, 0, lista);
    int caracteres;
    if(valido == 1) printf("Nome invalido!");
    else{
        caracteres = analisa_nome(nome, 0, lista);
        if(caracteres == 1) printf("Nome invalido!");
        else printf("Nome %s valido!", nome);
    }

    return 0;
}