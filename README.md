# So_Long
## Descripción
 Este proyecto es un pequeño juego en 2D. Está diseñado para hacerte
trabajar con texturas y sprites y algunos otros elementos básicos de jugabilidad

## Funciones autorizadas
• open, close, read, write,
malloc, free, perror,
strerror, exit
• Todas las funciones de la
librería math flag del
compilador -lm, man 3 math
• Todas las funciones de la
miniLibX
• ft_printf y cualquier función
equivalente que tú hayas
escrito

## Juego
* Primer argumento: archivo con la descripción del mapa de extensión `.ber`
* Objetivo: recolectar todos los objetos presentes en el mapa y salir eligiendo la ruta más corta posible
* `W A S D` moverse en 4 direcciones
* Colisión con paredes
* Contador de movimientos en terminal

## Gestión de gráficos
* El programa mostrará la imagen en una ventana.
* Gestión de ventana limpia (cambiar de ventana, minimizar, etc)
* Pulsar la tecla ESC debe cerrar la ventana y cerrar el programa limpiamente.
* Hacer clic en la cruz roja de la ventana debe cerrar la ventana y terminar el programa limpiamente.
* El uso de images de la `miniLibX` es obligatorio

## Mapa
* `0` Vacío, `1` Muro, `C` Colecionable, `E` salida, `P` Inicio.
* Mapa rectangular, rodeado de muros, camino válido y sin salida o inicio duplicados.
* `Error:` “Error\n” seguido de un mensaje explícito de tu elección.

## Bonus
* Patrulla de enemigos
* Sprites animados
* Contador de movimientos en pantalla

## Documentación

* [Subject](https://cdn.intra.42.fr/pdf/pdf/135299/es.subject.pdf)
* [MLX42](https://github.com/codam-coding-college/MLX42).
* [MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx/introduction.html#introduction-1)
* [MinilibXIntro](https://www.youtube.com/watch?v=bYS93r6U0zg)

* [Guide](https://42-cursus.gitbook.io/guide/rank-02/so_long)
* [Guide2](https://gontjarow.github.io/MiniLibX/)
* [Guide3](https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx)
* [Git1](https://github.com/gjmacias/so_long/blob/main/sources/so_long.c)
* [Git2](https://github.com/mewmewdevart/so_long/tree/main)
* [Git2](https://github.com/tblaase/so_long/tree/master)
* [Git2](https://github.com/madebypixel02/so_long/tree/main)
* [Git2](https://github.com/achrafelkhnissi/so_long/tree/master)