#include <stdio.h>
//#include <stdio_ext.h>
#include "utn.h"
#include "ArrayEmployees.h"

#define QTY 1000

int main()
{
    setbuf(stdout,NULL);
    int rta;
    int contId;
    int flag;
    int idPedido;
    contId = 1;
    flag = 0;

    Employee ArrayEmployees[QTY];

	do{
        if(utn_getNumero(&rta, "\n1.Altas \n2.Modificar \n3.Baja \n4.Informar\n",
            "Opción inválida\n\n", 1, 4, 2) == 0){
            switch(rta){
                case 1:
                    printf("Ud. ha seleccionado la opción 1-Alta \n\n");
                    /*if(addEmployeeForced(ArrayEmployees, QTY, 1, "Rios", "Gabina",15000,2) == 0 &&
                        addEmployeeForced(ArrayEmployees, QTY, 2, "Gutierrez", "Jesica",19000,5) == 0 &&
                        addEmployeeForced(ArrayEmployees, QTY, 3, "Rios", "Ezequiel",55000,4) == 0 &&
                        addEmployeeForced(ArrayEmployees, QTY, 4, "Quispe", "Matias",85000,9) == 0 &&
                        addEmployeeForced(ArrayEmployees, QTY, 5, "Wasik", "Juliana",10000,3) == 0 ){*/
                    if(addEmployee(ArrayEmployees, QTY, &contId) == 0){
                        printf("\nEl alta se ha realizado con exito\n\n");
                        flag = 1;
                    }
                    else{
                        printf("\nError\n\n");
                    }
                    break;
                case 2:
                    if(flag == 1){
                        printf("Ud. ha seleccionado la opción 2-Modificación \n\n");
                        if(utn_getNumero(&idPedido, "Ingrese el id del empleado a modificar\n",
                            "Opción inválida\n\n", 1, 1000, 2) == 0){
                            if(modifyEmployee(ArrayEmployees, QTY, idPedido) != 0){
                                printf("\nError en la modificación\n\n");
                            }
                        }
                    }
                    else{
                         printf("\nError, no se hizo un alta de empleado para poder modificarlo\n\n");
                    }
                    break;
                case 3:
                    if(flag == 1){
                        printf("Ud. ha seleccionado la opción 3-Baja \n\n");
                        if(utn_getNumero(&idPedido, "Ingrese el id del empleado a dar de baja\n",
                            "Opción inválida\n\n", 1, 1000, 2) == 0){
                            if(removeEmployee(ArrayEmployees, QTY, idPedido) != 0){
                                printf("\nError en la baja\n\n");
                            }
                        }
                    }
                    else{
                         printf("\nError, no se hizo un alta de avion para poder darlo de baja\n\n");
                    }
                    break;
                case 4:
                    if(flag == 1){
                        printf("Ud. ha seleccionado la opción 4-Informar \n\n");
                        if(informEmployeesAndAverageSalary(ArrayEmployees, QTY) != 0){
                            printf("\nError\n\n");
                        }
                    }
                    else{
                         printf("\nError, no se hizo un alta de avion para poder informar\n\n");
                    }
                    break;
                default:
                    break;
            }
		}
    }
    while(rta <= 4);

    return 0;
}
