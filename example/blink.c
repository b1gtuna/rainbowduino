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
      unsigned int i=0;

      /* set PORTB/C/D high */
      PORTB = 0xFF;
      PORTC = 0xFF;
      PORTD = 0xFF;

      /* set PORTC LE (inactive) low*/
      PORTC = PORTC & ~0x4;;
      _delay_ms(300);

      for(i=0;i<8;i++){
          PORTC = PORTC | 0x3;
      	  _delay_ms(300);
          PORTC = PORTC & ~0x2;
      }

      /* set PORTC LE (active) high*/
      PORTC = PORTC | 0x4;;

      _delay_ms(300);

      /* set PORTC OE (active) low */
      PORTC = PORTC & ~0x8;

      _delay_ms(3000);
  }

  return 1;
}

