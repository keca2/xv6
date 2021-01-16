#ifdef CS333_P2
#include "types.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  uint uid;
  printf(1, "***** In %s: my uid is %d\n\n", argv[0], getuid());
  printf(1, "***** Setting UID to 100\n");
  setuid(100);
  uid = getuid();
  printf(1, "Current UID is: %d\n", uid);
  exit();
}
#endif
