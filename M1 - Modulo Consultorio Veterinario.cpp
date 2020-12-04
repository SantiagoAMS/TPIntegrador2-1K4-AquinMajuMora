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
int logeado=0, reintentar=0, actualizacion=0;

FILE *FMascotas, *FTurnos, *FUsuarios, *FVeterinarios;


void mostrarListado(FILE *FFmascotas, FILE *FFTurnos, FILE *FFUsuarios, FILE *FFVeterinarios);
void sesion(FILE *FFmascotas, FILE *FFTurnos, FILE *FFUsuarios, FILE *FFVeterinarios);
void atender(FILE *FFmascotas, FILE *FFTurnos, FILE *FFUsuarios, FILE *FFVeterinarios);

main ()
{
	setlocale(LC_ALL, "");
	
	FMascotas=fopen("Mascotas.dat","r+b");
	FTurnos=fopen("Turnos.dat","r+b");
	FUsuarios=fopen("Usuarios.dat","r+b");
	FVeterinarios=fopen("Veterinarios.dat","r+b");
	
	do
	{
		if (reintentar!=1)
		{
			opcion = menu(1);
		}
		else
		{
			opcion = menu(4);
		}
		
		if (opcion==1 or reintentar==1) sesion(FMascotas, FTurnos, FUsuarios, FVeterinarios);//
		else if (opcion==2)
		{
			if (logeado==1)
			{
				//funcion
			} 
			else 
			{
				printf("\n\n\n\tTienes que iniciar sesion para utilizar esta funcion...\n\n\t");
				system("pause");
			}
		}
		else if (opcion==3)
		{
			if (logeado==1)
			{
				//funcion
			} 
			else 
			{
				printf("\n\n\n\tTienes que iniciar sesion para utilizar esta funcion...\n\n\t");
				system("pause");
			}
		};
	}
	while (opcion!=4);
}

void sesion(FILE *FFmascotas, FILE *FFTurnos, FILE *FFUsuarios, FILE *FFVeterinarios)
{
	veterinario regV;
	personal regP;
	mascota regM;
	turnos regT;
	int logreg, errorA=0, errores=0, encontrado=0, confirmo=0;
	char busquedaUSU[11], busquedaCON[61];
	system("cls");
	if (logeado==0)
	{
		do
		{
			errores=1;
			encontrado=0;
			printf("Nombre de usuario del veterinario: ");
			_flushall();
			gets(busquedaUSU);
			rewind(FVeterinarios);
			while(!feof(FFVeterinarios) and encontrado==0)
			{
				fread(&regV, sizeof(regV), 1, FFVeterinarios);
				if (busquedaUSU!=regV.usuario) //
				{
					printf("No. ");
					fread(&regV, sizeof(regV), 1, FVeterinarios);
				}
				else
				{
					encontrado=1;
					errores=0;
					printf("Usuario '%s' encontrado con exito\n",regV.usuario);
				};
				if (encontrado==0)
				{
					printf("No se encontro al usuario, vuelva a intentarlo...\n");
					system("pause");
					system("cls");
				}
			}
		} while (errores!=0);
		do
		{
			errores=1;
			encontrado=0;
			system("clear");
			printf("Usuario: %s\n",regV.usuario);
			printf("Contraseña del veterinario: ");
			_flushall();
			gets(busquedaCON);
			
			if (busquedaCON!=regV.usuario) //
			{
				printf("Contraseña incorrecta\n Deseas ingresar otro usuario?\n(1=SI, 0=NO): ");
				scanf("%i",&reintentar);
				if (reintentar==1)
				{
					errores==0;
					system("pause");
				}
			}
			else
			{
				logeado=1;
				errores=0;
				printf("\nBienvenido %s!\n",regV.apeNom);
				system("pause");
			}
		} while (errores!=0);
	}
	else if (logeado==1)
	{
		printf("\tDeseas cerrar sesion?(1=SI, 0=NO): ");
		scanf("%i",&confirmo);
		if (confirmo==1)
		{
			logeado=0;
			printf("\nSesion cerrada exitosamente. ¡Que tenga un buen dia!");
		};
	};
}

void atender(FILE *FFmascotas, FILE *FFTurnos, FILE *FFUsuarios, FILE *FFVeterinarios)
{
	veterinario regV;
	personal regP;
	mascota regM;
	turnos regT;
	
	char apeDuenio[30], nombreMascota[30];
	do
	{
			/*Apellido y Nombres de la mascota (el apellido corresponde al dueño o familia), 
			DNI del dueño, 
			Localidad, 
			Edad (calculada con la fecha de nacimiento registrada), 
			Peso*/
		printf("Ingrese el apellido del dueño: ");
		_flushall();
		gets(apeDuenio);
		
		printf("Ingrese el nombre de la mascota: ");
		_flushall();
		gets(apeDuenio);
		
		printf("Ingrese el domicilio de la mascota: ");
		
		printf("Ingrese el dni del dueño: ");
		
		printf("Fecha de nacimiento de la mascota: \n");
		printf("\tAño: ");
		printf("\tMes: ");
		printf("\tDia: ");
		
		printf("Ingrese el peso de la mascota");
		
		printf("Ingrese el telefono del dueño");
		char Telefono[25];
	} while (!feof(FFturnos))
}
