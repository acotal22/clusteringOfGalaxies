# Clustering of Galaxies

En base al algoritmo DBScan 2020 del autor Yiqiu Wang https://github.com/wangyiqiu/dbscan, se procesan las imágenes para encontrar clusters en imagenes de galaxias previamente procesadas (eliminación de ruido y bordes sin información).

En este repositorio se podrán encontrar 8 imágenes de ejemplo en la carpeta /main/Data para las pruebas de la aplicación.

## Paso 1: Instalación de requerimientos.
1. Instalación de "ImageMagick" https://imagemagick.org/index.php 
2. Instalación de DBSCan 2020 https://github.com/wangyiqiu/dbscan/tree/master/code, siguiendo los pasos del github (SIN JeMalloc), luego reemplazar el archivo compilado "DBSCAN" ubicado en la carpeta "main" por el nuevo archivo ejecutable "DBSCAN".
3. Contar con la libreria libX11.
4. Instalar OpenCV, en el caso nuestro nos resultó instalar como en el siguiente link http://techawarey.com/programming/install-opencv-c-c-in-ubuntu-18-04-lts-step-by-step-guide/ .

## Paso 2: Como compilar.

Para compilar se puede utilizar el script ubicado en /main llamado "compilar.sh".

## Paso 3: Ejecutar.

Se puede ejecutar simplemente con ./ejecutable desde la consola.

## Paso 4: Uso de interfaz. 

La primera pantalla muestra la configuración para el algoritmo Dbscan, donde se puede escoger 1 de las 8 imágenes disponibles en la carpeta /main/data (si se desea utilizar otra imagen hay que reemplazarlas en la carpeta data, manteniendo los nombres y formato , por ej "1.tiff"). Para seleccionar una imagen desde la interfaz, primero hay que desmarcar la que esté marcada y luego marcar la imagen que se desea. Luego de tener los parámetros definidos y la imagen seleccionada se puede presionar el boton "start", donde lo llevará a la otra pantalla con los resultados.

![Captura_de_pantalla_de_2022-12-15_23-00-52](https://user-images.githubusercontent.com/89815275/208330932-98c1d6b1-83c5-4e01-b617-563283bc5516.png)

En esta pantalla se puede observar los clusters encontrados pintados según el id correspondiente de cada clusters. Además se puede ver información sobre los puntos y cantidad de clusters encontrados.

Para ejecutar con otra imagen se debe cerrar el programa (presionando la tecla "esc") y luego volver a ejecutarlo. 

![Captura_de_pantalla_de_2022-12-15_23-01-02](https://user-images.githubusercontent.com/89815275/208331009-54539492-b540-43a8-9964-ff0ecf3be242.png)
