/*
 * =====================================================================================
 *
 *       Filename:  ServerSocket.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/21/2016 05:13:55 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dengbzh (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include"ServerSocket.h"
ServerSocket::ServerSocket(const string &host,const int port)
{
    int ret = Create();
    if(ret == -1)
    {
        err_sys("server socket create failed...\n");
    }
    ret = Bind(host,port);
    if(ret == -1)
    {
        err_sys("server socket bind failed...\n");
    }
    ret = Listen();
    if(ret == -1)
    {
        err_sys("server socket bind failed...\n");
    }
}

ServerSocket::~ServerSocket()
{

}
