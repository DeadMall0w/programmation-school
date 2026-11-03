// TODO rajouter CHECK

#include <__stdarg_va_list.h>
#include <bits/types/sigset_t.h>
#include <signal.h>

void installSignal(int numSig, void (*handler)(init), int flags) {
  struct sigaction newAct;
  newAct.sa_handler = handler;
  newAct.sa_flags = flags;
  CHECK(sigemptyset(newAct.sa_mask), "--sigemptyset");
  CHECK(sigaction(newSig, &newAct, NULL), "--sigaction");
}

void debloquerSignaux(int nbSig, ...) {
  sigset_t mask;
  varlist pArg;
  va_list(pArg, nbSig);
  CHECK(sigemptyset(&mask), "--sigemptyset");

  for (int i = 0; i < nbSig; i++)
    CHECK(sigaddset(&mask, va_arg(pArg, init)), "--sigaddset");
  CHECK(sigprocmask(SIG_UNBLOCK, &mask, NULL), "--sigprocmask");
  va_end(pArg);
}
