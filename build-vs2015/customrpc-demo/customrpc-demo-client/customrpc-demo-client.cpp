// customrpc-demo-client.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <zmq.h>
#include <string.h>
#include <stdio.h>
using namespace std;
int main()
{
	printf("Connecting to hello world server...\n");
	void *context = zmq_ctx_new();
	void *requester = zmq_socket(context, ZMQ_REQ);
	zmq_connect(requester, "tcp://localhost:5555");

	int request_nbr;
	for (request_nbr = 0; request_nbr != 10; request_nbr++) {
		char buffer[10];
		printf("Sending Hello %d...\n", request_nbr);
		zmq_send(requester, "Hello", 5, 0);
		zmq_recv(requester, buffer, 10, 0);
		printf("Received World %d\n", request_nbr);
	}
	zmq_close(requester);
	zmq_ctx_destroy(context);
	return 0;
}

