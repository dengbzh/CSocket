/*
 * =====================================================================================
 *
 *       Filename:  ServerSocket.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/21/2016 05:10:08 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dengbzh (), 
 *   Organization:  
 *
 * =====================================================================================
*/
#ifndef _SERVERSOCKET_H
#define _SERVERSOCKET_H
#include"Socket.h"
class ServerSocket:public Socket
{
private:
    ServerSocket();
public:
    ServerSocket(const string &host,const int port);
    virtual ~ServerSocket();
};
#endif

