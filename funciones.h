#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct {

    char nombre[51];
    int edad;
    int estado;
    int dni;

}EPersona;

int validar_cadena(char[], int);
int validar_char(char []);
void pasaje_nombre(char[]);
void init(EPersona[], int );
int validar_entero(char[]);
int validar_edad(char[], int, int);
void funcion_pausa(void);
void ordenarPorNombre(EPersona[], int);
void listar(EPersona[], int);
int buscarPorDni(EPersona[], char[], int);
int coincidenciaDNI(EPersona[], char[], int);
void GraficoHorizontal(EPersona[], int );


#endif // FUNCIONES_H_INCLUDED
