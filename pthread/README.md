# Solución a preguntas sobre [Taller de principios de programación paralela] (https://github.com/josanabr/distributedsystems/tree/master/threads)
Este directorio contiene las respuestas a las preguntas del trabajo de pthread y los archivos relacionados con los códigos de cada asignación.

### 1) Asignación - `thread_101_1.c`

Quitar las instrucciones relacionadas con `pthread_join` y explicar:

- Cúal es el comportamiento del programa?

>Al quitar la función `pthread_join`, el programa ya no es determinístico, se generan resultados diferentes para x.

- Si es inesperado, Qúe piensas que ha pasado?
 
>Si, teniendo en cuenta que `pthread_join` hace que el hilo se duerma para esperar que el otro termine y retornar el valor final, al quitarlo el valor nunca es sincronizado por lo que el valor de x es diferente en cada ejecución.

Ejecuta el programa varias veces.

- Todas las ejecuciones fueron iguales?
 
>No, el valor de x es diferente.

### 2) Asignación - `3s-00.c`

Adicionar las sentencias de código adecuadas que permitan determinar cuánto tiempo pasa el programa durante:

- La inicialización del vector.
- Contando el número de 3s en un vector dado.

>La solución a este punto está en el archivo de código `3s-00.c`

### 3) Asignación - `3s-01.c`

Incluir las sentencias de código que permitan estimar cuánto tiempo se toma cada hilo en contar el número de 3s en un vector dado.

>La solución a este punto está en el archivo de código `3s-01.c`

Responder las siguientes preguntas:

- Cuántos elementos tiene el vector grande?

>Tiene 100 elementos

- El programa es correcto? Qué hay de malo en el? Qué valor se obtiene y cuál es el esperado?

>El programa es incorrecto, porque el conteo que se imprime en pantalla de 3s que se hace por medio hilos es diferente a la que se realiza durante el proceso de "initialize_vector en la variable doble_check que es el esperado,  en el programa se detectan dos problemas 1) No se hace el pthread_join para que terminen los hilos y se sincronicen los valores  y 2) Se trabaja sobre la misma variable por lo que los valores pueden tener problemas de concurrencia y ser alterados al mismo tiempo por uno o varios hilos.

