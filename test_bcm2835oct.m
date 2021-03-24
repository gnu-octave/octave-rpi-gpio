## Test bcm2835oct.oct
## 14.01.2013 Andreas Weber
##

bcm2835_init();

# for RPi revision 1 GPIO header
# RPI_GPIO_P1_26 = 7
# set output
bcm2835_gpio_fsel (7, 1)

bcm2835_gpio_clr (7)
sleep(3);
bcm2835_gpio_set (7)
sleep(3);
bcm2835_gpio_clr (7)

bcm2835_close()

