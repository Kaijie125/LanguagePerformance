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

# directorio de imagen usando almacenamiento de los pixeles en memoria

cd $ROOT_DIR/build/img_bmp/aritmetica/aritmetica_con_buffer
> "$OUTPUT_FILE"

command_list=(
    "./aritmetica_buffer_c"
    "./aritmetica_buffer_cpp"
    "java -jar aritmetica_buffer_java.jar"
    "python3 aritmetica_buffer.py"
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

rm *.bmp

# directorio de imagen sin usar almacenamiento de los pixeles en memoria

cd $ROOT_DIR/build/img_bmp/aritmetica/aritmetica_sin_buffer
> "$OUTPUT_FILE"

command_list=(
    "./aritmetica_c"
    "./aritmetica_cpp"
    "java -jar aritmetica_java.jar"
    "python3 aritmetica.py"
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

rm *.bmp

# directorio de imagen usando hilos y almacenamiento de los pixeles en memoria

cd $ROOT_DIR/build/img_bmp/aritmetica/aritmetica_hilos_buffer
> "$OUTPUT_FILE"

command_list=(
    "./aritmetica_hilos_c"
    "./aritmetica_hilos_cpp"
    "java -jar aritmetica_hilos_java.jar"
    "python3 aritmetica_hilos.py"
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

rm *.bmp


cd $ROOT_DIR/build/img_bmp/mandel/mandel_simple
> "$OUTPUT_FILE"

command_list=(
    "./mandel_c"
    "./mandel_cpp"
    "java -jar mandel_java.jar"
    "python3 mandel.py"
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

rm *.bmp

# directorio de imagen mandelbrot usando hilos

cd $ROOT_DIR/build/img_bmp/mandel/mandel_hilos
> "$OUTPUT_FILE"

command_list=(
    "./mandel_hilos_c"
    "./mandel_hilos_cpp"
    "java -jar mandel_hilos_java.jar"
    "python3 mandel_hilos.py"
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

rm *.bmp

# directorio de imagen mandelbrot usando cuda

cd $ROOT_DIR/build/img_bmp/mandel/mandel_cuda
> "$OUTPUT_FILE"
export LD_LIBRARY_PATH=.

command_list=(
    "./mandel_cuda_c"
    "./mandel_cuda_cpp"
    "java -jar mandel_cuda_java.jar"
    "python3 mandel_cuda.py"
)

for cmd in "${command_list[@]}"; do
    echo "Consumo de memoria $cmd"
    memory "$cmd"
done
for (( i=0; i<5; i++ )); do
    for cmd in "${command_list[@]}"; do
        echo "Ejecutando en la iteracion $i: $cmd"
        execute "$cmd"
    done
done
for (( i=0; i<5; i++ )); do
    for cmd in "${command_list[@]}"; do
        echo "Energia en la iteracion $i: $cmd"
        energy "$cmd"
    done
done

rm *.bmp
