/*
 Copyright (C) 2013 Andreas Weber

 stub for an octave wrapper around the bcm2835 lib from
 http://www.open.com.au/mikem/bcm2835/
*/

#include <octave/oct.h>
#include <bcm2835.h>

static int init_ret = 0;

DEFUN_DLD (bcm2835_init, args, nargout,
  "-*- texinfo -*-\n\
@deftypefn  {@var{ret}=} bcm2835_init ()\n\
Initialise the library by opening /dev/mem and getting pointers to the\n\
internal memory for BCM 2835 device registers. You must call this\n\
(successfully) before calling any other functions in this library\n\
(except bcm2835_set_debug). If bcm2835_init() fails by returning 0,\n\
calling any other function may result in crashes or other failures.\n\
Prints messages to stderr in case of errors. \n\
@end deftypefn")
{
  octave_value_list retval;
  init_ret = bcm2835_init ();
  retval(0) = init_ret;
  return retval;
}

DEFUN_DLD (bcm2835_close, args, nargout,
  "-*- texinfo -*-\n\
@deftypefn  {@var{ret}=} bcm2835_close ()\n\
Close the library, deallocating any allocated memory and closing /dev/mem\n\
@end deftypefn")
{
  octave_value_list retval;
  retval(0) = bcm2835_close ();
  return retval;
}

DEFUN_DLD (bcm2835_gpio_fsel, args, nargout,
  "-*- texinfo -*-\n\
@deftypefn  {} bcm2835_gpio_fsel (@var{pin}, @var{mode})\n\
TDOD: document me!\n\
@end deftypefn")
{
  octave_value_list retval;
  int nargin = args.length ();

  if (nargin != 2)
    print_usage ();

  if (! init_ret)
    error ("bcm2835 not initialized");

  int pin = args(0).int_value();
  int mode = args(1).int_value();

  bcm2835_gpio_fsel (pin, mode);
  return retval;
}

DEFUN_DLD (bcm2835_gpio_set, args, nargout,
  "-*- texinfo -*-\n\
@deftypefn  {} bcm2835_gpio_set (@var{pin})\n\
TDOD: document me!\n\
@end deftypefn")
{
  octave_value_list retval;
  int nargin = args.length ();

  if (nargin != 1)
    print_usage ();

  if (! init_ret)
    error ("bcm2835 not initialized");

  int pin = args(0).int_value();

  bcm2835_gpio_set (pin);
  return retval;
}

DEFUN_DLD (bcm2835_gpio_clr, args, nargout,
  "-*- texinfo -*-\n\
@deftypefn  {} bcm2835_gpio_clr (@var{pin})\n\
TDOD: document me!\n\
@end deftypefn")
{
  octave_value_list retval;
  int nargin = args.length ();
  if (nargin !=1)
    print_usage ();

  if (! init_ret)
    error ("bcm2835 not initialized");

  int pin = args(0).int_value();

  bcm2835_gpio_clr (pin);
  return retval;
}
