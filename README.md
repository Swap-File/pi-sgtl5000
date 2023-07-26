# pi-sgtl5000


The sgtl5000 driver in raspbian does not expose some of the sgtl5000's advanced functionality and the functionality it does expose can be difficult to use.

This modified version of PaulStoffregen's sgtl5000 control library exposes everything for modification and it keeps the element naming from sgtl5000 datasheet, which you will likely want to reference as you set the chip up.

I use it with my Fe-Pi Audio Z V2:

https://fe-pi.com/products/fe-pi-audio-z-v2

It uses bcm2835 for i2c access:

http://www.airspayce.com/mikem/bcm2835/

Note:  If you take over control of the sgtl5000 with a program like this it will break alsamixer until the next reboot.  Custom settings will not persist across reboots.

Note:  Rewritten to use i2cdev here:

https://github.com/Swap-File/portal-gun-4/blob/master/portal/i2c/sgtl5000.c

Now it can coexist with othe i2c devices.
