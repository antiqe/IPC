#!/bin/bash
## launcher.sh for lemipc in /home/leprov_a//project/tek2/lemipc/rendu
## 
## Made by alexis leprovost
## Login   <leprov_a@epitech.net>
## 
## Started on  Fri Mar 29 20:45:14 2013 alexis leprovost
## Last update Sun Mar 31 20:29:26 2013 ronan guiho
##

i=0
path=$1
name=$2
count=$3

if [ -f $path ] || [ -f $name ] || [ -f $count ]; then
    echo "Usage: ./launcher.sh pathname teamname teamsize"
else
    while (($i < $count)); do
	./lemipc $path $name&
	i=$(expr $i + 1)
	usleep 100000
	echo "Creating player $i"
    done
fi