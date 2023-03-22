routing table
	show ip route
	C - directly connected
	L - local route within the connected 
	/32 mask - every bit turned on which refers to a single host (host route)
	sub-netted -
	variably sub-netted

creating static connections
	ip route <destination> <mask> <next-hop>
	
static routes are not aware of the state of the network

use interfaces instead of ip addresses

DTE port - data terminal equipment
DCE port - data circuit termination equipment (has a clock rate)
