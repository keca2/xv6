#ifdef CS333_P2
#include "types.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  printf(1, "***** In %s: my uid is %d and my gid is %d", argv[0], getuid(), getgid());

  exit();
}
#endif
