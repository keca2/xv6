#ifdef CS333_P2
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

  if(pid == 0) // child process
  {
    ++argv;
    exec(argv[0], argv);
    exit();
  }

  else if(pid < 0) //error
    exit();

  else // parent process
  {
    wait();
    end = uptime();
    elapsed = end - start;

    // formatting variables
    int seconds = elapsed / 1000;
    int tens = (elapsed %= 1000) / 100;
    int hunds = (elapsed %= 1000) / 10;
    int thous = elapsed %= 10;


    printf(1, "%s ran in %d.%d%d%d seconds.\n", argv[1], seconds, tens, hunds, thous);
    exit();
  }
}
#endif
