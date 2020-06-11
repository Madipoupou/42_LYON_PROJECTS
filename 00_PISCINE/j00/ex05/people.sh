ldapsearch -Q "(uid=z*)" | grep "^cn" | grep .  | sort -f -d -r
