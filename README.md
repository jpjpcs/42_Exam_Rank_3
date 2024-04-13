# 42_exam_rank_3

## 📝 1 - **From where I study**

I followed Pasqualerossi solutions for exam rank 3. Both pass the exam. I made the get_next_line solution and passed. Others made the ft_printf solution and also passed.

- https://github.com/pasqualerossi/42-School-Exam-Rank-03


Notes:
- My GNL works but it´s too long. So I didn´t use it. https://github.com/jpjpcs/42_get_next_line 
- The solution of Cralos works, but it´s also too long. 
https://github.com/Cralos9/Gnl_exam
- The solution of Alex Mitcul **doesn´t pass**. https://github.com/AlexMitcul/42-School-Exam-Rank-03/blob/main/get_next_line/get_next_line.c


## 📝 2 - **How I study**



### 2.1.- **Regarding FT_PRINTF:** 

**ft_printf has 3 functions: ft_printf, put_digit and put_string.**

**2.1.1.- FT_PRINTF** I memorized ft_printf **divided in 3 parts**:

1️⃣ - First the **Creation of the Variadic arguments** (A "variadic variable," also known as a variadic variable, is a type of variable in programming languages that can store a variable number of values. Essentially, a variadic variable is a list of values, where you can add or remove elements as needed during program execution).

```markdown 
int ft_printf(const char* **format**, ...)
{ 
  int len = 0;
  **va_list pointer** //declaration of the variadic variable. declares a variable of type va_list named pointer. va_list is a special type defined in the <stdarg.h> library that is used for manipulating lists of variable arguments.
  **va_start(pointer, format)** // initializes the variable argument list pointed to by pointer. This means that pointer now points to the first variable argument after the fixed argument format in the call to the ft_printf function. This function is used to begin traversing the variable argument list.
...
```

2️⃣ - **While loop with conversions**
```markdown 
// Loop through the format string
    while(*format)
    {
        // Check if the current character is '%' and the next character is a valid specifier
        if ((*format == '%') && ((*(format + 1) == 's') || (*(format + 1) == 'd') || (*(format + 1) == 'x'))) // **just a detail**: its format + 1. Also, be cautious with the parenthesis. They should be doing the right thing. Before *(format + 1) == 's' we have 2 parenthesis at the beginning and 1 at the end (just an example).
        {
            // Move to the next character in the format string
            format++;

            // Check the specifier and call the appropriate function

            if (*format == 's')
                put_string(va_arg(pointer, char *), &len); // **just a detail**: its &len and not len.

            else if (*format == 'd') // **just a detail**: its else if and not if
                put_digit((long long int)va_arg(pointer, int), 10, &len);  **just a detail**: its &len and not len.

            else if (*format == 'x')  //**just a detail**: its else if and not if.
                put_digit((long long int)va_arg(pointer, unsigned int), 16, &len); //**just a detail**: its &len and not len.
        }

        else
            // If not a specifier, write the character to the output
            len += write (1, format, 1);

        // Move to the next character in the format string
        format++;
    }
```
    
3️⃣ - **Close va_lis**t and **return len**. 
```markdown 
// End the variable argument list and return the total length
    return(va_end(pointer), len);
```



Then I memorized the other 2 functions: 

#### **2.1.2.- **PUT_DIGIT**

1️⃣ - First Create a hexadecimal variable to make the conversion from decimal to hexadecimal.
2️⃣ - If number (nbr) is lower than zero.
3️⃣ - If number (nbr) is higher than the base.

```markdown 
**void put_digit**(long long int nbr, int base, int *len) //**just a detail**: its *len and not len.
{
    // Array of hexadecimal characters
    char *hexadecimal = "0123456789abcdef";

    // If the number is negative, print '-' and make it positive
    if(nbr < 0) **just a detail**: its if, not while.
    {
        nbr *= -1;
        *len += write(1, "-", 1); //**just a detail**: its *len and not len.
    }
    
    // If the number is greater than or equal to the base, recursively call put_digit
    if (nbr >= base) **just a detail**: its if and not else if or while.
        put_digit ((nbr /base), base, len); // Basically we use repeated division (using recursion) by 16 and keep track of the remainders. Recursively calls put_digit for the next digit.
    
    // Print the digit
    *len += write(1, &hexadecimal[nbr % base], 1); //**just a detail**: its *len and not len. It´s &hexadecimal and not hexadecimal.
                                                    // nbr % base: Calculates the remainder when the number (nbr) is divided by the base (base). This remainder represents the current digit of the number in the specified base. &hexadecimal[nbr % base]: Accesses the character in the hexadecimal array corresponding to the current digit. Since hexadecimal characters are represented by characters '0' to '9' and 'A' to 'F', this expression fetches the correct character from the array based on the remainder.
}
```
#### ****2.1.3.- PUT_STRING**

1️⃣ - Verify if the string is NULL.
2️⃣ - Iterate the string and return len.

```markdown 
void put_string(char *string, int *len) //**just a detail**: its *len and not len.
{
    // If the string is NULL, set it to "(null)"
    if (!string)
        string = "(null)";
    // Loop through the string and print each character
    while (*string)
        *len += write(1, string++, 1); //**just a detail**: its *len and not len. It´s string++...don´t forget it.
}
```

**LAST_NOTES**

It also helped to memorize how many lines (lines written including braces) each of the functions had.

`PF consists of 3 functions and each of them has the following lines:`
```markdown
- ft_printf (20 lines).
- put_digit (9 lines).
- put_string (4 lines).
```


`- Don´t forget stdarg.h and unistd.h libraries. stdarg is the library of va_list. unistd is the library of write:`
```markdown
#include <stdarg.h>
#include <unistd.h>
```

`- Don´t forget to make a main to test it, as well to include stdio.h library (the library of print):`
```markdown 
#include <stdio.h>
int main ()
{
    // Test the ft_printf function
    ft_printf("%d\n", ft_printf("hello, %s! %d %x\n", "world", -2345, 42));
    // Test the printf function
    printf("%d\n", printf("hello, %s! %d %x\n", "world", -2345, 42));
}
```
.
.
.
.
.
.
### **2.2.-Regarding GET_NEXT_LINE:** 

**GNL has 2 files: get_next_line.c and get_next_line.h.**
It´s expected to deliver both files in the exam.

**get_next_line.c is composed by 6 functions:**
```markdown
1 - get_next_line
2 - ft_strdup
3 - ft_strlen
4 - ft_strcpy
5 - ft_strchr
6 - ft_strjoin
```

2.2.1. - I memorized get_next_line function **divided in 5 + 2 parts** and this function is the basis to the rest:

1st step - **Create 5 variables**;

```markdown 
    static char buf[BUFFER_SIZE + 1];
    char *line;
    char *newline;
    int countread; 
    int to_copy;
```

2nd step - **Line (Declaration and Initialization in the While** Loop);

```markdown 
   line = ft_strdup(buf); // first function to make after get_next_line.

    while(!(newline = ft_strchr(line, '\n')) && (countread = read(fd, buf, BUFFER_SIZE))) //ft_strchr is the fifth function to be made. after ft_strdup, ft_strlen & ft_stcpy (that are called inside ft_strdup).
    {
        buf[countread] = '\0';
        line = ft_strjoin (line, buf); // ft_strjoin is the last(six) function to make. The first and only time it´s called is in the get_next_line function.
    }
```

3rd step - **Security measure** (check if line exists);

```markdown 
 if (ft_strlen(line) == 0) // ft_strlen is the third function to make right after ft_strdup. The first time it´s called is in the ft_strdup function, so it should be made after it.
        return(free(line), NULL);
```
      
4th step - Whether **newline exists or not** (make if or else);

```markdown
if (newline != NULL)
    {
        to_copy = newline - line + 1;
        ft_strcpy(buf, newline + 1); // ft_strcpy is the third function to make after ft_strdup. The first time it´s called is in the ft_strdup function, right after ft_strlen.
    }
    else
    {
        to_copy = ft_strlen(line);
        buf[0] = '\0';
    }
```

5th step - **"Closing" the line** with the to_copy variable as position and **return it**;
```markdown
line[to_copy] = '\0';
    return(line);
```

6th step - **Main** (create a main function to test the function);
```markdown
int main()
{
    char *line;
    int fd = open ("vazio.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    return(0);
} 
```

7th step - **Valgrind** (run Valgrind to check for memory leaks).


**LAST_NOTES**

It also helped to memorize how many lines (lines written including braces) each of the functions had.

`GNL consists of 6 functions and each of them has the following lines:`

```markdown
GNL has 25.
ft_strdup has 6.
ft_strlen has 4.
ft_strcpy has 3.
ft_strchr has 7.
And ft_strjoin has 11.
```

`- Don´t forget to include get_next_line.h`
```markdown
#include "get_next_line.h"
```

`- Don´t forget stdlib.h and unistd.h libraries. stdlib is the library of malloc. unistd is the library of read.:`
```markdown
#include <stdlib.h>
#include <unistd.h>
```

`- Use the main above to test it, and don´t forget to include stdio.h library (the library of print) and fcntl.h (the library of open and O_RDONLY:`
```markdown 
#include <stdio.h>
#include <fcntl.h>
```

##### The rest is practice and attention to detail.


## 📝 3 - ** To Remember Notes**

1. The exam have a duration of 3 hours.

2. No norminette enforcement is applied during the exam.

3. Difference between **Exam Simulator** and the **Real Exam**

### 📝 3.1. - **Exam Simulator**

Practice for the exam just as you would in the actual exam using this tool - Script to launch the program: bash -c "$(curl https://grademe.fr)"

That could be found in the website: https://grademe.fr/

#### 3.1.1 - 👓 CHEAT code :
(sorry don't work in exam at 42)

`remove_grade_time`: remove grade time between two push


> The maximum time to complete the exam is only information. 
  Here, the exercise can always be corrected even after the time limit.

`force_success`: force an exercice to success `

`new_ex`: generate a new exercice on the same level

### 📝 3.2. - **Real Exam**

#### 3.2.1. - Access Information

1. **Sign In With:**
   - Username: exam
   - Password: exam

2. **On the terminal:**
   Enter 'examshell' command

3. **Your 42 Intranet Credentials:**
   - Username: your 42 intra username
   - Password: your password

4. **Submit Your 42 Intranet Photo:**
   Grant permission for photo verification

5. **Submission Confirmation:**
   Type 'y' or 'yes'

6. **Limited Commands in Exam Shell:**
   - 'status': View time and other details
   - 'grademe': Assess pushed exercises (moulinet)
   - 'finish': Close examshell and conclude the exam

#### 📝 3.2.2. - **Exam Submission Details**

When you are ready to submit, make sure the requested folder is inside the Rendu folder and push it by doing the following:

1️⃣ `git add <folder name/files in folder>`

2️⃣ `git status`

3️⃣ `git commit -m "any commit message you like in these strings"`

4️⃣ `git push`

5️⃣ After you git push, type `grademe` in the examshell for your project to be evaluated.

## 📝 4 - **Last Notes**

**Good luck** and in case of any doubt, just contact me: https://github.com/jpjpcs
