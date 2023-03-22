Lab goal:

1. Explore HTTP protocol
1. Explore persistent and non-persistent HTTP connection
1. Compare HTTP to HTTPS connection

## HTTP Protocol

HTTP, as well as DNS are located in the application layer.

### HTTP Request Message

(Request line)  method - sp - URL - sp - Version - cr - lf
(Header lines)
(Blank line)    cr - lf
(Entity body)

### HTTP Response Message 

(Status line)   version - sp - status code - sp - phase - cr - lf 
(Header lines)
(Blank line)    cr - lf
(Entity body)


### What is Going on Inside the Network

DNS request

Connection establishment(Three-way handshake)

Client send GET request

Server send Response 

Connection termination;
? Graceful Connection;
? Release

___Steps:___

1. Send DNS request 
1. DNS response give ip address of info.cern.ch
1. TCP connection establishment (Three-way handshake)
1. Client send GET request
1. Server send Response
    1. Server send Response (Header)
    1. Server send Response (Body)
1. Connection termination

### Three-way handshake

TODO

## Persistent and Non-Persistent HTTP Connection

RTT - round trip time.

### Non-persistent connection 

One call at a time. For example, the time to get 5 images will take 5(2RTT + RIT) 

### Persistent connection 

All calls at once. The time to get 5 images will take RTT + 5RIT + RTT

WHAT IS RIT??

## Difference Between HTTP and HTTPS Connection