# SNADOS

Proyecto final sobre juego Snados en ANSI C que se ejecuta en consola.

El juego consiste en una serpiente que avanza permanentemente en el laberinto en la dirección en la que se encuentre su cabeza. El jugador controla la dirección en la que avanza la serpiente mediante el ingreso de una de las cuatro flechas del teclado. Su objetivo es lograr que la serpiente crezca lo más que se pueda al comerse la mayor cantidad de comidas que se encuentren dentro del laberinto, evitando que la serpiente se estrelle con las paredes o con su mismo cuerpo.

Su implementación consiste en una máquina de estados que cuenta con instancias concurrentes de la serpiente. Para esto se aplica encapsulamiento al objeto de la serpiente para generar varias máquinas de estado concurrentes que permitan el juego simultáneo de varios jugadores que tengan asignadas diferentes teclas cada uno.

Trabajo presentado para el ingeniero Juan Carlos Giraldo, en la clase de Software para Procesadores, Pontificia Universidad Javeriana 2020.

Contribuidores: ChaparroMP, Valentina Hidalgo y Karen Vargas

Comando para ejecutar el proyecto desde consola:
´gcc snados.c food.c -o snados.exe´
