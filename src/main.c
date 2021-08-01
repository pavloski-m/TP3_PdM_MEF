/*=============================================================================
 * Author: Dany Tito - Pablo Morzán
 * Date: 2021/07/26
 * Version: 1.0
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "main.h"

/*=====[Definition macros of private constants]==============================*/

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/



int main(void){


   /* ------------- INICIALIZACIONES ------------- */

   /* Inicializar la placa */
   boardConfig();


   /* Declaración de variables locales */


   //Inicialización de MEF
  inicializarMEF_TEC1();
  inicializarMEF_TEC2();
  inicializarMEF_TEC3();
  inicializarMEF_TEC4();

 /* ------------- REPETIR POR SIEMPRE ------------- */

    while(1) {
    	actualizarMEF_TEC1();
    	actualizarMEF_TEC2();
    	actualizarMEF_TEC3();
    	actualizarMEF_TEC4();

    //actualizaciones de MEF


/* NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa no es llamado
      por ningun S.O. */
    }

    return 0 ;

}





//================================FUNCICONES=================================

