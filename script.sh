#!/bin/bash
echo "Hora de inicio: $(date +"%T")"


ROOT_DIR=$(dirname "$(realpath "$0")")
cd $ROOT_DIR

./scripts/dependencias.sh
if [ $? -eq 0 ]; then
    echo "El script de verificacion se ejecuto correctamente."
else
    echo "Error: El script de verificacion encontro problemas."
    exit 1
fi


./scripts/basico.sh $ROOT_DIR 1
./scripts/algoritmos.sh $ROOT_DIR 1
./scripts/img.sh $ROOT_DIR 1

if [ "$1" == "delete" ]; then
    echo "Borrando build..."
    rm -rf build
fi

echo "Hora de finalizacion: $(date +"%T")"