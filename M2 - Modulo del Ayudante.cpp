#include "Estructurador.h"

int sesion(FILE *FFMascotas, FILE *FFTurnos, FILE *FFUsuarios, FILE *FFVeterinarios);
int numerito=0, logeado=0, reintentar=0;
//-1 = reintentar en el item 1
// 0 = uso deslogeado
// 1 = reintentar en el item 1
// 2 = salir logeado del item 1
main ()
{
	FILE *FMascotas, *FTurnos, *FUsuarios, *FVeterinarios;
	setlocale(LC_ALL, "");
	FMascotas=fopen("Mascotas.dat","r+b");
	FTurnos=fopen("Turnos.dat","r+b");
	FUsuarios=fopen("Usuarios.dat","r+b");
	FVeterinarios=fopen("Veterinarios.dat","r+b");
	do
	{
		opcion = menu(2);
		if (opcion==1);//Iniciar sesion
		else if (opcion==2);//Registrar mascota
		else if (opcion==3);//registrar turno
		else if (opcion==4);//listado de atenciones por veterinario y fecha
		
	} while (opcion!=5);
	
	do
	{
		if (numerito==2 or logeado==1)//SI la sesion esta iniciada
		{
			menu(5);
			
			if (opcion==1) numerito = sesion(FMascotas, FTurnos, FUsuarios, FVeterinarios);
			else if (opcion==2); //
			else if (opcion==3); //
			else if (opcion==4); //
		}
		else if (numerito==1)//MARCADO para reinicio
		{
			numerito=sesion(FMascotas, FTurnos, FUsuarios, FVeterinarios);
		}
		else if (numerito==0)//SESION NO INICIADA
		{
			opcion = menu(2);
			
			if (opcion==1)numerito=sesion(FMascotas, FTurnos, FUsuarios, FVeterinarios);
			else if (opcion==2 or opcion==3 or opcion==4)
			{
				printf("\n\n\n\tTienes que iniciar sesion para utilizar esta funcion...\n\n\t");
				system("pause");
			}
		}
	} while (opcion!=5);
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
			printf("\n\tNombre de usuario del asistente: ");
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
			printf("\n\tContraseña del asistente: ");
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
