#!/bin/bash
# script	: addscript.sh
# discript	: used for new script added
# author	: raiden
# date		: 2011-02-08
# version	: 0.1.0
#

CURRENT_DIR=`pwd`
EDITOR=vim
SCRIPT_DIR=script
SCRIPT_NAME=""
TEMPLATE=$CURRENT_DIR"/template/script"

if [ -z $1 ];
then
	echo script name should not be null
	exit;
fi

SCRIPT_NAME=$1

SCRIPT=$CURRENT_DIR/$SCRIPT_DIR/$SCRIPT_NAME
if [ ! -d $CURRENT_DIR/$SCRIPT_DIR ];
then
	mkdir $CURRENT_DIR/$SCRIPT_DIR -p
fi

cp $TEMPLATE $SCRIPT
$EDITOR $SCRIPT
echo done
