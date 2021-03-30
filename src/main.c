#define __AVR_ATmega328__
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
	DDRB |= (1<<PB5);
	DDRD &= ~(1<<PD2); // input mode on PIND2
	while (1) {
		if(PIND & (1<<2)) {
			PORTB |= (1<<PB5);
		} else {
			PORTB &= ~(1<<PB5);
		}
	}
	return 0;
}
