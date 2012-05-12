/*
*********************************************************************************************************
*                                         Association OufffTEAM
*                                     Coupe de France de Robotique
*
*
* File : Fichier de strategie produit par StrategyGenerator
*
* Suivi de version :
* 2011-06-01 | PBE | Creation de la version de base pour la coupe 2011
* 2011-11-02 | PBE | Mise a jour du fichier pour en faire un fichier pattern pour la couleur A
*********************************************************************************************************
*/

#include "StrategyFromColor.h"

#ifdef TEST_STRATEGY_ENABLED

#define DEFAULT_SPEED (50)
extern float error_debug_1;
extern float error_debug_2;
extern float error_debug_3;
extern float error_debug_4;
extern float error_debug_5;

// ------------------------------------------------------------------------------------------------
INT8U StrategyColorA_GetInitCmd(StructCmd *InitCmd)
{
	if(NULL == InitCmd)
		return ERR__INVALID_PARAM;

	InitCmd->Cmd				= App_SetNewPos;
	InitCmd->CmdType			= CmdType_Blocking;
	InitCmd->Param2				= 2935;	
	InitCmd->Param3				= 1667;	
	InitCmd->Param4				= AppConvertDegInRad(180);
	InitCmd->ActiveSensorsFlag		= APP_PARAM_APPFLAG_NONE;

	return ERR__NO_ERROR;
}

// ------------------------------------------------------------------------------------------------
INT8U StrategyColorA_GetNextAction(StructCmd *NextAction)
{
	static int		NextActionID = 1;
	int			CurrentActionID = 0;
	INT8U 			Err = 0;
	OS_FLAGS		CurrentFlag = 0;
	StructCmd 		*p = NextAction;

	if(NULL == NextAction)
		return ERR__INVALID_PARAM;

	// Set all actions as blocking actions
	p->CmdType = CmdType_Blocking;

	// Set CurrentID to NextID
	CurrentActionID = NextActionID;

	error_debug_1 = (float)(NextActionID);
	error_debug_2 = (float)(CurrentActionID);

	// Read Next Action
	switch(CurrentActionID)
	{
		// StructuredFileLoopBegin
		// LoopID = 0
		case 1:		p->Cmd = MvtSimple_MoveInMM;			p->CmdType = CmdType_Blocking;	p->Param1 = APP_HOMOL_ROBOT_SPEED;			p->Param2 = 580.0;													p->ActiveSensorsFlag = APP_PARAM_APPFLAG_SENSORS_FRONT;			NextActionID++;	break;
/*		case 2:		p->Cmd = MvtSimple_RotateToAngleInDeg;	p->CmdType = CmdType_Blocking;	p->Param1 = APP_HOMOL_ROBOT_SPEED;															p->Param4 = 90.0;	p->ActiveSensorsFlag = APP_PARAM_APPFLAG_NONE;					NextActionID++;	break;
		case 3:		p->Cmd = MvtSimple_MoveInMM;			p->CmdType = CmdType_Blocking;	p->Param1 = APP_HOMOL_ROBOT_SPEED;			p->Param2 = -367;													p->ActiveSensorsFlag = APP_PARAM_APPFLAG_SENSORS_BACK;			NextActionID++;	break;
		case 4:		p->Cmd = Mvt_UsePivotMode;				p->CmdType = CmdType_Blocking;	p->Param1 = APP_HOMOL_ROBOT_SPEED;			p->Param2 = RIGHT_WHEEL;						p->Param4 = 180.0;	p->ActiveSensorsFlag = APP_PARAM_APPFLAG_SENSORS_BACK;			NextActionID++;	break;
		case 5:		p->Cmd = MvtSimple_MoveInMM;			p->CmdType = CmdType_Blocking;	p->Param1 = APP_HOMOL_ROBOT_SPEED;			p->Param2 = -250;													p->ActiveSensorsFlag = APP_PARAM_APPFLAG_SENSORS_BACK;			NextActionID++;	break;
		case 6:		p->Cmd = Mvt_UseMixedMode;				p->CmdType = CmdType_Blocking;	p->Param1 = APP_HOMOL_ROBOT_SPEED;			p->Param2 = 2500;			p->Param3 = 1000;	p->Param4 = -145;	p->ActiveSensorsFlag = APP_PARAM_APPFLAG_SENSORS_FRONT;			NextActionID++;	break;
		case 7:		p->Cmd = MvtSimple_MoveInMM;			p->CmdType = CmdType_Blocking;	p->Param1 = APP_HOMOL_ROBOT_SPEED;			p->Param2 = 500;													p->ActiveSensorsFlag = APP_PARAM_APPFLAG_SENSORS_FRONT;			NextActionID++;	break;
		case 8:		p->Cmd = Mvt_UseMixedMode;				p->CmdType = CmdType_Blocking;	p->Param1 = APP_HOMOL_ROBOT_SPEED;			p->Param2 = 2260;			p->Param3 = 500;	p->Param4 = 90;		p->ActiveSensorsFlag = APP_PARAM_APPFLAG_SENSORS_FRONT;			NextActionID++;	break;
		case 9:		p->Cmd = Mvt_UseMixedMode;				p->CmdType = CmdType_Blocking;	p->Param1 = APP_HOMOL_ROBOT_SPEED * 0.5;	p->Param2 = 2260;			p->Param3 = 65;		p->Param4 = 90;		p->ActiveSensorsFlag = APP_PARAM_APPFLAG_SENSORS_BACK;			NextActionID++;	break;
*/		// StructuredFileLoopEnd

		// StructuredFileLoopBegin
		// LoopID = 1
		case 100:	p->CmdType = CmdType_Blocking;		p->ActiveSensorsFlag =	APP_PARAM_APPFLAG_SENSORS_FRONT;	NextActionID = 101;		p->Cmd = MvtSimple_RotateToAngleInDeg;		NextAction->Param1 = DEFAULT_SPEED;    NextAction->Param4 = 90;    		break;	
		case 101:	p->CmdType = CmdType_Blocking;		p->ActiveSensorsFlag =	APP_PARAM_APPFLAG_SENSORS_BACK;		NextActionID = 102;		p->Cmd = MvtSimple_MoveInMM;		NextAction->Param1 = DEFAULT_SPEED;    NextAction->Param2 = -367;    		break;	
		case 102:	p->CmdType = CmdType_Blocking;		p->ActiveSensorsFlag =	APP_PARAM_APPFLAG_SENSORS_BACK;		NextActionID = 103;		p->Cmd = Mvt_UsePivotMode;		NextAction->Param1 = DEFAULT_SPEED;    NextAction->Param2 = RIGHT_WHEEL;    NextAction->Param4 = 180;    		break;	
		case 103:	p->CmdType = CmdType_Blocking;		p->ActiveSensorsFlag =	APP_PARAM_APPFLAG_SENSORS_BACK;		NextActionID = 104;		p->Cmd = MvtSimple_MoveInMM;		NextAction->Param1 = DEFAULT_SPEED;    NextAction->Param2 = -250;    		break;	
		case 104:	p->CmdType = CmdType_Blocking;		p->ActiveSensorsFlag =	APP_PARAM_APPFLAG_SENSORS_FRONT;	NextActionID = 105;		p->Cmd = Mvt_UseMixedMode;		NextAction->Param1 = DEFAULT_SPEED;    NextAction->Param2 = 2500;    NextAction->Param3 = 1000;    NextAction->Param4 = -125;    		break;	
		case 105:	p->CmdType = CmdType_Blocking;		p->ActiveSensorsFlag =	APP_PARAM_APPFLAG_SENSORS_FRONT;	NextActionID = 106;		p->Cmd = MvtSimple_MoveInMM;		NextAction->Param1 = DEFAULT_SPEED;    NextAction->Param2 = 500;    		break;	
		case 106:	p->CmdType = CmdType_Blocking;		p->ActiveSensorsFlag =	APP_PARAM_APPFLAG_SENSORS_FRONT;	NextActionID = 107;		p->Cmd = Mvt_UseMixedMode;		NextAction->Param1 = DEFAULT_SPEED;    NextAction->Param2 = 2260;    NextAction->Param3 = 500;    NextAction->Param4 = 90;    		break;	
		case 107:	p->CmdType = CmdType_Blocking;		p->ActiveSensorsFlag =	APP_PARAM_APPFLAG_SENSORS_BACK;		NextActionID = 107;		p->Cmd = Mvt_UseMixedMode;		NextAction->Param1 = DEFAULT_SPEED;    NextAction->Param2 = 2260;    NextAction->Param3 = 75;    NextAction->Param4 = 90;    		break;	
		// StructuredFileLoopEnd

		// StructuredFileLoopBegin
		// LoopID = 2
		// StructuredFileLoopEnd

		// StructuredFileLoopBegin
		// LoopID = 3
		// StructuredFileLoopEnd

		// StructuredFileLoopBegin
		// LoopID = 4
		// StructuredFileLoopEnd

		// StructuredFileLoopBegin
		// LoopID = 5
		// StructuredFileLoopEnd

		// StructuredFileLoopBegin
		// LoopID = 6
		// StructuredFileLoopEnd

		// StructuredFileLoopBegin
		// LoopID = 7
		// StructuredFileLoopEnd

		// StructuredFileLoopBegin
		// LoopID = 8
		// StructuredFileLoopEnd

		// StructuredFileLoopBegin
		// LoopID = 9
		// StructuredFileLoopEnd

		// StructuredFileLoopBegin
		// LoopID = 10
		// StructuredFileLoopEnd

		default:
			return ERR__NO_MORE_DATA_AVAILABLE;
			break;
	}

	
	error_debug_5 = p->Cmd;

	// Check for Wait command --------------------------------------------
	if(App_Wait == p->Cmd)
	{
		// Execute the wait command
		OSTimeDlyHMSM(p->Param1, p->Param2, p->Param3, p->Param4);
		return StrategyColorA_GetNextAction(p);
	}

	// Check for conditionnal command ------------------------------------
	if(App_IfGoto == p->Cmd)
	{
		// Read the current Flags
		CurrentFlag = OSFlagAccept(AppFlags, APP_PARAM_APPFLAG_START_BUTTON, OS_FLAG_WAIT_SET_ANY, &Err);

		if((CurrentFlag & (p->Param1)) != 0)
			NextActionID = (int)(p->Param2);
		else
			NextActionID = (int)(p->Param3);

		return StrategyColorA_GetNextAction(p);
	}
	
	// Create the MvtSimple Command --------------------------------------
	if(MvtSimple_MoveInMM == p->Cmd) 
		LibMoving_MoveInMM(p->Param2, p->Param1, p);

	if(MvtSimple_RotateInDeg == p->Cmd)
		LibMoving_RotateInDeg(p->Param4, p->Param1, p);
	
	if(MvtSimple_RotateToAngleInDeg == p->Cmd)
		LibMoving_RotateToAngleInDeg(p->Param4, p->Param1, p);

	// Angle Conversion --------------------------------------------------
	if((Mvt_UsePivotMode == p->Cmd) || (Mvt_UseMixedMode == p->Cmd))
	{
		p->Param4 = AppConvertDegInRad(p->Param4);
	}

	return ERR__NO_ERROR;
}

#endif
