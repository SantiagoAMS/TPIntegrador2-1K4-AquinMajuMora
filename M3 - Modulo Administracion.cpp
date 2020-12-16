#include "Estructurador.h"



/*printf("\n\tTercer modulo: Administracion");                                                                                      
			printf("\n\t ========================="); 
			printf("\n\t 1.- Registrar Veterinario "); 
			printf("\n\t 2.- Registrar Usuario Asistente"); 
			printf("\n\t 3.- Atenciones por Veterinarios "); 
			printf("\n\t 4.- Ranking de Veterinarios por Atenciones "); 
			printf("\n\t 5.- Cerrar la aplicacion. "); */
			
void registrarV(FILE *FFUsuarios, FILE *FFVeterinarios);
void registrarU(FILE *FFUsuarios, FILE *FFVeterinarios);
void atencionesPV(FILE *FFmascotas, FILE *FFTurnos, FILE *FFUsuarios, FILE *FFVeterinarios);
void ranking(FILE *FFmascotas, FILE *FFTurnos, FILE *FFUsuarios, FILE *FFVeterinarios);

main ()
{
	setlocale(LC_ALL, "");
	FILE *FMascotas, *FTurnos, *FUsuarios, *FVeterinarios;
	FMascotas=fopen("Mascotas.dat","r+w");
	FTurnos=fopen("Turnos.dat","r+w");
	FUsuarios=fopen("Usuarios.dat","r+w");
	FVeterinarios=fopen("Veterinarios.dat","r+w");
	do
	{
		opcion = menu(3);
		if (opcion==1)registrarV(FUsuarios, FVeterinarios);
		else if (opcion==2)registrarU(FUsuarios, FVeterinarios);
		else if (opcion==3)atencionesPV(FMascotas, FTurnos, FUsuarios, FVeterinarios);
		else if (opcion==4)ranking(FMascotas, FTurnos, FUsuarios, FVeterinarios);
	}
	while (opcion!=5);
	fclose(FMascotas);
	fclose(FTurnos);
	fclose(FVeterinarios);
	fclose(FUsuarios);
}

void registrarV(FILE *FFUsuarios, FILE *FFVeterinarios)
{
	veterinario regVeteete, lectura1;
	turnos regTurnurn;
	mascota regMascasc;
	personal regPersers, lectura2;

	char usuarioF[11], contraseniaF[33], contraseniaF2[33];
	int introducido=0, errores=-1;
	int numeroCONT=0, mayusCONT=0, minusCONT=0, primeraMinus=0, numerosCONS=0, tieneSimbolo=0;
	int letrasSeguidas=0, volver=0, conteo=0, matricula=0;
	char apeNom[61], telefonoC[11], dni[9];
	
	rewind(FFUsuarios);
	rewind(FFVeterinarios);
	
	if (FFVeterinarios==NULL)
	{
		printf("Error al abrir el archivo veterinario");
		system("pause");
	}
	else
	{
		system("cls");
		printf("\n\nCondiciones para registrar al veterinario: ");
		printf("\n\n\tSer único para cada usuario registrado.");
		printf("\n\tComenzar con una letra minúscula.");
		printf("\n\tTener al menos 6 caracteres y como maximo 10.");
		printf("\n\tTener al menos 2 letras mayúsculas.");
		printf("\n\tTener como máximo 3 dígitos (numeros o simblos). ");
			
		printf("\n\nIngrese el nombre de usuario: ");
		_flushall();
		gets(usuarioF);
		_flushall();
		
		do
		{
			system("cls");
			numeroCONT=0;
			mayusCONT=0;
			primeraMinus=0;
			errores=0;
			rewind(FFUsuarios);
			rewind(FFVeterinarios);
			fread(&lectura1, sizeof(veterinario), 1, FFVeterinarios);
			fread(&lectura2, sizeof(personal), 1, FFUsuarios);
			while(!feof(FFVeterinarios))
			{
				//printf("%s - %s - %s\n",lectura1.usuario,lectura2.usuario,usuarioF);
				//system("pause");

				if (strcmp(lectura1.usuario,usuarioF)==0 or strcmp(lectura2.usuario,usuarioF)==0)
				{
					printf("\n**El nombre de usuario no esta disponible, intenta con otro...");
					errores=1;
				}
				fread(&lectura1, sizeof(veterinario), 1, FFVeterinarios);
				fread(&lectura2, sizeof(personal), 1, FFUsuarios);
			}
			
			if (strlen(usuarioF)<6 or strlen(usuarioF)>10)
			{
				printf("\n**El usuario tiene que tener entre 6 y 10 caracteres...");
				errores==1;
			};
			
			for (int i=0 ; i<10 ; i++)
			{
				if (isdigit(usuarioF[i])) numeroCONT++;
				
				for (int j=0 ; j<26 ; j++)
				{
					if (mayusculas[j]==usuarioF[i]) mayusCONT++;
					if (minusculas[j]==usuarioF[0]) primeraMinus=1;
					if (j<8) if (simbolos[j]==usuarioF[i])numeroCONT++;
				};
			}
			if (mayusCONT<2)
			{
				printf("\n**El usuario tiene que tener al menos 2 mayusculas...");
				errores=1;
			};
			if(primeraMinus==0)
			{
				printf("\n**El primer caracter tiene que ser una minuscula...");
				errores=1;
			};
			if (numeroCONT>3)
			{
				printf("\n**El usuario no puede tener mas de 3 numeros...");
				errores==1;
			};
	
			if (errores==1)
			{
				printf("\n\nCondiciones para registrar al veterinario: ");
				printf("\n\n\tSer único para cada usuario registrado.");
				printf("\n\tComenzar con una letra minúscula.");
				printf("\n\tTener al menos 6 caracteres y como maximo 10.");
				printf("\n\tTener al menos 2 letras mayúsculas.");
				printf("\n\tTener como máximo 3 dígitos (numeros o simblos). ");
				
				printf("\n\nIngrese el nombre de usuario: ");
				_flushall();
				gets(usuarioF);
				_flushall();
			}
		} while (errores==1 or strlen(usuarioF)<6);
		strcpy(regVeteete.usuario,usuarioF);
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////Contraseña//////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		system("cls");
		printf("El nombre del veterinario '%s' esta disponible... \n\nCondiciones para escribir una contraseña: \n",usuarioF);
		printf("\n\tAl menos una mayúscula, una minúscula y un número");
		printf("\n\tSolo letras y numeros");
		printf("\n\tDeberá tener entre 6 y 32 caracteres");
		printf("\n\tNo puede tener 4 numeros seguidos");
		printf("\n\tNo puede tener simbolos (+-/*?¿!¡)");
		printf("\n\tNo debe tener 2 letras consecutivas alfabeticamente (ab - Bc - Mn - XY)");
		
		printf("\n\nIngrese la contraseña para el usuario %s: ",usuarioF);
		_flushall();
		gets(contraseniaF);
		_flushall();
		
		do
		{
			system("cls");
			numeroCONT=0;
			minusCONT=0;
			numerosCONS=0;
			tieneSimbolo=0;
			errores=0;
			letrasSeguidas=0;
			mayusCONT=-1;
			volver=0;
			
			for (int i=0 ; i<36 ; i++)
			{
				if (i<10)
				{
					if (isdigit(contraseniaF[i])) numeroCONT++;
					
					for (int j=0 ; j<25 ; j++)
					{
						if (mayusculas[j]==contraseniaF[i])mayusCONT++;
	
						if (minusculas[j]==contraseniaF[i]) minusCONT=1;
						if (j<25) if ((mayusculas[j]==contraseniaF[i] or (minusculas[j]==contraseniaF[i])) and (mayusculas[j+1]==contraseniaF[i+1] or (minusculas[j+1]==contraseniaF[i+1]))) letrasSeguidas=1;
						if (j<8) if (simbolos[j]==contraseniaF[i])tieneSimbolo=1;
					};
				};
				if (i<33)
				{
					if(isdigit(contraseniaF[i]) and isdigit(contraseniaF[i+1]) and isdigit(contraseniaF[i+2])) numerosCONS=1;
				}
			};
			if (minusCONT<1)
			{
				printf("\n**La contraseña tiene que tener al menos una minuscula");
				errores=1;
			}
			if (mayusCONT<1)
			{
				printf("\n**La contraseña tiene que tener al menos una mayuscula");
				errores=1;
			};
			if (numeroCONT==0)
			{
				printf("\n**La contraseña tiene que tener al menos un numero");
				errores=1;
			}
			if (strlen(contraseniaF)<6 or strlen(contraseniaF)>32)
			{
				printf("\n**La contraseña debe tener entre 6 y 32 caracteres...");
				errores==1;
			};
			if (numerosCONS==1)
			{
				printf("\n**La contraseña no puede tener mas de 3 numeros consecutivos");
				errores==1;
			};
	
			if(letrasSeguidas==1)
			{
				printf("\n**La contraseña no puede tener letras consecutivas alfabeticamente");
				errores==1;
			}
			if (errores==0)
			{
				system("cls");
				printf("Vuelve a escribir la contraseña para confirmarla\nO escribe 'salir' para introducir una nueva\n\n");
				printf("Ingresa la contraseña: ");
				_flushall();
				gets(contraseniaF2);
				
				if (strcmp(contraseniaF2,contraseniaF)==0)
				{
					printf("\n\nLa contraseña para el usuario %s es %s\n¡Recuerdala bien!\n\n",usuarioF,contraseniaF);
					system("pause");
				}
				else if (strcmp(strlwr(contraseniaF2),"salir")==0)
				{
					volver=1;
					errores==1;
					system("cls");
				}
				else
				{
					printf("\n\nLa contraseña ingresada no es correcta... \n\n");
					system("pause");
					errores==1;
				}
			};
			if (errores==1 or volver==1)
			{
				printf("\n\nCondiciones para escribir una contraseña: \n");
				printf("\n\tAl menos una mayúscula, una minúscula y un número");
				printf("\n\tSolo letras y numeros");
				printf("\n\tDeberá tener entre 6 y 32 caracteres");
				printf("\n\tNo puede tener 4 numeros seguidos");
				printf("\n\tNo puede tener simbolos (+-/*?¿!¡)");
				printf("\n\tNo debe tener 2 letras consecutivas alfabeticamente (ab - Bc - Mn - XY)");
				
				printf("\n\nIngrese la contraseña para el usuario %s: ",usuarioF);
				_flushall();
				gets(contraseniaF);
			}
		} while (errores==1 or strlen(contraseniaF)<6 or strlen(contraseniaF)>32 or strcmp(contraseniaF2,contraseniaF)!=0 or volver==1);
		strcpy(regVeteete.contrasenia,contraseniaF);
		
		
		system("cls");
		
		printf("Ingrese el apellido y nombre del veterinario: ");
		_flushall();
		gets(regVeteete.apeNom);
		system("cls");
		
		printf("Ingrese el numero de matricula del veterinario: ");
		scanf("%i",&regVeteete.matricula);
		system("cls");
		
		do
		{
			system("cls");
			errores=0;
			conteo=0;
			printf("Ingrese el telefono del veterinario: ");
			printf("\nEl formato solicitado es el siguiente: XXX XXX-XXXX (sin espacios o signos, solo numeros): ");
			printf("\n                              Ejemplo: 381 948-3852 (deberia escribirse como 3819483852)");
			printf("\n                              Ingreso: ");
			_flushall();
			gets(regVeteete.telefono);
			
			for (int i=0;i<10;i++)
			{
				if (isdigit(regVeteete.telefono[i]))conteo++;
				else
				{
					i=10;
					errores=1;
				}
			};
			if (conteo!=10)
			{
				printf("El numero tiene que tener 10 digitos (numeros)\n");
				errores=1;
				system("pause");
			}
		} while (errores==1);
		
		do
		{
			system("cls");
			errores=0;
			conteo=0;
			
			printf("Ingrese el dni del veterinario: ");
			_flushall();
			gets(regVeteete.dni);
			
			for (int i=0;i<7;i++)
			{
				if (isdigit(regVeteete.dni[i]))conteo++;
				else
				{
					i=10;
					errores=1;
				}
			};
			if (conteo!=7)
			{
				printf("\nEl numero tiene que tener 7 digitos (numeros)\n\n");
				errores=1;
				system("pause");
			}
			
		} while (errores==1);
		
		_flushall();
		fwrite(&regVeteete, sizeof(veterinario), 1, FFVeterinarios);
		//fwrite(&reg, sizeof(registro), 1, archivo1);
		
		/*char apeNom[60];
		int matricula;
		char dni;
		char telefono[11];
		char usuario[10];
		char contrasenia[32]*/
		printf("\n\nVeterinario ingresado exitosamente\n\n");
		
	}
	
	system("pause");
}

void registrarU(FILE *FFUsuarios, FILE *FFVeterinarios)
{
	veterinario lectura1;
	//turnos regTurnurn;
	//mascota regMascasc;
	personal lectura2;

	char usuarioF[11], contraseniaF[33], contraseniaF2[33];
	int introducido=0, errores=-1;
	int numeroCONT=0, mayusCONT=0, minusCONT=0, primeraMinus=0, numerosCONS=0, tieneSimbolo=0;
	int letrasSeguidas=0, volver=0, conteo=0;
	char apeNom[61];
	
	rewind(FFUsuarios);
	rewind(FFVeterinarios);
	
	if (FFUsuarios==NULL)
	{
		printf("Error al abrir el archivo veterinario");
		system("pause");
	}
	else
	{
		system("cls");
		printf("Condiciones para validar el usuario del asistente: ");
		printf("\n\n\tNombre de usuario unico.");
		printf("\n\tComenzar con una letra minúscula.");
		printf("\n\tTener al menos 2 letras mayúsculas.");
		printf("\n\tTener como máximo 3 dígitos o simbolos. ");
			
		printf("\n\nIngrese el nombre de usuario: ");
		_flushall();
		gets(usuarioF);
		
		do
		{
			system("cls");
			numeroCONT=0;
			mayusCONT=0;
			primeraMinus=0;
			errores=0;
			rewind(FFUsuarios);
			rewind(FFVeterinarios);
			fread(&lectura1, sizeof(veterinario), 1, FFVeterinarios);
			fread(&lectura2, sizeof(personal), 1, FFUsuarios);
			while(!feof(FFVeterinarios))
			{
				if (strcmp(lectura1.usuario,usuarioF)==0 or strcmp(lectura2.usuario,usuarioF)==0)
				{
					printf("**El nombre de usuario no esta disponible, intenta con otro...");
					errores=1;
				}
				fread(&lectura1, sizeof(veterinario), 1, FFVeterinarios);
				fread(&lectura2, sizeof(personal), 1, FFUsuarios);
			}
			
			if (strlen(usuarioF)<6 or strlen(usuarioF)>10)
			{
				printf("\n**El usuario tiene que tener entre 6 y 10 caracteres...");
				errores==1;
			};
			
			for (int i=0 ; i<10 ; i++)
			{
				if (isdigit(usuarioF[i])) numeroCONT++;
				
				for (int j=0 ; j<26 ; j++)
				{
					if (mayusculas[j]==usuarioF[i]) mayusCONT++;
					if (minusculas[j]==usuarioF[0]) primeraMinus=1;
					if (j<8) if (simbolos[j]==usuarioF[i])numeroCONT++;
				};
			}
			if (mayusCONT<2)
			{
				printf("\n**El usuario tiene que tener al menos 2 mayusculas...");
				errores=1;
			};
			if(primeraMinus==0)
			{
				printf("\n**El primer caracter tiene que ser una minuscula...");
				errores=1;
			};
			if (numeroCONT>3)
			{
				printf("\n**El usuario no puede tener mas de 3 numeros...");
				errores==1;
			};
	
			if (errores==1)
			{
				printf("\n\nCondiciones para validar el usuario del asistente: ");
				printf("\n\n\tNombre de usuario unico.");
				printf("\n\tComenzar con una letra minúscula.");
				printf("\n\tTener al menos 2 letras mayúsculas.");
				printf("\n\tTener como máximo 3 dígitos o simbolos. ");
				
				printf("\n\nIngrese el nombre de usuario: ");
				_flushall();
				gets(usuarioF);
				_flushall();
			}
		} while (errores==1);
		strcpy(regPers.usuario,usuarioF);
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////Contraseña//////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		system("cls");
		printf("El nombre del veterinario '%s' esta disponible... \n\nCondiciones para escribir una contraseña: \n",usuarioF);
		printf("\n\tAl menos una mayúscula, una minúscula y un número");
		printf("\n\tSolo letras y numeros");
		printf("\n\tDeberá tener entre 6 y 32 caracteres");
		printf("\n\tNo puede tener 4 numeros seguidos");
		printf("\n\tNo puede tener simbolos (+-/*?¿!¡)");
		printf("\n\tNo debe tener 2 letras consecutivas alfabeticamente (ab - Bc - Mn - XY)");
		
		printf("\n\nIngrese la contraseña para el usuario %s: ",usuarioF);
		_flushall();
		gets(contraseniaF);
		
		do
		{
			system("cls");
			numeroCONT=0;
			minusCONT=0;
			numerosCONS=0;
			tieneSimbolo=0;
			errores=0;
			letrasSeguidas=0;
			mayusCONT=-1;
			volver=0;
			
			for (int i=0 ; i<36 ; i++)
			{
				if (i<10)
				{
					if (isdigit(contraseniaF[i])) numeroCONT++;
					
					for (int j=0 ; j<25 ; j++)
					{
						if (mayusculas[j]==contraseniaF[i])mayusCONT++;
	
						if (minusculas[j]==contraseniaF[i]) minusCONT=1;
						if (j<25) if ((mayusculas[j]==contraseniaF[i] or (minusculas[j]==contraseniaF[i])) and (mayusculas[j+1]==contraseniaF[i+1] or (minusculas[j+1]==contraseniaF[i+1]))) letrasSeguidas=1;
						if (j<8) if (simbolos[j]==contraseniaF[i])tieneSimbolo=1;
					};
				};
				if (i<33)
				{
					if(isdigit(contraseniaF[i]) and isdigit(contraseniaF[i+1]) and isdigit(contraseniaF[i+2])) numerosCONS=1;
				}
			};
			if (minusCONT<1)
			{
				printf("\n**La contraseña tiene que tener al menos una minuscula");
				errores=1;
			}
			if (mayusCONT<1)
			{
				printf("\n**La contraseña tiene que tener al menos una mayuscula");
				errores=1;
			};
			if (numeroCONT==0)
			{
				printf("\n**La contraseña tiene que tener al menos un numero");
				errores=1;
			}
			if (strlen(contraseniaF)<6 or strlen(contraseniaF)>32)
			{
				printf("\n**La contraseña debe tener entre 6 y 32 caracteres...");
				errores==1;
			};
			if (numerosCONS==1)
			{
				printf("\n**La contraseña no puede tener mas de 3 numeros consecutivos");
				errores==1;
			};
	
			if(letrasSeguidas==1)
			{
				printf("\n**La contraseña no puede tener letras consecutivas alfabeticamente");
				errores==1;
			}
			if (errores==0)
			{
				system("cls");
				printf("Vuelve a escribir la contraseña para confirmarla\nO escribe 'salir' para introducir una nueva\n\n");
				printf("Ingresa la contraseña: ");
				_flushall();
				gets(contraseniaF2);
				
				if (strcmp(contraseniaF2,contraseniaF)==0)
				{
					printf("\n\nLa contraseña para el usuario %s es %s\n¡Recuerdala bien!\n\n",usuarioF,contraseniaF);
					system("pause");
				}
				else if (strcmp(strlwr(contraseniaF2),"salir")==0)
				{
					volver=1;
					errores==1;
					system("cls");
				}
				else
				{
					printf("\n\nLa contraseña ingresada no es correcta... \n\n");
					system("pause");
					errores==1;
				}
			};
			if (errores==1 or volver==1)
			{
				printf("\n\nCondiciones para escribir una contraseña: \n");
				printf("\n\tAl menos una mayúscula, una minúscula y un número");
				printf("\n\tSolo letras y numeros");
				printf("\n\tDeberá tener entre 6 y 32 caracteres");
				printf("\n\tNo puede tener 4 numeros seguidos");
				printf("\n\tNo puede tener simbolos (+-/*?¿!¡)");
				printf("\n\tNo debe tener 2 letras consecutivas alfabeticamente (ab - Bc - Mn - XY)");
				
				printf("\n\nIngrese la contraseña para el usuario %s: ",usuarioF);
				_flushall();
				gets(contraseniaF);
			}
		} while (errores==1 or strlen(contraseniaF)<6 or strlen(contraseniaF)>32 or strcmp(contraseniaF2,contraseniaF)!=0 or volver==1);
		strcpy(regPers.contrasenia,contraseniaF);
		
		
		system("cls");
		
		printf("Ingrese el apellido y nombre del asistente: ");
		_flushall();
		gets(regPers.apeNom);
		system("cls");
		
		_flushall();
		fwrite(&regPers, sizeof(personal), 1, FFUsuarios);

		printf("\n\nAsistente ingresado exitosamente\n\n");
	}
	
	system("pause");
}

void atencionesPV(FILE *FFmascotas, FILE *FFTurnos, FILE *FFUsuarios, FILE *FFVeterinarios)
{
	system("cls");
}

void ranking(FILE *FFmascotas, FILE *FFTurnos, FILE *FFUsuarios, FILE *FFVeterinarios)
{
	system("cls");
	printf("Ranking de los veterinarios con mas mascotas atendidas: ");
	
	rewind(FFmascotas);
	rewind(FFTurnos);
	rewind(FFUsuarios);
	rewind(FFVeterinarios);
	
	//leer a todas las mascotas atendidas
	//generar un vector con ese tamaño
	//agregar por cada elemento el nombre
	//contar la cantidad de veces que se repite un nombre
	
	//contar la cantidad de veces que se repite un nombre
	
	/*while(!feof(FFVeterinarios) and encontrado==0)
	{
		//fread(&regVete, sizeof(regVete), 1, FFVeterinarios);
	}*/
}
