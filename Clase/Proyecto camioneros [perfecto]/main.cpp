#include <iostream>
using namespace std;
#include "Funciones.h"

int main()
{
    /*LO QUE NECESITO:

        MENU PRINCIPAL:
            *REGISTRAR CONDUCTOR
                -INGRESAR EL NOMBRE DEL CONDUCTOR <<
                (MOSTRAR SU NOMBRE Y EL CÓDIGO RESPECTIVO) <<
            *BUSCAR CONDUCTOR (QUIERE BUSCAR POR NOMBRE O POR CODIGO?)
                (MOSTRANDO LOS DATOS DEL CONDUCTOR, MARIO ADALBERTO RIVERA OLIVO MARO01, POR EJEMPLO) <<
                -MOSTRAR REGISTRO DE VIAJES
                -MOSTRAR PLANILLA DE PAGOS
            *MODIFICAR REGISTRO DE CONDUCTOR
                (MOSTRANDO LOS DATOS DEL CONDUCTOR, MARIO ADALBERTO RIVERA OLIVO MARO01, POR EJEMPLO) <<
                -INGRESAR VIAJES (CALCULAR CUÁNTO SE LE PAGARÁ DEPENDIENDO DE LA DISTANCIA RECORRIDA)
                    -
                -CAMBIAR NOMBRE
            *ELIMINAR
                (MOSTRANDO LOS CONDUCTORES EN EL SISTEMA, CON SU RESPECTIVO CODIGO) <<
                -INGRESE EL CODIGO DE QUIEN DESEA ELIMINAR

	void getDescuentoAfp(){
            // 6.25%
            this->descuentoAfp = this->sueldoMensual*0.00625;
            cout << "Descuento AFP: $" << this->descuentoAfp << endl;
        }
        void getDescuentoIsr(){
            //if sueldo 0.01 <= 472 no hay descuento
            //if sueldo 472.01 <= 895.24 multiplicar (sueldo - 472) por 0.1 y sumarle 17.67
            //if sueldo 895.25 <= 2038.10 multiplicar (sueldo - 895.24) por 0.2 y sumarle 60
            //if sueldo>2038.10 multiplicar (sueldo - 2038.10) por 0.3 y sumarle 288.57
            if(this->sueldoMensual <= 472.00){
                cout << "Descuento Isr: $0" << endl;
            }
            if(this->sueldoMensual>472.00 && this->sueldoMensual<895.25){
                this->descuentoIsr = (this->sueldoMensual - 472.00)*0.1 + 17.67;
                cout << "Descuento Isr: $" << this->descuentoIsr << endl;
            }
            if(this->sueldoMensual>895.24 && this->sueldoMensual<2038.11){
                this->descuentoIsr = (this->sueldoMensual - 895.24)*0.2 + 60;
                cout << "Descuento Isr: $" << this->descuentoIsr << endl;
            }
            if(this->sueldoMensual>2038.10){
                this->descuentoIsr = (this->sueldoMensual - 2038.10)*0.3 + 288.57;
                cout << "Descuento Isr: $" << this->descuentoIsr << endl;
            }
        }
        void getTotalPagar(){
            this->totalPagar = this->sueldoMensual - this->descuentoAfp - this->descuentoIsr - this->descuentoIsss;
            cout << "Total a pagar: $" << this->totalPagar << endl << endl;
        }

    */
    menu();

    return 0;
}
