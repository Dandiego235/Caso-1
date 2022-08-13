# Caso 1
**Curso: Estructuras de datos**
*Profesor Rodrigo Núñez*
*Estudiante: Daniel Granados Retana*
*Carné: 2022104692*
*Fecha: 13/08/2022*

El Caso #1 consiste en hacer un algoritmo que pueda aplicar el teorema de los cuatro colores usando una estructura de datos.

La estructura de datos para representar las regiones del mapa define 2 propiedas: el color de la región y un vector con sus regiones adyacentes.
Al final, se define un arreglo para representar el mapa. Aquí se debe cambiar el número de elementos del arreglo para cambiar la cantidad de 
regiones en el mapa.
```
struct region{
    int color = 0;
    vector<int> adyacentes;
} mapa[10]; --> Aquí se cambia la cantidad de regiones del mapa.
```
Cada región del mapa va a ser representada por un índice de este arreglo, entonces las regiones se numeran del 0 hasta (cantidad de regiones - 1).

Luego, cuando se ejecuta el programa, el programa va a leer la entrada del usuario para establecer las regiones adyacentes a cada región. Para ingresar una región, se escribe el número y se presiona la tecla Enter. Cuando se quiere llenar la siguiente región, se deja la línea vacía; Solo se presiona Enter:
```
Ingrese las adyacencias de la region 0:
1
2
3

Ingrese las adyacencias de la region 1:
0
...
```
No se pueden ingresar regiones adyacentes que sean la misma a la región o que no existan. Igualmente, cada pareja de regiones adyacentes debe ser recíprocamente adyacentes. Por ejemplo, si la región 0 es adyacente a la región 3, la región 3 debe ser adyacente a la región 0.

Al final de ingresar las adyacencias, el programa imprime una lista con las regiones que les corresponde cada color. Ejemplo:
```
Ingrese las adyacencias de la region 0: 
1
2
3
4
5
6

Ingrese las adyacencias de la region 1: 
0
2
6
7

Ingrese las adyacencias de la region 2: 
0
1
3
7
8

Ingrese las adyacencias de la region 3: 
0
2
4
8

Ingrese las adyacencias de la region 4: 
0
3
5
8
9

Ingrese las adyacencias de la region 5: 
0
6
4
9

Ingrese las adyacencias de la region 6: 
0
1
5
7
9

Ingrese las adyacencias de la region 7: 
1
2
8
9
6

Ingrese las adyacencias de la region 8: 
2
3
4
7
9

Ingrese las adyacencias de la region 9: 
4
5
6
7
8

Regiones con color 1
0, 7,
Regiones con color 2
2, 4, 6,
Regiones con color 3
1, 5, 8,
Regiones con color 4
3, 9,
```
![Ejemplo de arriba:](/assets/images/fourcolorejemplo.png)
El algoritmo funciona de la siguiente manera:
1. Lee las adyacencias de cada región.
2. Ordena las regiones en un orden descendente de acuerdo con la cantidad de regiones adyacentes que tienen.
3. Recorre este orden y por cada región, recorre sus adyacencias, eliminando sus colores de una lista de colores disponibles.
4. Cuando termina de recorrer las adyacencias, le asigna el primer color que quedó en la lista de colores disponibles a la región. Esto hace que se usen la menor cantidad de colores repitiendo colores siempre que se pueda.
5. Si al final no se le pudo asignar un color a alguna región, el mapa está erróneo y envía un mensaje de error.
6. Imprime los colores de cada región.