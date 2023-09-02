#include <16F628A.h>
#use delay (clock=4000000)
#fuses NOMCLR,INTRC_IO
#include <lcd.c>

int s,m,h,setm,seth;

#define af pin_b3

int i;

void Cs3()

{
 for(i=0; i<26; i++)
  {output_high(af);
   delay_us (893);
   output_low (af);
   delay_us (893);
  }
}

void E3()

{
 for(i=0; i<30; i++)
  {output_high(af);
   delay_us (757);
   output_low (af);
   delay_us (757);
  }
}

void Fs3()

{
 for(i=0; i<34; i++)
  {output_high(af);
   delay_us (675);
   output_low (af);
   delay_us (675);
  }
}

void Gs3()

{
 for(i=0; i<40; i++)
  {output_high(af);
   delay_us (595);
   output_low (af);
   delay_us (595);
  }
}

void A3()

{
 for(i=0; i<40; i++)
  {output_high(af);
   delay_us (568);
   output_low (af);
   delay_us (568);
  }
}

void B3()

{
 for(i=0; i<44; i++)
  {output_high(af);
   delay_us (506);
   output_low (af);
   delay_us (506);
  }
}

void add()
{
 s++;
 if(s==60)
 {s=0;
  m++;}
 if(m==60)
 {m=0;
  h++;}
 if(h==24)
 {h=0;}
}

main()
{

lcd_init();

s=0;
m=0;
h=0;
setm=00;
seth=12;

while(1)
{
 alarm:
 
 while(input(pin_a5)==0)

{

 if(m==setm && h==seth)
 { 
 
 while (1)
 
 {
 lcd_gotoxy(3,1);
 printf(lcd_putc,"   Awake!    "); 
    
    E3(); 
    delay_ms (15);
    
    add();
    if(input(pin_a5)==1)
   {goto inicio;}
    
    delay_ms (60);
    Gs3();
    
    add();
    if(input(pin_a5)==1)
   {goto inicio;}
    
    delay_ms (10);
    A3();
    
    add();
    if(input(pin_a5)==1)
   {goto inicio;}
    
    delay_ms (72);
    E3();
    
    add();
    if(input(pin_a5)==1)
   {goto inicio;}
    
    delay_ms (10);
    Gs3();
    
    add();
    if(input(pin_a5)==1)
   {goto inicio;}
    
    delay_ms (10);
    A3();
    
    add();
    if(input(pin_a5)==1)
   {goto inicio;}
    
    delay_ms (72);
    E3();
    
    add();
    if(input(pin_a5)==1)
   {goto inicio;}
    
    delay_ms (10);
    Gs3();
    
    add();
    if(input(pin_a5)==1)
   {goto inicio;}
    
    delay_ms (10);
    A3();
    
    add();
    if(input(pin_a5)==1)
   {goto inicio;}
    
    delay_ms (10);
    B3();
    
    add();
    if(input(pin_a5)==1)
   {goto inicio;}
    
    delay_ms (10);
    A3();
    
    add();
    if(input(pin_a5)==1)
   {goto inicio;}
    
    delay_ms (10);
    Gs3();
    
    add();
    if(input(pin_a5)==1)
   {goto inicio;}
    
    delay_ms (12);
    A3();
    
    add();
    if(input(pin_a5)==1)
   {goto inicio;}
    
    delay_ms (12);
    E3();
    
    add();
    if(input(pin_a5)==1)
   {goto inicio;}
    
    delay_ms (75);
    Gs3();
    
    add();
    if(input(pin_a5)==1)
   {goto inicio;}
    add();
    
    delay_ms (10);
    A3();
    
    add();
    if(input(pin_a5)==1)
   {goto inicio;}
    
    delay_ms (71);
    Cs3();
    
    add();
    if(input(pin_a5)==1)
   {goto inicio;}
    
    delay_ms (71);
    E3();
    
    add();
    if(input(pin_a5)==1)
   {goto inicio;}
    
    delay_ms (71);
    Fs3();
    
    add();
    if(input(pin_a5)==1)
   {goto inicio;}
    
    delay_ms (71);
    E3();
    
    add();
    if(input(pin_a5)==1)
   {goto inicio;}
    add();
    
    delay_ms (10);
    E3();
    
    add();
    if(input(pin_a5)==1)
   {goto inicio;}
    
    delay_ms (10);
    Fs3();
    
    add();
    if(input(pin_a5)==1)
   {goto inicio;}
    
    delay_ms (10);
    A3();
    
    add();
    if(input(pin_a5)==1)
   {goto inicio;}
    
    delay_ms (10);
    Gs3();
    
    add();
    if(input(pin_a5)==1)
   {goto inicio;}
   
    delay_ms (10);
   }
 } 
 
 lcd_gotoxy(3,1);
 printf(lcd_putc,"Alarm ");
 printf(lcd_putc,"%02u:",seth);
 printf(lcd_putc,"%02u",setm);
 if(input(pin_a5)==1)
 {goto inicio;}
 
 delay_ms(100);
 
 if(input(pin_a0)==0)
 {setm++;}
 if(input(pin_a1)==0)
 {seth++;}
 if(s==60)
 {s=0;
  m++;}
 if(m==60)
 {m=0;
  h++;}
 if(h==24)
 {h=0;}
 if(setm==60)
 {setm=0;
  seth++;}
 if(seth==24)
 {seth=0;}
 if(input(pin_a5)==1)
 {goto inicio;}
 
 lcd_gotoxy(3,1);
 printf(lcd_putc,"Alarm ");
 printf(lcd_putc,"%02u:",seth);
 printf(lcd_putc,"%02u",setm);
 
 delay_ms(100);
 
 s++;
 if(input(pin_a0)==0)
 {setm++;}
 if(input(pin_a1)==0)
 {seth++;}
 if(s==60)
 {s=0;
  m++;}
 if(m==60)
 {m=0;
  h++;}
 if(h==24)
 {h=0;}
 if(setm==60)
 {setm=0;
  seth++;}
 if(seth==24)
 {seth=0;}
   
 }
 
 inicio:
 
 lcd_gotoxy(3,1);
 printf(lcd_putc,"  %02u:",h);
 printf(lcd_putc,"%02u:",m);
 printf(lcd_putc,"%02u   ",s);
 
 if(input(pin_a5)==0)
 {goto alarm;}
 
 delay_ms(100);
 
 if(input(pin_a0)==0)
 {m++;}
 if(input(pin_a1)==0)
 {h++;} 
 if(m==60)
 {m=0;
 h++;}
 if(h==24)
 {h=0;}

 lcd_gotoxy(3,1);
 printf(lcd_putc,"  %02u:",h);
 printf(lcd_putc,"%02u:",m);
 printf(lcd_putc,"%02u   ",s);
 if(input(pin_a5)==0)
 {goto alarm;}
 
 delay_ms(100);

 s++;
 if(input(pin_a0)==0)
 {m++;}
 if(input(pin_a1)==0)
 {h++;}
 if(s==60)
 {s=0;
  m++;}
 if(m==60)
 {m=0;
  h++;}
 if(h==24)
 {h=0;}

}
}




