#include <avr/io.h>
#include <util/delay.h>

#define SDI PC0 //0x1
#define CLK PC1 //0x2
#define LE  PC2 //0x4
#define OE  PC3 //0x8

int main (void)
{
  unsigned int blue[24] = {0, 0, 1, 1, 1, 0, 0, 1,
			   1, 1, 0, 0, 0, 0, 1, 1,
			   1, 0, 0, 1, 1, 1, 0, 1};

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
      PORTC &= ~(1 << LE);;
      _delay_ms(50);

      for(i=0;i<24;i++){
	  /* 
	   * SDI = HIGH
	   * CLK = Toggle
	   */
	  if(blue[i] == 1){
		PORTC |= 0x1;
	  }
	  else{
		PORTC &= 0x0;
	  }
          PORTC |= (1 << CLK);
      	  _delay_ms(50);
          PORTC &= ~(1 << CLK);
      }

      /* set PORTC LE (active) high*/
      PORTC |= (1 << LE);

      _delay_ms(50);

      /* set PORTC OE (active) low */
      PORTC &= ~(1 << OE);

      _delay_ms(50);
  }

  return 1;
}

