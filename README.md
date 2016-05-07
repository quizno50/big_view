# big_view

Simple application to display text in a terminal window, but much larger.

##Installation
make
sudo cp big_view /usr/local/bin/

##Example
```
EEEEEEE                                        lll             
 EE   E                                         ll             
 EE E    xx   xx   aaaa    mmm mm   pp ppp      ll     eeeee   
 EEEE     xx xx       aa   mmmmmmm   pp  pp     ll    ee   ee  
 EE E      xxx     aaaaa   mm m mm   pp  pp     ll    eeeeeee  
 EE   E   xx xx   aa  aa   mm m mm   ppppp      ll    ee       
EEEEEEE  xx   xx   aaa aa  mm m mm   pp        llll    eeeee   
                                    pppp                       
```

##My Use Case
A terminal window that runs:
watch big_view -f /sys/class/thermal/thermal_zone0/temp

So I can keep an eye on my CPU temperature.

##TODO
 - Auto detect terminal width and height so the font can be adjusted accordingly.
 - Allow text to be fed in via stdin
 - Colored text?
