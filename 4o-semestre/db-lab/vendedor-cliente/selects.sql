SELECT MAX(salario_vendedor) AS MAIOR_SALARIO,
MIN(salario_vendedor) AS MENOR_SALARIO
FROM vendedor;

SELECT nome_vendedor, salario_vendedor
FROM vendedor
WHERE salario_vendedor = (SELECT MAX(salario_vendedor) FROM vendedor)
OR salario_vendedor = (SELECT MIN(salario_vendedor) FROM vendedor);

SELECT nome_vendedor, 
FROM vendedor
where salario_vendedor < 1000.00;

WITH ranking_salario AS (
    SELECT nome_vendedor, salario_vendedor,
    RANK() OVER (ORDER BY salario_vendedor DESC) AS rank_maior,
    RANK() OVER (ORDER BY salario_vendedor ASC) AS rank_menor
    FROM vendedor
)
SELECT nome_vendedor, salario_vendedor,
CASE
    WHEN rank_maior = 1 THEN 'maior salario'
    WHEN rank_menor = 1 THEN 'menor salario'
END AS tipo
FROM ranking_salario
WHERE rank_maior = 1 OR rank_menor = 1;

-- encontrar salarios iguais na tabela vendedor

SELECT salario_vendedor, COUNT() AS quantidade
FROM vendedor
GROUP BY salario_vendedor
HAVING COUNT() > 0;

---------------
---- VIEWS ----
---------------
CREATE VIEW vw_vendedores AS
SELECT nome_vendedor, tel_vendedor
FROM vendedor;

SELECT * FROM vw_vendedores;

SELECT * FROM vw_vendedores WHERE nome_vendedor LIKE "Ana%";

DROP VIEW vw_vendedores;

ALTER VIEW vw_vendedores AS
SELECT nome_vendedor, tel_vendedor, salario_vendedor
FROM vendedor
WHERE salario_vendedor > 3000;

SELECT * FROM vw_vendedores
WHERE salario > 5000
ORDER BY salario_vendedor DESC;

CREATE OR REPLACE VIEW vw_vendedores AS
SELECT nome_vendedor, tel_vendedor, salario_vendedor,
    (salario_vendedor * 0.1) AS bonus,
    (salario_vendedor + salario_vendedor * 0.1) AS salario_bonado
FROM vendedor
ORDER BY salario_vendedor DESC;