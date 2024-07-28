#!/bin/bash

ROOT_DIR=$1
ITER=$2
cd $ROOT_DIR
OUTPUT_FILE="output.txt"

if [ -z "$ITER" ]; then
  # valor por defecto, las veces que se ejecuta cada programa
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

# directorio de fibonacci

cd $ROOT_DIR/build/algoritmos/fibonacci
> "$OUTPUT_FILE"

command_list=(
    "./fibo_c"
    "./fibo_cpp"
    "java -jar fibo_java.jar"
    "python3 fibo.py"
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

# directorio de los algorithmos de ordenamiento
for (( i=0; i<ITER; i++ )); do

    # genera lista de numeros aleatorios
    cd $ROOT_DIR/build/algoritmos/orden
    python3 $ROOT_DIR/build/random_gen.py

    # directorio de las funciones existentes
    cd $ROOT_DIR/build/algoritmos/orden/fun_existente

    command_list=(
        "./orden_c"
        "./orden_cpp"
        "java -jar orden_java.jar"
        "python3 orden.py"
    )

    # consumo de memoria
    if [ $i -eq 0 ]; then
        > "$OUTPUT_FILE"
        for cmd in "${command_list[@]}"; do
            echo "Consumo de memoria $cmd"
            memory "$cmd"
        done
    fi

    # performance
    for cmd in "${command_list[@]}"; do
        echo "Ejecutando en la iteracion $i: $cmd"
        execute "$cmd"
    done

    # energia
    for cmd in "${command_list[@]}"; do
        echo "Energia en la iteracion $i: $cmd"
        energy "$cmd"
    done

    # directorio de quicksort
    cd $ROOT_DIR/build/algoritmos/orden/quicksort

    command_list=(
        "./quicksort_c"
        "./quicksort_cpp"
        "java -jar quicksort_java.jar"
        "python3 quicksort.py"
    )

    # consumo de memoria
    if [ $i -eq 0 ]; then
        > "$OUTPUT_FILE"
        for cmd in "${command_list[@]}"; do
            echo "Consumo de memoria $cmd"
            memory "$cmd"
        done
    fi

    # performance
    for cmd in "${command_list[@]}"; do
        echo "Ejecutando en la iteracion $i: $cmd"
        execute "$cmd"
    done

    # energia
    for cmd in "${command_list[@]}"; do
        echo "Energia en la iteracion $i: $cmd"
        energy "$cmd"
    done

    # directorio timsort
    cd $ROOT_DIR/build/algoritmos/orden/timsort

    command_list=(
        "./timsort_c"
        "./timsort_cpp"
        "java -jar timsort_java.jar"
        "python3 timsort.py"
    )

    # consumo de memoria
    if [ $i -eq 0 ]; then
        > "$OUTPUT_FILE"
        for cmd in "${command_list[@]}"; do
            echo "Consumo de memoria $cmd"
            memory "$cmd"
        done
    fi

    # performance
    for cmd in "${command_list[@]}"; do
        echo "Ejecutando en la iteracion $i: $cmd"
        execute "$cmd"
    done

    # energia
    for cmd in "${command_list[@]}"; do
        echo "Energia en la iteracion $i: $cmd"
        energy "$cmd"
    done

done

# directorio de busqueda
cd $ROOT_DIR/build/algoritmos/busqueda
> "$OUTPUT_FILE"

command_list=(
    "./bfs_c"
    "./bfs_cpp"
    "java -jar bfs_java.jar"
    "python3 bfs.py"
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
