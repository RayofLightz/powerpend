#!/bin/bash
powerpend_path="/opt/powerpend"
work_dir="/tmp/doubleup"
out_file="out.txt"
mkdir $work_dir
$powerpend_path/powerpend $1 $2 >> $work_dir/$out_file
$powerpend_path/powerpend $2 $1 >> $work_dir/$out_file
echo "wordlist in $work_dir/$out_file"


