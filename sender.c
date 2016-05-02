#include "sender.h"

void * sender(void *untyped_argv)
{
    char **argv = (char **) untyped_argv;
    struct in_addr localInterface;
    struct sockaddr_in groupSock;

    int sd;
    char databuf[BUF_SIZE];
    int datalen = sizeof(databuf);

    sd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sd < 0) {
        perror("Opening datagram socket error");
        exit(1);
    }

    memset((char *) &groupSock, 0, sizeof(groupSock));
    groupSock.sin_family = AF_INET;
    // multicast group (Class D) - leading bits are 1110.
    // 224..239 == 1110_0000..1110_1111
    groupSock.sin_addr.s_addr = inet_addr("226.1.1.1");

    groupSock.sin_port = htons(4321);

    /* Set local interface for outbound multicast datagrams. */
    /* The IP address specified must be associated with a local, */
    /* multicast capable interface. */
    localInterface.s_addr = inet_addr(argv[1]);
    if (setsockopt(sd, IPPROTO_IP, IP_MULTICAST_IF, (char *)&localInterface, sizeof(localInterface)) < 0) {
        perror("Setting local interface error");
        exit(1);
    }

    /* Send a message to the multicast group specified by the*/
    /* groupSock sockaddr structure. */
    while(1) {
        readline(databuf, BUF_SIZE);
        if(sendto(sd, databuf, datalen, 0, (struct sockaddr*)&groupSock, sizeof(groupSock)) < 0) {
            perror("Sending datagram message error");
        }
    }
}
