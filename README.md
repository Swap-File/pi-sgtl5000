# pi-sgtl5000


The sgtl5000 driver in raspbian does not expose some of the sgtl5000's advanced functionality and the advanced functionality it does expose can be difficult to use.

This modified version of PaulStoffregen's sgtl5000 control library exposes everything and keeps all the naming of the sgtl5000 datasheet, which you will likely want to reference as you set the chip up.

I use it with my Fe-Pi Audio Z V2:

https://fe-pi.com/products/fe-pi-audio-z-v2

It uses bcm2835 for i2c access:

http://www.airspayce.com/mikem/bcm2835/
