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

>El programa es incorrecto, porque el conteo que se imprime en pantalla de 3s que se hace por medio hilos es diferente a la que se realiza durante el proceso de "initialize_vector en la variable doble_check que es el esperado,  en el programa se detectan dos problemas 1) No se hace el pthread_join para que terminen los hilos y se sincronicen los valores  y 2) Se trabaja sobre la misma variable y no se maneja alguna tecnica para la exlusión mutua, por lo que los valores pueden tener problemas de concurrencia y ser alterados al mismo tiempo por uno o varios hilos.

###4) Asignación - `3s-02.c`

Incluir las sentencias de código que permitan estimar cuánto tiempo se toma cada hilo en contar el número de 3s en un vector dado.

>La solución a este punto está en el archivo de código `3s-02.c`

- ¿Qué está mal con este código esta vez?

>En este programa se adiciono la parte del pthread_join para que todos los hilos terminen, pero sigue manteniendo el problema con el acceso concurrente a la misma variable por parte de los hilos, y hasta el momento no se obtienen los valores esperados.

###5) Asignación - `3s-03.c`

- Identificar porque este programa ahora si lo hace bien.
 
>El programa funciona correctamente porque se utilizan mecanismos para el acceso controlado, las funciones para este manejo de zonas de acceso exclusivo tienen el prefijo pthread_mutex, donde se bloquea el acceso de los demás hilos a la variable hasta que finaliza el proceso y se desbloquea para que el siguiente hilo puede acceder.

- Incluir las sentencias de código que permitan estimar cuánto tiempo se toma cada hilo en contar el número de 3s en un segmento del vector completo.

>La solución a este punto está en el archivo de código `3s-03.c`

- Cúanto tiempo se toma para obtener la cantidad total de 3s en el todo el vector.

>La solución a este punto está en el archivo de código `3s-03.c`

###6) Asignación - `3s-04.c`

- Cúal es la diferencia entre el 3s-03.c y el 3s-04.c?

>La diferencia está en que en el programa 3s-03.c cada hilo bloquea el acceso a la variable count durante todo el recorrido del segmento asignado, mientras que en el programa 3s-04.c la variable solo es bloqueada cuando el hilo ha encontrado un 3, esto es muy significativo en cuanto a rendimiento,teniendo en cuenta que en el programa  3s-03.c lo bloquea durante todo el for, evitando que hilos que ya han terminado puedan acceder y colocar su valor.

- Comparar el tiempo transcurrido por hilo durante el proceso de conteo y el tiempo total que todos los hilos tomaron para contar el número de 3s en toda la matriz. Ejecutar todos los programas (3s-03 y 3s-04) tres veces y calcular el tiempo promedio por programa. Presente sus resultados y explicarlos.
 
>

###7) Asignación - `3s-05.c`

- ¿Dónde reside el éxito de este programa?
 
> El éxito de este programa reside en 3 cosas que fuimos identificando a medida que se fueron adicionando funcionalidades: 1)Manejo de hilos en procesamiento paralelo `pthread_create` para mejorar rendimiento.2)Establecer mecanismo `pthread_join` para esperar a que todos los hilos terminen su ejecución y asi tener los valores sincronizados. 3) Establecer mecanismos para el acceso controlado a las variables `pthread_mutex...`. 4) Manejar el conteo de los hilos independientemente utilizando un vector `private_count` que permite una vez finalizado el conteo por hilo, hacer un llamado para pedir control sobre la variable y bloquearla para poder actualizar su valor de conteo (a diferencia de la instancia anterior que bloquean el acceso a la variable durante la ejecución del for que recorre el segmento asignado al hilo). 

- Compare la ejecución de este programa y compare su rendimiento con las instancias previas y escriba sus observaciones.

>

