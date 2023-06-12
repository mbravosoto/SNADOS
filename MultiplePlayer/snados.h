/* Ruler 1         2         3         4         5         6         7        */
/*         DEVELOPED BY: Bravo Manuela, Chaparro Ma. del Pilar,               */
/*                   Hidalgo Valentina & Vargas Karen                         */
//*****************************************************************************/

#define STAGE_ROWS 21             /* Maximum number of rows in map of stage */
#define STAGE_COLS 21             /* Maximum number of cols in map of stage */

#define CON_ROWS (STAGE_ROWS)     /* Maximum number of rows in console */
#define CON_COLS (2*STAGE_COLS+1) /* Maximum number of cols in console */


#ifndef	 SNADOS_H
#define  SNADOS_H

/******************* Declaration of Classes with Attributes *******************/
/* Declaration of enumeration type for normalized unitary vector */
typedef enum { LEFT, RIGHT, DOWN, UP } DIRECTION_T;

typedef struct  FOOD_T  FOOD_T;
struct FOOD_T{
    char ubication[2]; /* Absolute position in stage */   
};

typedef struct UBICATION_STAGE_T UBICATION_STAGE_T; 
/* Declaration of general coordinates in the stage */
struct UBICATION_STAGE_T {
    char ubication[2]; /* Absolute position in stage */   
};

typedef struct SNAKE_T SNAKE_T;
/* Declaration of snake status */
struct SNAKE_T{
    char direction[2]; /* Normalized head snake direction */ 
	UBICATION_STAGE_T body_snake[100];/*Body coordinates*/
};


/************************ Prototypes of Public Methods ************************/

int Initiate_Stage_in_Text_Mode( char console_buf[][CON_COLS],
                                 char stage[][STAGE_COLS]);

#endif /*  SNADOS_H */