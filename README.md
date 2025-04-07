# yandex-coderun

Решенные задачи для [coderun.yandex.ru](https://coderun.yandex.ru/) на C++

## Оглавление

Общее
- [Личная предыстория](#личная-предыстория)
- [Почему CodeRun, а не LeetCode](#почему-coderun-а-не-leetcode)
- [Другие репозитории с решениями](#другие-репозитории-с-решениями)
- [Принципы, по которым решаются все задачи](#принципы-по-которым-решаются-все-задачи)

Решения
- [Решённые задачи (`/catalog`)](#решённые-задачи-catalog)


## Личная предыстория
Я создал репозиторий в тот же день, как прошёл тестовые задания на 
платформе [contest.yandex.ru](https://contest.yandex.ru/) для 
стажировки как бэкенд-разработчик на C++

Ну как прошёл: за 5 часов дали 5 заданий и их все я не смог завершить.
Нет, код для каждого задания я написал, но я не смог адекватно его
протестировать, потому что большая часть тестов являются закрытыми

И по итогу я сделал рабочий код, который работает только в начальных тестах
и нескольких последующих, а в остальных нет

Поэтому я решил, что мне нужно подтянуть алгоритмы и выбрал я для
этой задачи [coderun.yandex.ru](https://coderun.yandex.ru/)


## Почему CodeRun, а не LeetCode
Если кратко - потому что LeetCode слишком хорош

Основная причина почему я решил прорешать весь CodeRun, а не LeetCode - это
наличие у CodeRun **разграничения на открытые и закрытые тесты**

Мне это самому не нравится, но как показывает мой опыт, только LeetCode
имеет такую особенность как открытые тесты (не полностью, но посмотреть 
есть возможность), также вкладку с гайдами и решениями других пользователей
(тоже частичные)

То есть если подытожить, то CodeRun хуже LeetCode и именно поэтому он 
значительно лучше выполняет свою основную роль - заставить того,
кто эти тесты решает, думать над решением задачи

Да, наличие полностью закрытых тестов - это плохо в любом случае, но
так работают большинство таких платформ, поэтому лучше сразу привыкнуть
к такому, чтобы в будущем не было проблем с их выполнением

Другие платформы - это
- [coderun.yandex](https://coderun.yandex.ru/)
- [contest.yandex](https://contest.yandex.ru/)
- [new.contest.yandex](https://new.contest.yandex.ru/)
- Вся проклятая система Moodle


## Принципы, по которым решаются все задачи

Главный принцип - любой ценой сделать решение самым **быстрым** и 
самым **легковесным** (по памяти). Оба важны, нельзя пренебрегать
одним в угоду другого. В худшем случае надо брать **скорость всегда**

Также по коду я постараюсь размещать разъяснительные комментарии и 
также в начале каждого файла будет общее описание того, что это.
Шаблон этого стартого описание [находится тут](CREDITS_TEMPLATE.md)

Другие решения я не особо предпочитаю, но если они и будут, то только
в другом файле, с тем же названием, но с цифрой `2`. В `README` их не будет


---

## Другие репозитории с решениями

- [Gusunov/coderun](https://github.com/Gosunov/coderun)
- [horkhe/YCodeRun](https://github.com/horkhe/YCodeRun)
- [aeon32/yandex_coderun](https://github.com/aeon32/yandex_coderun)

## Решённые задачи (`/catalog`)

- [1. Средний элемент](catalog/01-median-out-of-three.cpp)
- [2. Самый дешевый путь](catalog/02-cheapest-way.cpp)
- [3. Вывести маршрут максимальной стоимости](catalog/03-print-the-route-of-the-maximum-cost.cpp)
- [4. Ход конём](catalog/04-knight-move.cpp)

## Не решённые задачи (`/catalog`)
- [5. Кафе](catalog/05-cafe.cpp)
- [6. НОП с восстановлением ответа](catalog/06-nop-with-response-recovery.cpp)

---
- [7. Поиск в глубину](catalog/07-search-in-depth.cpp)
