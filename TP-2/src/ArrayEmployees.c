#include "ArrayEmployees.h"



/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len){
    int retorno = -1;
    if(list != NULL && len > 0){
        for(int i = 0;i < len;i++){
            list[i].isEmpty = TRUE;
        }
        retorno = 0;
    }
    return retorno;
}


/**
 * \brief finds the first empty position in list and returns the index of that position.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return  Return employee index empty position or (-1) if [Invalid length or NULL
 *  pointer received or employee not found]
 *
 */
int getEmptyPosition(Employee* list, int len){
    int posicion;
    posicion = -1;
    if(list != NULL && len > 0){
        for(int i = 0;i < len;i++){
            if(list[i].isEmpty == TRUE){
              posicion = i;
              break;
            }
        }
    }
    return posicion;
 }

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
 *  free space] - (0) if Ok
 *
 */
int addEmployeeForced(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector){
    int retorno = -1;
    int index;
    int retornoInit;
	Employee bufferEmployee;
	retornoInit = initEmployees(list, len);
	if(retornoInit == 0){
        index = getEmptyPosition(list, len);
    	if(list != NULL && len > 0 && id >= 0 && name != NULL &&
    	        lastName != NULL && salary > 0 && sector > 0 && index >= 0){
    			bufferEmployee.id = id;
    			strncpy(bufferEmployee.name, name, NAME);
    			strncpy(bufferEmployee.lastName, lastName, NAME);
    			bufferEmployee.salary = salary;
    			bufferEmployee.sector = sector;
    			bufferEmployee.isEmpty = FALSE;
    			list[index] = bufferEmployee;
    			retorno = 0;
    	}
	}
	return retorno;
}

/** \brief adds in a existing list of employees, a new employee in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
 *  free space] - (0) if Ok
 *
 */
int addEmployee(Employee* list, int len, int* id)
{
    int retorno = -1;
    int index;
    int retornoInit;
	Employee bufferEmployee;
	retornoInit = initEmployees(list, len);
	if(retornoInit == 0){
        index = getEmptyPosition(list, len);
    	if(list != NULL && len > 0 && index < len && index >= 0 && id != NULL)
    	{
    		if(utn_getCadena(bufferEmployee.name, NAME, "Ingrese el nombre\n","\nERROR\n",2) == 0 &&
    			utn_getCadena(bufferEmployee.lastName, NAME, "Ingrese el apellido\n","\nERROR\n",2) == 0 &&
    			utn_getNumeroFlotante(&bufferEmployee.salary,"Ingrese el salario\n","\nERROR\n",10000,70000,2) == 0 &&
    			utn_getNumero(&bufferEmployee.sector,"Ingrese el sector\n","ERROR\n",1,10,2)== 0)
    		{
    			bufferEmployee.id = *id;
    			bufferEmployee.isEmpty = FALSE;
    			list[index] = bufferEmployee;
    			(*id)++;
    			retorno = 0;
    		}
    	}
	}
	return retorno;
}

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id)
{
    int retorno = -1;
    for(int i = 0;i < len;i++){
        if(list[i].id == id){
           retorno = i;
        }
    }
    return retorno;
}

/** \brief modifies the data of an existing employee
 * \param list employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
 *  free space] - (0) if Ok
 *
 */
int modifyEmployee(Employee* list, int len, int id)/// terminar de modificar
{
    int retorno = -1;
    int index;
    int rta;
	Employee bufferEmployee;
	index = findEmployeeById(list, len,id);
	if(list != NULL && len > 0 && index >= 0 && index < len )
	{
	    do{
            if(utn_getNumero(&rta, "\n1.Modificar nombre \n2.Modificar apellido \n3.Modificar salario \n4.Modificar sector\n5.Salir\n",
                "Opción inválida\n\n", 1, 5, 2) == 0){
                switch(rta){
                    case 1:
                        printf("Ud. ha seleccionado la opción 1-Modificar nombre \n\n");
                        if(utn_getCadena(bufferEmployee.name, NAME, "Ingrese el nombre\n","\nERROR\n",2) == 0){
                            strncpy(list[index].name, bufferEmployee.name, NAME);
                            printf("\nLa modificacion del nombre se ha realizado con exito.\n\n");
                        }
                        else{
                            printf("\nError\n\n");
                        }
                        break;
                    case 2:
                        printf("Ud. ha seleccionado la opción 2-Modificar apellido\n\n");
                        if(utn_getCadena(bufferEmployee.lastName, NAME, "Ingrese el apellido\n","\nERROR\n",2) == 0){
                            strncpy(list[index].lastName, bufferEmployee.lastName, NAME);
                            printf("\nLa modificacion del apellido se ha realizado con exito.\n\n");
                        }
                        else{
                             printf("\nError\n\n");
                        }
                        break;
                    case 3:
                        printf("Ud. ha seleccionado la opción 3-Modificar salario \n\n");
                        if(utn_getNumeroFlotante(&bufferEmployee.salary,"Ingrese el salario\n","\nERROR\n",10000,70000,2) == 0){
                            list[index].salary = bufferEmployee.salary;
                            printf("\nLa modificacion del salario se ha realizado con exito.\n\n");
                        }
                        else{
                             printf("\nError\n\n");
                        }
                        break;
                    case 4:
                        printf("Ud. ha seleccionado la opción 4-Modificar sector \n\n");
                        if(utn_getNumero(&bufferEmployee.sector,"Ingrese el sector\n","\nERROR\n",1,10,2) == 0){
                            list[index].sector = bufferEmployee.sector;
                            printf("\nLa modificacion del sector se ha realizado con exito.\n\n");
                        }
                        else{
                             printf("\nError\n\n");
                        }
                        break;
                    default:
                        break;
                }
                retorno = 0;
    		}
        }
        while(rta <= 4);
	}
    return retorno;
}

/** \brief print the content of employees array
 * \param list Employee*
 * \param len int
 * \return int
 *
 */
int printEmployees(Employee* list, int len)
{
    int retorno = -1;
    if(list != NULL && len > 0){
       printf("\n\t\t\tEmployees\n\n");
       printf("\tId\t\tName\t\tLast name\t\tSalary\t\tSector\n");
       printf("----------------------------------------------------------------------------------------------------------------\n");
       for(int i = 0;i < len;i++){
            if(list[i].isEmpty == FALSE){
                fflush(stdin);//fflush
                printf("%8d- \t\t%s\t\t%8s-\t\t%2.f - \t%8d\n", list[i].id,
        	    list[i].name, list[i].lastName,list[i].salary, list[i].sector);
                retorno = 0;
            }
        }
    }
    return retorno;
}


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id){
    int retorno = -1;
	int index;
	char decision;
	index = findEmployeeById(list, len, id);
	if(list != NULL && len > 0 && id >= 0 && index >= 0 && index < len)
	{
	   if(utn_getCaracter(&decision,"\nSeguro que lo quiere dar de baja?(s/n) \n","\nERROR\n",'n','s',2)==0 &&
                decision == 's'){
                list[index].isEmpty = 1;
                retorno = 0;
                fflush(stdin);
                printf("Se ha dado de baja con exito");
        }
    }
	return retorno;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order)
{
    int retorno = -1;
    Employee bufferEmployee;
    if(list != NULL && len > 0 && (order == 0 || order == 1)){
        for(int i = 0;i<len-1;i++){
            for(int j = i + 1;j < len;j++){
                if(((strncmp(list[i].lastName, list[j].lastName, NAME) > 0 && order == 1)||
                (strncmp(list[i].lastName, list[j].lastName, NAME) == 0 && order == 1 && list[i].sector > list[j].sector)) ||
                  ((strncmp(list[i].lastName, list[j].lastName, NAME) < 0 && order == 0)||
                    (strncmp(list[i].lastName, list[j].lastName, NAME) == 0 && order == 0 && list[i].sector < list[j].sector))){
                    bufferEmployee = list[i];
                    list[i] = list[j];
                    list[j] = bufferEmployee;
                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}

int getTotalAndAverageSalaries(Employee* list, int len, float* acum, float* promSalaries, int* contPromEmployees){
    int retorno = -1;
    if(list != NULL && len > 0 && acum != NULL && promSalaries != NULL && contPromEmployees != NULL){
        for(int i = 0;i < len;i ++){
            *acum = *acum + list[i].salary;
        }
        *promSalaries = *acum / len;
        for(int i = 0;i < len;i ++){
            if(list[i].salary > *promSalaries){
                *contPromEmployees = *contPromEmployees + 1;
            }
        }
        retorno = 0;
    }
    return retorno;
}

int informEmployeesAndAverageSalary(Employee* list, int len){
    int retorno = -1;
    int rta;
    int order;
    float acum;
    float promSalaries;
    int contPromEmployees;
    acum = 0;
    contPromEmployees = 0;
    do{
        if(utn_getNumero(&rta,
            "\n1.Listado de los empleados ordenados alfabéticamente por Apellido y Sector. \n2.Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n3.Salir\n",
            "Opción inválida\n\n", 1, 3, 2) == 0){
            switch(rta){
                case 1:
                    printf("Ud. ha seleccionado la opción 1.Listado de los empleados ordenados alfabéticamente por Apellido y Sector. \n\n");
                    if(utn_getNumero(&order,"\nIngrese el tipo de orden que quiere utilizar.\n0.Ordenar en forma descendente.\n1.Ordenar en forma ascendente.\n",
                        "Opción inválida\n\n", 0, 1, 2) == 0){
                        if(sortEmployees(list,len,order) == 0){
                            printEmployees(list, len);
                        }
                        else{
                            printf("\nError\n\n");
                        }
                    }
                    break;
                case 2:
                    printf("Ud. ha seleccionado la opción 2.Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n\n");
                    if(getTotalAndAverageSalaries(list,len, &acum, &promSalaries, &contPromEmployees) == 0){
                        printf("El total de los salarios es %.2f\n",acum);
                        printf("El promedio de los salarios es %.2f\n",promSalaries);
                        printf("La cantidad de empleados que supera el salario promedio es %d\n",contPromEmployees);
                    }
                    else{
                         printf("\nError\n\n");
                    }
                    break;
                default:
                    break;
            }
            retorno = 0;
		}
    }
    while(rta != 3);
    return retorno;
}








