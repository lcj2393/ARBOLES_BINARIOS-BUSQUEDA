#include <stdio.h>
#include <stdlib.h>
#define reserva (nodo*)malloc(sizeof(nodo))

struct nodo{
    int dato;
    nodo *izq;
    nodo *der;
};

void menu(nodo *&);
void insertar_nodo(nodo *&,int);
bool buscar_nodo(nodo *,int);
void mostrar_arbol(nodo *&,int);

int main(){
    nodo *arbol=NULL;
    menu(arbol);
}

void menu(nodo *&arbol){
    int x, a;
    char c;

    printf("******ARBOLES BINARIOS*********\n");
    printf("1. Insertar elementos\n");
    printf("2. Mostrar arbol\n");
    printf("3. Buscar nodo\n");
    printf("4. Modificar nodo\n");
    printf("5. Salir\n");
    printf("Digite opcion: ");
    scanf("%d",&x);
    switch(x){
        case 1:{
            do{
                printf("Ingrese dato: ");
                scanf("%s",&c);
                int convertir=c;
                if(convertir>=62 && convertir<=90 || convertir>=97 && convertir<=122){
                    if(convertir>90){
                        convertir=convertir-32;
                    }
                    insertar_nodo(arbol,convertir);
                }else{
                    printf("Caracter ingresado no valido\n");
                }
                printf("Desea ingresar mas datos 1.SI  2.NO: ");
                scanf("%d",&a);
            }while(a!=2);
        }break;
        case 3:{
            printf("Ingrese dato que desea buscar: ");
            scanf("%s",&c);
            int convertir=c;
            if(convertir>=62 && convertir<=90 || convertir>=97 && convertir<=122){
                if(convertir>90){
                    convertir=convertir-32;
                }
                if(buscar_nodo(arbol,convertir)==true){
                    printf("Elemento encontrado\n");
                }else{
                    printf("Elemento no encontrado\n");
                }
            }else{
                printf("Caracter ingresado no valido\n");
            }
            system("pause");
        }break;
    }
    menu(arbol);
}

nodo *crear_nodo(int n){
    nodo *nuevo=reserva;
    nuevo->dato=n;
    nuevo->izq=NULL;
    nuevo->der=NULL;

    return nuevo;
}

void insertar_nodo(nodo *&arbol, int n){
    if(arbol==NULL){
        nodo *nuevo_nodo=crear_nodo(n);
        arbol=nuevo_nodo;
    }else{
        int valor=arbol->dato;
        if(n<valor){
            insertar_nodo(arbol->izq,n);
        }else{
            insertar_nodo(arbol->der,n);
        }
    }
}

bool buscar_nodo(nodo *arbol, int n){
    if(arbol==NULL){
        return false;
    }else if(arbol->dato==n){
        return true;
    }else if(n<arbol->dato){
        return buscar_nodo(arbol->izq,n);
    }else{
        return buscar_nodo(arbol->der,n);
    }
}
