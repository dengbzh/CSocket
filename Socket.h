/*
 * =====================================================================================
 *
 *       Filename:  Socket.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/10/2016 05:12:08 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dengbzh (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef _SOCKET_H
#define _SOCKET_H
#include"Utility.h"
#define  MAXRECV 1024
class Socket{
private:
    int m_fd;
    struct sockaddr_in m_address;
public:
    Socket();
    virtual ~Socket();
    
    //server initialization
    int Create();
    int Bind(const string &host,const int port);
    int Listen(int back_log =5);
    int Accept(Socket & clientSoket)const;

    //client initalization
    int Connect(const string &host,const int port);
    
    //Data transmission
    int Send(Socket &socket,const string &msg)const;
    int Receive(Socket &socket,string &msg)const;

    int  setNonBlocking();
};


#endif
