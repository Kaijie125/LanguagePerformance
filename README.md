# LanguagePerformance
## Contenido del repositorio

En este repositorio contiene el material usado para medir y obtener los resultados. Donde se encuantran:

Programas de apoyo como my_cat.py para ver el formato de las imagenes generadas o random_gen.py que genera numeros y los almacena en un binario para diversas pruebas.

En el directorio analisis_basico se encuentran las pruebas:
- bucle
- generacion de numeros pseudo aleatorios
- array
- condicionales/estructuras de control de flujo

En el directorio algoritmo se encuentran las pruebas:
- fibonacci
- algoritmos de ordenacion: con funciones existentes, e implementaciones del quicksort y timsort
- algoritmo de busqueda en amplitud

En el directorio img_bmp se encuentran las pruebas:
- aritmetica, donde se genera imagenes con operaciones aritmeticas sencillas
- mandel, donde se genera una imagen del conjunto de Mandelbrot

En el directorio scripts se encuentran:
- dependencias.sh, que comprueba los requisitos necesarios para ejecutar
- basico.sh, que ejecuta las prubas del directorio analisis_basico
- algoritmos.sh, que ejeuta las pruebas del directorio algoritmos
- img.sh, que ejecuta las prubas del directorio img_bmp

script.sh, ejecuta los scripts del directorio anterior
resultados.ipynb, muestra los resultados obtenidos tras la ejecución de script.sh


## Ejecución de las pruebas

Para comenzar la ejecucion de las prubas del repositorio, sigue estos pasos:

1. Clona el repositorio en tu máquina local:

```bash
git clone https://github.com/Kaijie125/LanguagePerformance.git
```

2. Cambia al directorio del proyecto:

```bash
cd LanguagePerformance
```

3. Genera el directorio de las pruebas:

```bash
mkdir build
cd build
cmake ..
cmake --build .
cd ..
```

4. Ejecucion de las pruebas:

```bash
./script.sh
```

5. Una vez finalizado la ejecucion se puede usar el fichero resultados.ipynb para actualizar y visualizar los nuevos resultados obtenidos:

## Posibles fallos

Si los ficheros sh no tiene permisos:
```bash
chmod +x nombre.sh 
```

Si no se tiene instalado las herramientas, programas, librerias... Se tendran que instalarlas:
```bash
sudo apt update
sudo apt install ...
pip install ...
...
```

Si perf no tiene permisos:
```bash
echo 0 | sudo tee /proc/sys/kernel/perf_event_paranoid
```
