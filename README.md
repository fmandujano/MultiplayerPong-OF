# Proyecto de Juego Cliente-Servidor con UDP en OpenFrameworks

    Este proyecto demuestra la implementación de la arquitectura Cliente-Servidor utilizando el protocolo UDP en un entorno 2D desarrollado con OpenFrameworks. El juego se comunica mediante el uso de ofxUDPManager, una biblioteca de OpenFrameworks.

    El servidor es el jugador 1 que controla al círculo rojo mientras que el cliente es el jugador 2, controlando al cuadrado amarillo. Los jugadores se pueden desplazar en el eje X y Y.

## Requisitos

    OpenFrameworks 0.11.2 o superior.
    Conexión a la red para probar la interacción cliente-servidor entre diferentes máquinas.
    Conocimientos básicos de redes y OpenFrameworks.

## Instalación

    1. Descargar [openFrameworks](https://openframeworks.cc/download/) y descomprimirlo en algún directorio.
    2. Clonar (o descomprimir) este repositorio en el **directorio myApps** de OpenFrameworks
    3. Compilar y probar.

## Errores posibles

    Si no hay conectividad, revisar que el firewall permita el uso del puerto UDP 6666.
    La solución está configurada con vcpkg desactivado, ya que openframeworks incluye sus propias bibliotecas y pueden crear conflictos al linkear.

## Licencia

    Este proyecto está licenciado bajo la MIT License.




