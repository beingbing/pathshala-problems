# Modular Arithmetic: The Arithmetic of Remainders

In modular arithmetic, we operate within a **fixed range of numbers** defined by a modulus m. When calculating `a % b = c`, where b != 0, the remainder c always lies within **[0, b - 1]**. This fixed range allows values to "wrap around" in cycles, creating a **periodic pattern on the number line**. For example, if c is the remainder when dividing by b, then `a + b`, `a + 2b`, etc., will also have a remainder of c when module by b. This introduces the concept of **modular congruence**.

## Modular Congruence
Two numbers are **modularly congruent** if they yield the same remainder when divided by a given number. For example, `13` and `3` are **congruent modulo `5`**, since both leave a remainder of `3` when divided by `5`.

## Key Properties of Modular Arithmetic

1. **Addition**: Adding two numbers and then taking the remainder is equivalent to adding their individual remainders and taking the remainder of the result.
```
(a + b) % m = ((a % m) + (b % m)) % m // remainder-of-sum =  (sum-of-remainders) % m
```

2. **Subtraction**: Subtracting with modular arithmetic requires adjusting for cases where the result becomes negative by adding m to bring it back into the positive remainder range, as result of modulus can never be negative.
```
(a - b) % m = a % m - b % m            if a % m >= b % m
            = a % m - b % m + m        if a % m < b % m
```

3. **Multiplication**: Taking the product of two numbers and then taking the remainder is equivalent to multiplying their individual remainders and taking the remainder of the result.
```
(a * b) % m = ((a % m) * (b % m)) % m
```