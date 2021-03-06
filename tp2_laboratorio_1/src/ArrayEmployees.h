
#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include <stdio.h>
#define FREE 0
#define OCCUPIED 1
#include "gets.h"
#include <string.h>

struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;

}typedef Employee;

/**
 * @fn int initEmployees(Employee[], int)
 * @brief Inicializa el campo isEmpty en 0 para indicar que todas las posiciones del array estan vacias
 *
 * @param Array de empleados
 * @param Tama?o del array
 * @return Devuelve -1 si hubo error, 0 si esta ok
 */

int initEmployees(Employee[],int);

/**
 * @fn int searchFreeEmployee(Employee[], int)
 * @brief Busca la primera posicion libre que se encuentre en el array
 *
 * @param Array de empleados
 * @param Tama?o del array
 * @return Devuelve la primera posicion libre que encontro, sino encontro ninguna posicion libre devuelve -1
 */

int searchFreeEmployee(Employee[],int);

/**
 * @fn int findEmployeeById(Employee[], int, int)
 * @brief Busca un empleado recibiendo como par?metro su id
 *
 * @param Array de empleados
 * @param Tama?o del array
 * @param Id del empleado
 * @return Devuelve la posicion del empleado, devuelve -1 sino la encontro
 */

int findEmployeeById(Employee[],int,int);

/**
 * @fn int generateId(int, int)
 * @brief Genera id automaticamente
 *
 * @param Contador de empleados
 * @param Id de inicio que marca el comienzo del contador
 * @return devuelve el id resultado de la suma entre el contador y el id de inicio
 */
int generateId(int,int);

/**
 * @fn Employee registerAnEmployee(Employee[], int, int, int)
 * @brief Registra un empleado
 *
 * @param Array de empleados
 * @param Tama?o del array
 * @param Contador de empleados
 * @param Id de inicio
 * @return Devuelve un empleado cargado con todos sus datos
 */
Employee registerAnEmployee(Employee[],int,int,int);

/**
 * @fn int loadEmployee(Employee[], int, int, int)
 * @brief Carga a un empleado
 *
 * @param Array de empleados
 * @param Tama?o del array
 * @param Contador de empleados
 * @param Id inicio
 * @return Devuelve 1 si logro cargar los datos, caso contrario devuelve -1
 */
int loadEmployee(Employee[],int,int,int);

/**
 * @fn int addEmployees(Employee[], int, int, char[], char[], float, int)
 * @brief A?ade a un array de empleados existente los valores recibidos como parametro en la primer posicion libre
 *
 * @param Array de empleados
 * @param Tama?o del array
 * @param Id del empleado
 * @param Nombre del empleado
 * @param Apellido del empleado
 * @param Salario del empleado
 * @param Sector del empleado
 * @return Devuelve 0 si logro a?adir, caso contrario devuelve -1
 */

int addEmployees(Employee[],int,int,char[],char[],float,int);

/**
 * @fn int getIdEmployeeDelete(char[], char[], char[], char[], Employee[], int)
 * @brief Pide id existente en el array de empleados para eliminar o no(en caso de cancelaci?n) a un empleado con ese id
 *
 * @param Mensaje
 * @param Id solicitado
 * @param Mensaje de error
 * @param Mensaje de error de solo numeros
 * @param Array de empleados
 * @param Tama?o del array
 * @return Devuelve 1 si se elimino, -1 sino encontro el id, 0 si se cancela la eliminacion
 */
int getIdEmployeeDelete(char[],char[],char[],char[],Employee[],int);

/**
 * @fn int getIdEmployeeModify(char[], char[], char[], char[], Employee[], int)
 * @brief Pide id existente en el array de empleados para modificar o no(en caso de cancelaci?n) a un empleado con ese id
 *
 * @param Mensaje
 * @param Id solicitado
 * @param Mensaje de error
 * @param Mensaje de error de solo numeros
 * @param Array de empleados
 * @param Tama?o del array
 * @return Devuelve 1 si se modifico, -1 sino encontro el id, 0 si se cancela la modificaci?n
 */
int getIdEmployeeModify(char[],char[],char[],char[],Employee[],int);

/**
 * @fn int modifyEmployee(Employee[], int, int)
 * @brief Modifica datos del empleado recibiendo como parametro el id del empleado
 *
 * @param Array de empleados
 * @param tama?o del array
 * @param id del empleado
 * @return Devuelve 1 si se modifico, -1 sino encontro el id, 0 si se cancela la modificaci?n
 */
int modifyEmployee(Employee[],int,int);

/**
 * @fn int removeEmployee(Employee[], int, int)
 * @brief Elimina datos del empleado recibiendo como parametro el id del empleado
 *
* @param Array de empleados
 * @param tama?o del array
 * @param id del empleado
 * @return Devuelve 1 si se elimino, -1 sino encontro el id, 0 si se cancela la eliminaci?n
 */
int removeEmployee(Employee[],int,int);

/**
 * @fn int sortEmployeeByLastName(Employee[], int, int)
 * @brief Ordena el array por apellido de forma ascendente o descendente
 *
 * @param Array de empleados
 * @param Tama?o del array
 * @param 1 indica (UP) - 0 indica (DOWN)
 * @return Devuelve -1 si no pudo ordenar, 0 si lo logro
 */
int sortEmployeeByLastName(Employee[],int,int);

/**
 * @fn int sortEmployeeBySector(Employee[], int, int)
 * @brief Ordena el array por sector de forma ascendente o descendente
 *
 * @param Array de empleados
 * @param Tama?o del array
 * @param 1 indica (UP) - 0 indica (DOWN)
 * @return Devuelve -1 si no pudo ordenar, 0 si lo logro
 */
int sortEmployeeBySector(Employee[],int,int);

/**
 * @fn int printEmployee(Employee[], int)
 * @brief Muestra el array de empleados
 *
 * @param Array de empleados
 * @param Tama?o del array
 * @return Devuelve -1 si no pudo mostrar datos, 1 si lo logro
 */
int printEmployee(Employee[],int);

/**
 * @fn int printAnEmployee(Employee)
 * @brief Muestra un solo empleado
 *
 * @param Un empleado
 * @return Devuelve -1 si no pudo mostrar datos, 1 si lo logro
 */
int printAnEmployee(Employee);

/**
 * @fn int searchIdEmployee(Employee[], int, int)
 * @brief Verifica si el id recibido como parametro, exite en el array de empleados
 *
 * @param Array de empleados
 * @param Tama?o del array
 * @param Id de empleado
 * @return Devuelve el id si existe, -1 en caso contrario
 */
int searchIdEmployee(Employee[],int,int);

/**
 * @fn int menuOrdenamiento(char[], char[], char[], Employee[], int, char[])
 * @brief Muestra un menu para seleccionar que tipo de ordenamiento se quiere realizar si por sector o por apellido
 *
 * @param Mensaje
 * @param Opcion seleccionada
 * @param Mensaje de error
 * @param Array de empleados
 * @param Tama?o del array
 * @param Mensaje de un subMenu
 * @return Devuelve 0 si se decide salir del menu, -1 si no se pudo ingresar a las opciones
 */
int menuOrdenamiento(char[],char[],char[],Employee[],int,char[]);

/**
 * @fn float calculateAverage(int, int)
 * @brief Calcular promedio
 *
 * @param Acumulador
 * @param Contador
 * @return Promedio calculado
 */
float calculateAverage(int,int);
/**
 * @fn float calculateSalaryAverage(Employee[], int)
 * @brief Calcula promedio de los salarios de todos los empleados
 *
 * @param Array de empleados
 * @param Tama?o del array
 * @return Promedio de todos los salarios
 */
float calculateSalaryAverage(Employee[],int);

/**
 * @fn int printAverageSalary(Employee[], int)
 * @brief Muestra el promedio de los salarios
 *
 * @param Array de empleados
 * @param Tama?o del array
 * @return Devuelve -1 sino pudo mostrar, 1 si lo logro
 */
int printAverageSalary(Employee[],int);

/**
 * @fn float calculateTotalSalary(Employee[], int)
 * @brief Calcula el total de los salarios
 *
 * @param Array de empleados
 * @param Tama?o del array
 * @return Total de los salarios
 */
float calculateTotalSalary(Employee[],int);

/**
 * @fn int printTotalSalary(Employee[], int)
 * @brief Muestra el total de los salarios
 *
 * @param Array de empleados
 * @param Tama?o del array
 * @return Devuelve -1 sino pudo mostrar, 1 si lo logro
 */
int printTotalSalary(Employee[],int);

/**
 * @fn int printEmployeeExceedsAverageSalary(Employee[], int)
 * @brief Muestra los empleados que superan el salario promedio
 *
 * @param Array de empleados
 * @param Tama?o del array
 * @return Devuelve -1 sino pudo mostrar, 1 si lo logro
 */
int printEmployeeExceedsAverageSalary(Employee[],int);

/**
 * @fn int countEmployeeExceedsAverageSalary(Employee[], int)
 * @brief Cuenta a los empleados que superan el salario promedio
 *
 * @param Array de empleados
 * @param Tama?o del array
 * @return Cantidad de empelados que superan el salario promedio
 */
int countEmployeeExceedsAverageSalary(Employee[],int);
#endif /* ARRAYEMPLOYEES_H_ */
