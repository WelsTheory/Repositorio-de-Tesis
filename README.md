# Diseño e implementación de un sistema de adquisición digital programable para señales ECG
Repositorio de la tesis "Diseño e implementación de un sistema de adquisición digital programable para señales ECG". Autor: William's Limonchi Sandoval
## Requisitos
Es necesario tener instalado los siguientes programas:
* [Matlab](https://www.mathworks.com/products/matlab.html) - La versión 2014 o superior
* [XC16](https://www.microchip.com/mplab/compilers) - El compilador XC16 para generar el programa del microcontrolador
* [Device Blocks for Simulink](https://www.microchip.com/forums/m878432.aspx) - Herramienta para trabajar con Microchip en Simulink
También es necesario tener la tarjeta de adquisición de la investigación para poder trabajar con el sistema. Los archivos de la tarjeta se encuentran en la carpeta Demo SAQD_ECG/Diseño Hardware_KiCad
### Carpetas del repositorio
* Carpeta de pruebas:
En esta carpeta se encuentran todos los ejemplos realizados antes de obtener el trabajo final
* Demo SAQD_ECG:
En esta carpeta se encuentra el programa principal de la tesis, desde el diseño de hardware de la investigación hasta el programa final con su interfaz gráfica.
* Ejemplos:
En esta carpeta se encuentran diferentes ejemplos que se han unido con el sistema. 
1) Downsamplin, para obtener otro tiempo de muestreos.
2) Filtros butterworth, para saber como trabajan los filtros butterworth con la investigación.
3) Filtros de 1er orden, son filtros sencillos de 1er orden para saber como trabaja la investigación
4) Sistema con tres filtros, es el programa principal con sólo 3 filtros.
5) Sistema con un único filtro, es el programa principal con un único filtro.
Estos programas son ejemplos para modificar el bloque Programable del programa principal. 
* Framework:
En esta carpeta se encuentra una copia del programa principal de la investigación, esto para poder modificar este programa sin necesidad de causar un error en el demo de la investigación.
## Contribución
Para contribuir con la investigación primero se debe hacer un fork al repositorio y seguidamente se puede enviar los cambios o modificaciones al correo: williams.limonchi.sandoval@gmail.com
## Version 
Esta investigación está en la versión 1.0.1 por lo que aún hay detalles que pulir y mejorar.
## Autor
William's Limonchi Sandoval [Twitter](http://twitter.com/welstheory)

