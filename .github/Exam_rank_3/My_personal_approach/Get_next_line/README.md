# 📜 **GET_NEXT_LINE PROJECT** 📜

### 📂 **Expected Files**

📝 **1. get_next_line.c**  
📝 **2. get_next_line.h**



### 🚨 **Allowed Functions**

🔓 You are allowed to use only the following functions:

- `read`
- `free`
- `malloc`


### 📌 **Function Prototype**

```c
char *get_next_line(int fd);
```



### 📝 **The Program**

Your goal is to implement the **`get_next_line`** function, which will read and return one line at a time from a given file descriptor.

#### 🎯 **Objectives**

- The function **must return a line** that has been read from the file descriptor passed as a parameter.
- A "line that has been read" is defined as a sequence of 0 to n characters that **ends with a `\n`** (ASCII code 0x0A) or **End Of File (EOF)**.
- The line should be returned **including the `\n`** if it is present at the end of the line.



#### 📊 **Behavior with the Buffer**

- When the **EOF** is reached, store the current buffer in a `char *` and return it.
- The buffer will be dynamically allocated, and when it's empty, your function should return **`NULL`**.



#### ❌ **Return NULL**

- Return **`NULL`** if:
  - There’s an error during reading.
  - The buffer is empty.
  
- In case of not returning `NULL`, the pointer should be **free-able** (dynamically allocated memory).


#### 💾 **Memory Management**

- Your program will be compiled with the flag **`-D BUFFER_SIZE=xx`**, which defines the buffer size for the `read` calls in your function.
- Your function **must be memory-leak-free**.
- Once the **EOF** is reached, there should be **no remaining allocated memory** (except for the line returned).


#### 🔄 **Continuous Reading**

- You should be able to call `get_next_line` **in a loop** to read the contents of a file descriptor, **one line at a time** until the end of the text.
- The size of the text or one of its lines does not matter.


#### 💡 **Important Considerations**

- Ensure that your function behaves well when reading:
  - From a file,
  - From standard input (stdin),
  - From redirections (piping),
  - And other file descriptor sources.
  
- There should be **no interference** with the file descriptor between two calls to `get_next_line`.

#### ⚠️ **Undefined Behavior**

⚠️ **Undefined behavior** will occur when reading from a **binary file**, so it's important to handle text-based files only.


### 📊 **Example Usage**

```c
int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);  // Don't forget to free the returned line!
}
close(fd);
```

---
