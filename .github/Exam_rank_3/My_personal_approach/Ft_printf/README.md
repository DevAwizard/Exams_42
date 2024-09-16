# 🌟 **FT_PRINTF PROJECT** 🌟

### 📄 **1. Required File**

📂 **ft_printf.c**


### 🚨 **Allowed Functions**

🔓 You can use the following C standard library functions:

- `malloc`
- `free`
- `write`
- `va_start`
- `va_arg`
- `va_copy`
- `va_end`



### 📌 **Function Prototype**

```c
int ft_printf(const char *, ...);
```


### 📝 **The Program**

Your mission, should you choose to accept, is to write a function named `ft_printf` that mimics the behavior of the real **printf**, but with a twist! 😎

#### 🎯 **Objectives**

- The function must manage only these conversions:
  - **`%s`** (string)
  - **`%d`** (decimal integer)
  - **`%x`** (lowercase hexadecimal)

- Your function should handle **variable arguments** and **formatting**, just like the real **printf**.


### 📊 **Examples of Expected Output**

1️⃣ **Example 1:**

**Call**:  
```c
ft_printf("%s\n", "toto");
```

**Output**:  
```
toto$
```


2️⃣ **Example 2:**

**Call**:  
```c
ft_printf("Magic %s is %d", "number", 42);
```

**Output**:  
```
Magic number is 42%
```


3️⃣ **Example 3:**

**Call**:  
```c
ft_printf("Hexadecimal for %d is %x\n", 42, 42);
```

**Output**:  
```
Hexadecimal for 42 is 2a$
```


### 🏆 **Your Goal**

Your goal is to implement **`ft_printf`** and make sure it properly mimics the basic functionality of the original `printf`, using only the allowed functions and managing only the specified format conversions (`%s`, `%d`, and `%x`).


💡 **Tips**:
- Don't forget to handle **null strings** for `%s`. If the string is `NULL`, you should print `(null)`.
- Handle negative numbers correctly for the `%d` conversion.
- Convert integers to hexadecimal for `%x` using lowercase letters (`a-f`).



🌟 **Good Luck!** You’ve got this! Keep your code clean, readable, and efficient. 💪

---
