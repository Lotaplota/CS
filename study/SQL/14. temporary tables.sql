CREATE TEMPORARY TABLE temp_table (
	first_name VARCHAR(50),
    last_name VARCHAR(50),
    favorite_movie VARCHAR(100)
);

SELECT *
FROM temp_table;

INSERT INTO temp_table VALUES (
	'Alex', 'Freberg', 'Lord of the Rings: The Two Towers'
);

CREATE TEMPORARY TABLE salary_over_50k # A temp table only persists in the session it has been created
SELECT *
FROM employee_salary
WHERE salary >= 50000;

SELECT *
FROM salary_over_50k;