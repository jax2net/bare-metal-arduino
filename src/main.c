#define __AVR_ATmega328__
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
	DDRB |= (1<<PB0);
	DDRD &= ~(1<<PD2); // input mode on PD2
	while (1) {
		if (PIND & (1<<PD2)) {
			// init
		} else {

		}
	}
	return 0;
}
