SELECT *
FROM employee_salary;

SELECT *
FROM employee_demographics;

DELIMITER $$
CREATE TRIGGER employee_insert
	AFTER INSERT ON employee_salary # Or, optionally, BEFORE
    FOR EACH ROW
    BEGIN
		INSERT INTO employee_demographics (employee_id, first_name, last_name)
        VALUES (NEW.employee_id, NEW.first_name, NEW.last_name);
	END $$
DELIMITER ;

INSERT INTO employee_salary (employee_id, first_name, last_name, occupation, salary, dept_id)
VALUES (13, 'Jean Ralphio', 'Saperstein', 'Entertainment 720 CEO', 1000000, NULL);

-- EVENTS
SELECT *
FROM employee_demographics;

DELIMITER $$
CREATE EVENT delete_retirees
	ON SCHEDULE EVERY 30 SECOND
	DO
	BEGIN
		DELETE
		FROM employee_demographics
		WHERE age >= 60;
	END $$
DELIMITER ;

DROP EVENT delete_retirees;
DROP TRIGGER employee_insert;

SHOW VARIABLES LIKE 'event%';