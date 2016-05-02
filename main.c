#include <pthread.h>
#include "sender.h"
#include "receiver.h"

int main(int argc, char *argv[])
{
    pthread_t threadId;
    pthread_create(&threadId, NULL, &receiver, argv);
    sender(argv);
}
