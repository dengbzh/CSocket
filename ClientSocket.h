/*
 * =====================================================================================
 *
 *       Filename:  ClientSocket.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/21/2016 05:17:22 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dengbzh (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef _CLIENTSOCKET_H
#define _CLIENTSOCKET_H
#include"Socket.h"

class ClientSocket:public Socket
{
public:
    ClientSocket();
    virtual ~ClientSocket();
    ClientSocket(const string &host,const int port);

    int Receive(string &msg);
    int Send(const string &msg);
};
#endif
