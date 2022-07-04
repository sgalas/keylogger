#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <math.h>
int main()
{
	//
	char bnazwa[]="log";
	struct sockaddr_in adres;
	socklen_t addr_size=sizeof adres;
	int numerPliku=0;
	FILE * plik;
	struct sockaddr_in my_addr;
	int sockfd = socket(PF_INET, SOCK_STREAM, 0);
	memset(my_addr.sin_zero, '0', sizeof my_addr.sin_zero);
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(1337);     // short, network byte order
	my_addr.sin_addr.s_addr =INADDR_ANY;
	bind(sockfd, (struct sockaddr *)&my_addr, sizeof my_addr);
	char buffer[1024];
	char numer[4];
	while(1)
	{
		listen(sockfd,1);
		int victim=accept(sockfd,(struct sockaddr *)&adres,&addr_size);
		bnazwa[3]='\0';
		numerPliku++;
		sprintf(numer,"%d",numerPliku);
		strcat(bnazwa,numer);
		bnazwa[4+(int)log10(numerPliku)]='\0';
		printf("\n");
		printf(bnazwa);
		plik=fopen(bnazwa,"w");
		while(1)
		{
			memset(buffer,0,1024);
			int ileZnakow;
			ileZnakow=recv(victim,buffer,sizeof(buffer),0);
			//case when victim aborts the connection.
			if(!ileZnakow)
			{
				fprintf(plik,"\nConnection closed!\n");
				fclose(plik);
				close(victim);
				break;
			}
			fprintf(plik,buffer);
			fclose(plik);
			bnazwa[3]='\0';
			strcat(bnazwa,numer);
			plik=fopen(bnazwa,"a");
		}
		
	}
    return 0;
}
