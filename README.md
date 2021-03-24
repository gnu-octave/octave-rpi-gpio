octave-rpi-gpio
===============

GNU Octave wrapper around libbcm2835 for GPIO control of the RaspberryPI IOs

Oct wrapper v0.0.2 around libbcm2835

1.) install octave and liboctave-dev as described on
    http://wiki.octave.org/Rasperry_Pi

2.) get and compile libbcm2835 from http://www.airspayce.com/mikem/bcm2835/:

```
    $ wget http://www.airspayce.com/mikem/bcm2835/bcm2835-1.68.tar.gz
    $ tar xzvf bcm2835-1.68.tar.gz
    $ cd bcm2835-1.68/
    $ ./configure CFLAGS=-fPIC
    $ make
    $ sudo make install
```

3.) compile the oct wrapper
```
  $ cd ..
  (current directory is now octave-rpi-gpio, the root of the repo)
  $ make
```  
4.) Test it (run octave as root to have GPIO access rights)
```
   $ sudo octave
   execute simple Test with GPIO 7 (lower right edge, see here http://elinux.org/RPi_Low-level_peripherals)
   Attention: there is also a Revision2 with different GPIO layout

   octave:1> test_bcm2835oct
```
