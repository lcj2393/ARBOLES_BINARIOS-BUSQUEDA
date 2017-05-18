#include <stdio.h>
#include <stdlib.h>

/**DEFINIR ASIGNACION DE MEMORIA**/
#define ReservaMemoria (Nodo*)malloc(sizeof(Nodo))

/**ESTRCUTURA NODO ARBOL**/
struct Nodo{
    int dato;
    Nodo *Izquierda;
    Nodo *Derecha;
};

void menu(Nodo *&);/**FUNCION MENU**/
void insNodo(Nodo *&,int);/**FUNCION INSERTAR EN NODO**/
bool buscNodo(Nodo *,int);/**FUNCION PARA BUSCAR NODOS EN EL ARBOL**/
void impArbol(Nodo *);/**FUNCION PARA IMPRIMIR EL ARBOL**/


int main(){
    /**DECLARACION DEL ARBOL**/
    Nodo *arbol=NULL;
    system("cls");
    menu(arbol);
    return 0;
}

void menu(Nodo *&arbol){/**FUNCION MENU PRINCIPLA DELPROGRAMA**/
    int opc, sub_opc;
    char letra;
    system("cls");
    printf("\n\t\t\t+++++MENU ARBOL BINARIO+++++\n\n");
    printf("\n1. Insertar Datos");
    printf("\n2. Imprimir Arbol");
    printf("\n3. Buscar Nodo del Arbol");
    printf("\n0. Salir\n");
    printf("Digite opcion: ");
    scanf("%d",&opc);

    switch(opc){
        case 0:
            system("cls");
            printf("\n\t\tHas salido del programa!!!\n\n");
            system("pause");
            break;
        case 1:
            printf("\n\t\t\t+++++INSERTAR DATOS+++++\n\n");
            do{
                printf("Digite Dato a Ingresar: ");
                scanf("%s",&letra);
                int convert_c2int=letra;
                if(convert_c2int>=62 && convert_c2int<=90 || convert_c2int>=97 && convert_c2int<=122){
                    if(convert_c2int>90){
                        convert_c2int=convert_c2int-32;
                    }
                    insNodo(arbol,convert_c2int);
                }else{
                    printf("Caracter ingresado no valido\n");
                }
                printf("Continuar Ingresando? (1)SI - (2)NO: ");
                scanf("%d",&sub_opc);
            }while(sub_opc!=2);
            system("pause");
            system("cls");
            menu(arbol);
            break;
        case 2:
            printf("\n\t\t\t+++++IMPRIMIR ARBOL+++++\n\n");
            printf("\nEl Arbol contiene los sigueintes Nodos: \n\n");
            while(arbol!=NULL){
                impArbol(arbol);
            }
            system("pause");
            system("cls");
            menu(arbol);
            break;
        case 3:
            printf("\n\t\t\t+++++BUSCAR ARBOL+++++\n\n");
            printf("Ingrese dato que desea buscar: ");
            scanf("%s",&letra);
            int convert_c2int=letra;
            if(convert_c2int>=62 && convert_c2int<=90 || convert_c2int>=97 && convert_c2int<=122){
                if(convert_c2int>90){
                    convert_c2int=convert_c2int-32;
                }
                if(buscNodo(arbol,convert_c2int)==true){
                    printf("Elemento %s encontrado en el Arbol!!\n",letra);
                }else{
                    printf("Elemento %s no encontrado en el Arbol!!\n",letra);
                }
            }else{
                printf("Caracter ingresado no valido\n");
            }
            system("pause");
            system("cls");
            menu(arbol);
            break;
    }
}
void insNodo(Nodo *&arbol, int n){/**FUNCION INSERTAR EN NODO**/
    if(arbol==NULL){
        Nodo *nuevo_Nodo=ReservaMemoria;
        arbol=nuevo_Nodo;
        nuevo_Nodo->dato=n;
        nuevo_Nodo->Izquierda=NULL;
        nuevo_Nodo->Derecha=NULL;
    }else{
        int valor=arbol->dato;
        if(n<valor){
            insNodo(arbol->Izquierda,n);
        }else{
            insNodo(arbol->Derecha,n);
        }
    }
}
bool buscNodo(Nodo *arbol, int n){/**FUNCION PARA BUSCAR NODOS EN EL ARBOL**/
    if(arbol==NULL){
        return false;
    }else if(arbol->dato==n){
        return true;
    }else if(n<arbol->dato){
        return buscNodo(arbol->Izquierda,n);
    }else{
        return buscNodo(arbol->Derecha,n);
    }
}
void impArbol(Nodo *arbol){/**FUNCION PARA IMPRIMIR EL ARBOL**/
    if(arbol!=NULL){
        arbol=arbol->Izquierda;
        printf(" <%s> ",arbol->dato);
        arbol=arbol->Derecha;
        printf(" <%s> ",arbol->dato);
    }else{
        printf("\n\nArbol Vacio!!\n\n");
    }
}
