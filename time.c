#include "types.h"
#include "user.h"

 
int
Fork(void)
{
  int pid;

  if((pid = fork()) < 0)
    printf(1, "fork system call failed.\n");
  return pid;
}

int 
main(int argc, char * argv[])
{
  if(argc == 0)
    exit();

  int start = uptime();
  int end;
  int elapsed;
  int pid = Fork();

  if(pid > 0)  // parent process
    wait();

  if(pid == 0) // child process
  {
    ++argv;
    exec(argv[0], argv);
    exit();
  }

  // parent process
  end = uptime();
  elapsed = end - start;

  printf(1, "%s ran in %d.%d seconds.\n", argv[1], elapsed/1000, elapsed%1000);
  exit();
}
