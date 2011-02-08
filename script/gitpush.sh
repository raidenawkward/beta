#!/bin/bash
# script	: gitpush.sh
# discript	: push project to git hub
# author	: raiden
# date		: 2011-02-08
# version	: 0.1.0
#
git fetch origin
git rebase origin/master

git push origin master
