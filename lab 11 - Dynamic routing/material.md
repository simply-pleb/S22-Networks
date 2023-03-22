show ip ospf neighbour
show ip ospf interface
show ip ospf database

BGP - border gate protocol. used to transfer data to exterior networks.
it's a protocol of ISPs and the internet.



figure out the best path

	RIP - hop count
	EIGRP - 

Interior gateway protocol and Link state protocol
	
	OSPF (open shortest path first)
	link state advertisement
	LSDB (link state data base)
	
	become neighbours - two routers running OSPF on the same link agree
		to form a neighbour relationship
	exchanging database information - the neighbour routers swap their LSDB 
		information with each other
	choose the best routes - each router chooses the best routes to add to its
		routing table based on the learned LSDB infomation
	
	router ID can either be set manually of automatically by the router
	
	send hello, recieve init, send hello -> enter 2 way state and become neighbours
		
	DBD - data base description
	
	loading stage - request any information a router doesnt have from the DBD
	Link state request - a router sees that its neighbour has the LSA of an 
		address it doest have and requests it from its neighbour
	Link state update - the router at the other end of the LSR sends LSU
	Link state acknowledgement - the first router send LSAck at the end of LSU
	At the end of the exchange process the two neighbours become full neighbour
		relationship. But this is only in point to point network. In networks with
		DR and BDR routers can be full neighbors only with the DR and the BDR.
		
	Cost calculation
	
	cost of connections can be configured on the router
	

1 - What is ‘Hello Interval’?

	his defines how often we send the hello packet.
	 
2 - What is ‘Router Dead Interval’? 
	
	this defines how long we should wait for hello packets before we declare the neighbor dead.
	
3 - What is ‘Link-State Request’? 
	
	link state request is a request called to update the list of link state addresses
		from a neighbour of the router that calls it.
	
4 - What is DR and BDR? 

	DR - designated router. gets the update and sends it to the other neighbouring routers
	BDR - backup designated router
	
5 - What is ‘passive interface’?
	
	The passive interface should be configured on interfaces that do not have an OSPF router connected to them so that they won’t receive any OSPF information. By silencing routing announcements on network interfaces, we tell the router to “listen but don’t talk.” A protocol’s routing load on the CPU can be reduced by minimizing the number of interfaces with which it must interact. The ‘passive-interface’ command disables OSPF and EIGRP route processing for that interface. If you’re sure the routing protocol won’t need to communicate with anything on the specified interface, use this command.

Another reason to apply passive interface is to increase security. An attacker could start an application that replies with OSPF hello packets then our router will try to establish neighbor relationship. The attacker could then advertise fake routes to misdirect traffic.
