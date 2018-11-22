#!/bin/bash

workpath="/tmp/wordlist"
outfile="wordlist.txt"
tmpout="tmpout.txt"
powerpath="/opt/powerpend"

mkdir $workpath

$powerpath/powerpend $1 $2 >> $workpath/$outfile
cat $workpath/$outfile >> $workpath/$tmpout
$powerpath/powerpend $workpath/$outfile $1 >> $workpath/$outfile
$powerpath/powerpend $workpath/$tmpout $2 >> $workpath/$outfile
rm $workpath/$tmpout

echo "Word list is located at $workpath$outfile"
