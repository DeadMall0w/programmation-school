#include <signal.h>
#include <stdarg.h>

void installSignal(int numSig, void (*handler)(int), int flags);
void debloquerSignaux(int nbSig, ...);
void installSignaux(void (*handler)(int), int flags, int nbSig, ...);
void bloquerTousSignaux(void);
void installSIGCHLD(void);
void traiterSIGCHLD(int sig);
