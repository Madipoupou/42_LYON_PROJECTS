ifconfig | grep 'ether ' | tr -d '\t' | cut -c7- | tr -d ' '
