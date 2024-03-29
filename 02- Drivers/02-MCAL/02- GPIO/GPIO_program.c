/***************************/
/*  Author  : Yousif Hazim */
/*  Date    : 26 JUL 2023  */
/*  Version : V01		   */
/***************************/

#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"

#include <MCAL/GPIO/GPIO_interface.h>
#include <MCAL/GPIO/GPIO_private.h>


void MGPIO_voidSetPinDirection(u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8Mode)
{
	switch(Copy_u8PORT)
	{
		case GPIOA :
					if(Copy_u8PIN <= 7)
					{
						GPIOA_CRL &= ~((0b1111)<< (Copy_u8PIN * 4)); // Clear the mode
						GPIOA_CRL |= ((Copy_u8Mode)<< (Copy_u8PIN * 4)); // Set the mode
					}					
					else if(Copy_u8PIN <= 15)
					{
						Copy_u8PIN = Copy_u8PIN - 8;
						GPIOA_CRH &= ~((0b1111)<< (Copy_u8PIN * 4)); // Clear the mode
						GPIOA_CRH |= ((Copy_u8Mode)<< (Copy_u8PIN * 4)); // Set the mode
					}
					break;
		case GPIOB :
					if(Copy_u8PIN <= 7)
					{
						GPIOB_CRL &= ~((0b1111)<< (Copy_u8PIN * 4)); // Clear the mode
						GPIOB_CRL |= ((Copy_u8Mode)<< (Copy_u8PIN * 4)); // Set the mode
					}					
					else if(Copy_u8PIN <= 15)
					{
						Copy_u8PIN = Copy_u8PIN - 8;
						GPIOB_CRH &= ~((0b1111)<< (Copy_u8PIN * 4)); // Clear the mode
						GPIOB_CRH |= ((Copy_u8Mode)<< (Copy_u8PIN * 4)); // Set the mode
					}
					break;
		case GPIOC :
					if(Copy_u8PIN <= 7)
					{
						GPIOC_CRL &= ~((0b1111)<< (Copy_u8PIN * 4)); // Clear the mode
						GPIOC_CRL |= ((Copy_u8Mode)<< (Copy_u8PIN * 4)); // Set the mode
					}					
					else if(Copy_u8PIN <= 15)
					{
						Copy_u8PIN = Copy_u8PIN - 8;
						GPIOC_CRH &= ~((0b1111)<< (Copy_u8PIN * 4)); // Clear the mode
						GPIOC_CRH |= ((Copy_u8Mode)<< (Copy_u8PIN * 4)); // Set the mode
					}
					break;
		default:	break;
	}
}

void MGPIO_voidSetPinValue(u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8Value)
{
		switch(Copy_u8PORT)
		{
		case GPIOA :
				if(Copy_u8Value == GPIO_HIGH)
				{
					SET_BIT(GPIOA_ODR , Copy_u8PIN);
				}					
				else if(Copy_u8Value == GPIO_LOW)
				{
					CLR_BIT(GPIOA_ODR , Copy_u8PIN);
				}
				break;
			
		case GPIOB :
				if(Copy_u8Value == GPIO_HIGH)
				{
					SET_BIT(GPIOB_ODR , Copy_u8PIN);
				}					
				else if(Copy_u8Value == GPIO_LOW)
				{
					CLR_BIT(GPIOB_ODR , Copy_u8PIN);
				}
				break;
			
		case GPIOC :
				if(Copy_u8Value == GPIO_HIGH)
				{
					SET_BIT(GPIOC_ODR , Copy_u8PIN);
				}					
				else if(Copy_u8Value == GPIO_LOW)
				{
					CLR_BIT(GPIOC_ODR , Copy_u8PIN);
				}
				break;
			
		default: break;
		}
}


u8 MGPIO_u8GetPinValue(u8 Copy_u8PORT , u8 Copy_u8PIN)
{
	u8	LOC_u8Result = 0;
	
	switch(Copy_u8PORT)
		{
		case GPIOA :
				LOC_u8Result = GET_BIT(GPIOA_IDR,Copy_u8PIN);
				break;
			
		case GPIOB :
				LOC_u8Result = GET_BIT(GPIOB_IDR,Copy_u8PIN);
				break;
			
		case GPIOC :
				LOC_u8Result = GET_BIT(GPIOC_IDR,Copy_u8PIN);
				break;
			
		default: break;
		}
		return LOC_u8Result;
}
