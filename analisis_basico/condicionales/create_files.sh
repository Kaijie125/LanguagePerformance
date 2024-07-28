#!/bin/bash

cd if_case_1000
python3 ../conditional_gen.py if c 1000
python3 ../conditional_gen.py if cpp 1000
python3 ../conditional_gen.py if java 1000
python3 ../conditional_gen.py if python 1000

cd ..
cd switch_case_1000
python3 ../conditional_gen.py switch c 1000
python3 ../conditional_gen.py switch cpp 1000
python3 ../conditional_gen.py switch java 1000
python3 ../conditional_gen.py switch python 1000

cd ..
cd if_case_10
python3 ../conditional_gen.py if c 10
python3 ../conditional_gen.py if cpp 10
python3 ../conditional_gen.py if java 10
python3 ../conditional_gen.py if python 10

cd ..
cd switch_case_10
python3 ../conditional_gen.py switch c 10
python3 ../conditional_gen.py switch cpp 10
python3 ../conditional_gen.py switch java 10
python3 ../conditional_gen.py switch python 10

cd ..
cd if_case_3
python3 ../conditional_gen.py if c 3
python3 ../conditional_gen.py if cpp 3
python3 ../conditional_gen.py if java 3
python3 ../conditional_gen.py if python 3

cd ..
cd switch_case_3
python3 ../conditional_gen.py switch c 3
python3 ../conditional_gen.py switch cpp 3
python3 ../conditional_gen.py switch java 3
python3 ../conditional_gen.py switch python 3