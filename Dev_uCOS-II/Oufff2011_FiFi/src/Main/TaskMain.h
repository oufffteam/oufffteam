/*
*********************************************************************************************************
*                                         Association OufffTEAM
*                                     Coupe de France de Robotique
*
* File : TaskMain.h
*********************************************************************************************************
*/

#ifndef TASKMAIN_H
#define TASKMAIN_H

#include "AppIncludes.h"

// Functions --------------------------------------------------------------------------------------
void TaskMain_Init();
	// Init function

void TaskMain_GetCurrentPos(StructOdoPos *pCurrentPos);
	// Function to read current position
	// Value are stored into pCurrentPos. If pCurrentPos is NULL, fonctions does nothing

void TaskMain_Main(void *p_arg);
	// Fonction principale
	// void *p_arg		: Arg for this task


#endif // TASKMAIN_H
