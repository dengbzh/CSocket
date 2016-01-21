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

int main()
{
    ServerSocket server("127.0.0.1",7777);
    ClientSocket client;
    server.Accept(client);
    string msg;
    while(1)
    {
       server.Receive(client,msg);
       server.Send(client,msg);
    }

    return 0;
}
