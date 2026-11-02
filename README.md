# Práctica 2 — Multiplicación de enteros grandes

  

C++ implementando multiplicación clásica y Karatsuba sobre cadenas decimales.

  

## Estructura

- `src/operations.h`, `src/operations.cpp`: operaciones auxiliares.

- `src/classic.h`, `src/classic.cpp`: multiplicación clásica.

- `src/karatsuba.h`, `src/karatsuba.cpp`: Karatsuba híbrido.

- `src/main.cpp`: programa principal.

- `tests/test_correctness.cpp`: pruebas de corrección.

- `tests/benchmark.cpp`: medición de tiempos.

  

## Requisitos

Compilador C++ con soporte C++17, por ejemplo `g++`. Ajustar los comandos si la estructura del proyecto cambia.

  

## Compilar y ejecutar

```bash

g++ -std=c++17 -O2 src/main.cpp src/operations.cpp src/classic.cpp src/karatsuba.cpp -o karatsuba

./karatsuba

```

  

## Pruebas

```bash

g++ -std=c++17 -O2 tests/test_correctness.cpp src/operations.cpp src/classic.cpp src/karatsuba.cpp -o test_correctness

./test_correctness

```

Las pruebas comparan Karatsuba con el método clásico en diferentes casos; en la ejecución reportada no hubo errores.

  

## Benchmark

```bash

g++ -std=c++17 -O2 tests/benchmark.cpp src/operations.cpp src/classic.cpp src/karatsuba.cpp -o benchmark

./benchmark

```

Se emplea `std::chrono::steady_clock` y se reportan microsegundos. Los tiempos dependen del compilador, opciones, equipo y carga del sistema. En las mediciones disponibles (16–2048 dígitos, 15 repeticiones), el método clásico fue más rápido desde 32 hasta 2048 dígitos; no se observó punto de cruce en ese rango.

  

## Datos de entrega

**Integrantes:** 
- Alejandro Martínez Vivanco
- Brayan Santiago González Mateus
