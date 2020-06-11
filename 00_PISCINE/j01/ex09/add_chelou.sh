echo 'obase=13; ibase=5; ' $FT_NBR1 + $FT_NBR2 | tr '\\"?!' '1234' | tr "'" "0" | tr 'mrdoc' '01234' | sed 's/3/o/1' | bc | tr '0123456789ABC' 'gtaio luSnemf'
