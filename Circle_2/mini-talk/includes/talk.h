////////////////////////////////////////////////////////////////////////////////////////////
////                                                                                    ////
////                                 Minitalk - TALK.H                                  ////
////                                                                                    ////
////////////////////////////////////////////////////////////////////////////////////////////

#ifndef TALK_H
#define TALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdbool.h>

void    send_message(int pid, char *message);
void    handle_signal(int signo, siginfo_t *info, void *context);
void    setup_signal(void (*handler)(int, siginfo_t *, void *));

#endif
