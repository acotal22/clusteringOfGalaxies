./primero $1 
./DBSCAN -eps $2 -minpts $3 -o clusters.txt archivo.txt >>cout.txt
./filesread
./ultimo $1
