

#include <stdlib.h>
#include "ArrayEmployees.h"
#define LEN 4
int main(void)
{
	setbuf(stdout,NULL);

	Employee arrayEmployee[LEN];

	int option;
	int subMenuOption;
	char strOption[3];
	int itCanPrint;
	int itCanDelete;
	int itCanSort;
	int itCanModify;
	int accountant;
	int itCanLoad;
	char strId[10];

	int flag;

	flag = 0;

	accountant = 0;
	initEmployees(arrayEmployee,LEN);
	do
	{

		option = Menu("1.ALTAS\n2.MODIFICAR\n3.BAJA\n4.INFORMAR\n5.SALIR\nIngrese opcion: ",strOption,"Ingrese opcion valida: ");
		switch(option)
		{
		case 1:
			flag = 1;
			itCanLoad = loadEmployee(arrayEmployee,LEN,accountant,1);
			if(itCanLoad==1)
			{
				accountant++;
				printf("Carga exitosa!\n");

			}
			else
			{
				printf("Espacio insuficiente\n");
			}

			break;

		case 2:
			if(flag==1)
			{
				itCanModify = getIdEmployeeModify("Ingrese id a modificar: ",strId,"Ingrese id existente: ","Ingrese opcion valida: ",arrayEmployee,LEN);
				switch(itCanModify)
				{
				case 0:
					printf("Modificacion cancelada\n");
					break;
				case -1:
					printf("No se encontro id\n");
					break;
				case 1:
					printf("Saliste de modificacion\n");
					break;
				}
			}
			else
			{
				printf("Cargue datos\n");
			}

			break;
		case 3:
			if(flag==1)
			{
				itCanDelete = getIdEmployeeDelete("Ingrese id a eliminar: ",strId,"Ingrese id existente: ","Ingrese opcion valida: ",arrayEmployee,LEN);
				switch(itCanDelete)
				{
				case 1:
					printf("Eliminacion exitosa!\n");
					break;
				case 0:
					printf("Eliminacion cancelada\n");
					break;
				case -1:
					printf("No se encontro id\n");
					break;
				}
			}
			else
			{
				printf("Cargue datos\n");
			}

			break;
		case 4:
			if(flag==1)
			{
				do
				{
					subMenuOption = Menu("1.Ordenar listado\n2.Total de los salarios\n3.Promedio de los salarios\n4.Cantidad de empleados que superan el salario promedio\n5.Volver\nIngrese opcion: ",strOption,"Ingrese opcion valida: ");
					switch(subMenuOption)
					{
					case 1:

						itCanSort = menuOrdenamiento("1.Ordenar por apellido\n2.Ordenar por sector\n3.Salir\nIngrese opcion: ",strOption,"Ingrese opcion valida: ",arrayEmployee,LEN,"1.Ordenar de forma Ascendente\n0.Ordenar de forma Descendente\n2.Volver\nIngrese opcion: ");
						switch(itCanSort)
						{
						case 0:
							printf("Ordenamiento cancelado\n");
							break;
						case -1:
							printf("No se pudo ordenar\n");
						break;

						case 1:
							printf("Saliste de ordenamiento\n");
							break;

						}
						break;

				   case 2:

					itCanPrint = printTotalSalary(arrayEmployee,LEN);
					if(itCanPrint==1)
					{
						printf("Informe exitoso!\n");
					}
					else
					{
						printf("No se pudo informar\n");
					}
					break;

				  case 3:

					itCanPrint = printAverageSalary(arrayEmployee,LEN);
					if(itCanPrint==1)
					{
						printf("Informe exitoso!\n");
					}
					else
					{
						printf("No se pudo informar\n");
					}
					break;

				case 4:

					itCanPrint = printEmployeeExceedsAverageSalary(arrayEmployee,LEN);
					if(itCanPrint==1)
					{
						printf("Informe exitoso!\n");
					}
					else
					{
						printf("No se pudo informar\n");
					}
					break;

				case 5:

					printf("Saliste de INFORMES\n");
					break;

				default:
					printf("Ingrese opcion valida\n");
				 }
				}while(subMenuOption!=5);
			}
			else
			{
				printf("Cargue datos\n");
			}


		break;

		case 5:
			printf("FIN DEL PROGRAMA\n");
			break;
		default:
			printf("Ingrese opcion valida\n");
		}
	}while(option!=5);











	return EXIT_SUCCESS;
}
