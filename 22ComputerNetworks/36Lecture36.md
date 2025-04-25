# Socket programming

## Writing chat application using Sockets
- we have 1 server and 2 clients
- intention: client 1 sends message to server, which server forwards to client 2, vis-a-vis client 2 sends message to server, which server forwards to client 1

### Steps involved
- Servers starts and binds itself to a port. bind(port)
- server invokes listen() method to listen for incoming connections on given port.
- client sends a connection request to server connect(IP, port)
- server accepts the connection request. accept()
- client 2 also sends a connection request to server connect(IP, port)
- server accepts the second connection request. accept()
- connect() binds clients implicitly to an ephemeral port for the duration of connection and strats listening to that port
- client 1 sends message to server: send() :: receive()
- server forwards message to client 2: send() :: receive()
- If a client exits the chat, close() is called and the connection with server for that client breaks.
- also, if server already has too many clients connected and can't accept anymore connections then it will throw an exception: TOO_MANY_CONNECTIONS
