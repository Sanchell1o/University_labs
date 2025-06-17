# ✨ Алгоритмы шифрования

## 📌 Прежде чем приступить к выполнению работы

Перед началом выполнения заданий:

```bash
$ cd путь/к/рабочей_директории
$ workon venv
```

Создайте ветку разработки:

```bash
(venv) $ git checkout -b develop master
```

Создайте ветку новой функциональности:

```bash
(venv) $ git checkout -b feature/caesar develop
```

Создайте папку:

```bash
(venv) $ mkdir homework01
```

---

## 🔐 Шифр Цезаря

📚 Подробнее: [Шифр Цезаря — Wikipedia](https://ru.wikipedia.org/wiki/Шифр_Цезаря)

Сдвиг на 3 буквы:

```
A → D, B → E, C → F, ...
X → A, Y → B, Z → C
```

Пример:

```
PYTHON → SBWKRQ
```

### ✍️ Реализуйте функции:

```python
def encrypt_caesar(plaintext):
    """
    >>> encrypt_caesar("PYTHON")
    'SBWKRQ'
    >>> encrypt_caesar("python")
    'sbwkrq'
    >>> encrypt_caesar("Python3.6")
    'Sbwkrq3.6'
    >>> encrypt_caesar("")
    ''
    """
    # PUT YOUR CODE HERE
    return ciphertext


def decrypt_caesar(ciphertext):
    """
    >>> decrypt_caesar("SBWKRQ")
    'PYTHON'
    >>> decrypt_caesar("sbwkrq")
    'python'
    >>> decrypt_caesar("Sbwkrq3.6")
    'Python3.6'
    >>> decrypt_caesar("")
    ''
    """
    # PUT YOUR CODE HERE
    return plaintext
```

💡 Подсказка: используйте функции `ord()` и `chr()`.

📁 Создайте файл и сделайте коммиты:

```bash
(venv) $ git add homework01/caesar.py
(venv) $ git commit -m "Добавлен шаблон для шифра Цезаря"
(venv) $ git commit -am "Реализована функция encrypt_caesar()"
(venv) $ git commit -am "Реализована функция decrypt_caesar()"
```

🧪 Тестирование:

```bash
$ python3 -m doctest -v caesar.py
```

🧹 Проверка PEP8:

```bash
$ pep8 caesar.py
```

🔀 Слияние:

```bash
(venv) $ git checkout develop
(venv) $ git merge --no-ff feature/caesar
```

✅ Улучшение: добавьте параметр `shift`:

```python
encrypt_caesar(plaintext, shift)
decrypt_caesar(ciphertext, shift)
```

---

## 🔐 Шифр Виженера

📚 Подробнее: [Шифр Виженера — Wikipedia](https://ru.wikipedia.org/wiki/Шифр_Виженера)

Пример:

```
Сообщение: ATTACKATDAWN
Ключ:      LEMONLEMONLE
Результат: LXFOPVEFRNHR
```

### ✍️ Реализуйте функции:

```python
def encrypt_vigenere(plaintext, keyword):
    """
    >>> encrypt_vigenere("PYTHON", "A")
    'PYTHON'
    >>> encrypt_vigenere("python", "a")
    'python'
    >>> encrypt_vigenere("ATTACKATDAWN", "LEMON")
    'LXFOPVEFRNHR'
    """
    # PUT YOUR CODE HERE
    return ciphertext


def decrypt_vigenere(ciphertext, keyword):
    """
    >>> decrypt_vigenere("PYTHON", "A")
    'PYTHON'
    >>> decrypt_vigenere("python", "a")
    'python'
    >>> decrypt_vigenere("LXFOPVEFRNHR", "LEMON")
    'ATTACKATDAWN'
    """
    # PUT YOUR CODE HERE
    return plaintext
```

📁 Создайте ветку и файл:

```bash
(venv) $ git checkout -b feature/vigener develop
(venv) $ git add homework01/vigener.py
(venv) $ git commit -m "Добавлен шаблон для шифра Виженера"
```

📥 Завершение работы:

```bash
(venv) $ git commit -am "Реализованы функции encrypt_vigenere и decrypt_vigenere"
(venv) $ git checkout develop
(venv) $ git merge --no-ff feature/vigener
```

---

## 🔐 RSA шифрование

📚 Подробнее:

- [RSA в объяснении для ребёнка (quora)](https://www.quora.com/How-do-you-explain-how-an-RSA-public-key-works-to-a-child)
- [Учебник по RSA](http://kpfu.ru/docs/F366166681/mzi.pdf)

---

### 🧠 Этап 1: Проверка на простоту

```python
def is_prime(n):
    """
    >>> is_prime(2)
    True
    >>> is_prime(11)
    True
    >>> is_prime(8)
    False
    """
    # PUT YOUR CODE HERE
    pass
```

Создание ветки:

```bash
(venv) $ git checkout -b feature/rsa develop
(venv) $ git add homework01/rsa.py
(venv) $ git commit -m "Добавлен шаблон для RSA шифрования"
```

---

### 🔐 Этап 2: Генерация ключей

```python
def generate_keypair(p, q):
    if not (is_prime(p) and is_prime(q)):
        raise ValueError('Both numbers must be prime.')
    elif p == q:
        raise ValueError('p and q cannot be equal')

    # n = p * q
    # phi = (p - 1) * (q - 1)

    e = random.randrange(1, phi)
    g = gcd(e, phi)
    while g != 1:
        e = random.randrange(1, phi)
        g = gcd(e, phi)

    d = multiplicative_inverse(e, phi)

    return ((e, n), (d, n))
```

---

### 🔢 Этап 3: Поиск НОД

```python
def gcd(a, b):
    """
    >>> gcd(12, 15)
    3
    >>> gcd(3, 7)
    1
    """
    # PUT YOUR CODE HERE
    pass
```

```bash
(venv) $ git commit -am "Реализована функция поиска НОД"
```

---

### 📐 Этап 4: Обратный элемент (расширенный Евклид)

```python
def multiplicative_inverse(e, phi):
    """
    >>> multiplicative_inverse(7, 40)
    23
    """
    # PUT YOUR CODE HERE
    pass
```

```bash
(venv) $ git commit -am "Реализованы функции multiplicative_inverse() и generate_keypair()"
```

---

## 🏁 Финальные шаги

Создание релиза:

```bash
(venv) $ git checkout -b release-1.0 develop
(venv) $ git commit -m "Релиз 1.0"
```

Слияние с `master`:

```bash
(venv) $ git checkout master
(venv) $ git merge --no-ff release-1.0
(venv) $ git tag -a 1.0
```

Удаление веток:

```bash
(venv) $ git branch -d feature/caesar
(venv) $ git branch -d feature/vigener
(venv) $ git branch -d feature/rsa
```
