#ifdef CS333_P2
#include "types.h"
#include "uproc.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int MAXNAME = 12;
  int len = 0;
  int max_size = 64; // Variable to change for testing
  struct uproc * u = malloc(max_size * sizeof(struct uproc));

  int counter = getprocs(max_size, u);

  if(counter > max_size)
  {
    printf(1, "Error. Active processes should not be over 64. Exiting.");
    exit();
  }

  else if(counter < 0)
  {
    printf(2, "Error retrieving processes. Exiting.");
    exit();
  }

  printf(1, "PID\tName\t     UID\tGID\tPPID\tElapsed\tCPU\tState\tSize\n");

  for(int i = 0; i < counter; i++)
  {
    len = strlen(u[i].name);
    if(len > MAXNAME)
    {
      u[i].name[MAXNAME] = '\0';
      len = MAXNAME;
    }
    printf(1, "%d\t%s", u[i].pid, u[i].name);
    for(int i = len; i <=MAXNAME; i++)
      printf(1, " ");

    // for CPU time formatting
    int cpu_time = u[i].CPU_total_ticks;
    int sec = cpu_time / 1000;
    int tens = (cpu_time %= 1000) / 100;
    int hunds = (cpu_time %= 100) / 10;
    int thous = cpu_time %= 10;

    printf(1, "%d\t\t%d\t%d\t%d.%d\t%d.%d%d%d\t%s\t%d\n", u[i].uid, u[i].gid, u[i].ppid, u[i].elapsed_ticks/1000, u[i].elapsed_ticks%1000, sec, tens, hunds, thous, u[i].state, u[i].size);  
  }
 
  if(u)
    free(u);

  exit();
}
#endif // CS333_P2
