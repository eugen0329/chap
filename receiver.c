#include "receiver.h"

void * receiver(void *untyped_argv)
{
    char **argv = (char **) untyped_argv;
    struct sockaddr_in localSock;
    struct ip_mreq group;
    int sd;
    int datalen;
    char databuf[BUF_SIZE];
    int reuse = 1;

    socklen_t slen;
    /* Create a datagram socket on which to receive. */
    sd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sd < 0) {
        perror("Opening datagram socket error");
        exit(1);
    }

    /* Enable SO_REUSEADDR to allow multiple instances of this */
    /* application to receive copies of the multicast datagrams. */
    if(setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(reuse)) < 0) {
        perror("Setting SO_REUSEADDR error");
        close(sd);
        exit(1);
    }

    /* Bind to the proper port number with the IP address */
    /* specified as INADDR_ANY. */
    memset((char *) &localSock, 0, sizeof(localSock));
    localSock.sin_family = AF_INET;
    localSock.sin_port = htons(4321);
    localSock.sin_addr.s_addr = INADDR_ANY;
    if(bind(sd, (struct sockaddr*)&localSock, sizeof(localSock))) {
        perror("Binding datagram socket error");
        close(sd);
        exit(1);
    }

    // Join the multicast group 226.1.1.1 on the local argv[1] addr interface.
    group.imr_multiaddr.s_addr = inet_addr("226.1.1.1");
    group.imr_interface.s_addr = inet_addr(argv[1]);

    if(setsockopt(sd, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char *)&group, sizeof(group)) < 0) {
        perror("Adding multicast group error");
        close(sd);
        exit(1);
    }

    slen = sizeof(localSock);
    while(1) {
        if (recvfrom(sd, databuf, sizeof(databuf), 0, (struct sockaddr *) &localSock, &slen) < 0) {
            perror("Reading datagram message error");
            close(sd);

            exit(1);
        } else {
            printf("<- \"%s\"\n", databuf);
        }
    }
}



