# Solución a preguntas sobre Principles of Parallel Programming - Chapter One

### 1) Assignment - `thread_101_1.c`

Remove the instructions related to `pthread_join` and explain:

- What is the program's behavior

**Resultado:**

Al quitar la función `pthread_join`, el programa ya no es determinístico, se generan resultados diferentes para x.

- If it is unexpected, what did you think that happen?
 
>**Resultado:**
Si, Teniendo en cuenta que `pthread_join` hace que el hilo se duerma para esperar que el otro termine y retornar el valor final, al quitarlo el valor nunca es sincronizado por lo que el valor de x es diferente en cada ejecución.

Try the program several times.

- All the executions were equal?
 
**Resultado:**

No, el valor de x es diferente.

