#!/bin/bash

ROOT_DIR=$1
ITER=$2
cd $ROOT_DIR
OUTPUT_FILE="output.txt"

if [ -z "$ITER" ]; then
  # valor por defecto es 5, las veces que se ejecuta cada programa
  ITER=5
fi

memory () {
    command="$1"
    echo "Memoria de la ejecucion: $1" >> "$OUTPUT_FILE"
    # valgrind --tool=massif --massif-out-file=output $command
    # grep mem_heap_B output | sed -e 's/mem_heap_B=\(.*\)/\1/' | sort -g | tail -n 1 >> "$OUTPUT_FILE"
    /usr/bin/time -v $command 2>&1 | grep "Maximum resident set size" >> "$OUTPUT_FILE"
    echo "-----------------------------------" >> "$OUTPUT_FILE"
}

execute () {
    command="$1"
    perf_command="perf stat -e context-switches,cycles,instructions,cache-references,cache-misses,branches,branch-misses"

    echo "Ejecutando $1" >> "$OUTPUT_FILE"
    eval "$perf_command $command" >> "$OUTPUT_FILE" 2>&1
    echo "-----------------------------------" >> "$OUTPUT_FILE"
}

energy () {
    command="$1"
    energy_command="perf stat -e power/energy-pkg/,power/energy-cores/,power/energy-gpu/"

    echo "Consumo de energia $1" >> "$OUTPUT_FILE"
    eval "$energy_command $command" >> "$OUTPUT_FILE" 2>&1
    echo "-----------------------------------" >> "$OUTPUT_FILE"
}

# directorio de bucle

cd $ROOT_DIR/build/analisis_basico/bucle
> "$OUTPUT_FILE"

command_list=(
    "./bucle_c"
    "./bucle_cpp"
    "java -jar bucle_java.jar"
    "python3 bucle.py"
)

for cmd in "${command_list[@]}"; do
    echo "Consumo de memoria $cmd"
    memory "$cmd"
done
for (( i=0; i<ITER; i++ )); do
    for cmd in "${command_list[@]}"; do
        echo "Ejecutando en la iteracion $i: $cmd"
        execute "$cmd"
    done
done
for (( i=0; i<ITER; i++ )); do
    for cmd in "${command_list[@]}"; do
        echo "Energia en la iteracion $i: $cmd"
        energy "$cmd"
    done
done

# directorio de la generacion de numeros aleatorios

cd $ROOT_DIR/build/analisis_basico/aleatorio
> "$OUTPUT_FILE"

command_list=(
    "./aleatorio_c"
    "./aleatorio_cpp"
    "java -jar aleatorio_java.jar"
    "python3 aleatorio.py"
)

for cmd in "${command_list[@]}"; do
    echo "Consumo de memoria $cmd"
    memory "$cmd"
done
for (( i=0; i<ITER; i++ )); do
    for cmd in "${command_list[@]}"; do
        echo "Ejecutando en la iteracion $i: $cmd"
        execute "$cmd"
    done
done
for (( i=0; i<ITER; i++ )); do
    for cmd in "${command_list[@]}"; do
        echo "Energia en la iteracion $i: $cmd"
        energy "$cmd"
    done
done

# directorio del manejo de arrays

cd $ROOT_DIR/build/analisis_basico/array
> "$OUTPUT_FILE"

command_list=(
    "./array_c"
    "./array_cpp"
    "java -jar array_java.jar"
    "python3 array.py"
)

for cmd in "${command_list[@]}"; do
    echo "Consumo de memoria $cmd"
    memory "$cmd"
done
for (( i=0; i<ITER; i++ )); do
    for cmd in "${command_list[@]}"; do
        echo "Ejecutando en la iteracion $i: $cmd"
        execute "$cmd"
    done
done
for (( i=0; i<ITER; i++ )); do
    for cmd in "${command_list[@]}"; do
        echo "Energia en la iteracion $i: $cmd"
        energy "$cmd"
    done
done

# directorio de condicionales
cd $ROOT_DIR/build/analisis_basico/condicionales/
python3 $ROOT_DIR/build/random_gen.py

# if con 3 condiciones

cd $ROOT_DIR/build/analisis_basico/condicionales/if_case_3
> "$OUTPUT_FILE"

command_list=(
    "./if_case_3_c"
    "./if_case_3_cpp"
    "java -jar if_case_3_java.jar"
    "python3 if_case_3.py"
)

for cmd in "${command_list[@]}"; do
    echo "Consumo de memoria $cmd"
    memory "$cmd"
done
for (( i=0; i<ITER; i++ )); do
    for cmd in "${command_list[@]}"; do
        echo "Ejecutando en la iteracion $i: $cmd"
        execute "$cmd"
    done
done
for (( i=0; i<ITER; i++ )); do
    for cmd in "${command_list[@]}"; do
        echo "Energia en la iteracion $i: $cmd"
        energy "$cmd"
    done
done

# if con 10 condiciones

cd $ROOT_DIR/build/analisis_basico/condicionales/if_case_10
> "$OUTPUT_FILE"

command_list=(
    "./if_case_10_c"
    "./if_case_10_cpp"
    "java -jar if_case_10_java.jar"
    "python3 if_case_10.py"
)

for cmd in "${command_list[@]}"; do
    echo "Consumo de memoria $cmd"
    memory "$cmd"
done
for (( i=0; i<ITER; i++ )); do
    for cmd in "${command_list[@]}"; do
        echo "Ejecutando en la iteracion $i: $cmd"
        execute "$cmd"
    done
done
for (( i=0; i<ITER; i++ )); do
    for cmd in "${command_list[@]}"; do
        echo "Energia en la iteracion $i: $cmd"
        energy "$cmd"
    done
done

# if con 1000 condiciones

cd $ROOT_DIR/build/analisis_basico/condicionales/if_case_1000
> "$OUTPUT_FILE"

command_list=(
    "./if_case_1000_c"
    "./if_case_1000_cpp"
    "java -jar if_case_1000_java.jar"
    "python3 if_case_1000.py"
)

for cmd in "${command_list[@]}"; do
    echo "Consumo de memoria $cmd"
    memory "$cmd"
done
for (( i=0; i<ITER; i++ )); do
    for cmd in "${command_list[@]}"; do
        echo "Ejecutando en la iteracion $i: $cmd"
        execute "$cmd"
    done
done
for (( i=0; i<ITER; i++ )); do
    for cmd in "${command_list[@]}"; do
        echo "Energia en la iteracion $i: $cmd"
        energy "$cmd"
    done
done

# switch con 3 condiciones

cd $ROOT_DIR/build/analisis_basico/condicionales/switch_case_3
> "$OUTPUT_FILE"

command_list=(
    "./switch_case_3_c"
    "./switch_case_3_cpp"
    "java -jar switch_case_3_java.jar"
    "python3 switch_case_3.py"
)

for cmd in "${command_list[@]}"; do
    echo "Consumo de memoria $cmd"
    memory "$cmd"
done
for (( i=0; i<ITER; i++ )); do
    for cmd in "${command_list[@]}"; do
        echo "Ejecutando en la iteracion $i: $cmd"
        execute "$cmd"
    done
done
for (( i=0; i<ITER; i++ )); do
    for cmd in "${command_list[@]}"; do
        echo "Energia en la iteracion $i: $cmd"
        energy "$cmd"
    done
done

# switch con 10 condiciones

cd $ROOT_DIR/build/analisis_basico/condicionales/switch_case_10
> "$OUTPUT_FILE"

command_list=(
    "./switch_case_10_c"
    "./switch_case_10_cpp"
    "java -jar switch_case_10_java.jar"
    "python3 switch_case_10.py"
)

for cmd in "${command_list[@]}"; do
    echo "Consumo de memoria $cmd"
    memory "$cmd"
done
for (( i=0; i<ITER; i++ )); do
    for cmd in "${command_list[@]}"; do
        echo "Ejecutando en la iteracion $i: $cmd"
        execute "$cmd"
    done
done
for (( i=0; i<ITER; i++ )); do
    for cmd in "${command_list[@]}"; do
        echo "Energia en la iteracion $i: $cmd"
        energy "$cmd"
    done
done

# switch con 1000 condiciones

cd $ROOT_DIR/build/analisis_basico/condicionales/switch_case_1000
> "$OUTPUT_FILE"

command_list=(
    "./switch_case_1000_c"
    "./switch_case_1000_cpp"
    "java -jar switch_case_1000_java.jar"
    "python3 switch_case_1000.py"
)

for cmd in "${command_list[@]}"; do
    echo "Consumo de memoria $cmd"
    memory "$cmd"
done
for (( i=0; i<ITER; i++ )); do
    for cmd in "${command_list[@]}"; do
        echo "Ejecutando en la iteracion $i: $cmd"
        execute "$cmd"
    done
done
for (( i=0; i<ITER; i++ )); do
    for cmd in "${command_list[@]}"; do
        echo "Energia en la iteracion $i: $cmd"
        energy "$cmd"
    done
done