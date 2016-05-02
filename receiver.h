#ifndef RECEIVER_H_EFP8YXQ7
#define RECEIVER_H_EFP8YXQ7


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

void * receiver(void* argv);

#endif /* end of include guard: RECEIVER_H_EFP8YXQ7 */
