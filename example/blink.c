#include <avr/io.h>
#include <util/delay.h>


int main (void)
{
  /* set PORTB for output*/
  DDRB = 0xFF;
  /* set PORTC low for output*/
  DDRC = 0xFF;
  /* set PORTD for output*/
  DDRD = 0xFF;

  while (1)
    {
      /* set PORTB/D high */
      PORTB = 0xFF;
      PORTD = 0xFF;

      /* set PORTC OE (active) low */
      PORTC = 0xF7;

      _delay_ms(3000);

      /* set PORTB/D low */
      PORTB = 0x00;
      PORTD = 0x00;

      /* set PORTC OE (active) low */
      /* set PORTC LE low */
      PORTC = 0xF3;

      _delay_ms(3000);
    }

  return 1;
}

