a, b, m = map(int, input().split())
res = 0
sum_solutions = 0  # Змінна для сумування підходящих розв'язків
min_solution = None  # Змінна для зберігання найменшого розв'язку
max_solution = None  # Змінна для зберігання найбільшого розв'язку

for x in range(m):
    if (a * x) % m == b:
        print(x)
        sum_solutions += x  # Додаємо підходяще значення до суми
        res += 1
        if min_solution is None or x < min_solution:
            min_solution = x  # Оновлюємо найменший розв'язок
        if max_solution is None or x > max_solution:
            max_solution = x  # Оновлюємо найбільший розв'язок

sum_modulo = sum_solutions % m  # Результат суми по модулю m

if min_solution is not None and max_solution is not None:
    min_max_sum_modulo = (min_solution + max_solution) % m  # Сума найменшого та найбільшого розв'язку по модулю m
    min_max_product_modulo = (min_solution * max_solution) % m  # Добуток найменшого та найбільшого розв'язку по модулю m
else:
    min_max_sum_modulo = '-'  # Якщо розв'язків немає
    min_max_product_modulo = '-'  # Якщо розв'язків немає

print('res =', res)
print('sum_modulo =', sum_modulo)
if min_solution is not None and max_solution is not None:
    print('min_solution =', min_solution)
    print('max_solution =', max_solution)
    print('min_max_sum_modulo =', min_max_sum_modulo)
    print('min_max_product_modulo =', min_max_product_modulo)
else:
    print('min_solution = -')
    print('max_solution = -')
    print('min_max_sum_modulo = -')
    print('min_max_product_modulo = -')
