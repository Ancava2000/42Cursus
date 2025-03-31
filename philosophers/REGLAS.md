REGLAS
1. Comer, pensar o dormir, uno a la vez
2. Tantos tenedores como filósofos
3. Mesa, un solo bol, filosofos y tenedores
3. Cuando comen cogen el de la derecha e izquierda
4. Tras comer se duerme
5. Tras dormir pensar
6. Simulacion termine cuando alguno muere por hambre
7. Todos comen
8. Ninguno habla

INSTRUCCIONES
1. numero de filosofos: asignados a partir del uno
2. numero de tenedores: asignados a partir del 0
3. tiempo de morir: tiempo antes de morir si no com (ultima vez que comio)
4. tiempo de comer: el tiempo que tienen para comer
5. tiempo para dormir
6. logs: en ms, logs de coger tenedor, comer, dormir, pensar, morir, comeinzo y final simulacion

FUNCIONES
./philo 5 (numero filosofos) 800 (tiempo desde que comio por ultima vez) 200 (tiempo para comer) 200 (tiempo para dormir)
1. gettimeofday: <sys/time.h>
2. pthread: <pthread.h>
3. mutex: <pthread.h>

.h
struct -> mesa: numero filosofos, time_to_die, time_to_eat, time_to_sleep, empieza simulacion, termina simulacion, struct filosofos, struct tenedores, 
struct -> filosofos: int id filosofo, bool ha comio, long morir(tiempo desde ultima comida), t_fork tenedor der, t_fork tenedor izq, pthread thread id
struct -> tenedores: int id, pthread mutex tenedor(para saber si uno esta ocupado o no)

ESQUEMA MAIN
./philo 5 800 200 200
1. si numero de argc esta bien:
	- parseo: son numeros, negativos y limites (atoi), tiempos (pasar a ms y limites)
	- inicializacion datos: con tabla (TODO), mutex, pthreads
	- empiezo programa
	- limpieza
2. si no esta bien argc
	- mensaje error (funcion error personalizada)