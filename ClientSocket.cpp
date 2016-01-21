/*
 * =====================================================================================
 *
 *       Filename:  ClientSocket.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/21/2016 05:19:31 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dengbzh (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include"ClientSocket.h"

ClientSocket::ClientSocket()
{

}

ClientSocket::ClientSocket(const string &host,const int port)
{
    int ret = Socket::Create();
    if(ret == -1)
    {
        err_sys("client create failed...\n");
    }
    ret = Socket::Connect(host,port);
    if(ret == -1)
    {
        err_sys("client connect failed...\n"); 
    }
}

ClientSocket::~ClientSocket()
{

}

int ClientSocket::Receive(string &msg)
{
    return Socket::Receive(static_cast<Socket&>(*this),msg);
}

int ClientSocket::Send(const string &msg)
{
    return Socket::Send(static_cast<Socket&>(*this),msg);
}
