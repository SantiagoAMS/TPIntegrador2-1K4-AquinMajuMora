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
int logeado=0, reintentar=0, actualizacion=0;


void mostrarListado(FILE *FFmascotas, FILE *FFTurnos, FILE *FFUsuarios, FILE *FFVeterinarios);
void sesion(FILE *FFmascotas, FILE *FFTurnos, FILE *FFUsuarios, FILE *FFVeterinarios);
void atender(FILE *FFmascotas, FILE *FFTurnos, FILE *FFUsuarios, FILE *FFVeterinarios);

main ()
{
	FILE *FMascotas, *FTurnos, *FUsuarios, *FVeterinarios;
	setlocale(LC_ALL, "");
	FMascotas=fopen("Mascotas.dat","r+b");
	FTurnos=fopen("Turnos.dat","r+w");
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
	
	fclose(FMascotas);
	fclose(FTurnos);
	fclose(FVeterinarios);
	fclose(FUsuarios);
}

void sesion(FILE *FFmascotas, FILE *FFTurnos, FILE *FFUsuarios, FILE *FFVeterinarios)
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
			printf("Nombre de usuario del veterinario: ");
			_flushall();
			gets(busquedaUSU);
			rewind(FFVeterinarios);
			while(!feof(FFVeterinarios) and encontrado==0)
			{
				fread(&regVete, sizeof(regVete), 1, FFVeterinarios);
				if (busquedaUSU!=regVete.usuario) //
				{
					printf("No. ");
					fread(&regVete, sizeof(regVete), 1, FFVeterinarios);
				}
				else
				{
					encontrado=1;
					errores=0;
					printf("Usuario '%s' encontrado con exito\n",regVete.usuario);
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
			printf("Usuario: %s\n",regVete.usuario);
			printf("Contrase�a del veterinario: ");
			_flushall();
			gets(busquedaCON);
			
			if (busquedaCON!=regVete.usuario) //
			{
				printf("Contrase�a incorrecta\n Deseas ingresar otro usuario?\n(1=SI, 0=NO): ");
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
				printf("\nBienvenido %s!\n",regVete.apeNom);
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
			printf("\nSesion cerrada exitosamente. �Que tenga un buen dia!");
		};
	};
}

void atender(FILE *FFmascotas, FILE *FFTurnos, FILE *FFUsuarios, FILE *FFVeterinarios)
{
	
	char apeDuenio[30], nombreMascota[30];
	do
	{
			/*Apellido y Nombres de la mascota (el apellido corresponde al due�o o familia), 
			DNI del due�o, 
			Localidad, 
			Edad (calculada con la fecha de nacimiento registrada), 
			Peso*/
		printf("Ingrese el apellido del due�o: ");
		_flushall();
		gets(apeDuenio);
		
		printf("Ingrese el nombre de la mascota: ");
		_flushall();
		gets(apeDuenio);
		
		printf("Ingrese el domicilio de la mascota: ");
		
		printf("Ingrese el dni del due�o: ");
		
		printf("Fecha de nacimiento de la mascota: \n");
		printf("\tA�o: ");
		printf("\tMes: ");
		printf("\tDia: ");
		
		printf("Ingrese el peso de la mascota");
		
		printf("Ingrese el telefono del due�o");
		char Telefono[25];
	} while (!feof(FFTurnos));
}


