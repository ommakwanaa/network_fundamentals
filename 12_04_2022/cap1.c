// this program shows how to use packet interface to capture all the packets at data link layer //
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netpacket/packet.h>
#include<net/ethernet.h>

void main(){
    int packet_socket,n;
    struct sockaddr_ll sa;
    socklen_t sl;
    char buff[2000];
    sl = sizeof(struct sockaddr_ll );
    packet_socket = socket(PF_PACKET,SOCK_RAW,htons(ETH_P_ALL));
    if(packet_socket<0){
        printf("failed");
        exit(0);
    }
    printf("packet socket successfully opened\n");
    while (1)
    {
        n = recvfrom(packet_socket,buff,2000,0,(struct sockaddr *)&sa,&sl);
        printf("received packet of length %d\n",n);

    }
    close(packet_socket);
    
}