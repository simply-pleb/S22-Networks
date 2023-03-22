Network address translation

problem: we dont have enough addresses to represent each machine

fit more IPs into IPv4 network than physically possible

static nat: # ip nat inside source static <private-ip> <public-ip>

dynamic nat:    # ip nat pool Innopolis <pool-first-ip> <pool-last-ip> netmask 255.255.255.255
                # access-list 1 permit <private-ip> 0.0.0.255
                # ip nat inside source list 1 pool Innopolis

pat: # ip nat inside source list 1 pool Innopolis overload


NAT:
|    IP    |    TCP    |    data	|
use some of the bits in the TCP header to extend the address space.
the particular addresses it uses are port numbers, and the source port in particular

remapping of the IPs in one network (private) to another one (public) with the use of a gateway.
Example:
10.0.0.10:32621 -> 128.243.20.20:16
10.0.0.11:32621 -> 128.243.20.20:17
10.0.0.12:32621 -> 128.243.20.20:18
10.0.0.13:32621 -> 128.243.20.20:19
10.0.0.14:32621 -> 128.243.20.20:20

private area is the network of your router 
public area is the global internet

Static NAT - maps a private address to a public address 

Dynamic NAT - In this type of NAT, multiple private IP addresses are mapped to 
a pool of public IP addresses. It is used when we know the number of fixed 
users who want to access the Internet at a given point in time. 

PAT (Port Address Translation) - Port Address Translation (PAT) is another type 
of dynamic NAT which can map multiple private IP addresses to a single public 
IP address by using a technology known as Port Address Translation.

Static NAT v PAT

Static NAT has 1 to 1 mapping between addresses. Like this address in my 
private network will be that address in the public network

PAT creates the mapping itself, so that you dont know exactly what address your 
PC has in the public network

Dynamic NAT v  PAT

Dynamic NAT maps addresses in the private area to multiple addresses in the 
public area from a group of public IP addresses called as NAT pool

PAT maps addresses in the private area to a single address in the public area 
by using different ports


