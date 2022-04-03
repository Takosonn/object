#include <REGX52.H>

////////////////////////////////////////////////////////////////

sbit IN11 = P0^5; //left front wheel
sbit IN12 = P0^6;

sbit IN13 = P0^3; //right front wheel
sbit IN14 = P0^4;

sbit IN21 = P3^5; //left rear wheel
sbit IN22 = P3^6;

sbit IN23 = P3^3; //right rear wheel
sbit IN24 = P3^4;

////////////////////////////////////////////////////////////////

void LF_motor_go()
{ IN11 = 0;IN12 = 1; }
void LF_motor_stop()
{ IN11 = 1;IN12 = 1; }
void LF_motor_back()
{ IN11 = 1;IN12 = 0; }
void RF_motor_go()
{ IN13 = 0;IN14 = 1; }
void RF_motor_stop()
{ IN13 = 1;IN14 = 1; }
void RF_motor_back()
{ IN13 = 1;IN14 = 0; }
void LR_motor_go()
{ IN21 = 1;IN22 = 0; }
void LR_motor_stop()
{ IN21 = 1;IN22 = 1; }
void LR_motor_back()
{ IN21 = 0;IN22 = 1; }
void RR_motor_go()
{ IN23 = 1;IN24 = 0; }
void RR_motor_stop()
{ IN23 = 1;IN24 = 1; }
void RR_motor_back()
{ IN23 = 0;IN24 = 1; }

