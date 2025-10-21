# Ejercicios lenguaje C
 Ejercicios y algoritmos creados en C para el curso CS50.
 Uso la libreria cs50.h la cual "ayuda" un poco en algunas funciones.

# Colección de ejercicios en C (CS50)
Una recopilación de ejercicios y pequeños proyectos en C usados para practicar conceptos de programación de sistemas. Algunos usan la librería auxiliar `cs50.h`; todos están pensados para ser didácticos pero con retos no triviales.

Resumen conciso de cada ejercicio (raíz y carpetas)

Archivos en la raíz:

- `cash.c` — Problema de cambio óptimo: dado un monto en centavos, calcula el número mínimo de monedas necesarias. Requiere razonamiento greedy y manejo robusto de entradas numéricas.
- `population.c` — Simulación demográfica discretizada: determina cuántos años tarda una población en alcanzar un objetivo con reglas de nacimiento/mortalidad por fracciones; hay que cuidar casos límite y crecimiento estable/inestable.
- `mario.c` — Generador de pirámides estilo NES: construye patrones de caracteres según la altura solicitada. Sencillo en apariencia, pero exige control preciso de índices y formato.
- `max.c` — Implementación de un máximo simple: leer datos y devolver el máximo. Ejercicio básico con énfasis en validación.
- `no-vowels.c` — Filtrado de vocales: elimina vocales de una cadena. Trabajo con manipulación de strings y sets de caracteres.
- `password.c` — Validador de contraseñas: determina la fuerza de una contraseña según reglas (mayúsculas, minúsculas, dígitos, símbolos). Manejo de condiciones compuestas y conteo.
- `plurality.c` — Votación por pluralidad: simula un recuento de votos y declara ganador(es). Involucra arrays, conteo y desempates.
- `snackbar.c` — Ejercicio orientado a estructuras y lógica de negocios simple (gestión/selección). Requiere atención a detalle en la entrada/salida.
- `substitution.c` — Cifrado por sustitución: aplica una clave de 26 letras únicas para cifrar texto preservando mayúsculas/minúsculas. Considerado uno de los retos más exigentes tempranos por manejo de validación y mapeos.
- `tempsdesc.c` — Ordenamiento/descenso de temperaturas: procesamiento y ordenamiento de datos numéricos.
- `testing123.c` — Archivo de pruebas y experimentos varios; sirve como banco de pruebas para fragmentos pequeños.

Carpetas y ejercicios notables:

- `bottomup/` (`bottomup.c`, `bmp.h`) — Proyecto de manipulación de imágenes BMP con enfoque en técnicas "bottom-up"; exige comprensión de formatos binarios y memoria.
- `cash/` (`cash.c`) — Variante o práctica separada del problema de cambio; ayuda a consolidar lógica greedy y validación en un entorno aislado.
- `debug/` (`debug.c`, `half/half.c`) — Ejercicios de depuración: encontrar y corregir errores sutiles; imprescindible para afinar la lectura crítica de código.
- `dna/` (`dna.py`, `sequences/`) — Análisis de secuencias: scripts que examinan cadenas de ADN; mezcla de patrón y conteo de repeticiones en archivos de datos.
- `filter-less/` (`filter.c`, `helpers.c`, `bmp.h`) — Implementación de filtros sobre imágenes BMP sin usar librerías avanzadas; trabajar con bytes y alineación de filas.
- `hello/` (`hello.c`) — Programa "hola mundo" básico; punto de partida. No subestimar la importancia de configurar correctamente el entorno.
- `hours/` (`hours.c`) — Gestión de horas/trabajo: calcula tiempos y validaciones de entrada.
- `inheritance/` (`inheritance.c`) — Simulaciones conceptuales de herencia (en C): estructura y composición para modelar comportamientos.
- `mario-less/` (`mario.c`) — Variante del ejercicio de pirámide, versión más simple o con restricciones diferentes.
- `no-vowels/` (`no-vowels.c`) — Implementación en carpeta que replica o amplía la versión raíz.
- `prime/` (`prime.c`) — Determinación de primos: tests de primalidad y generación simple; atención a la eficiencia para entradas grandes.
- `readability/` (`readability.c`) — Índice de legibilidad de texto: análisis de oraciones, palabras y caracteres para calcular un grado aproximado.
- `repasos/` (varios `.c`) — Colección de ejercicios de repaso: desde condicionales y loops hasta pequeños programas de entrada/salida; útil para reforzar fundamentos.
- `reverse/` (`reverse.c`, `wav.h`) — Trabajo con archivos WAV: leer y escribir encabezados y datos de audio; manipulación binaria y estructura de archivos.
- `scrabble/` (`scrabble.c`) — Simula puntuación de Scrabble por palabra; combina tablas de valores y manejo de strings.
- `smiley/` (`colorize.c`, `helpers.c`, `bmp.h`) — Transformaciones de imagen (colorize): manipulación de píxeles para añadir efectos.
- `speller/` (`speller.c`, `dictionary.c/h`, `texts/`, `keys/`) — Proyecto completo de corrector ortográfico: estructuras de datos (hash/trie), lectura masiva de textos y tests con corpus; uno de los ejercicios más complejos del repositorio.
- `substitution/` (carpeta) — Código relacionado con `substitution.c` principal y pruebas (`testing.c`).
- `trie/` (`trie.c`, `dog_names.txt`) — Estructura trie para búsquedas de prefijos/nombres; implementa operaciones no triviales de memoria dinámica y recorrido.

Notas finales:

Estos ejercicios cubren desde básicos (hello, hello-world, pirámides) hasta temas intermedios/avanzados (manipulación de BMP/WAV, tries, corrector ortográfico y cifrados). A primera vista pueden parecer sencillos; la práctica demuestra que varios son más exigentes de lo que aparentan — perfectos para pulir habilidades en C.

