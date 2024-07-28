#!/bin/bash

if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    echo "El sistema operativo es Linux."
else
    echo "Este script está diseñado para ejecutarse en Linux. Sistema operativo actual: $OSTYPE"
    exit 1
fi

echo
if type -p java >/dev/null; then
    echo "Java está instalado"
    java -version
else
    echo "Java no está instalado, saliendo"
    exit 1
fi

echo
if type -p javac >/dev/null; then
    echo "javac está instalado"
    javac -version
else
    echo "javac (Java Compiler) no está instalado, saliendo"
    exit 1
fi

echo
python_version=$(python3 --version 2>&1 | awk '{print $2}')
if [[ $(python3 --version 2>&1 | awk '{print $2}' | cut -d '.' -f1) -ge 3 && $(python3 --version 2>&1 | awk '{print $2}' | cut -d '.' -f2) -ge 10 ]]; then
    echo "Python $python_version está instalado"
else
    echo "Python 3.10 o superior no está instalado, saliendo"
    exit 1
fi

echo
if type -p gcc >/dev/null; then
    echo "GCC está instalado"
    gcc --version | head -n1
else
    echo "GCC no está instalado, saliendo"
    exit 1
fi

echo
if type -p g++ >/dev/null; then
    echo "G++ está instalado"
    g++ --version | head -n1
else
    echo "G++ no está instalado, saliendo"
    exit 1
fi

echo
if type -p nvcc >/dev/null; then
    echo "nvcc está instalado"
    nvcc --version | grep release
else
    echo "nvcc (NVIDIA CUDA Compiler) no está instalado, saliendo"
    exit 1
fi

echo
if pip show pycuda >/dev/null 2>&1; then
    echo "pycuda está instalado"
    pip show pycuda | grep Version
else
    echo "pycuda no está instalado, saliendo"
    exit 1
fi

echo
if pip show pandas >/dev/null 2>&1; then
    echo "pandas está instalado"
    pip show pandas | grep Version
else
    echo "pandas no está instalado, saliendo"
    exit 1
fi

echo
if pip show matplotlib >/dev/null 2>&1; then
    echo "matplotlib está instalado"
    pip show matplotlib | grep Version
else
    echo "matplotlib no está instalado, saliendo"
    exit 1
fi

echo
if pip show numpy >/dev/null 2>&1; then
    numpy_version=$(pip show numpy | grep Version | awk '{print $2}' | head -n1)
    echo "numpy está instalado: $numpy_version"

else
    echo "numpy no está instalado, saliendo"
    exit 1
fi

exit 0
