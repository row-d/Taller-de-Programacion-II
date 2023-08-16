#!/bin/bash
folder=$(date +'%d-%m-%Y')
cp -R "./template" $folder
cd $folder