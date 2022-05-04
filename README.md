# LSM-KVS
## Описание структуры

- Log — массив “ключ + позиция в файле”
- Memory — шардинг SSTable в стиле 2048 + фильтр Блюма на каждый шард
Здесь имеется ввиду, что данные хранятся не больше чем в $log_2 \ n/d$ SSTable’ах,
и при наличии двух таблиц одного размера $s$, они объединяются в одну таблицу размера $2s$.
Помимо этого для каждой такой таблицы мы поддерживаем фильтр Блюма в оперативной памяти.
