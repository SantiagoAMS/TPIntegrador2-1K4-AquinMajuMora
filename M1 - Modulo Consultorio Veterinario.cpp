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

int sesion(FILE *FFMascotas, FILE *FFTurnos, FILE *FFUsuarios, FILE *FFVeterinarios);
void mostrarListado(FILE *FFMascotas, FILE *FFTurnos, FILE *FFUsuarios, FILE *FFVeterinarios);
void atender(FILE *FFMascotas, FILE *FFTurnos, FILE *FFUsuarios, FILE *FFVeterinarios);

int numerito=0;
// 0 = uso deslogeado
// 1 = reintentar en el item 1
// 2 = salir logeado del item 1
main ()
{
	logeado=1;
	FILE *FMascotas, *FTurnos, *FUsuarios, *FVeterinarios;
	setlocale(LC_ALL, "");
	FMascotas=fopen("Mascotas.dat","r+b");
	FTurnos=fopen("Turnos.dat","r+w");
	FUsuarios=fopen("Usuarios.dat","r+b");
	FVeterinarios=fopen("Veterinarios.dat","r+b");

	do
	{
		if (numerito==2 or logeado==1)//SI la sesion esta iniciada
		{
			menu(4);
			
			if (opcion==1) numerito = sesion(FMascotas, FTurnos, FUsuarios, FVeterinarios);
			else if (opcion==2) mostrarListado(FMascotas, FTurnos, FUsuarios, FVeterinarios);
			else if (opcion==3) atender(FMascotas, FTurnos, FUsuarios, FVeterinarios);
		}
		else if (numerito==1)//MARCADO para reinicio
		{
			numerito=sesion(FMascotas, FTurnos, FUsuarios, FVeterinarios);
		}
		else if (numerito==0)//SESION NO INICIADA
		{
			opcion = menu(1);
			
			if (opcion==1)numerito=sesion(FMascotas, FTurnos, FUsuarios, FVeterinarios);
			else if (opcion==2 or opcion==3)
			{
				printf("\n\n\n\tTienes que iniciar sesion para utilizar esta funcion...\n\n\t");
				system("pause");
			}
		}
	} while (opcion!=4);
	
	fclose(FMascotas);
	fclose(FTurnos);
	fclose(FVeterinarios);
	fclose(FUsuarios);
}

int sesion(FILE *FFMascotas, FILE *FFTurnos, FILE *FFUsuarios, FILE *FFVeterinarios)
{
	veterinario regVete;
	personal regPers;
	mascota regMasc;
	turnos regTurn;
	int logreg, errorA=0, errores=0, encontrado=0, confirmo=0;
	char busquedaUSU[11], busquedaCON[61];
	system("cls");
	if (logeado==0)
	{
		do
		{
			errores=1;
			encontrado=0;
			printf("\n\tNombre de usuario del veterinario: ");
			_flushall();
			gets(busquedaUSU);

			//rewind(FFUsuarios);
			rewind(FFVeterinarios);
			//fread(&lectura2, sizeof(personal), 1, FFUsuarios);
			fread(&lectura1, sizeof(veterinario), 1, FFVeterinarios);	
			while(!feof(FFVeterinarios)and encontrado==0)
			{
				if (strcmp(lectura1.usuario,busquedaUSU)==0/* or strcmp(lectura2.usuario,usuarioF)==0*/)
				{
					encontrado=1;
					errores=0;
					printf("\n\tUsuario '%s' encontrado con exito\n\n\t",busquedaUSU);
					system("pause");
				}
				else
				{
					fread(&lectura1, sizeof(veterinario), 1, FFVeterinarios);
					//fread(&lectura2, sizeof(personal), 1, FFUsuarios);
				}
			};
			if (encontrado==0)
			{
				system("cls");
				printf("\n\tNo se encontro al usuario '%s', vuelva a intentarlo...\n\n\t",busquedaUSU);
				system("pause");
				system("cls");
			}
	
		} while (errores!=0);
		
		do
		{
			errores=1;
			encontrado=0;
			system("cls");
			printf("\n\tUsuario: %s",busquedaUSU);
			printf("\n\tContraseña del veterinario: ");
			_flushall();
			gets(busquedaCON);
			
			if (strcmp(lectura1.contrasenia,busquedaCON)!=0) //
			{
				printf("\n\tContraseña incorrecta\n\n\n\tDeseas ingresar otro usuario, o intentar con el mismo?\n\t(1=OTRO, 0=MISMO): ");
				do
				{
					scanf("%i",&numerito);
					if (numerito==1 or numerito==0) return numerito;
					else
					{
						printf("\n\n\tOpcion no valida, vuelve a ingresarla\n\n\tOpcion: ");
					};
				} while (numerito!=1 or numerito!=0);
			}
			else
			{
				system("cls");
				logeado=1;
				errores=0;
				printf("\n\tBienvenido %s!\n\n\t",lectura1.apeNom);
				system("pause");
				numerito=2;
			}
		} while (errores==1 and reintentar!=1);
	} 
	else if (logeado==1)
	{
		printf("\tDeseas cerrar sesion?(1=SI, 0=NO): ");
		scanf("%i",&confirmo);
		if (confirmo==1)
		{
			logeado=0;
			printf("\nSesion cerrada exitosamente. ¡Que tenga un buen dia!");
			numerito=0;
			system("pause");
		};
	};
}

void mostrarListado(FILE *FFMascotas, FILE *FFTurnos, FILE *FFUsuarios, FILE *FFVeterinarios)
{
	int dia, mes, anio, errores=0;
	system("cls");
	printf("\n\tPor favor, ingrese la fecha actual\n\n\t");
	
	do
	{
		errores=1;
		printf("\n\tAño: ");
		scanf("%i", &anio);
		if (anio>=1000 and anio<=9999) errores=0;
		else printf("Tienes que ingresar un año valido (1000-9999)...\n");
	} while (errores==1);
	
	do
	{
		errores=1;
		printf("\tMes: ");
		scanf("%i", &mes);
		if (mes>0 and mes<13) errores=0;
		else printf("Tienes que ingresar un mes valido (1-12)...\n");
	} while (errores==1);
	
	do
	{
		errores=1;
		printf("\tDia: ");
		scanf("%i", &dia);
		if (anio % 4 ==0)
		{
			if (mes==2)
			{
				if (dia>0 and dia<30) errores=0;
				else printf("Tienes que ingresar un dia valido para un año biciesto(1-29)...\n");
			}
			else if (dia>0 and dia<32) errores=0;
			else printf("Tienes que ingresar un dia valido (1-31)...\n");
		}
		else if (mes==2)
		{
			if (dia>0 and dia<29) errores=0;
			else printf("Tienes que ingresar un dia valido (1-28)...\n");
		}
		else if (dia>0 and dia<32) errores=0;
		else printf("Tienes que ingresar un dia valido (1-31)...\n");
		
	} while (errores==1);
		
	
	printf("\n\tMascotas con turno para hoy: ");
}
void atender(FILE *FFMascotas, FILE *FFTurnos, FILE *FFUsuarios, FILE *FFVeterinarios)
{
	
	char apeDuenio[30], nombreMascota[30];
	do
	{
			/*Apellido y Nombres de la mascota (el apellido corresponde al dueño o familia), 
			DNI del dueño, 
			Localidad, 
			Edad (calculada con la fecha de nacimiento registrada), 
			Peso*/
		system("cls");
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
	} while (!feof(FFTurnos));
}
