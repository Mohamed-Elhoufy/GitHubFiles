
#include "StdTypes.h" /*Must be above other includes 34an used fehom*/
#include "Utils.h"

#include "RCC_Interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void RCC_voidInit(void)
{
	u32 Local_u32TimeOut= 0 ;

	/*		System Buses prescallers			 */
	/*		 AHB		PRESCALER					*/
#if		AHB_PRESCALLER	==	SYSCLK_DIV_1
			CLR_BIT(RCC_CFGR,7);
#elif	AHB_PRESCALLER	==	SYSCLK_DIV_2
			SET_BIT(RCC_CFGR,7);
			CLR_BIT(RCC_CFGR,6);
			CLR_BIT(RCC_CFGR,5);
			CLR_BIT(RCC_CFGR,4);
#elif	AHB_PRESCALLER	==	SYSCLK_DIV_4
			SET_BIT(RCC_CFGR,7);
			CLR_BIT(RCC_CFGR,6);
			CLR_BIT(RCC_CFGR,5);
			SET_BIT(RCC_CFGR,4);
#elif	AHB_PRESCALLER	==	SYSCLK_DIV_8
			SET_BIT(RCC_CFGR,7);
			CLR_BIT(RCC_CFGR,6);
			SET_BIT(RCC_CFGR,5);
			CLR_BIT(RCC_CFGR,4);
#elif	AHB_PRESCALLER	==	SYSCLK_DIV_16
			SET_BIT(RCC_CFGR,7);
			CLR_BIT(RCC_CFGR,6);
			SET_BIT(RCC_CFGR,5);
			SET_BIT(RCC_CFGR,4);
#elif	AHB_PRESCALLER	==	SYSCLK_DIV_64
			SET_BIT(RCC_CFGR,7);
			SET_BIT(RCC_CFGR,6);
			CLR_BIT(RCC_CFGR,5);
			CLR_BIT(RCC_CFGR,4);
#elif	AHB_PRESCALLER	==	SYSCLK_DIV_128
			SET_BIT(RCC_CFGR,7);
			SET_BIT(RCC_CFGR,6);
			CLR_BIT(RCC_CFGR,5);
			SET_BIT(RCC_CFGR,4);
#elif	AHB_PRESCALLER	==	SYSCLK_DIV_256
			SET_BIT(RCC_CFGR,7);
			SET_BIT(RCC_CFGR,6);
			SET_BIT(RCC_CFGR,5);
			CLR_BIT(RCC_CFGR,4);
#elif	AHB_PRESCALLER	==	SYSCLK_DIV_512
			SET_BIT(RCC_CFGR,7);
			SET_BIT(RCC_CFGR,6);
			SET_BIT(RCC_CFGR,5);
			SET_BIT(RCC_CFGR,4);
#endif
/*		 APB1		PRESCALER					*/
#if		ABP1_PRESCALLER ==  HCLK_DIV_1
			CLR_BIT(RCC_CFGR,10);
#elif	ABP1_PRESCALLER ==  HCLK_DIV_2
			SET_BIT(RCC_CFGR,10);
			CLR_BIT(RCC_CFGR,9);
			CLR_BIT(RCC_CFGR,8);
#elif	ABP1_PRESCALLER ==  HCLK_DIV_4
			SET_BIT(RCC_CFGR,10);
			CLR_BIT(RCC_CFGR,9);
			SET_BIT(RCC_CFGR,8);
#elif	ABP1_PRESCALLER ==  HCLK_DIV_8
			SET_BIT(RCC_CFGR,10);
			SET_BIT(RCC_CFGR,9);
			CLR_BIT(RCC_CFGR,8);
#elif	ABP1_PRESCALLER ==  HCLK_DIV_16
			SET_BIT(RCC_CFGR,10);
			SET_BIT(RCC_CFGR,9);
			SET_BIT(RCC_CFGR,8);

#endif
/*		 APB2		PRESCALER					*/
#if		ABP1_PRESCALLER ==  HCLK_DIV_1
			CLR_BIT(RCC_CFGR,13);
#elif	ABP1_PRESCALLER ==  HCLK_DIV_2
			SET_BIT(RCC_CFGR,13);
			CLR_BIT(RCC_CFGR,12);
			CLR_BIT(RCC_CFGR,11);
#elif	ABP1_PRESCALLER ==  HCLK_DIV_4
			SET_BIT(RCC_CFGR,13);
			CLR_BIT(RCC_CFGR,12);
			SET_BIT(RCC_CFGR,11);
#elif	ABP1_PRESCALLER ==  HCLK_DIV_8
			SET_BIT(RCC_CFGR,13);
			SET_BIT(RCC_CFGR,12);
			CLR_BIT(RCC_CFGR,11);
#elif	ABP1_PRESCALLER ==  HCLK_DIV_16
			SET_BIT(RCC_CFGR,13);
			SET_BIT(RCC_CFGR,12);
			SET_BIT(RCC_CFGR,11);

#endif
/*		ADC  			PRESCALLER 				*/

#if    ADC_PRESCALLER ==	PCLK2_DIV_2
			CLR_BIT(RCC_CFGR,14);
			CLR_BIT(RCC_CFGR,15);
#elif	ADC_PRESCALLER ==	PCLK2_DIV_4
			SET_BIT(RCC_CFGR,14);
			CLR_BIT(RCC_CFGR,15);
#elif	ADC_PRESCALLER ==	PCLK2_DIV_6
			CLR_BIT(RCC_CFGR,14);
			SET_BIT(RCC_CFGR,15);
#else
			SET_BIT(RCC_CFGR,14);
			SET_BIT(RCC_CFGR,15);
#endif

	/*			System clock selection				*/
	#if			CLOCK_TYPE == RCC_HSI
		/*			HSI ON			*/
			SET_BIT(RCC_CR,0);
		/*		HSI is Ready ?	//POLLING	*/
			while(!GET_BIT(RCC_CR,1) && Local_u32TimeOut !=10000)
			{
				Local_u32TimeOut++;
			}
	#elif		CLOCK_TYPE == RCC_HSE
		/*	System Clock Switch		*/
			SET_BIT(RCC_CFGR,0);
			CLR_BIT(RCC_CFGR,1);
		/*	HSE is Crystal or RC   */
		#if		RCC_HSE_SOURCE== RCC_HSE_CRYSTAL
			/*0   dont bypass crystal   */
				CLR_BIT(RCC_CR,18);
		#elif  RCC_HSE_SOURCE== RCC_HSE_RC
				/*1 bypass crystal*/
				SET_BIT(RCC_CR,18);
		#endif
/*			HSE ON		Check on BYPASS BIT	*/
				SET_BIT(RCC_CR,16);

		/*		HSE is Ready ?	//POLLING	*/
			while(!GET_BIT(RCC_CR,17) && Local_u32TimeOut !=10000)
			{
				Local_u32TimeOut++;
			}
			/*       POLLING ON SWS			 */ Local_u32TimeOut=0;
			while(!GET_BIT(RCC_CFGR,2) && GET_BIT(RCC_CFGR,3)&&Local_u32TimeOut !=10000)
			{
				Local_u32TimeOut++;
			}

	#elif		CLOCK_TYPE == RCC_PLL
/*			System Clock Switch	 PLL for System	*/
			CLR_BIT(RCC_CFGR,0);
			SET_BIT(RCC_CFGR,1);
/*				PLL muliplacation factor		*/


#if		RCC_PLL_MUL==2
			CLR_BIT(RCC_CFGR,18);
			CLR_BIT(RCC_CFGR,19);
			CLR_BIT(RCC_CFGR,20);
			CLR_BIT(RCC_CFGR,21);
#elif  RCC_PLL_MUL==3
			SET_BIT(RCC_CFGR,18);
			CLR_BIT(RCC_CFGR,19);
			CLR_BIT(RCC_CFGR,20);
			CLR_BIT(RCC_CFGR,21);
#elif  RCC_PLL_MUL==4
			CLR_BIT(RCC_CFGR,18);
			SET_BIT(RCC_CFGR,19);
			CLR_BIT(RCC_CFGR,20);
			CLR_BIT(RCC_CFGR,21);
#elif  RCC_PLL_MUL==5
			SET_BIT(RCC_CFGR,18);
			SET_BIT(RCC_CFGR,19);
			CLR_BIT(RCC_CFGR,20);
			CLR_BIT(RCC_CFGR,21);
#elif  RCC_PLL_MUL==6
			CLR_BIT(RCC_CFGR,18);
			CLR_BIT(RCC_CFGR,19);
			SET_BIT(RCC_CFGR,20);
			CLR_BIT(RCC_CFGR,21);
#elif  RCC_PLL_MUL==7
			SET_BIT(RCC_CFGR,18);
			CLR_BIT(RCC_CFGR,19);
			SET_BIT(RCC_CFGR,20);
			CLR_BIT(RCC_CFGR,21);
#elif  RCC_PLL_MUL==8
			CLR_BIT(RCC_CFGR,18);
			SET_BIT(RCC_CFGR,19);
			SET_BIT(RCC_CFGR,20);
			CLR_BIT(RCC_CFGR,21);
#elif  RCC_PLL_MUL==9
			SET_BIT(RCC_CFGR,18);
			SET_BIT(RCC_CFGR,19);
			SET_BIT(RCC_CFGR,20);
			CLR_BIT(RCC_CFGR,21);
#elif  RCC_PLL_MUL==10
			CLR_BIT(RCC_CFGR,18);
			CLR_BIT(RCC_CFGR,19);
			CLR_BIT(RCC_CFGR,20);
			SET_BIT(RCC_CFGR,21);
#elif  RCC_PLL_MUL==11
			SET_BIT(RCC_CFGR,18);
			CLR_BIT(RCC_CFGR,19);
			CLR_BIT(RCC_CFGR,20);
			SET_BIT(RCC_CFGR,21);
#elif  RCC_PLL_MUL==12
			CLR_BIT(RCC_CFGR,18);
			SET_BIT(RCC_CFGR,19);
			CLR_BIT(RCC_CFGR,20);
			SET_BIT(RCC_CFGR,21);
#elif  RCC_PLL_MUL==13
			SET_BIT(RCC_CFGR,18);
			SET_BIT(RCC_CFGR,19);
			CLR_BIT(RCC_CFGR,20);
			SET_BIT(RCC_CFGR,21);
#elif  RCC_PLL_MUL==14
			CLR_BIT(RCC_CFGR,18);
			CLR_BIT(RCC_CFGR,19);
			SET_BIT(RCC_CFGR,20);
			SET_BIT(RCC_CFGR,21);
#elif  RCC_PLL_MUL==15
			SET_BIT(RCC_CFGR,18);
			CLR_BIT(RCC_CFGR,19);
			SET_BIT(RCC_CFGR,20);
			SET_BIT(RCC_CFGR,21);
#elif  RCC_PLL_MUL==16
			SET_BIT(RCC_CFGR,18);
			SET_BIT(RCC_CFGR,19);
			SET_BIT(RCC_CFGR,20);
			SET_BIT(RCC_CFGR,21);
#endif
	/*		Select PLL input Clock			*/
#if RCC_PLL_SOURCE==RCC_PLL_HSI_DIV_2
	/*Select PLL source as HSI/2 */
			CLR_BIT(RCC_CFGR,16);
	/*			HSI ON			*/
			SET_BIT(RCC_CR,0);
	/*		HSI is Ready ?	//POLLING	*/
	    	while(!GET_BIT(RCC_CR,1) && Local_u32TimeOut !=10000)
			{
							Local_u32TimeOut++;
			}

#elif RCC_PLL_SOURCE==RCC_PLL_HSE_DIV_2
	    /*Select PLL source as HSE/2 */
	    	SET_BIT(RCC_CFGR,17);
	    	SET_BIT(RCC_CFGR,16);

	    /*	HSE is Crystal or RC   */
	#if		 RCC_PLL_HSE_SOURCE ==  RCC_HSE_CRYSTAL
	    	/*0   dont bypass crystal   */
	    	CLR_BIT(RCC_CR,18);
	#elif  RCC_PLL_HSE_SOURCE== RCC_HSE_RC
	    	/*1 bypass crystal*/
	    	SET_BIT(RCC_CR,18);
	 #endif
	 /*			HSE ON		         	*/
	    	SET_BIT(RCC_CR,16);
	    /*		HSE is Ready ?	//POLLING	*/
	    	while(!GET_BIT(RCC_CR,17) && Local_u32TimeOut !=10000)
	    	{
	    		Local_u32TimeOut++;
	    	}


#elif  RCC_PLL_SOURCE==RCC_PLL_HSE_DIV_1
	    	/*Select PLL source as HSE/2 */
	    	 CLR_BIT(RCC_CFGR,17);
	    	 SET_BIT(RCC_CFGR,16);
	   /*	HSE is Crystal or RC   */
	#if		 RCC_PLL_HSE_SOURCE ==  RCC_HSE_CRYSTAL
	  	/*0   dont bypass crystal   */
	       	CLR_BIT(RCC_CR,18);
	#elif  RCC_PLL_HSE_SOURCE== RCC_HSE_RC
	       	/*1 bypass crystal*/
	       	SET_BIT(RCC_CR,18);
	 #endif
	  /*			HSE ON		         	*/
	      	SET_BIT(RCC_CR,16);
	 /*		HSE is Ready ?	//POLLING	*/
	        while(!GET_BIT(RCC_CR,17) && Local_u32TimeOut !=10000)
	    	{
	    		 Local_u32TimeOut++;
	        }
#endif

	 /*		Enable     PLL is Ready?		*/
	    	 SET_BIT(RCC_CR,24);	 Local_u32TimeOut=0;
	    	  while(!GET_BIT(RCC_CR,25) && Local_u32TimeOut !=10000)
	    	   	{
	    	        Local_u32TimeOut++;
	    	     }
     /*       POLLING ON SWS			 */ Local_u32TimeOut=0;
	    	   while(!GET_BIT(RCC_CFGR,2) && GET_BIT(RCC_CFGR,3)&&Local_u32TimeOut !=10000)
	    	    {
	    	    	Local_u32TimeOut++;
	    	    }

	#else
				#error "Wrong clock system choice!"

	#endif


}

void RCC_voidEnablePeripheralClock(u8 Copy_u8BusID,Prephiral_Id_type Copy_u8PeripheralID)
{
	/*	Range Check	*/
	if(Copy_u8PeripheralID < 32)
	{
		switch(Copy_u8BusID)
		{
			case RCC_AHB :	SET_BIT( RCC_AHBENR,Copy_u8PeripheralID);	break;
			case RCC_APB1:	SET_BIT( RCC_APB1ENR,Copy_u8PeripheralID);	break;
			case RCC_APB2:	SET_BIT( RCC_APB2ENR,Copy_u8PeripheralID);	break;
		}
	}
	else{/*		Return ERROR	*/}
}
void RCC_voidDisablePeripheralClock(u8 Copy_u8BusID,Prephiral_Id_type Copy_u8PeripheralID)
{
	/*	Range Check	*/
	if(Copy_u8PeripheralID < 32)
	{
		switch(Copy_u8BusID)
		{
			case RCC_AHB :	CLR_BIT(RCC_AHBENR,Copy_u8PeripheralID);	break;
			case RCC_APB1:	CLR_BIT(RCC_APB1ENR,Copy_u8PeripheralID);	break;
			case RCC_APB2:	CLR_BIT(RCC_APB2ENR,Copy_u8PeripheralID);	break;
		}
	}
	else{/*		Return ERROR	*/}
}
/*Update by placing Hexa in the EN Register*/
void RCC_voidEnablePeripheralClock_EntireBus(u8 Copy_u8BusID)
{
	if(Copy_u8BusID<3)
	{
		switch(Copy_u8BusID)
		{
		case RCC_AHB:
			for(Prephiral_Id_type i=AHB_FIRST_PREPHERIAL;i<=AHB_TOTAL;i++)
				SET_BIT( RCC_AHBENR,AHB_Bus_On_Off_Array[i]);
			break;

		case RCC_APB2:
			for(Prephiral_Id_type i=APB2_FIRST_PREPHERIAL;i <= APB2_TOTAL;i++)
				SET_BIT( RCC_APB2ENR,APB2_Bus_On_Off_Array[i]);
			break;

		case RCC_APB1:
			for(Prephiral_Id_type i=APB1_FIRST_PREPHERIAL;i<=APB1_TOTAL;i++)
				SET_BIT( RCC_APB1ENR,APB1_Bus_On_Off_Array[i]);
			break;


		}
	}
	else{/*Error*/}


}


void RCC_voidDisblePeripheralClock_EntireBus(u8 Copy_u8BusID)
{
	if(Copy_u8BusID <3)
	{
		switch(Copy_u8BusID)
		{
		case RCC_AHB:
			for(Prephiral_Id_type i=AHB_FIRST_PREPHERIAL;i<=AHB_TOTAL;i++)
				CLR_BIT( RCC_AHBENR,AHB_Bus_On_Off_Array[i]);
			break;

		case RCC_APB2:
			for(Prephiral_Id_type i=APB2_FIRST_PREPHERIAL;i<=APB2_TOTAL;i++)
				CLR_BIT( RCC_APB2ENR,APB2_Bus_On_Off_Array[i]);
			break;

		case RCC_APB1:
			for(Prephiral_Id_type i=APB1_FIRST_PREPHERIAL;i<=APB1_TOTAL;i++)
				CLR_BIT( RCC_APB1ENR,APB1_Bus_On_Off_Array[i]);
			break;


		}
	}
	else{/*Error*/}
}


