#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "Estructurador.h"
/*Esta parte del proyecto estar� dirigida a los diferentes profesionales que atienden y registran la evoluci�n de las mascotas en una base de datos de historias cl�nicas

El sistema deber� contar con un listado de las mascotas que est�n registradas para ser atendidas ese d�a
El veterinario deber� identificarse en el sistema por medio de su n�mero de matr�cula y contrase�a y accediendo a la opci�n indicada
De esta manera el veterinario llamar� por apellido y nombre a la mascota que atender�, una vez realizada esta tarea procede al ingreso de la evoluci�n, en un texto de no m�s de 380 caracteres
Luego de realizada esta operaci�n la mascota debe desaparecer del listado

Los datos de inter�s para el veterinario en este proceso son: 
	Apellido y Nombres de la mascota (el apellido corresponde al due�o o familia), 
	DNI del due�o, 
	Localidad, 
	Edad (calculada con la fecha de nacimiento registrada), 
	Peso
	
La historia cl�nica de la mascota es com�n para todos los veterinarios, 
por lo tanto se deber� visualizar fecha de atentaci�n de la misma y el nombre del veterinario que la redacto. */
FILE *FMascotas, *FTurnos, *FUsuarios, *FVeterinarios;

main ()
{
	setlocale(LC_ALL, "");
	FMascotas=fopen("Mascotas.dat","r+b");
	FTurnos=fopen("Turnos.dat","r+b");
	FUsuarios=fopen("Usuarios.dat","r+b");
	FVeterinarios=fopen("Veterinarios.dat","r+b");
	menu(1);
}

