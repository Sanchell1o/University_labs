import random
import typing as tp


def is_prime(n: int) -> bool:
    """
    Tests to see if a number is prime.

    >>> is_prime(2)
    True
    >>> is_prime(11)
    True
    >>> is_prime(8)
    False
    """
    if n <= 1:  # Числа меньше или равные 1 не являются простыми
        return False
        # Проверяем делимость числа n на все числа от 2 до квадратного корня из n
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:  # Если n делится без остатка на i, то оно не простое
            return False
    return (
        True  # Если ни одно из чисел от 2 до квадратного корня из n не делится на n, то n простое
    )
    pass


def gcd(a: int, b: int) -> int:
    """
    Euclid's algorithm for determining the greatest common divisor.

    >>> gcd(12, 15)
    3
    >>> gcd(3, 7)
    1
    """
    if b == 0:  # Если b равно 0, то НОД равен a
        return a
    else:
        return gcd(b, a % b)  # Рекурсивно вызываем gcd для b и остатка от деления a на b
    pass


def multiplicative_inverse(e: int, phi: int) -> int:
    """
    Euclid's extended algorithm for finding the multiplicative
    inverse of two numbers.

    >>> multiplicative_inverse(7, 40)
    23
    """
    # Инициализируем коэффициенты Безу перед числами
    a, b = phi, e
    c, s = 1, 0
    t, d = 0, 1

    # Алгоритм Евклида
    while b != 0:
        quotient = a // b  # Вычисляем остаток от деления
        # Обновляем коэффициенты
        a, b = b, a - quotient * b
        c, s = s, c - quotient * s
        t, d = d, t - quotient * d

    # Если коэффициент a равен 1, то e и phi взаимно просты),
    # то t является мультипликативным обратным e по модулю phi
    if a == 1:
        return t % phi
    else:
        raise ValueError("e и phi не взаимно простые числа")
    pass


def generate_keypair(p: int, q: int) -> tp.Tuple[tp.Tuple[int, int], tp.Tuple[int, int]]:
    if not (is_prime(p) and is_prime(q)):
        raise ValueError("Both numbers must be prime.")
    elif p == q:
        raise ValueError("p and q cannot be equal")

    # n = pq
    n = p * q  # произведение двух простых чисел

    # phi = (p-1)(q-1)
    phi = (p - 1) * (q - 1)  # Вычисляется функция Эйлера

    # Choose an integer e such that e and phi(n) are coprime
    e = random.randrange(1, phi)

    # Use Euclid's Algorithm to verify that e and phi(n) are coprime
    g = gcd(e, phi)
    while g != 1:
        e = random.randrange(1, phi)
        g = gcd(e, phi)

    # Use Extended Euclid's Algorithm to generate the private key
    d = multiplicative_inverse(e, phi)

    # Return public and private keypair
    # Public key is (e, n) and private key is (d, n)
    return ((e, n), (d, n))


def encrypt(pk: tp.Tuple[int, int], plaintext: str) -> tp.List[int]:
    # Unpack the key into it's components
    key, n = pk
    # Convert each letter in the plaintext to numbers based on
    # the character using a^b mod m
    cipher = [(ord(char) ** key) % n for char in plaintext]
    # Return the array of bytes
    return cipher


def decrypt(pk: tp.Tuple[int, int], ciphertext: tp.List[int]) -> str:
    # Unpack the key into its components
    key, n = pk
    # Generate the plaintext based on the ciphertext and key using a^b mod m
    plain = [chr((char**key) % n) for char in ciphertext]
    # Return the array of bytes as a string
    return "".join(plain)


if __name__ == "__main__":
    print("RSA Encrypter/ Decrypter")
    p = int(input("Enter a prime number (17, 19, 23, etc): "))
    q = int(input("Enter another prime number (Not one you entered above): "))
    print("Generating your public/private keypairs now . . .")
    public, private = generate_keypair(p, q)
    print("Your public key is ", public, " and your private key is ", private)
    message = input("Enter a message to encrypt with your private key: ")
    encrypted_msg = encrypt(private, message)
    print("Your encrypted message is: ")
    print("".join(map(lambda x: str(x), encrypted_msg)))
    print("Decrypting message with public key ", public, " . . .")
    print("Your message is:")
    print(decrypt(public, encrypted_msg))
