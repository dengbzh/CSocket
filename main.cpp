/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/21/2016 05:35:29 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dengbzh (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include"ClientSocket.h"
#include"ServerSocket.h"
#include<signal.h>
#include<unistd.h>

static int visitedTimes;
static double average_age;
FILE *logFp;
char logmsg[40];

static void sig_alrm(int signo)
{

    snprintf(logmsg,40,"Agerage age:%.4f\n",average_age);    
    if(logFp)
    {
        fputs(logmsg,logFp);
        fflush(logFp);
    }
 //   printf("%s\n",logmsg);
    signal(SIGALRM,sig_alrm);
    alarm(10);

}
static int myAtoi(const char *p)
{
    int ans = 0;
    while(*p >= '0' && *p <= '9')
    {
        ans += *p - '0';
        ans *= 10;
        p++;
    }
    ans /= 10;
    return ans;
}
int main(int argc,char *argv[])
{

    if(argc != 4)
    {
        exit(-1);
    }
    char *ip;
    int port;
    ip = argv[1];
    port = atoi(argv[2]);
    char file_name[40];
    sprintf(file_name,"Visited_%s.log",argv[3]);
    logFp = fopen(file_name,"a+");
    if(logFp == NULL)
    {
        exit(-1);
    }
    ServerSocket server(ip,port);
    ClientSocket client;
    string msg;
    visitedTimes = 0;
    average_age = 0.0;
    int cur_age;
//again:
   // alarm(0);
   // server.Accept(client);

    if(signal(SIGALRM,sig_alrm) == SIG_ERR)
    {
        exit(-1);
    }
    alarm(10);
    server.Accept(client);
    while(1)
    {
      int ret = server.Receive(client,msg);
      if( ret > 0 )
      {
        const char *tmp = msg.c_str();
        int len = msg.length();
        int i = 0;
        while(i != len)
        {
            if(*tmp == 'A' && strncmp(tmp,"Age=",4) == 0)
            {
                tmp += 4;
                break;
            }
            tmp++;
            i++;
        }
        cur_age = myAtoi(tmp);
       server.Send(client,msg);
//       printf("%s\n cur age: %d \n visited times:%d\n",msg.c_str(),cur_age,visitedTimes);
       visitedTimes++;
       average_age = (average_age/visitedTimes)*(double)(visitedTimes-1) + (double)cur_age/visitedTimes;
      }
      else if(ret == 0)
      {
         // printf("exit\n");
         server.Accept(client);
      }else 
          break;
    }
    fclose(logFp);
    return 0;
}
