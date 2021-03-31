#define __AVR_ATmega328__
#include <avr/io.h>
#include <util/delay.h>

#define DELAY_MS 1000

void init() {
	DDRD |= (1<<PD2);
	DDRD |= (1<<PD3);
	DDRD |= (1<<PD4);
	DDRD |= (1<<PD5);
	DDRD |= (1<<PD6);
	DDRD |= (1<<PD7);
	DDRB |= (1<<PB0);
}

/* clear all bits (set bits to 0) */
void clear() {
	PORTD &= ~(1<<PD2);
	PORTD &= ~(1<<PD3);
	PORTD &= ~(1<<PD4);
	PORTD &= ~(1<<PD5);
	PORTD &= ~(1<<PD6);
	PORTD &= ~(1<<PD7);
	PORTB &= ~(1<<PB0);
}

void one(void) {
	PORTD |= (1<<PD4); // bottom right
	PORTB |= (1<<PB0); // top right
}

void two(void) {
	PORTD |= (1<<PD7); // top
	PORTB |= (1<<PB0); // top right
	PORTD |= (1<<PD5); // middle
	PORTD |= (1<<PD2); // bottom left
	PORTD |= (1<<PD3); // bottom
}

void three(void) {
	PORTD |= (1<<PD7);
	PORTD |= (1<<PD4);
	PORTD |= (1<<PD5);
	PORTB |= (1<<PB0);
	PORTD |= (1<<PD3);
}


int main(void) {
	while (1) {
		one();
		_delay_ms(DELAY_MS);
		clear();

		two();
		_delay_ms(DELAY_MS);
		clear();

		three();
		_delay_ms(DELAY_MS);
		clear();
	}
	return 0;
}
