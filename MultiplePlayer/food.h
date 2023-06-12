/* Ruler 1         2         3         4         5         6         7        */
/*         DEVELOPED BY: Bravo Manuela, Chaparro Ma. del Pilar,               */
/*                   Hidalgo Valentina & Vargas Karen                         */
//*****************************************************************************/

/********************************** Headers ***********************************/
#include "snados.h"

#ifndef	 FOOD_H
#define  FOOD_H

/******************* Declaration of Classes with Attributes *******************/

/************************ Prototypes of Public Methods ************************/

FOOD_T   *FOOD_New(); 
 
FOOD_T   *FOOD_Set(FOOD_T *food_n_ptr, double *ti_food_n_ptr,SNAKE_T *snake_1_ptr, 
                   SNAKE_T *snake_2_ptr,char stage[][STAGE_COLS],
				   char stage_1[][STAGE_COLS]);	
				   
int      FOOD_Get_Time(FOOD_T *food_n_ptr, double *ti_food_n_ptr,    
                       SNAKE_T *snake_1_ptr,SNAKE_T *snake_2_ptr,
					   char stage[][STAGE_COLS],char stage_1[][STAGE_COLS]);
						

int      FOOD_Free( FOOD_T *food_n_ptr );						

#endif /*  FOOD_H */
