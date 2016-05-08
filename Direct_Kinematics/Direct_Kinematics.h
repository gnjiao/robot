/*
 * Direct_Kinematics.h
 *
 *  Created on: May 3, 2016
 *      Author: AnhTuan
 */

#ifndef _DIRECT_KINEMATICS_H_
#define _DIRECT_KINEMATICS_H_

#include "include.h"

/* UP6 YAKAWA MOTOMAN ROBOT
 theta     d         a      alpha
 L(1) = Link([ 0       0.45      0.15   -pi/2   0]);
 L(2) = Link([ 0       0         0.57    pi     0]);
 L(3) = Link([ 0       0         0.13   -pi/2   0]);
 L(4) = Link([ 0      -0.64      0       pi/2   0]);
 L(5) = Link([ 0       0         0       pi/2   0]);
 L(6) = Link([ 0       0.095     0       0      0]);
 */

static  real_T d[7] =
{ 0, 0.45, 0, 0, -0.64, 0, 0.95 }; // d[0] not used onlly for synchoronous
static  real_T a[7] =
{ 0, 0.15, 0.57, 0.13, 0, 0, 0 };  // a[0] not used
static  real_T Apha[7] =
{ 0, -PI / 2, PI, -PI / 2, PI / 2, PI / 2, 0 }; // alpha[0] not used

static  real_T A1[4][4], A2[4][4], A3[4][4], A4[4][4], A5[4][4], A6[4][4];

extern void DH_A1(real_T q1 , real_T temp[4][4]);
extern void DH_A(int i , real_T q , real_T temp[4][4]);
extern void Make_DK(real_T q1 , real_T q2 , real_T q3 , real_T q4 , real_T q5 ,real_T q6);

#endif /*DIRECT_KINEMATICS_H_*/
