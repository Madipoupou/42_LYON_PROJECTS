# /bin/sh

IP=$(ifconfig | grep "inet " | cut -d ' ' -f2)
if [ -z "$IP" ]
then
	echo "I am lost!"
else
	echo $IP | tr ' ' '\n';
fi
