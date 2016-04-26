def find_node_address

set $_head = $arg0
set $i=1

while($i < $arg1)
	
	p $arg0 = $arg0->next
	p $i = $i+1

end

p $arg2 = $arg0

p $arg0 = $_head

end
