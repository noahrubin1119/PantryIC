/*
 * IC-V1.c
 *
 * Created: 4/21/2021 1:11:06 PM
 * Author : user
 */ 

#define F_CPU 800000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	
	/*
	 Pi power on C5, Empty Button on C4, Shutdown button on C3, Magnet switch on C2
	 DDRC = 0b00100000 = 0x20
	*/
	
	DDRC = 0x20;
	PORTC = 0x1C;
	
	while(1){
		
		if(!(PINC & 0x10)){ //Empty Button
			PORTC |= 0x20; //Pi Power On
		}
		if(!(PINC & 0x08)){ //Shutdown pin
			PORTC &= 0xDF; //Pi Off
		}
		if(!(PINC & 0x04)){//magnet switch
			PORTC |= 0x20; //mark pin C5 high and keep rest of C pins
			_delay_ms(500);
			PORTC &= 0xDF; //mask: 11011111
			_delay_ms(500);
		}
	}
}

