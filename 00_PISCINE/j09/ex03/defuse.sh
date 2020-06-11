touch -r bomb.txt -A '-000001' bomb.txt && stat bomb.txt | cut -d ' ' -f11
