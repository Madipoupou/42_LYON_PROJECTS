#!/bin/bash

usage='usage: ./manage.sh [ start | stop | log ]'

if [ $# -ne 1 ]
then
	echo $usage
else
	if [ $1 = 'start' ]
	then
		docker-compose up >> log.txt 2>&1 &
	elif [ $1 = 'stop' ]
	then
		docker-compose down
	elif [ $1 = 'log' ]
	then
		if [ -f 'log.txt' ]
		then
			tail log.txt
		fi
	else
		echo $usage
	fi
fi
