/*
*********************************************************************************************************
*                                         Association OufffTEAM
*                                     Coupe de France de Robotique
*
* File : TaskOdo.h
*********************************************************************************************************
*/

#ifndef TASKODO_H
#define TASKODO_H

#include <AppIncludes.h>

// Conversion factor : determined imperically
// !Calibration methodology!
// 1- Measure increments of encoders for a know distance
// Use several trials to average correctly and compute a first estimation of left and right factors : factor = distance (mm) / nb of incs
// 2- Measure entraxe to determine conversion factor for angle
// 3- Do several trials to refine factors in angle
// First correct angle in right line : if angle +, reduces left factor (because factor scales in 1/x)
// Then correct distance by proportionality :
// current_distance --- coeff 1 ---> distance_to_reach
// current left factor --- coeff 2 ---> current right factor
// new right factor = current right factor * coeff 1 * coeff2

// For distance of 789.5 mm, we add 16902 increments on encoder right and 16922 increments on encoder left
#define CONVERSION_MM_TO_INC_RIGHT  (float)(21.4338)
#define CONVERSION_MM_TO_INC_LEFT	(float)(21.4085)


// For an angle of = entraxe
#define CONVERSION_RAD_TO_MM	(float)(273.0)

void TaskOdo_Main(void *p_arg);
	// Fonction principal du process d'odométrie
	// void *p_arg		: Arg for this task

#endif // TASKODO_H
