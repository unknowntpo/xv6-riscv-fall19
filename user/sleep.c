#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  if (argc <= 1) {
    printf("usage: sleep <sec>\n");
    exit();
  }

  int i = 0;
  while (i < argc) {
    printf("argv[%d] = %s%s", i, argv[i], i < argc - 1 ? " " : "\n");
    i++;
  }

  exit();
}
