/*=============================================================================
 * Author: Dany Tito - Pablo Morzán
 * Date: 2021/07/31
 * Version: 1.0
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "teclas.h"

/*=====[Definition macros of private constants]==============================*/

typedef enum{
	B_UP,
	B_FALL,
	B_DOWN,
	B_RAISE,

	B_QTY
}EstadosBotones;

EstadosBotones tecla1 = B_UP;
EstadosBotones tecla2 = B_DOWN;
EstadosBotones tecla3 = B_DOWN;
EstadosBotones tecla4 = B_UP;

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/

void buttonPressed(gpioMap_t tecla);
void buttonReleased(gpioMap_t tecla);


delay_t delayTEC1;
delay_t delayTEC2;
delay_t delayTEC3;
delay_t delayTEC4;


//================================FUNCIONES=================================

void inicializarMEF_TEC1(void){
	if (gpioRead(TEC1)){
		tecla1 = B_UP;
	}
	else {tecla1 = B_DOWN;
	}
	delayConfig( &delayTEC1, 40 );
};

void inicializarMEF_TEC2(void){
	if (gpioRead(TEC2)){
		tecla2 = B_UP;
	}
	else {tecla2 = B_DOWN;
	}
	delayConfig( &delayTEC2, 40 );
};

void inicializarMEF_TEC3(void){
	if (gpioRead(TEC3)){
		tecla3 = B_UP;
	}
	else {tecla3 = B_DOWN;
	}
	delayConfig( &delayTEC3, 40 );
};

void inicializarMEF_TEC4(void){
	if (gpioRead(TEC4)){
		tecla4 = B_UP;
	}
	else {tecla4 = B_DOWN;
	}
	delayConfig( &delayTEC4, 40 );
};



void actualizarMEF_TEC1(void){
	switch (tecla1){

		case B_UP:
			if(!gpioRead(TEC1)){
				tecla1 = B_FALL;
			}
			break;

		case B_DOWN:
			if(gpioRead(TEC1)){
				tecla1 = B_RAISE;
			}
			break;

		case B_RAISE:
			if(delayRead( &delayTEC1 )){
				if(gpioRead(TEC1)){
					tecla1 = B_UP;
					buttonReleased(TEC1);
				}
				else tecla1 = B_RAISE;
			}
			break;

		case B_FALL:
			if(delayRead( &delayTEC1 )){
				if(!gpioRead(TEC1)){
					tecla1 = B_DOWN;
					buttonPressed(TEC1);
				}
				else tecla1 = B_UP;
			}
			break;

		}
}

void actualizarMEF_TEC2(void){
	switch(tecla2){
	case B_UP :
		if(!gpioRead(TEC2)){
			tecla2 = B_FALL;
		}
		break;

	case B_DOWN :
		if(gpioRead(TEC2)){
			tecla2 = B_RAISE;
		}
		break;

	case B_RAISE :
		if(delayRead( &delayTEC2 )){
			if(gpioRead(TEC2)){
				tecla2 = B_UP;
				buttonReleased(TEC2);
			}
		}
		break;

	case B_FALL :
		if(delayRead( &delayTEC2 )){
			if(!gpioRead(TEC2)){
				tecla2 = B_DOWN;
				buttonPressed(TEC2);
			}
		}
		break;

	}
}

void actualizarMEF_TEC3(void){
	switch(tecla3){
	case B_UP :
		if(!gpioRead(TEC3)){
			tecla3 = B_FALL;
		}
		break;

	case B_DOWN :
		if(gpioRead(TEC3)){
			tecla3 = B_RAISE;
		}
		break;

	case B_RAISE :
		if(delayRead( &delayTEC3)){
			if(gpioRead(TEC3)){
				tecla3 = B_UP;
				buttonReleased(TEC3);
			}
		}
		break;

	case B_FALL :
		if(delayRead( &delayTEC3)){
			if(!gpioRead(TEC3)){
				tecla3 = B_DOWN;
				buttonPressed(TEC3);
			}
		}
		break;

	}
}

void actualizarMEF_TEC4(void){
	switch(tecla4){
	case B_UP :
		if(!gpioRead(TEC4)){
			tecla4 = B_FALL;
		}
		break;

	case B_DOWN :
		if(gpioRead(TEC4)){
			tecla4 = B_RAISE;

		}
		break;

	case B_RAISE :
		if(delayRead( &delayTEC4 )){
			if(gpioRead(TEC4)){
				tecla4 = B_UP;
				buttonReleased(TEC4);
			}
		}
		break;

	case B_FALL :
		if(delayRead( &delayTEC4 )){
			if(!gpioRead(TEC4)){
				tecla4 = B_DOWN;
				buttonPressed(TEC4);
			}
		}
		break;

	}
}


void buttonPressed(gpioMap_t tecla){
	gpioWrite(tecla+6, OFF);
}

void buttonReleased(gpioMap_t tecla){
	gpioWrite(tecla+6, ON);
}

