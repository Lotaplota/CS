int *p, x = 5; // Estabelecendo um ponteiro de um inteiro
p = &x;
*p *= 2**p;    // Multiplicando o conteúdo do endereço &p por 2 vezes o conteúdo do endereço &p. O conteúdo de p seria 50
printf("%d", x);