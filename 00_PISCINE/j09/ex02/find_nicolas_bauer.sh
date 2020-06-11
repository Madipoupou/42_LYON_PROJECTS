cat contacts_hard.txt | grep -i bauer | grep -i nicolas | grep -vi anastacio | grep -vi bomber | tr '\t' ' ' | sed 's/San //' | sed 's/Los //' | sed 's/78097 //' | sed 's/37033 //' | cut -d ' ' -f4
