#!/bin/bash
# script	: addclass.sh
# discript	: add new class for project
# author	: raiden
# date		: 2010-08-21
# version	: 1.1.0
#

CLASS_AUTHOR="Raiden"
CLASS_NAME=$1
CLASS_ORIGIN_VERSION="0.1.0"
PROJECT_NAME="beta"
PROJECT_TYPE="qmake"
SRC_DIR="src"
INC_DIR="include"
AUTO_MAKE_TOOL="qmake"

if [ -z $1 ];
then
#script usage:
echo usage : addclass.sh [classname] [projectname] ["description"]
exit 0
fi

echo "create new class $CLASS_NAME ? (y/n)"
echo "attention: any file with a similar name will be covered"
read CHOICE
case $CHOICE in
y|Y|YES|Yes|yes)
	echo now begin;;
n|N|No|NO|no)
	echo canceled
	exit 0;;
*)
	echo invalid selection
	exit 0;;
esac

if [  $2 ];
then
PROJECT_NAME="$2"
fi

CLASS_DISCRIPTION=$3

CLASS_CONTENT="/*
 * class        : $CLASS_NAME
 * description  : $CLASS_DISCRIPTION
 * author       : $CLASS_AUTHOR
 * date         : `date +%Y-%m-%d`
 * version      : $CLASS_ORIGIN_VERSION
 */"

echo running script addclass.sh

HEADER=`echo "$CLASS_NAME.h" | tr "A-Z" "a-z" `
SOURCE=`echo "$CLASS_NAME.cpp" | tr "A-Z" "a-z"`

echo creating header file : $HEADER
echo creating source file : $SOURCE

if [ -f $INC_DIR/$HEADER ];
then
echo class file $HEADER exists
exit 0
fi

if [ -f $SRC_DIR/$SOURCE ];
then
echo class file $SOURCE exists
exit 0
fi

touch $INC_DIR/$HEADER
touch $SRC_DIR/$SOURCE
sync
echo done

echo writting contents into class file ..
echo "$CLASS_CONTENT" > $INC_DIR/$HEADER
echo "#include \"../$INC_DIR/$HEADER\"" > $SRC_DIR/$SOURCE
echo done
sync


#function write project infomation into .pro file
function writeIntoProFile()
{
  echo "qmake project"
  echo "writting new class info into project file"
  if [ -f "$PROJECT_NAME.pro" ];
  then
	touch .projectTmp
	echo "		$INC_DIR/$HEADER  \\" > .projectTmp
	sed -i '/HEADERS +=/ { 
	r .projectTmp
	}' $PROJECT_NAME.pro
	
	echo "		$SRC_DIR/$SOURCE \\" > .projectTmp
	sed -i '/SOURCES +=/ { 
        r .projectTmp
        }' $PROJECT_NAME.pro
	
	rm -rf .projectTmp
	sync
  else
	echo .pro file not exists
  fi
  echo done
}

if [ $PROJECT_TYPE = "qmake" ];
then
writeIntoProFile
fi

#rebuild the project
echo "rebuild the project?(y/n)"
read CHOICE
case $CHOICE in
Y|y|Yes|yes|YES)
	echo now rebuild the project
	make clean
	rm ./Makefile -rf
	$AUTO_MAKE_TOOL
	make
	echo done;;
N|n|No|no|NO)
	echo do not rebuild the project;;
*)
	echo ... invalid selection;;
esac

echo all done
exit 1
