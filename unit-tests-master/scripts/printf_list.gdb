def printf_list
p $_head = $arg0

while($arg0)
	p $arg0->value
	p $arg0 = $arg0->next
end

p $arg0 = $_head

end
