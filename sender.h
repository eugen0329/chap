#ifndef SENDER_H_NBHXX2CE
#define SENDER_H_NBHXX2CE

#ifndef BUF_SIZE
#  define BUF_SIZE 1024
#endif

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <locale.h>
#include <string.h>

void * sender(void *untyped_argv);

#endif /* end of include guard: SENDER_H_NBHXX2CE */
