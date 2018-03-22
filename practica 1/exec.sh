# $1 - archivo a ejecutar
# $2 - nombre del archivo a compilar
# [$3] - librerias

# gcc -Wall $1 -o $2 $3
gcc -Wall $1 -o $2 
./$2 $3
