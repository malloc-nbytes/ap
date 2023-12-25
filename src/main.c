#define AP_IMPL
#include "./ap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
  char *str = NULL;
  (void)ap_eat(&argc, &argv);
  while ((str = ap_eat(&argc, &argv)) != NULL) {
    struct Arg arg = ap_parse(str, '-');

    if (AP_CHECK_0HYPH_OK(arg)) {
      printf("0HYPH: %s\n", arg.value);
    }
    else if (AP_CHECK_1HYPH_OK(arg)) {
      printf("1HYPH: %s\n", arg.value);
    }
    else if (AP_CHECK_2HYPH_OK(arg)) {
      printf("2HYPH: %s\n", arg.value);
    }
    else {
      printf("PROG NAME: %s\n", ap_prog_name());
    }
  }

  return 0;
}
