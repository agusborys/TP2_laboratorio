#include"funciones.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>

/** \brief verifica que una cadena de caracteres no se desborde.
 *
 * \param cadena de caracteres a verificar.
 * \param tamaño de la cadena tipo entero.
 * \return devuelve 1 si se desborda, 0 si no.
 *
 */
int validar_cadena(char aux[], int tam){
    if(strlen(aux)>tam){
        return 1;
    }
    else{
        return 0;
    }
}

/** \brief verifica si en una cadena de caracteres hay algun numero.
 *
 * \param cadena de caracteres a verificar.
 * \return devuelve 1 si la cadena tiene nuemero/s, 0 si no.
 *
 */
int validar_char(char aux[]){
    int flag = 0;
    for(int i=0;i<strlen(aux); i++){
        if(isdigit(aux[i])){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        return 1;
    }
    else{
        return 0;
    }
}

/** \brief Pasa a mayúscula el primer caracter y el seguido de un espacio, los demas los pasa a minúscula.
 *
 * \param cadena de caracteres a pasar.
 *
 */
void pasaje_nombre(char aux[]){
    strlwr(aux);
    aux[0] = toupper(aux[0]);
    for(int i=0;i<strlen(aux);i++){
        if(aux[i]==' '){
        aux[i+1] = toupper(aux[i+1]);
        }
    }
}

/** \brief inicializa los estados de la lista de personas.
 *
 * \param verctor de estructuras de personas a inicializar.
 * \param tamaño del vector de estructuras.
 *
 */
void init(EPersona per[], int tam){
    for (int i=0; i<tam; i++){
        per[i].estado = 0;
    }
}

/** \brief verifica si hay letras en un dato que se utilizará como entero.
 *
 * \param cadena de caracteres a verificar.
 * \return devuelve 1 si se encuentra letra, 0 si no.
 *
 */
int validar_entero(char op[]){
    int flag = 0;
    for(int i=0; i<strlen(op); i++){
        if(!isdigit(op[i])){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        return 1;
    }
    else{
        return 0;
    }
}

/** \brief valida si la edad esta fuera del rango o dentro.
 *
 * \param cadena de caracteres con la edad a validar.
 * \param minimo de la edad.
 * \param maximo de edad.
 * \return devuelve 1 si esta fuera del rango, 0 si no.
 *
 */
int validar_edad(char auxed[], int min, int max){
    if(atoi(auxed)<min || atoi(auxed)>max){
      return 1;
    }
    else{
        return 0;
    }
}

/** \brief Hace una pausa en el programa esperando que el usuario ingrese un caracter por teclado.
 *
 */
void funcion_pausa(void)
{
    printf("\nPulse tecla para volver al menu\n");
    getch();
}
/** \brief Lista un vector de estructuras.
 *
 * \param vector de estructuras a listar.
 * \param tamaño del vector.
 *
 */
void listar(EPersona lista[], int tam){
    printf("\nNombre---Edad---DNI\n\n");
    int flag = 0;
    for(int i=0;i<tam; i++){
        if(lista[i].estado != 0){
            printf("%s---%d---%d\n",lista[i].nombre,lista[i].edad,lista[i].dni);
            flag = 1;
        }
    }
    if(flag == 0){
        printf("\nLista vacia!\n");
    }
}
/** \brief ordena alfabeticamente un vector de estructuras.
 *
 * \param vector estructura a ordenar.
 * \param tamaño del vector de estructuras.
 *
 */
void ordenarPorNombre(EPersona lista[], int tam){
    EPersona aux;
    for(int i=0;i<tam-1;i++){
        for(int j=i+1; j<tam;j++){
            if(lista[i].estado==1 && lista[j].estado==1){
                if(strcmp(lista[i].nombre,lista[j].nombre)>0){
                    aux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;
                }
                else{
                    if(strcmp(lista[i].nombre,lista[j].nombre)==0){
                        if(lista[i].edad>lista[j].edad){
                            aux = lista[i];
                            lista[i] = lista[j];
                            lista[j] = aux;
                        }
                    }
                }
            }
        }
    }
}
/** \brief Busca coincidencia por el DNI en el vector estructuras y el dato ingresado.
 *
 * \param vector de estructura a buscar coincidencia.
 * \param cadena de caracteres que contiene el DNI a comparar.
 * \param tamaño del vector de estructuras.
 * \return devuelve el indice del vector de DNI que coincide, si no lo encuentra devuelve -1.
 *
 */
int buscarPorDni(EPersona lista[], char aux[], int tam){
    for(int i=0; i<tam; i++){
        if(lista[i].estado==1 && atoi(aux)==lista[i].dni){
            return i;
        }
    }
    return -1;
}

/** \brief Busca coincidencia por el DNI en el vector estructuras y el dato ingresado.
 *
 * \param cadena de caracteres que contiene el DNI a comparar.
 * \param cadena de caracteres que contiene el DNI a comparar.
 * \param tamaño del vector de estructuras.
 * \return devuelve 1 si hay coincidencia, 0 si no.
 *
 */
int coincidenciaDNI(EPersona lista[], char auxdni[], int tam){
     for(int i=0; i<tam;i++){
        if(atoi(auxdni) == lista[i].dni){
            return 1;
        }
    }
    return 0;
}

/** \brief realiza un grafico horizontal de las edades en el vector de estructuras.
 *
 * \param vector de estructura a analizar.
 * \param tamaño del vector de estructuras
 *
 */
void GraficoHorizontal(EPersona lista[], int tam){

    int menor18=0, entre19y35=0, mayor35=0, mayortotal=0;
    for(int i=0;i<tam;i++){
        if(lista[i].estado==1 && lista[i].edad < 18){
            menor18++;
        }
        else{
            if(lista[i].estado==1 && lista[i].edad >=18 && lista[i].edad<=35){
                entre19y35++;
            }
            else{
                if(lista[i].estado==1 && lista[i].edad>35){
                    mayor35++;
                }
            }
        }
    }
    if(menor18>= entre19y35 && menor18>=mayor35){
        mayortotal = menor18;
    }
    else{
        if(entre19y35>=menor18 && entre19y35>= mayor35){
            mayortotal = entre19y35;
        }
        else{
            if(mayor35>=menor18 && mayor35>=entre19y35){
                mayortotal = mayor35;
            }
        }
    }
    printf("       ");
    for(int i=1;i<=mayortotal;i++){
        printf("%d",i);
    }
    printf("\n<18   |");
    for(int i=0; i<menor18;i++){
        printf("*");
    }
    printf("\n19-35 |");
    for(int i=0; i<entre19y35;i++){
        printf("*");
    }
    printf("\n>35   |");
    for(int i=0; i<mayor35;i++){
        printf("*");
    }

}

