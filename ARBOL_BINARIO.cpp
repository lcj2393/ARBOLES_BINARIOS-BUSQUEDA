/**ARBOL BINARIO**/

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
void modNodo(Nodo *&,int);/**FUNCION PARA MODIFICAR NODO DEL ARBOL**/
void impArbol(Nodo *);/**FUNCION PARA IMPRIMIR EL ARBOL**/
void impPosOrder(Nodo *);/**FUNCION PARA IMPRIMIR EL ARBOL POSORDEN**/
void impPreOrder(Nodo *);/**FUNCION PARA IMPRIMIR EL ARBOL PREORDEN**/
void impInOrder(Nodo *);/**FUNCION PARA IMPRIMIR EL ARBOL INORDEN**/

int main(){/**FUNCION MENU**/
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
    printf("\n\t\t+++++MENU ARBOL BINARIO+++++\n\n");
    printf("\n1. Insertar Datos");
    printf("\n2. Editar Elemento de Arbol");
    printf("\n3. Buscar Elemento en Arbol");
    printf("\n4. Eliminar Elemento de Arbol");
    printf("\n5. Mostrar Arbol");
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
            {do{
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
            menu(arbol);}
            break;
        case 2:
            printf("\n\t\t\t+++++MODIFICAR NODO DEL ARBOL+++++\n\n");
            {printf("Diite valor a modificar: ");
            scanf("%s",&letra);
            int convert_c2int=letra;
            if(convert_c2int>=62 && convert_c2int<=90 || convert_c2int>=97 && convert_c2int<=122){
                if(convert_c2int>90){
                    convert_c2int=convert_c2int-32;
                }
                modNodo(arbol,convert_c2int);
            }else{
                printf(" El caracter ingresado no es valido\n");
            }
            }break;
        case 3:
            printf("\n\t\t\t+++++BUSCAR ARBOL+++++\n\n");
            {printf("Digite valor a buscar: ");
            scanf("%c",&letra);
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
            }break;
        case 4:
            printf("\n\t\t\t+++++ELIMINAR NODO DE ARBOL+++++\n\n");
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
                printf("\n\t\t\t+++++ARBOL PREORDEN+++++\n\n");
                impInOrder(arbol);
                break;
            case 2:
                printf("\n\t\t\t+++++ARBOL POSORDEN+++++\n\n");
                impPreOrder(arbol);
                break;
            case 3:
                printf("\n\t\t\t+++++ARBOL INORDEN+++++\n\n");
                impInOrder(arbol);
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

Nodo *crearNodo(int n){
    Nodo *nNodo=(Nodo*)malloc(sizeof(Nodo));
    nNodo->dato=n;
    nNodo->Izquierda=NULL;
    nNodo->Derecha=NULL;
    return nNodo;
}

void insNodo(Nodo *&arbol, int n){/**FUNCION INSERTAR EN NODO**/
    int m;
    if(arbol==NULL){
        Nodo *nuevo=crearNodo(n);
        arbol=nuevo;
    }else{
        printf("Insertar a (1)Izquierda o (2)Derecha: ");
        scanf("%d",&m);
        if(m==1){
            insNodo(arbol->Izquierda,n);
        }else{
            insNodo(arbol->Derecha,n);
        }
    }
}
bool buscNodo(Nodo *arbol, int n){/**FUNCION PARA BUSCAR NODOS EN EL ARBOL**/
    int m;
    if(arbol==NULL){
        return false;
    }else{
        if(arbol->dato==n){
            return true;
        }else{
            printf("Buscar por <1>Izquierda O <2>Derecha: ");
            scanf("%d",&m);
            if(m==1){
                buscNodo(arbol->Izquierda,n);
            }else{
                buscNodo(arbol->Derecha,n);
            }
        }
    }
}
void modNodo(Nodo *&arbol, int n){/**FUNCION PARA MODIFICAR UN NODO DEL ARBOL**/
    int nuevoDato, ubicacion;
    if(arbol==NULL){
        return;
    }else{
        if(arbol->dato==n){
            printf("Digite nuevo dato: ");
            scanf("%d",&nuevoDato);
            arbol->dato=nuevoDato;
        }else{
            printf("Buscar 1.Izquierda  2.Derecha: ");
            scanf("%d",&ubicacion);
            if(ubicacion==1){
                modNodo(arbol->Izquierda,n);
            }else{
                modNodo(arbol->Derecha,n);
            }
        }
    }
}
void impPreOrder(Nodo *arbol){/**FUNCION PARA IMPRIMIR EL ARBOL PREORDEN**/
    if(arbol==NULL){
        return;
    }else{
        char convert_c2int=arbol->dato;
        printf("%c ",convert_c2int);
        impPreOrder(arbol->Izquierda);
        impPreOrder(arbol->Derecha);
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
void impPosOrder(Nodo *arbol){/**FUNCION PARA IMPRIMIR EL ARBOL POSORDEN**/
    if(arbol==NULL){
        return;
    }else{
        impPosOrder(arbol->Izquierda);
        impPosOrder(arbol->Derecha);
        char convert_c2int=arbol->dato;
        printf("%c ",convert_c2int);
    }
}

/**FIN DEL PROGRAMA!!**/
