Задание №1. «Классовая обертка над базовым типом int на языке С++»
Создать класс на языке С++ в среде Visual Studio для безопасной работы с типом int. 
1. Класс содержит:
1.1. Частный элемент int n.
1.2. Конструкторы: по умолчанию, копии, инициализации.
1.3. Деструктор
1.4. Перегруженные операции: 
1.4.1. явное преобразование типа
1.4.2. присваивание, сравнения, 
1.4.3. арифметические : сумма, разность, деление, умножение
2. Класс проверяет две ситуации:
выход за диапазон типа,
деление на ноль.
При возникновении исключительных ситуаций выбрасываются исключения: EOverflow, EDivideDyZero. Эти исключения наследуются от базового класса MyException.
3. Приложение должно содержать тестовые функции для автоматической проверки операций.
