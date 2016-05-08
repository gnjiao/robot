/*
 * Direct_Kinematics.c
 *
 *  Created on: May 3, 2016
 *      Author: AnhTuan
 */


#include "include.h"

// A1 Matrix
void  DH_A1(real_T q,real_T temp[4][4])
{
	temp[0][0]=cos(q);   temp[0][1]= 0;  temp[0][2]= -sin(q) ;  temp[0][3]=a[1]*cos(q);
	temp[1][0]=sin(q);   temp[1][1]= 0;  temp[1][2]=  cos(q) ;  temp[1][3]=a[1]*sin(q);
	temp[2][0]=   0   ;  temp[2][1]=-1;  temp[2][2]=    0 ;     temp[2][3]=   d[1]     ;
	temp[3][0]=   0   ;  temp[3][1]= 0;  temp[3][2]=    0 ;     temp[3][3]=   1      ;
}

// A2 Matrix
void  DH_A2(real_T q,real_T temp[4][4])
{
	temp[0][0]=cos(q);   temp[0][1]= sin(q);  temp[0][2]=    0 ;     temp[0][3]=a[2]*cos(q);
	temp[1][0]=sin(q);   temp[1][1]=-cos(q);  temp[1][2]=    0 ;     temp[1][3]=a[2]*sin(q);
	temp[2][0]=   0   ;  temp[2][1]=-1;       temp[2][2]=    0 ;     temp[2][3]=  0     ;
	temp[3][0]=   0   ;  temp[3][1]= 0;       temp[3][2]=    0 ;     temp[3][3]=  1     ;
}



void DH_A(int i,real_T q,real_T temp[4][4])// i  is joint
{
	q=  q*PI/180.0 ;// Convert to radian
	temp[0][0]=cos(q);     temp[0][1]= -sin(q)*cos(Apha[i]);     temp[0][2]=  sin(q)*sin(Apha[i]) ;  temp[0][3]=a[i]*cos(q);
	temp[1][0]=sin(q);     temp[1][1]=  cos(q)*cos(Apha[i]);     temp[1][2]= -cos(q)*sin(Apha[i]) ;  temp[1][3]=a[i]*sin(q);
	temp[2][0]=   0.0  ;   temp[2][1]=  sin(Apha[i]);            temp[2][2]=  cos(Apha[i])  ;        temp[2][3]=   d[i]    ;
	temp[3][0]=   0.0  ;   temp[3][1]=   0.0   ;                 temp[3][2]=    0.0         ;        temp[3][3]=   1.0     ;
}
void Make_DK(real_T q1,real_T q2, real_T q3, real_T q4, real_T q5 ,real_T q6)// calculator direct kinematics and display to Terminal UART_BASE_0
{

// Calculator each matrix Ai

	USART_SendData( UART4, (uint16_t)'\n' );
	DH_A( 1, q1, A1 );
	UART_Print_Matrix( A1 );
	USART_SendData( UART4, (uint16_t)'\n' );


	USART_SendData( UART4, (uint16_t)'\n' );
	DH_A( 2, q2, A2 );
	UART_Print_Matrix( A2 );
	USART_SendData( UART4,(uint16_t) '\n' );


	USART_SendData( UART4, (uint16_t)'\n' );
	DH_A( 3, q3, A3 );
	UART_Print_Matrix( A3 );
	USART_SendData( UART4,(uint16_t) '\n' );


	USART_SendData( UART4, (uint16_t)'\n' );
	DH_A( 4, q4, A4 );
	UART_Print_Matrix( A4 );
	USART_SendData( UART4, (uint16_t)'\n' );


	USART_SendData( UART4, (uint16_t)'\n' );
	DH_A( 5, q5, A5 );
	UART_Print_Matrix( A5 );
	USART_SendData( UART4, (uint16_t)'\n' );


	USART_SendData( UART4, (uint16_t)'\n' );
	DH_A( 6, q6, A6 );
	UART_Print_Matrix( A6 );
	USART_SendData( UART4,(uint16_t) '\n' );


// mult matrix

	USART_SendData( UART4, (uint16_t)'\n' );
	Mul_Matrix( A1, A2 );
	UART_Print_Matrix( A1 );
	USART_SendData( UART4, (uint16_t)'\n' );
	// A1=A1*A2

//	UARTprintf( "A1*A2*A3" );
	USART_SendData( UART4, (uint16_t)'\n' );
	Mul_Matrix( A1, A3 );
	UART_Print_Matrix( A1 );
	USART_SendData( UART4, (uint16_t)'\n' );
	// A1=A1*A2*A3

//	UARTprintf( "A1*A2*A3*A4" );
	USART_SendData( UART4, (uint16_t)'\n' );
	Mul_Matrix( A1, A4 );
	UART_Print_Matrix( A1 );
	USART_SendData( UART4, (uint16_t)'\n' );

//	UARTprintf( "A1*A2*A3*A4*A5" );
	USART_SendData( UART4, (uint16_t)'\n' );
	Mul_Matrix( A1, A5 );
	UART_Print_Matrix( A1 );
	USART_SendData( UART4, (uint16_t)'\n' );

//	UARTprintf( "A1*A2*A3*A4*A5*A6" );
	USART_SendData( UART4, (uint16_t)'\n' );
	Mul_Matrix( A1, A6 );
	UART_Print_Matrix( A1 );
	USART_SendData( UART4, (uint16_t)'\n' );

}
