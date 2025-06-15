# Push_swap

Este proyecto es parte del curriculum de 42 School. El objetivo es ordenar datos en una pila con un conjunto limitado de instrucciones, usando el menor número de movimientos posible.

## Descripción

Push_swap es un algoritmo de ordenamiento que utiliza dos pilas (A y B) y un conjunto específico de operaciones para ordenar una lista de enteros.

### Operaciones permitidas:

- `sa` : swap a - intercambia los 2 primeros elementos de la pila A
- `sb` : swap b - intercambia los 2 primeros elementos de la pila B  
- `ss` : `sa` y `sb` al mismo tiempo
- `pa` : push a - toma el primer elemento de B y lo pone en A
- `pb` : push b - toma el primer elemento de A y lo pone en B
- `ra` : rotate a - desplaza hacia arriba todos los elementos de A (el primero se convierte en el último)
- `rb` : rotate b - desplaza hacia arriba todos los elementos de B
- `rr` : `ra` y `rb` al mismo tiempo
- `rra` : reverse rotate a - desplaza hacia abajo todos los elementos de A (el último se convierte en el primero)
- `rrb` : reverse rotate b - desplaza hacia abajo todos los elementos de B
- `rrr` : `rra` y `rrb` al mismo tiempo

## Compilación

```bash
make
```

## Uso

```bash
./push_swap [lista de enteros]
```

### Ejemplos:

```bash
./push_swap 2 1 3
./push_swap 4 67 3 87 23
./push_swap 1 2 3 4 5  # Ya ordenado, no imprime nada
```

### Casos de error:

El programa imprime "Error" y termina con código de salida 1 si:
- Los argumentos no son enteros
- Hay números duplicados
- Los números están fuera del rango de int

## Algoritmo

El programa utiliza diferentes estrategias según el tamaño de la entrada:

- **2-3 elementos**: Algoritmo específico optimizado
- **4-5 elementos**: Ordena moviendo elementos mínimos a la pila B
- **Más de 5 elementos**: Radix sort utilizando representación binaria

## Estructura del proyecto

```
.
├── Makefile
├── inc/
│   └── push_swap.h
├── src/
│   ├── main.c
│   ├── stack_operations.c
│   ├── swap_operations.c
│   ├── push_operations.c
│   ├── rotate_operations.c
│   ├── reverse_rotate_operations.c
│   ├── parsing.c
│   ├── utils.c
│   └── algorithm.c
└── README.md
``` 