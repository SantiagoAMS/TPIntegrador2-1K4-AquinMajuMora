#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "Estructurador.h"
/*Esta parte del proyecto estará dirigida a los diferentes profesionales que atienden y registran la evolución de las mascotas en una base de datos de historias clínicas

El sistema deberá contar con un listado de las mascotas que están registradas para ser atendidas ese día
El veterinario deberá identificarse en el sistema por medio de su número de matrícula y contraseña y accediendo a la opción indicada
De esta manera el veterinario llamará por apellido y nombre a la mascota que atenderá, una vez realizada esta tarea procede al ingreso de la evolución, en un texto de no más de 380 caracteres
Luego de realizada esta operación la mascota debe desaparecer del listado

Los datos de interés para el veterinario en este proceso son: 
	Apellido y Nombres de la mascota (el apellido corresponde al dueño o familia), 
	DNI del dueño, 
	Localidad, 
	Edad (calculada con la fecha de nacimiento registrada), 
	Peso
	
La historia clínica de la mascota es común para todos los veterinarios, 
por lo tanto se deberá visualizar fecha de atentación de la misma y el nombre del veterinario que la redacto. */
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

