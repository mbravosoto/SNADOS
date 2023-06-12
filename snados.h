/* Ruler 1         2         3         4         5         6         7        */
/*         DEVELOPED BY: Bravo Manuela, Chaparro Ma. del Pilar,               */
/*                   Hidalgo Valentina & Vargas Karen                         */
//*****************************************************************************/

#define STAGE_ROWS 21             /* Maximum number of rows in map of stage */
#define STAGE_COLS 21             /* Maximum number of cols in map of stage */

#define CON_ROWS (STAGE_ROWS)     /* Maximum number of rows in console      */
#define CON_COLS (2*STAGE_COLS+1) /* Maximum number of cols in console      */


#ifndef	 SNAKE_H
#define  SNAKE_H

/******************* Declaration of Classes with Attributes *******************/
/* Declaration of general coordinates in the stage */
typedef struct UBICATION_STAGE_T UBICATION_STAGE_T; 
struct UBICATION_STAGE_T {
    char ubication[2];                  /* Absolute ubication in stage */   
};

/* Declaration of snake status */
typedef struct SNAKE_T SNAKE_T;
struct SNAKE_T{
    char direction[2];                  /* Normalized head snake direction */ 
	UBICATION_STAGE_T body_snake[100];  /*Body coordinates*/
};
/************************ Prototypes of Public Methods ************************/
#endif /*  SNAKE_H */