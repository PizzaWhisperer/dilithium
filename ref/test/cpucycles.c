#include <stdint.h>
#include <time.h>

uint64_t cpucycles_overhead(void) {
  uint64_t t0, t1, overhead = -1LL;
  unsigned int i;

  for(i=0;i<100000;i++) {
    t0 = (float)clock()*(1000000000/CLOCKS_PER_SEC);
    __asm__ volatile("");
    t1 = (float)clock()*(1000000000/CLOCKS_PER_SEC);
    if(t1 - t0 < overhead)
      overhead = t1 - t0;
  }

  return overhead;
}
