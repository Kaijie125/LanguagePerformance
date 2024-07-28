import sys
global n_conditions

try:
    n_conditions = sys.argv[3]
except:
    print("Invalid argument, must [if, switch] [c, cpp, java, python] [n_conditions]")
    sys.exit()

c_pre_code = """
#include <stdio.h>
#include <stdlib.h>
int readRandomBin(int **array_int, int *num){
    FILE *file = fopen("../random_list.bin", "rb");
    if (file == NULL) {
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    *num = file_size / sizeof(int);
    *array_int = (int *)malloc(*num * sizeof(int));

    fread(*array_int, sizeof(int), *num, file);

    fclose(file);
    return 0;
}

int main() {
    int *array_int;
    int num;

    if (readRandomBin(&array_int, &num) != 0){
        printf("Error reading file");
        return 1;
    }

    for (int i = 0; i < num; i++){
"""

c_post_code = """
    }
    free(array_int);
    return 0;
}
"""

cpp_pre_code = """
#include <iostream>
#include <fstream>
int readRandomBin(int *&array_int, int &num){
    std::ifstream file("../random_list.bin", std::ios::binary);
    if (!file) {
        return 1;
    }

    file.seekg(0, std::ios::end);
    long file_size = file.tellg();
    file.seekg(0, std::ios::beg);

    num = file_size / sizeof(int);
    array_int = new int[num];

    file.read(reinterpret_cast<char*>(array_int), file_size);

    file.close();
    return 0;
}

int main() {
    
    int num;
    int *array_int;

    if (readRandomBin(array_int, num) != 0) {
        std::cerr << "Error al abrir" << std::endl;
        return 1;
    }

    for (int i = 0; i < num; i++){
"""

cpp_post_code = """
    }
    delete[] array_int;
    return 0;
}
"""

java_imports = """
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
"""
java_if_else = """
public class if_case_""" + n_conditions + """{
"""

java_switch = """
public class switch_case_""" + n_conditions + """{
"""
java_pre_code = """
    static int[] readRandomBin() {
        try (DataInputStream file = new DataInputStream(new FileInputStream("../random_list.bin"))) {

            long fileSize = file.available();
            int num = (int) (fileSize / Integer.BYTES);

            int[] array_int = new int[num];

            // lee el archivo binario en formato bytes
            byte[] array_byte = new byte[(int) fileSize];
            file.read(array_byte);

            // convierte al orden de bytes nativo
            ByteBuffer buffer = ByteBuffer.wrap(array_byte);
            buffer.order(ByteOrder.nativeOrder());

            for (int i = 0; i < num; ++i) {
                array_int[i] = buffer.getInt();
            }

            return array_int;
            
        } catch (IOException e) {
            System.err.println("Error al leer el archivo binario: " + e.getMessage());
            return null;
        }
    }

    public static void main(String[] args) {
        int[] arr = readRandomBin();
        int n = arr.length;

        for (int i = 0; i < n; i++) {
"""

java_post_code = """
        }
    }
}
"""

python_pre_code = """
def readRandomBin():
    try:
        with open("../random_list.bin", "rb") as file:
            array_bytes = file.read()
    except:
        print("Error al abrir")
        exit(1)

    num = len(array_bytes) // 4
    array_int = [int.from_bytes(array_bytes[i:i+4], byteorder='little') for i in range(0, len(array_bytes), 4)]

    return num, array_int

if __name__ == "__main__":
    num, array_int = readRandomBin()

    for i in range(num):
"""


def generateIf():
    if sys.argv[2] == "c":
        with open("if_case_" + n_conditions + ".c", "w") as f:
            f.write(c_pre_code)
            f.write(f"        int value = array_int[i] % {n_conditions};\n")
            for i in range(int(n_conditions)):
                if i == 0:
                    f.write("        if (value == 0) {\n        }")
                else:
                    f.write(" else if (value == %d) {\n        }" % i)
            f.write(c_post_code)
    
    elif sys.argv[2] == "cpp":
        with open("if_case_" + n_conditions + ".cpp", "w") as f:
            f.write(cpp_pre_code)
            f.write(f"        int value = array_int[i] % {n_conditions};\n")
            for i in range(int(n_conditions)):
                if i == 0:
                    f.write("        if (value == 0) {\n        }")
                else:
                    f.write(" else if (value == %d) {\n        }" % i)
            f.write(cpp_post_code)
    
    elif sys.argv[2] == "java":
        with open("if_case_" + n_conditions + ".java", "w") as f:
            f.write(java_imports)
            f.write(java_if_else)
            f.write(java_pre_code)
            f.write(f"        int value = arr[i] % {n_conditions};\n")
            for i in range(int(n_conditions)):
                if i == 0:
                    f.write("            if (value == 0) {\n         }")
                else:
                    f.write(" else if (value == %d) {\n         }" % i)
            f.write(java_post_code)

    elif sys.argv[2] == "python":
        with open("if_case_" + n_conditions + ".py", "w") as f:
            f.write(python_pre_code)
            f.write(f"        value = array_int[i] % {n_conditions}\n")
            for i in range(int(n_conditions)):
                if i == 0:
                    f.write("        if value == 0:\n            pass\n")
                else:
                    f.write(f"        elif value == {i}:\n            pass\n")

    else:
        print("Invalid argument")
        sys.exit()               


def generateSwitch():
    if sys.argv[2] == "c":
        with open("switch_case_" + n_conditions + ".c", "w") as f:
            f.write(c_pre_code)
            f.write(f"        int value = array_int[i] % {n_conditions};\n")
            
            f.write("        switch (value) {\n")
            for i in range(int(n_conditions)):
                if i == 0:
                    f.write("            case 0:\n                break;\n")
                else:
                    f.write(f"            case {i}:\n                break;\n")
            f.write("            default:\n                break;\n")
            f.write("        }\n")
            f.write(c_post_code)
    
    elif sys.argv[2] == "cpp":
        with open("switch_case_" + n_conditions + ".cpp", "w") as f:
            f.write(cpp_pre_code)
            f.write(f"        int value = array_int[i] % {n_conditions};\n")
            
            f.write("        switch (value) {\n")
            for i in range(int(n_conditions)):
                if i == 0:
                    f.write("            case 0:\n                break;\n")
                else:
                    f.write(f"            case {i}:\n                break;\n")
            f.write("            default:\n                break;\n")
            f.write("        }\n")
            f.write(cpp_post_code)
    
    elif sys.argv[2] == "java":
        with open("switch_case_" + n_conditions + ".java", "w") as f:
            f.write(java_imports)
            f.write(java_switch)
            f.write(java_pre_code)
            f.write(f"        int value = arr[i] % {n_conditions};\n")
            
            f.write("            switch (value) {\n")
            for i in range(int(n_conditions)):
                if i == 0:
                    f.write("               case 0:\n                   break;\n")
                else:
                    f.write(f"              case {i}:\n                    break;\n")
            f.write("               default:\n                    break;\n")
            f.write("            }\n")
            f.write(java_post_code)

    elif sys.argv[2] == "python":
        with open("switch_case_" + n_conditions + ".py", "w") as f:
            f.write(python_pre_code)
            
            f.write(f"        value = array_int[i] % {n_conditions}\n")
            f.write("        match value:\n")
            for i in range(int(n_conditions)):
                if i == 0:
                    f.write("            case 0:\n                pass\n")
                else:
                    f.write(f"            case {i}:\n                pass\n")
            f.write("            case _:\n                pass\n")

    else:
        print("Invalid argument")
        sys.exit() 


if __name__ == "__main__":

    if sys.argv[1] == "if":
        generateIf()
    elif sys.argv[1] == "switch":
        generateSwitch()
    else:
        print("Invalid argument, must [if, switch] [c, cpp, java, python] [n_conditions]")
        sys.exit()
