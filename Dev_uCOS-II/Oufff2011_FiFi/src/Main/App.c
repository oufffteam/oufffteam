/*
*********************************************************************************************************
*                                         Association OufffTEAM
*                                     Coupe de France de Robotique
*
*
* File : App.c
*
* Suivi de version :
* 2009-03-26 | PBE | Creation de la version de base pour la coupe 2010
* 2009-04-01 | PBE | Mise � jour pour la coupe 2011
*********************************************************************************************************
*/

#include "App.h"		// Global Variables

// Task includes
#include "TaskOdo.h"
#include "TaskAsser.h"
#include "TaskSensors.h"
#include "TaskMain.h"
#include "TaskTempo.h"
#include "TaskMvt.h"

/***** Calling Stacks *****/
static OS_STK       AppTaskOdoStk[APP_TASK_ODO_STK_SIZE];
static OS_STK       AppTaskAsserStk[APP_TASK_ASSER_STK_SIZE];
static OS_STK       AppTaskSensorsStk[APP_TASK_SENSORS_STK_SIZE];
static OS_STK       AppTaskMainStk[APP_TASK_MAIN_STK_SIZE];
static OS_STK       AppTaskMvtStk[APP_TASK_MVT_STK_SIZE];
static OS_STK       AppTaskTempoStk[APP_TASK_TEMPO_STK_SIZE];

/*
*********************************************************************************************************
*                                            FUNCTION PROTOTYPES
*********************************************************************************************************
*/
void AppTaskStart();				/* Function to start all tasks		*/
void AppCreateIPCS();				/* Function to create IPCS			*/
void AppInitVar();					/* Function to initialize variables	*/

/*
*********************************************************************************************************
*                                                main()
*
* Description : This is the standard entry point for C code.
* Arguments   : none
*********************************************************************************************************
*/

#pragma config FPLLMUL = MUL_20, FPLLIDIV = DIV_2, FPLLODIV = DIV_1, FWDTEN = OFF, FSOSCEN = OFF, POSCMOD = HS, FNOSC = FRCPLL, FPBDIV = DIV_1, ICESEL=ICS_PGx1 

int  main (void)
{
	unsigned char test_color = 1;
	char 		uart_buffer[13];
	char 		*buffer_ptr;
    CPU_INT08U  err;

    BSP_IntDisAll();			/* Disable all interrupts until we are ready to accept them */
	OSInit();                   /* Initialize "uC/OS-II, The Real-Time Kernel"              */


	AppInitVar();				/* Initialize globale vars									*/
	AppCreateIPCS();			/* Create IPCS objects										*/
	AppTaskStart();				/* Start all tasks											*/

#ifdef _TARGET_440H
	Set_Line_Information( 1, 0, "OUFFF TEAM 2011  ", 16);
	OSTimeDlyHMSM(0, 0, 1, 0);
	Set_Line_Information( 1, 0, "                 ", 16);
#endif

	OSStart();                  /* Start multitasking (i.e. give control to uC/OS-II)       */
	/* This part would be never executed */
}

/*
*********************************************************************************************************
*                                          AppTaskStart
*
* Description : This function starts all configured tasks
* Arguments   : None
*********************************************************************************************************
*/

void  AppTaskStart()
{
    CPU_INT08U  err;

	// --------------------------------------------------------------------------------------------
	// Init BSP and FPGA module
    BSP_InitIO();                                                       // Initialize BSP functions
	BSPFPGA_Reset();

#if (OS_TASK_STAT_EN > 0)
    OSStatInit();                                                       // Determine CPU capacity
#endif

#ifdef APP_TASK_ODO_ENABLED
	// --------------------------------------------------------------------------------------------
	// Starts TaskOdo
    OSTaskCreateExt( TaskOdo_Main,                                      
				    (void *)0,
                    (OS_STK *)&AppTaskOdoStk[APP_TASK_ODO_STK_SIZE - 1],
                    APP_TASK_ODO_PRIO,
                    APP_TASK_ODO_PRIO,
                    (OS_STK *)&AppTaskOdoStk[0],
                    APP_TASK_ODO_STK_SIZE,
                    (void *)0,
                    OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR);

#if OS_TASK_NAME_SIZE > 13
    OSTaskNameSet(APP_TASK_ODO_PRIO, "TaskOdo", &err);
#endif
#endif

#ifdef APP_TASK_ASSER_ENABLED
	// --------------------------------------------------------------------------------------------
	// Starts TaskAsser
    OSTaskCreateExt( TaskAsser_Main,                                      
				    (void *)0,
                    (OS_STK *)&AppTaskAsserStk[APP_TASK_ASSER_STK_SIZE - 1],
                    APP_TASK_ASSER_PRIO,
                    APP_TASK_ASSER_PRIO,
                    (OS_STK *)&AppTaskAsserStk[0],
                    APP_TASK_ASSER_STK_SIZE,
                    (void *)0,
                    OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR);

#if OS_TASK_NAME_SIZE > 13
    OSTaskNameSet(APP_TASK_ASSER_PRIO, "TaskAsser", &err);
#endif
#endif

#ifdef APP_TASK_MVT_ENABLED
	// --------------------------------------------------------------------------------------------
	// Starts Mvt
    OSTaskCreateExt( TaskMvt_Main,                                      
				    (void *)0,
                    (OS_STK *)&AppTaskMvtStk[APP_TASK_MVT_STK_SIZE - 1],
                    APP_TASK_MVT_PRIO,
                    APP_TASK_MVT_PRIO,
                    (OS_STK *)&AppTaskMvtStk[0],
					APP_TASK_MVT_STK_SIZE,
                    (void *)0,
                    OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR);

#if OS_TASK_NAME_SIZE > 13
    OSTaskNameSet(APP_TASK_ASSER_PRIO, "TaskMvt", &err);
#endif

#endif


#ifdef APP_TASK_SENSORS_ENABLED
	// --------------------------------------------------------------------------------------------
	// Starts TaskSensors
    OSTaskCreateExt( TaskSensors_Main,                                       
				    (void *)0,
                    (OS_STK *)&AppTaskSensorsStk[APP_TASK_SENSORS_STK_SIZE - 1],
                    APP_TASK_SENSORS_PRIO,
                    APP_TASK_SENSORS_PRIO,
                    (OS_STK *)&AppTaskSensorsStk[0],
                    APP_TASK_SENSORS_STK_SIZE,
                    (void *)0,
                    OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR);

#if OS_TASK_NAME_SIZE > 13
    OSTaskNameSet(APP_TASK_SENSORS_PRIO, "TaskSensors", &err);
#endif
#endif

#ifdef APP_TASK_MAIN_ENABLED
	// --------------------------------------------------------------------------------------------
	// Starts TaskMain
    OSTaskCreateExt( TaskMain_Main,                                       
				    (void *)0,
                    (OS_STK *)&AppTaskMainStk[APP_TASK_MAIN_STK_SIZE - 1],
                    APP_TASK_MAIN_PRIO,
                    APP_TASK_MAIN_PRIO,
                    (OS_STK *)&AppTaskMainStk[0],
                    APP_TASK_MAIN_STK_SIZE,
                    (void *)0,
                    OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR);

#if OS_TASK_NAME_SIZE > 13
    OSTaskNameSet(APP_TASK_MAIN_PRIO, "TaskMain", &err);
#endif
#endif

#ifdef APP_TASK_TEMPO_ENABLED
	// --------------------------------------------------------------------------------------------
	// Starts TaskTempo
    OSTaskCreateExt( TaskTempo_Main,                                       
				    (void *)0,
                    (OS_STK *)&AppTaskTempoStk[APP_TASK_TEMPO_STK_SIZE - 1],
                    APP_TASK_TEMPO_PRIO,
                    APP_TASK_TEMPO_PRIO,
                    (OS_STK *)&AppTaskTempoStk[0],
                    APP_TASK_TEMPO_STK_SIZE,
                    (void *)0,
                    OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR);

#if OS_TASK_NAME_SIZE > 13
    OSTaskNameSet(APP_TASK_MAIN_PRIO, "TaskTempo", &err);
#endif
#endif

	// All tasks are started
	return;
}

/*
*********************************************************************************************************
*                                          AppCreateIPCS
*
* Description : This function creates all IPCS objects
* Arguments   : None
*********************************************************************************************************
*/
void AppCreateIPCS()
{
	INT8U perr;

#if APP_QUEUE_MAIN_SIZE > 0
	// Create an empty queue for main process
	AppQueueMainEvent = OSQCreate(AppQueueMainStk, APP_QUEUE_MAIN_SIZE);
	if(NULL == AppQueueMainEvent)		// Check if Queue is well created
	{
#ifndef __DEBUG
		putsUART2("Error : Unable to create MainQueue\n");
		putsUART2("Restarting...\n");	
		//SoftReset();
#else
		putsUART2("DEBUG (App.c) : Error -> Unable to create MainQueue\n");
		putsUART2("DEBUG (App.c) : Entering in sleeping mode...\n");	
#endif
		while(OS_TRUE)		// Infinite Loop
			OSTimeDlyHMSM(1, 0, 0, 0);		
	}
#endif

#if APP_QUEUE_ASSER_SIZE > 0
	// Create an empty queue for asser process
	AppQueueAsserEvent = OSQCreate(AppQueueAsserStk, APP_QUEUE_ASSER_SIZE);
	if(NULL == AppQueueAsserEvent)		// Check if Queue is well created
	{
#ifndef __DEBUG
		putsUART2("Error : Unable to create AsserQueue\n");
		putsUART2("Restarting...\n");	
		//SoftReset();
#else
		putsUART2("DEBUG (App.c) : Error -> Unable to create AsserQueue\n");
		putsUART2("DEBUG (App.c) : Entering in sleeping mode...\n");	
#endif
		while(OS_TRUE)		// Infinite Loop
			OSTimeDlyHMSM(1, 0, 0, 0);		
	}
#endif

	// Flags
	AppFlags = OSFlagCreate(APP_PARAM_APPFLAG_INITAL_VALUE, &perr);
	if(NULL == AppFlags)
	{
#ifndef __DEBUG
		putsUART2("Error : Unable to create Appliction Flag\n");
		putsUART2("Restarting...\n");	
		//SoftReset();
#else
		putsUART2("DEBUG (App.c) : Error -> Unable to create Appliction Flag\n");
		putsUART2("DEBUG (App.c) : Entering in sleeping mode...\n");	
#endif
		while(OS_TRUE)		// Infinite Loop
			OSTimeDlyHMSM(1, 0, 0, 0);		
	}

	return;
}

/*
*********************************************************************************************************
*                                          AppInitVar
*
* Description : This function initializes globale variables
* Arguments   : None
*********************************************************************************************************
*/
void AppInitVar()
{
	int i;

	// Vars
//	AppQueueMainEvent = NULL;												/* Queue for get TaskMain events				*/
//	AppQueueAsserEvent = NULL;												/* Queue for get Asser events					*/
	AppFlags = NULL;														/* Application Flags							*/
	AppCurrentColor = c_NotSet;												/* Set CurrentColor to NotSet					*/

	// Arrays
#if APP_QUEUE_MAIN_SIZE > 0
	memset(AppQueueMainStk, 0, sizeof(void*)*APP_QUEUE_MAIN_SIZE);			/* Set Main Queue to NULL					*/
#endif
#if APP_QUEUE_ASSER_SIZE > 0
	memset(AppQueueAsserStk, 0, sizeof(void*)*APP_QUEUE_ASSER_SIZE);		/* Set Main Queue to NULL					*/
#endif
	memset(AppMsgStk, 0, sizeof(StructMsg) * APP_QUEUES_TOTAL_SIZE);
	
	// Clear Msg
	for(i=0; i<APP_QUEUES_TOTAL_SIZE; i++)
		AppMsgStk[i].IsRead = OS_TRUE;
	
	return;
}
