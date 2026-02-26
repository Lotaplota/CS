# C fscanf() Format Specifiers - Quick Guide

## Basic Specifiers
| Specifier | Meaning |
|-----------|---------|
| `%c` | Single character |
| `%s` | String (stops at whitespace) |
| `%d` | Decimal integer |
| `%f` | Floating-point number |
| `%x` | Hexadecimal integer |

## Scansets
| Pattern | Meaning |
|---------|---------|
| `%[abc]` | Matches a, b, or c |
| `%[^abc]` | Matches anything except a, b, c |
| `%[a-z]` | Matches any lowercase letter |
| `%[A-Z]` | Matches any uppercase letter |
| `%[^,\n]` | Matches a delimiter, until comma or newline in this case |
| `%[0-9]` | Matches only digits |

## Examples
| Example | What does it do? |
|---------|------------------|
| `"%[^,],%[^,],%d,%[^,],%s"` | Parses CSV data |
| `"\"%[^\"]\""` | Reads quoted strings |
| `#%[A-Fa-f0-9]` | Reads #h3x4d3 numbers |
| `%[0-9:]` | Reads the time format 17:29:53 |
| `%d.%d.%d.%d` | Reads IP addresses |
| `%[^/]/%[^.]` | Reads a file's name and path |

## Modifiers
| Modifier | Meaning | Example |
|----------|---------|---------|
| `*` | Read and discard | `%*[^,]` |
| `9` | Max width (9 chars) | `%9s` |

## Practice Text
```
John Doe, 25, 175.5, john.doe@email.com`
Jane Smith, 31, 162.0, jane_smith@work.com
Bob Wilson, 42, 180.2, bob.wilson@company.org
Alice Brown, 29, 167.8, alice.b@email.net

Product: Laptop-2023, $899.99, IN-STOCK
Product: Mouse-Wireless, $29.95, OUT-OF-STOCK
Product: Monitor-27in, $349.50, IN-STOCK

2023-12-15 Order #A123: 5 items total $245.75
2023-12-16 Order #B456: 2 items total $89.90
2023-12-17 Order #C789: 8 items total $1230.45
```
## My humble first attempt
1. `fscanf(fptr, "%[^,],%[^\n]", name, rest);`
2. `fscanf(fptr, "%[^,], %i[^,]", rest, age);`
3. `fscanf(fptr, "%[^@]@%s[^\n]", rest, domain);`
4. `fscanf(fptr, "Product: %s[^,]", productName);`
5. `fscanf(fptr, "%[^$]$%[^,], %s[^\n]", rest, rest2, stock); // This one I cheated a little bit by using the previous value. Can I do that?`
6. `fscanf(fptr, "%[^#]#%s[4]", rest, orderID);`
7. `fscanf(fptr, "%[^$]$%[^\n]", amount);`

## Correct Solutions
```c
// 1. Names
fscanf(fptr, "%[^,]", name);

// 2. Ages
fscanf(fptr, "%*[^,], %d", &age);

// 3. Email domains
fscanf(fptr, "%*[^@]@%s", domain);

// 4. Product names
fscanf(fptr, "Product: %[^,]", productName);

// 5. Stock status
fscanf(fptr, "%*[^$]$%*f, %s", status);

// 6. Order IDs
fscanf(fptr, "%*[^#]#%4s", orderID);

// 7. Total amounts
float total;
fscanf(fptr, "%*[^$]$%f", &total);
```