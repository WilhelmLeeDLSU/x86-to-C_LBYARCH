nasm -f win64 asmdistance.asm -o asmdistance.obj
gcc -c cdistance.c -o cdistance.obj -m64
gcc cdistance.obj asmdistance.obj -o distance.exe -m64
distance.exe