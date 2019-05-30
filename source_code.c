#include <16F877A.h> // initialize the microcontroller
 #fuses NOWDT,XT,NOPUT,NOPROTECT,NODEBUG,NOBROWNOUT,NOLVP,NOCPD,NOWRT//fuses
 #use delay(clock=4000000) //working frecuency
 #use rs232(baud=9600,bits=8,parity=N,xmit=PIN_C6,rcv=PIN_C7) // bits per minute of i2c
 #use fast_io(A)
 #use fast_io(B)
 #use fast_io(C)
 #use fast_io(D)
//LED Variables
int8 led1=PIN_B3;
int8 led2=PIN_B4;
//motor variables
int8 IN_A1 = PIN_C3;
int8 IN_A2 = PIN_C0;
int8 IN_B1 = PIN_C4;
int8 IN_B2 = PIN_C5;
//PWM variables
int8 var,postscaler;
char valor;
//sensor varaibles
int sensor1 = PIN_D0;//input right sensor
int sensor2 = PIN_D7;//output right sensor
int sensor3 = PIN_D1;//input left sensor
int sensor4 = PIN_D6;//output left sensor
int sensor5 = PIN_D2;//input rear sensor
int sensor6 = PIN_D5;//output rear sensor


void IniPuertos() //Setting the ports of the pic
{
        set_tris_A(0xFF);
        set_tris_B(0x00);
        output_B(0x00);
        set_tris_C(0b11000000);
        set_tris_D(0b11100000);
}

void IniPWM() // setup of the PWM for motor speed control
{
        var=249;
        postscaler=1;
        setup_timer_2(T2_DIV_BY_4, var,postscaler);
        setup_ccp1(CCP_PWM);
        setup_ccp2(CCP_PWM);
        set_pwm1_duty(0);
        set_pwm2_duty(0);
}

void clear() // clear all the outputs of the pic
{
        output_bit(led1,0);
        output_bit(led2,0);
        output_bit(IN_A1,0);
        output_bit(IN_A2,0);
        set_pwm1_duty(0);
        output_bit(IN_B1,0);
        output_bit(IN_B2,0);
        set_pwm2_duty(0);
}
 
void stop() // Stop
{
        output_bit(IN_A1,0);
        output_bit(IN_A2,0);
        output_bit(IN_B1,0);
        output_bit(IN_B2,0);
}

void giroizquierdo() // Left turn
{
        output_bit(IN_A1,0);
        output_bit(IN_A2,0);
        set_pwm1_duty(195);
        output_bit(IN_B1,0);
        output_bit(IN_B2,1);
        set_pwm2_duty(195);
}

void giroderecho() // Right turn

{
        output_bit(IN_A1,1);
        output_bit(IN_A2,0);
        set_pwm1_duty(195);
        output_bit(IN_B1,0);
        output_bit(IN_B2,0);
        set_pwm2_duty(195);
}

void adelante() // Move forward
{
        output_bit(IN_A1,1);
        output_bit(IN_A2,0);
        set_pwm1_duty(255);
        output_bit(IN_B1,0);
        output_bit(IN_B2,1);
        set_pwm2_duty(255);
}

void atras() // Move backward
{
        output_bit(IN_A1,0);
        output_bit(IN_A2,1);
        set_pwm1_duty(255);
        output_bit(IN_B1,1);
        output_bit(IN_B2,0);
        set_pwm2_duty(255);
}
/*
* This is an interrupt so the micro keeps checking if the QTR sensors detect and edge so the robot can react respectively to
* which one of the sensors activated. I you have questions about the sequence on how to use them go check out the datasheet they explain
* why we need to do it this way.
*/

#INT_TIMER0
void sensorlinea(){ 

        output_high(sensor1);
        output_high(sensor3);
        output_high(sensor5);
        delay_us(15);
        if(input(sensor2)==0 && input(sensor4)==1 && input(sensor6)==1)//right sensor
        {
                atras();//move backward

        }
        if(input(sensor4)==0 && input(sensor2)==1 && input(sensor6)==1)//rear sensor
        {
                adelante();//move forward
        }
        if(input(sensor6)==0 && input(sensor2)==1 && input(sensor4)==1)//left sensor
        {
                atras();//move backward
        }
        if(input(sensor2)==0 && input(sensor6)==0 && input(sensor4)==1)//Righ and left sensor
        {
                atras();//move backward
        }
        output_low(sensor1);
        output_low(sensor3);
        output_low(sensor5);
        SET_TIMER0(6);
}

void main()
{
        delay_ms(5000);// 5 seconds delay - minisumo rule
        IniPuertos();
        IniPWM();
        clear();
        setup_timer_0(RTCC_INTERNAL | RTCC_DIV_4);
        SET_TIMER0(6);
        clear_interrupt(INT_TIMER0);
        enable_interrupts(INT_TIMER0);
        enable_interrupts(GLOBAL);
        while(true)
        {
                valor=getc();
                switch(valor) //  a switch to compare the data sent from the cell phone to the microcontroller, in order to make the correct instruction.
                {
                case 'u':
                        output_high(led1);
                        output_high(led2);
                        adelante(); //move forward
                        break;

                case 'd':
                        output_low(led1);
                        output_low(led2);
                        atras(); //move backward
                        break;

                case 'r':
                        output_high(led2);
                        output_low(led1);
                        giroderecho(); //right turn
                        break;

                case 'l':
                        output_high(led1);
                        output_low(led2);
                        giroizquierdo(); //left turn
                        break;

                case 's':
                        output_low(led1);
                        output_low(led2);
                        stop(); //stop
                        break;
                }
        }

}

