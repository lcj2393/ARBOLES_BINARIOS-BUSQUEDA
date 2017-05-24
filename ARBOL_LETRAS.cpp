/**ARBOL BINARIO DE BUSQUEDA**/

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
void modNodo(nodo *&,int);/**FUNCION PARA MODIFICAR NODO DEL ARBOL**/
void impArbol(Nodo *);/**FUNCION PARA IMPRIMIR EL ARBOL**/
void impPosOrden(Nodo *);/**FUNCION PARA IMPRIMIR EL ARBOL POSORDEN**/
void impPreOrden(Nodo *);/**FUNCION PARA IMPRIMIR EL ARBOL PREORDEN**/
void impInOrden(Nodo *);/**FUNCION PARA IMPRIMIR EL ARBOL INORDEN**/

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
    printf("\n\t\t+++++MENU ARBOL BINARIO DE BUSQUEDA+++++\n\n");
    printf("\n1. Insertar Datos");
    printf("\n2. Editar Elemento de Arbol");
    printf("\n3. Buscar Elemento en Arbol");
    printf("\n4. Eliminar Elemento de Arbol");
    printf("\n5. Mostrar Arbol");
    printf("\n6. Arbol PreOrden");
    printf("\n7. Arbol PosOrden");
    printf("\n8. Arbol InOrder");
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
        case 4:
            system("pause");
            system("cls");
            menu(arbol);
            break;
        case 5:
            printf("\n\t\t\t+++++IMPRIMIR ARBOL+++++\n\n");
            printf("\n1. Arbol PreOrden");
            printf("\n2. Arbol PosOrden");
            printf("\n3. Arbol InOrder");
            printf("\n0. Salir al Menu\n");
            printf("Digite opcion: ");
            scanf("%d",&sub_opc);
            switch(sub_opc){
            case 0:
                printf("\nHas Salido del menu de Tipos de Impresion del Arbol!!\n");
                system("pause");
                system("cls");
                menu(arbol);
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            default:
                printf("\n\nLa Opcion Ingresada no es Valida!!\n\n");
                break;
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
void modNodo(Nodo *&arbol, int n){/**FUNCION PARA MODIFICAR UN NODO DEL ARBOL**/
    char letra;
    if(arbol==NULL){
        return;
    }else if(arbol->dato==n){
        printf("Digite valor nuevo: ");
        scanf("%s",&letra);
        int convert_c2int=letra;
        if(convert_c2int>=65 && convert_c2int<=90 || convert_c2int>=97 && convert_c2int<=122){
            if(convert_c2int>90){
                convert_c2int=convert_c2int-32;
            }
            arbol->dato=convert_c2int;
        }else{
            printf("El Caracter ingresado no es valido\n");
        }
        return;
    }else if(n<arbol->dato){
        return modNodo(arbol->Izquierda,n);
    }else{
        return modNodo(arbol->Derecha,n);
    }
}
void impPreOrden(Nodo *arbol){/**FUNCION PARA IMPRIMIR EL ARBOL PREORDEN**/
    if(arbol==NULL){
        return;
    }else{
        char convert_c2int=arbol->dato;
        printf("%c ",convert_c2int);
        impPreOrden(arbol->Izquierda);
        impPreOrden(arbol->Derecha);
    }
}
void impInOrder(Nodo *arbol){/**FUNCION PARA IMPRIMIR EL ARBOL INORDEN**/
    if(arbol==NULL){
        return;
    }else{
        impInOrder(arbol->Izquierda);
        char convert_c2int=arbol->dato;
        printf("%c ",convert_c2int);
        impInOrder(arbol->Derecha);
    }
}
void impPosOrden(Nodo *arbol){/**FUNCION PARA IMPRIMIR EL ARBOL POSORDEN**/
    if(arbol==NULL){
        return;
    }else{
        impPosOrden(arbol->Izquierda);
        impPosOrden(arbol->Derecha);
        char convert_c2int=arbol->dato;
        printf("%c ",convert_c2int);
    }
}

/**FIN DEL PROGRAMA!!**/
