#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

struct fecha
{
	int dia;
	int mes;
	int anio;
};

struct usuarios
{
	char usuario[10];
	char contrasenia[10];
	char apeNom[60];
};

struct veterinario
{
	char apeNom[60];
	int matricula;
	int dni;
	char telefono[25];
};

struct mascota
{
	char apeNom[60];
	char Domicilio[60];
	int dniDuenio;
	char Localidad[60];
	fecha fecNac;
	float Peso;
	char Telefono[25];
	
};

struct turno
{
	int matricula;
	fecha dniDuenio;
	char DetalleDeAtencion[380] ;
};

main ()
{
	system("color 0a");
	printf("\n\n\n");
	printf("\n\tPrimer modulo: Consultorio veterinario");
	printf("\n\t====================================================");
	printf("\n\t 1.- Iniciar Sesion. ");
	printf("\n\t 2.- Visualizar Lista de Espera de Turnos (informe). ");
	printf("\n\t 3.- Registrar Evolucion de la Mascota. ");
    printf("\n\t 4.- Cerrar la aplicacion. ");
              
	system("pause");
}
