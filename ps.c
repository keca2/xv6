#ifdef CS333_P2
#include "types.h"
#include "uproc.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int MAXNAME = 12;
  int len = 0;
  int max_size = 64;
  struct uproc * u = malloc(max_size * sizeof(struct uproc));

  int counter = getprocs(max_size, u);

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

    printf(1, "%d\t\t%d\t%d\t%d.%d\t%d.%d\t%s\t%d\n", u[i].uid, u[i].gid, u[i].ppid, u[i].elapsed_ticks/1000, u[i].elapsed_ticks%1000, u[i].CPU_total_ticks/1000, u[i].CPU_total_ticks%1000, u[i].state, u[i].size);  
  }
 
  if(u)
    free(u);

  exit();
}
#endif // CS333_P2
