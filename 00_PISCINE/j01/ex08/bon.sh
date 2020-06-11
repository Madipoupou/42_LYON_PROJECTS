ldapsearch -Q "(sn=*bon*)" | grep 'uid:' | wc -l | tr -d ' '
