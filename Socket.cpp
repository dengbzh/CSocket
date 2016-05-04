/*
 * =====================================================================================
 *
 *       Filename:  Socket.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/10/2016 05:12:24 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dengbzh (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include"Socket.h"

Socket::Socket():m_fd(-1)
{
}

Socket::~Socket()
{
    if(m_fd != -1)
        close(m_fd);
}

int Socket::Create()
{
    m_fd = socket(AF_INET,SOCK_STREAM,0);
    if(m_fd == -1)
    {
        return -1;
    }

    return 0;
}


int Socket::Bind(const string &host,const int port)
{
    if(m_fd == -1)
        return -1;
    bzero(&m_address,sizeof(m_address));
    m_address.sin_family = AF_INET;
    inet_pton(AF_INET,host.c_str(),&m_address.sin_addr);
    m_address.sin_port = htons(port);
    int ret = bind(m_fd,(struct sockaddr*)&m_address,sizeof(m_address));
    return ret;
}

int Socket::Listen(int back_log)
{
    if(m_fd == -1)
        return -1;
    int ret = listen(m_fd,back_log);
    return ret;
}

int Socket::Connect(const string &host,const int port)
{
    if(m_fd == -1)
        return -1;
    bzero(&m_address,sizeof(m_address));
    m_address.sin_family = AF_INET;
    m_address.sin_port = htons(port);
    inet_pton(AF_INET,host.c_str(),&m_address.sin_addr);
    int ret = connect(m_fd,(struct sockaddr*)&m_address,sizeof(m_address));
    return ret;

}

int Socket::Accept(Socket &Clientsocket)const
{
    int ClentaddrLen = sizeof(Clientsocket.m_address);
    Clientsocket.m_fd = accept(m_fd,(struct sockaddr*)&Clientsocket.m_address,(socklen_t *)&ClentaddrLen);
    if(Clientsocket.m_fd == -1)
        return -1;
    return 0;
}

int Socket::Send(Socket &socket,const string &msg)const
{
    int ret = send(socket.m_fd,msg.c_str(),msg.length(),0);
    return ret;
}

int Socket::Receive(Socket &socket,string &msg)const
{
    char buffer[MAXRECV + 1];
    msg.clear();
    memset(buffer,0,MAXRECV + 1);

    int ret = recv(socket.m_fd,buffer,MAXRECV,0);
    msg = buffer;
    if(ret == -1)
    {
        close(socket.m_fd);
        socket.m_fd = -1;
    }
    return ret;
}

int Socket::setNonBlocking()
{
    if(m_fd == -1)
        return -1;
    int old_opt = fcntl(m_fd,F_GETFL);
    int new_opt = old_opt | O_NONBLOCK;
    fcntl(m_fd,F_SETFL,new_opt);
    return 0;
}
