#include "ArrayEmployees.h"
int initEmployees(Employee arrayEmployees[],int len)
{
	int i;
	int retorno;

	retorno = -1;
	for(i=0;i<len;i++)
	{
		arrayEmployees[i].isEmpty = FREE;
		retorno = 0;
	}

	return retorno;
}
int findEmployeeById(Employee arrayEmployees[],int len,int id)
{
	int i;
	int index;

	index = -1;

	for(i=0;i<len;i++)
	    {
	        if(arrayEmployees[i].id == id)
	        {
	            index = i;
	            break;

	        }
	    }

	return index;

}
int searchFreeEmployee(Employee arrayEmployee[],int len)
{
	int i;
	int index;
	index = -1;

	for(i=0; i<len; i++)
	{
		if(arrayEmployee[i].isEmpty == FREE)
		{
			index = i;
			break;
		}
	}

	return index;

}

int generateId(int accountant,int idInitiation)
{
	int id;
	if(accountant == 0 || accountant > 0)
	{
		id=accountant+idInitiation;
	}


	return id;
}
Employee registerAnEmployee(Employee arrayEmployee[],int lenEmployee,int idInitiation,int accountant)
{

	Employee anEmployee;
	char salary[10];
	char sector[10];
	anEmployee.id = 0;


	anEmployee.id = generateId(accountant,idInitiation);
	GetString("Ingrese nombre: ",anEmployee.name,"Ingrese solo letras: ");
	GetString("Ingrese apellido: ",anEmployee.lastName,"Ingrese solo letras: ");
	anEmployee.salary = GetFloat("Ingrese salario: ",salary,"Ingrese salario valido: ");
	anEmployee.sector = GetInt("Ingrese sector: ",sector,"Ingrese solo numeros: ");
	anEmployee.isEmpty = OCCUPIED;

	return anEmployee;
}
int loadEmployee(Employee arrayEmployee[],int len,int accountant,int idInitiation)
{
	int i;
	int index;
	int returnValue;

	returnValue = -1;
	index = searchFreeEmployee(arrayEmployee,len);
	if(index!=-1)
	{
		for(i=0;i<len;i++)
		{

			if(addEmployees(arrayEmployee,len,arrayEmployee[index].id,arrayEmployee[index].name,arrayEmployee[index].lastName,arrayEmployee[index].salary,arrayEmployee[index].sector)==0)
			{
				arrayEmployee[index] = registerAnEmployee(arrayEmployee,len,idInitiation,accountant);
				returnValue = 1;
				break;
			}
		}
	}


	return returnValue;
}
int addEmployees(Employee arrayEmployee[],int len,int id,char name[],char lastName[],float salary,int sector)
{
	int index;
	int returnValue;
	int i;

	returnValue = -1;

	index = searchFreeEmployee(arrayEmployee,len);

	if(index!=-1)
	{
		for(i=0;i<len;i++)
		{

			arrayEmployee[index].id = id;
			strcpy(arrayEmployee[index].name,name);
			strcpy(arrayEmployee[index].lastName,lastName);
			arrayEmployee[index].salary = salary;
			arrayEmployee[index].sector = sector;
			returnValue = 0;
			break;


		}
	}

	return returnValue;

}
int getIdEmployeeDelete(char message[],char str[],char error[],char errorOnlyNumbers[],Employee arrayEmployee[],int len)
{
	int returnValue;
	int accountant;

	int id;
	accountant = 0;
	int itCanDelete;


	printEmployee(arrayEmployee,len);

	id = GetInt(message,str,errorOnlyNumbers);
	itCanDelete = removeEmployee(arrayEmployee,len,id);
	while(itCanDelete==-1)
	{
		accountant++;
		if(accountant<4)
		{
			printf("%s",error);
			scanf("%d",&id);
			itCanDelete = removeEmployee(arrayEmployee,len,id);

		}
		else
		{
			returnValue = -1;
			break;
		}

	}
	if(itCanDelete==0)
	{
		returnValue = 0;
	}
	else
	{
		if(itCanDelete==1)
		{
			returnValue = 1;
		}

	}

	return returnValue;

}
int getIdEmployeeModify(char message[],char str[],char error[],char errorOnlyNumbers[],Employee arrayEmployee[],int len)
{
	int returnValue;
	int id;
	int itCanModify;
	int accountant;

	accountant = 0;

	printEmployee(arrayEmployee,len);

	id = GetInt(message,str,errorOnlyNumbers);
	itCanModify = modifyEmployee(arrayEmployee,len,id);

	while(itCanModify==-1)
	{
		accountant++;
		if(accountant<4)
		{
			printf("%s",error);
			scanf("%d",&id);
			itCanModify = modifyEmployee(arrayEmployee,len,id);
		}
		else
		{
			returnValue = -1;
			break;
		}
	}

	if(itCanModify==0)
	{
		returnValue = 0;
	}
	else
	{
		if(itCanModify==1)
		{
			returnValue = 1;
		}

	}

	return returnValue;


	}



int searchIdEmployee(Employee arrayEmployee[],int len,int id)
{
	int i;
	int returnId;

	returnId = -1;

	for(i=0;i<len;i++)
	{
		if(arrayEmployee[i].id == id && id > 0)
		{
			returnId = id;

			break;
		}

	}

	return returnId;
}
int modifyEmployee(Employee arrayEmployee[],int len,int id)
{

	int returnValue;
	int i;
	char userAnswer;
	char strOption[3];
	char auxName[11];
	char auxLastName[11];
	char strAuxSalary[10];
	float auxSalary;
	char strAuxSector[10];
	int auxSector;
	int opcion;
	userAnswer = ' ';

		returnValue = -1;

		id = searchIdEmployee(arrayEmployee,len,id);
			for(i=0;i<len;i++)
				{
					if(arrayEmployee[i].id==id)
					{
						printf("Se modificara a:");
						printAnEmployee(arrayEmployee[i]);
						userAnswer=GetChar("Realizar modificacion s/n: ",userAnswer,"Ingrese respuesta valida: ",'s','n');
						if(userAnswer=='s')
						{
							do
							{
								opcion = Menu("Seleccione que desea modificar:\n1.Nombre\n2.Apellido\n3.Salario\n4.Sector\n5.Salir\nSeleccione opcion: ",strOption,"Ingrese opcion valida: ");
								switch(opcion)
								{
									case 1:
										GetString("Ingrese nombre nuevo: ",auxName,"Ingrese solo letras: ");
										userAnswer=GetChar("Modificar nombre? s/n: ",userAnswer,"Ingrese respuesta valida: ",'s','n');
										if(userAnswer=='s')
										{
											strcpy(arrayEmployee[i].name,auxName);
											printf("Modificacion realizada!\n");
										}
										else
										{
											printf("Modificacion cancelada\n");
										}
										break;
									case 2:
										GetString("Ingrese apellido nuevo: ",auxLastName,"Ingrese solo letras: ");
										userAnswer=GetChar("Modificar apellido? s/n: ",userAnswer,"Ingrese respuesta valida: ",'s','n');
										if(userAnswer=='s')
										{
											strcpy(arrayEmployee[i].lastName,auxLastName);
											printf("Modificacion realizada!\n");
										}
										else
										{
											printf("Modificacion cancelada\n");
										}
										break;
									case 3:
										auxSalary = GetFloat("Ingrese salario nuevo: ",strAuxSalary,"Ingrese salario valido: \n");
										userAnswer=GetChar("Modificar salario? s/n: ",userAnswer,"Ingrese respuesta valida: ",'s','n');
										if(userAnswer=='s')
										{
											arrayEmployee[i].salary = auxSalary;
											printf("Modificacion realizada!\n");
										}
										else
										{
											printf("Modificacion cancelada\n");
										}

										break;
									case 4:
										auxSector = GetInt("Ingrese sector nuevo:  ",strAuxSector,"Ingrese solo numeros: ");
										userAnswer=GetChar("Modificar sector? s/n: ",userAnswer,"Ingrese respuesta valida: ",'s','n');
										if(userAnswer=='s')
										{
											arrayEmployee[i].sector = auxSector;
											printf("Modificacion realizada!\n");
										}
										else
										{
											printf("Modificacion cancelada\n");
										}
										break;
									case 5:
										returnValue = 1;
										break;
								}

							}while(opcion!=5);

						}
						else
						{
							returnValue = 0;
							break;
						}

						break;

					}

			}

		return returnValue;

}
int removeEmployee(Employee arrayEmployee[],int len,int id)
{
	int returnValue;
	int i;
	char userAnswer;

	userAnswer = ' ';
	returnValue = -1;
	id = searchIdEmployee(arrayEmployee,len,id);
	for(i=0;i<len;i++)
	{
		if(arrayEmployee[i].id==id)
		{
			printf("Se eliminara a:\n");
			printAnEmployee(arrayEmployee[i]);
			userAnswer = GetChar("Realizar eliminacion? s/n:",userAnswer,"Ingrese respuesta valida: ",'s','n');
			if(userAnswer=='s')
			{
				arrayEmployee[i].isEmpty = FREE;
				returnValue = 1;
				break;
			}
			else
			{
				returnValue = 0;
				break;
			}

			break;
		}

	}



	return returnValue;


}
int menuOrdenamiento(char message[],char str[],char error[],Employee arrayEmployee[],int len,char subMenuMessage[])
{
	int option;
	int returnValue;
	int itCanOrderAsc;
	int itCanOrderDesc;
	int subMenuOption;
	char userAnswer;
	userAnswer = 's';


	returnValue = -1;
	userAnswer = GetChar("Ingreso a ordenamiento. Se ordenara la lista de la forma que prefiera(ASC/DESC).Continuar?s/n: ",userAnswer,"Ingrese respuesta valida: ",'s','n');
	if(userAnswer=='s')
	{

		do
			{

				option = Menu(message,str,error);
				switch(option)
				{
				case 1:
					subMenuOption = Menu(subMenuMessage,str,error);
					switch(subMenuOption)
					{
					case 1:

						itCanOrderAsc = sortEmployeeByLastName(arrayEmployee,len,1);
						if(itCanOrderAsc==0)
						{
							 printEmployee(arrayEmployee,len);
							 printf("Se ordeno exitosamente!\n");
						}
						else
						{
							printf("Esta lista ya esta ordenada\n");
						}
						break;
					case 0:
						itCanOrderDesc = sortEmployeeByLastName(arrayEmployee,len,0);
						if(itCanOrderDesc==0)
						{
							printEmployee(arrayEmployee,len);
							printf("Se ordeno exitosamente!\n");
						}
						else
						{
							printf("Esta lista ya esta ordenada\n");
						}

						break;
					case 2:
						printf("Saliste del ordenamiento por apellido\n");
						break;

					default:
						printf("Ingrese opcion valida\n");

					}

					break;
					case 2:

						subMenuOption = Menu(subMenuMessage,str,error);
						switch(subMenuOption)
						{
						case 1:
							itCanOrderAsc = sortEmployeeBySector(arrayEmployee,len,1);
							if(itCanOrderAsc==0)
							{
								printEmployee(arrayEmployee,len);
								printf("Se ordeno exitosamente!\n");

							}
							else
							{
								printf("Esta lista ya esta ordenada\n");
							}
							break;
						case 0:
							itCanOrderDesc = sortEmployeeBySector(arrayEmployee,len,0);
							if(itCanOrderDesc==0)
							{
								printEmployee(arrayEmployee,len);
								printf("Se ordeno exitosamente!\n");

							}
							else
							{
								printf("Esta lista ya esta ordenada\n");
							}
							break;

						case 2:
							printf("Saliste del ordenamiento por sector\n");
							break;

						default:
							printf("Ingrese opcion valida\n");

						break;


						}
						break;
					case 3:
						returnValue = 1;
						break;

				}

			}while(option!=3);

	}
	else
	{
		returnValue = 0;
	}

	return returnValue;
}
int sortEmployeeByLastName(Employee arrayEmployee[],int len,int order)
{
	int i;
	int j;
	int returnValue;
	Employee auxEmployee;

	returnValue = -1;

	for(i=0;i<len-1;i++)
	{
		for(j=i+1;j<len;j++)
		{
			if(order == 1)
			{
				if(strcmp(arrayEmployee[i].lastName,arrayEmployee[j].lastName)>0)
				{
					auxEmployee = arrayEmployee[i];
					arrayEmployee[i] = arrayEmployee[j];
					arrayEmployee[j] = auxEmployee;
					returnValue = 0;
				}
			}
			else
			{
				if(strcmp(arrayEmployee[i].lastName,arrayEmployee[j].lastName)<0)
				{
					auxEmployee = arrayEmployee[i];
					arrayEmployee[i] = arrayEmployee[j];
					arrayEmployee[j] = auxEmployee;
					returnValue = 0;
				}
			}

		}
	}

	return returnValue;
}
int sortEmployeeBySector(Employee arrayEmployee[],int len,int order)
{
	int i;
		int j;
		int returnValue;
		Employee auxEmployee;

		returnValue = -1;

		for(i=0;i<len-1;i++)
		{
			for(j=i+1;j<len;j++)
			{
				if(order == 1)
				{
					if(arrayEmployee[i].sector > arrayEmployee[j].sector)
					{
						auxEmployee = arrayEmployee[i];
						arrayEmployee[i] = arrayEmployee[j];
						arrayEmployee[j] = auxEmployee;
						returnValue = 0;
					}
				}
				else
				{
					if(arrayEmployee[i].sector < arrayEmployee[j].sector)
					{
						auxEmployee = arrayEmployee[i];
						arrayEmployee[i] = arrayEmployee[j];
						arrayEmployee[j] = auxEmployee;
						returnValue = 0;
					}
				}

			}
		}

		return returnValue;
}
float calculateAverage(int acumulator,int accountant)
{
	float average;

	average = (float)acumulator/accountant;

	return average;
}
float calculateAverageSalary(Employee arrayEmployee[],int len)
{
	int accountant;
	int acumulator;
	int i;
	float averageSalary;
	accountant=0;
	acumulator = 0;

	averageSalary = 0;

	for(i=0;i<len;i++)
	{
		if(arrayEmployee[i].isEmpty==OCCUPIED)
		{
			accountant++;
			acumulator+=arrayEmployee[i].salary;


		}

	}
	if(acumulator!=0)
	{
		averageSalary = calculateAverage(acumulator,accountant);
	}




	return averageSalary;

}
int printAverageSalary(Employee arrayEmployee[],int len)
{

	float salaryAverage;
	int returnValue;

	returnValue = -1;

	salaryAverage = calculateAverageSalary(arrayEmployee,len);
	printf("El promedio de los salarios es: %.3f\n", salaryAverage);

	returnValue = 1;

	return returnValue;
}
float calculateTotalSalary(Employee arrayEmployee[],int len)
{
	int acumulator;
	int i;
	acumulator = 0;
	float totalSalary;

	for(i=0;i<len;i++)
	{
		if(arrayEmployee[i].isEmpty==OCCUPIED)
		{
			acumulator+=arrayEmployee[i].salary;


		}

	}
	totalSalary = acumulator;


	return totalSalary;
}
int printTotalSalary(Employee arrayEmployee[],int len)
{
	float totalSalary;
	int returnValue;

	returnValue = -1;

	totalSalary = calculateTotalSalary(arrayEmployee,len);
	printf("El total de los salarios es: %.3f\n",totalSalary);

	returnValue = 1;

	return returnValue;
}
int countEmployeeExceedsAverageSalary(Employee arrayEmployee[],int len)
{
	float salaryAverage;
	int accountant;
	int i;

	accountant = 0;

	salaryAverage = calculateAverageSalary(arrayEmployee,len);

	for(i=0;i<len;i++)
	{
		if(arrayEmployee[i].salary > salaryAverage && arrayEmployee[i].isEmpty == OCCUPIED)
		{
			accountant++;
		}
	}

	return accountant;
}
int printEmployeeExceedsAverageSalary(Employee arrayEmployee[],int len)
{
	int returnValue;

	int amountEmployeeExceedsAverageSalary;

	returnValue = -1;

	amountEmployeeExceedsAverageSalary = countEmployeeExceedsAverageSalary(arrayEmployee,len);

	printf("La cantidad de empleados que superan el salario promedio es: %d\n",amountEmployeeExceedsAverageSalary);

	returnValue = 1;

	return returnValue;
}
int printAnEmployee(Employee aEmployee)
{
	int returnValue;

	returnValue = -1;

	printf("%4d %15s %14s %15.3f %15d\n",aEmployee.id,
										 aEmployee.name,
										 aEmployee.lastName,
										 aEmployee.salary,
										 aEmployee.sector);

	returnValue = 1;


	return returnValue;
}
int printEmployee(Employee arrayEmployee[],int len)
{
	int returnValue;
	int itCanPrint;
	int i;

	returnValue = -1;
	//printf("%4s %15s %15s %15s %15s\n","ID","NAME","LASTNAME","SALARY","SECTOR");
	for(i=0;i<len;i++)
	{

		if(arrayEmployee[i].isEmpty == OCCUPIED)
		{
			itCanPrint = printAnEmployee(arrayEmployee[i]);
			if(itCanPrint==1)
			{
				returnValue = 1;
			}
		}
	}

	return returnValue;
}
