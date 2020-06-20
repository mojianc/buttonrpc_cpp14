// customrpc-demo-sever.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <zmq.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <windows.h>
#include <iostream>

int main()
{
	//  Socket to talk to clients
	void *context = zmq_ctx_new();
	void *responder = zmq_socket(context, ZMQ_REP);
	int rc = zmq_bind(responder, "tcp://*:5555");
	assert(rc == 0);

	while (1) {
		char buffer[10];
		zmq_recv(responder, buffer, 10, 0);
		printf("Received Hello\n");
		Sleep(1);          //  Do some 'work'
		zmq_send(responder, "World", 5, 0);
	}
	
	return 0;
}

