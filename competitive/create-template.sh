#!/bin/bash
function echolor(){
    local YELLOW='\033[1;33m'
    local NC='\033[0m'
    echo -e "${YELLOW}$1${NC}"
}
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
TEMPLATE="$SCRIPT_DIR/template"
NOW=$(date +"%d-%m-%Y")

echolor "Ingresa el nombre del problema."
read PROBLEM_FOLDER

if test ! -z $PROBLEM_FOLDER
then
    mkdir -p "$SCRIPT_DIR/$NOW"
    cp -R $TEMPLATE "$SCRIPT_DIR/$NOW/$PROBLEM_FOLDER"
    echolor "$SCRIPT_DIR/$NOW/$PROBLEM_FOLDER"
fi