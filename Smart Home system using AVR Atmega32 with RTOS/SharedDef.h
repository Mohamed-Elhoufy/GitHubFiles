#ifndef SHARED_DEF_H_
#define SHARED_DEF_H_

/******************************* OS Objects **********************************/

#define E_CHECK_PW_SCREEN      		 (1<<0)
#define E_WRONG_PW_SCREEN      		 (1<<1)
#define E_DOOR_LOCKED_SCREEN   		 (1<<2)
#define E_MAIN_SCREEN          		 (1<<3)
#define E_LIGHT_CONFIG_SCREEN  		 (1<<4)
#define E_ACTEMP_CONFIG_SCREEN		 (1<<5)
#define E_LOCK_CONFIG_SCREEN		 (1<<6)
#define E_ALARM_SCREEN				 (1<<7)
#define E_INSERT_DIGIT_DISP		     (1<<8)
#define E_LIGHT_MODE_UPDATE		     (1<<9)
#define E_LIGHT_INTENSITY_UPDATE     (1<<10)
#define E_CTEMP_UPDATE			     (1<<11)
#define E_ACTEMP_UPDATE			     (1<<12)
#define E_ALARM_STATUS_UPDATE		 (1<<13)
#define E_DISP_EVENTS				 (0x3FFF)

#define E_PW_UPDATE					 (1<<14)
#define E_PW_CHECK					 (1<<15)

#define E_RESET_SYSTEM				 ((u32)1<<16)
#define E_SET_SYSTEM_MANGMENT		 ((u32)1<<17)

//////////////////////////////////////Appliance Events////////////////////////////////////////////////////////////
#define E_ALARM						 ((u32)1<<0)
#define E_STARTFAN					 ((u32)1<<1)
#define E_STARTHEATER				 ((u32)1<<2)
#define E_ADJUSTLIHTING				 ((u32)1<<3)
#define E_OPEN_LOCK				     ((u32)1<<4)
#define E_STOPFAN					 ((u32)1<<5)
#define E_STOPHEATER				 ((u32)1<<6)
#define E_CLOSE_LOCK		         ((u32)1<<7)

#define E_DEVICE1_OFF                ((u32)1<<8)
#define E_DEVICE1_ON                 ((u32)1<<9)
#define E_DEVICE2_OFF                ((u32)1<<10)
#define E_DEVICE2_ON                 ((u32)1<<11)

////////////////////////////SHARED PARAMETERS ///////////////////////////////////////////

typedef enum{
	SS_PW_CHECK,
	SS_PW_MISS,
	SS_LOCK_STUCK,
	SS_MAIN,
	SS_LIGHT_CONFIG,
	SS_ACTEMP_CONFIG,
	SS_LOCK_CONFIG,
	SS_ALARM
}SystemState_t;

typedef struct{
	SystemState_t SysState;
	u8 PW[5];
	u8 digitvalue;
	u8 digitcounter;
	u8 Fspeed;
	u8 CTemp;
	u8 ACTemp;
	u8 Light_Intensity;
	u8 Ldr_Intensity;
	u8 Light_Mode;
	u8 Alarm_Status;
}SHApp_t;

////////////////////////////////////////////////////////////////////
extern SHApp_t	SHApp;

extern TaskHandle_t th_T_EnviroInterface;
extern TaskHandle_t th_T_DisplayManagment;
extern TaskHandle_t th_T_Alarm_Appliance;
extern TaskHandle_t th_T_User_Input ;
extern TaskHandle_t th_T_SysManagment;

extern EventGroupHandle_t	egEvents;
extern EventGroupHandle_t	egEventsAppliance;
/*Semaphores*/
extern xSemaphoreHandle bsCheck;


/*Functions or tasks prototype*/
void T_Alarm_Appliance(void* ptr);
void T_EnviroInterface(void* ptr);
void T_DisplayManagment(void* ptr);
void T_User_Input (void* ptr);
void T_SysManagment (void* ptr);
void System_Init(void);
void OUTPUT_Light_ADjustment(void);
void SHApp_DispScreen(SystemState_t);

#endif	// SHARED_DEF_H_