#!/bin/bash

name=$1;

mkdir $name;
cp template.cpp $name/$name.cpp;
touch $name/input.txt;